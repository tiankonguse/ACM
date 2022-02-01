#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<string>
#include<queue>
#include<map>
#include<cmath>
#include<stack>
#include<algorithm>
#include<functional>
#include<stdarg.h>
using namespace std;
#ifdef __int64
typedef __int64 LL;
#else
typedef long long LL;
#endif
int sign(double x,double eps=1e-8) {
    return(x<-eps?-1:x>eps);
}


struct Point;
struct Circle;
struct Triangle;

struct Point {
    double x,y;
    void input() {
        scanf("%lf%lf",&x,&y);
    }
    void output()const {
        printf("%lf %lf\n",x,y);
    }
    //初始化点
    Point(double x=0,double y=0):x(x),y(y) {}

    //定义<运算符，在map里需要使用
    bool operator<(Point const& o)const {
        if(sign(o.x - x) == 0) {
            return sign(o.y - y) < 0;
        } else {
            return sign(o.x - x) < 0;
        }
    }
    //定于==运算符，用于判断时候是一个中点。
    bool operator == (Point const&o)const {
        return sign(x -o.x) == 0 && sign(y - o.y) == 0;
    }

    Point operator +(Point const&o)const {
        return Point(x+o.x, y+o.y);
    }
    Point operator -(Point const&o)const {
        return Point(x-o.x, y-o.y);
    }
    Point operator *(double o)const {
        return Point(x*o, y*o);
    }
    Point operator /(double o)const {
        return Point(x/o, y/o);
    }
    double operator ^ (Point o) {
        return x*o.y - y*o.x;
    }

    //单位化一个向量
    Point init() {
        return *this / this->len();
    }
    //得到角度
    double angle() const {
        return(atan2(y,x));
    }

    double len() {
        return sqrt(x*x+y*y);
    }
    Point inversion() {
        double l = x*x+y*y;
        return Point(x/l, y/l);
    }
    //逆时针旋转 rad
    Point rotate(double rad) {
        return Point(x*cos(rad)-y*sin(rad), x*sin(rad)+y*cos(rad));
    }
} ;
struct Circle {
    Point center;
    double r;
    Circle() {}
    Circle(Point center, double r=0):center(center),r(r) {}
    Circle operator +(Point const&o)const {
        return Circle(center+o, r);
    }
    Circle operator -(Point const&o)const {
        return Circle(center - o, r);
    }
    Circle inversion() {
//        Point a = (center + Point(0,r)).inversion();
//        Point b = (center - Point(0,r)).inversion();
//        Point c = (center - Point(r,0)).inversion();
//        return Triangle(a,b,c).circumcircle();

        double x=1/(center.len() - r);
        double y=1/(center.len() + r);
        Circle s;
        s.r=(x-y)/2.;
        x=(x+y)/2.;
        y=center.len();
        s.center= center*(x/y);
        return s;
    }

    Point getAnglePoint(double angle) {
        return center + Point(r*cos(angle),r*sin(angle));
    }

    void input() {
        center.input();
        scanf("%lf",&r);
    }
    void output() {
        center.output();
        printf("r=%lf\n",r);
    }
};

struct Triangle {
    Point a,b,c;
    Triangle() {}
    Triangle(Point a, Point b, Point c):a(a),b(b),c(c) {}
    Circle circumcircle() {
        double bx=b.x-a.x,by=b.y-a.y;
        double cx=c.x-a.x,cy=c.y-a.y;
        double d=2*(bx*cy-by*cx);
        double x=(cy*(bx*bx+by*by)-by*(cx*cx+cy*cy))/d+a.x;
        double y=(bx*(cx*cx+cy*cy)-cx*(bx*bx+by*by))/d+a.y;
        Point res(x,y);
        return Circle(res,(res-a).len());
    }
    double xmult() {
        return (a-c)^(b-c);
    }
    int dot_inline() {
        return sign(xmult());
    }
};




vector<Circle>ans;

int main() {
    Circle one,two;
    Point vec,first,second, newVec;
    Point p,ZERO(0,0);
    double angle, base ;
    int t,s;
    scanf("%d",&t);
    while(t--) {
        ans.clear();
        one.input();
        two.input();
        p.input();
        //两个圆平移
        one = one - p;
        two = two - p;
//		one.output();
//		two.output();
        //两个圆反演
        one = one.inversion();
        two = two.inversion();
//1 1 2 10 10 2 5 5
        //one 大圆 two小圆
        if(sign(one.r - two.r) < 0) {
            swap(one, two);
        }
//		one.output();
//		two.output();
        //大圆到小圆的连心线的向量
        vec =  two.center - one.center;
        //连心线的角度
        base=atan2(vec.y, vec.x);
        //得到法线与连心线的角度
        angle  =  acos((one.r - two.r)/vec.len());
//        printf("%lf\n",angle);
        //向量旋转
//        newVec = vec.rotate(-angle);
//        first = one.center + newVec * one.r / newVec.len();
//        second = two.center + newVec * two.r / newVec.len();
        first = one.getAnglePoint(base+angle);
        second = two.getAnglePoint(base+angle);
        if(sign((one.center - first)^(second-first)) == sign((ZERO-first)^(second-first)) &&
                sign((two.center -first)^(second-first)) ==  sign((ZERO-first)^(second-first))  &&
                Triangle(first, second, ZERO).dot_inline() != 0) {
            first = first.inversion();
            second = second.inversion();
            ans.push_back(Triangle(first, second, ZERO).circumcircle() + p);
        }

//        //向量旋转
//        newVec = vec.rotate(angle);
//        first = one.center + newVec * one.r / newVec.len();
//        second = two.center + newVec * two.r / newVec.len();
        first = one.getAnglePoint(base-angle);
        second = two.getAnglePoint(base-angle);

        if(sign((one.center - first)^(second-first)) == sign((ZERO-first)^(second-first)) &&
                sign((two.center -first)^(second-first)) ==  sign((ZERO-first)^(second-first))  &&
                Triangle(first, second, ZERO).dot_inline() != 0) {
            first = first.inversion();
            second = second.inversion();
            ans.push_back(Triangle(first, second, ZERO).circumcircle() + p);
        }

        printf("%d\n",ans.size());
        for(int i=0; i<ans.size(); i++) {
            printf("%.8f %.8f %.8f\n",ans[i].center.x, ans[i].center.y, ans[i].r);
        }
    }

    return 0;
}
