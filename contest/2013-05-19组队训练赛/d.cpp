
#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
const double PI = acos(-1.0);
struct Point
{
    double x,y;
//    Point(){}
    Point(double x=0,double y=0):x(x),y(y){}
    void init(double _x,double _y){
        x = _x,y=_y;
    }
    void output(){
        printf("--%lf %lf\n",x,y);
    }
};
vector<Point>ab,ac,bc;
typedef Point Vector;
Point A,B,C;
Vector operator +(Vector A,Vector B)
{
    return Vector(A.x+B.x,A.y+B.y);
}
Vector operator -(Vector A,Vector B)
{
    return Vector(A.x-B.x,A.y-B.y);
}
const double eps=  1e-10;
int dcmp(double x)
{
    if(fabs(x)<eps)return 0;
    else return x<0?-1:1;
}
bool operator ==(const Point &a,const Point &b)
{
    return dcmp(a.x-b.x)==0&&dcmp(a.y-b.y)==0;
}
struct Circle
{
    Point c;
    double r;
    Circle(Point c,double r):c(c),r(r){}
    Circle(){}
    void init(Point _c,double _r){
        c=_c,r=_r;
    }
    Point point(double a)
    {
        return Point(c.x+cos(a)*r,c.y+sin(a)*r);
    }
};
double Angle(double a,double b,double c)
{
    return acos((b*b+c*c-a*a)/(2*b*c));
}

double Cirlearea(Circle a)
{
    return PI*a.r*a.r;
}

double angle(Vector v)
{
    return atan2(v.y,v.x);
}
double Dot(Vector A,Vector B)
{
    return A.x*B.x+A.y*B.y;
}
double Length(Vector A)
{
    return sqrt(Dot(A,A));
}
int getCircleCircleIntersection(Circle c1,Circle c2,vector<Point>&sol)
{
    double d = Length(c1.c-c2.c);
    if(dcmp(d)==0)
    {
        if(dcmp(c1.r-c2.r)==0)return -1;
        return 0;
    }
    if(dcmp(c1.r+c2.r-d)<0)return 0;
    if(dcmp(fabs(c1.r-c2.r)-d)>0)return 0;
    double a = angle(c2.c-c1.c);
    double da = acos((c1.r*c1.r+d*d-c2.r*c2.r)/(2*c1.r*d));
    Point p1 = c1.point((a-da)),p2 = c1.point(a+da);
    sol.push_back(p1);
    if(p1==p2)return 1;
    sol.push_back(p2);
    return 2;
}
double Dis(Point& a,Point& b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
bool isin(Circle& a,Point& b)
{
    return Dis(a.c,b)<=a.r;
}
double Cross(Vector A,Vector B)
{
    return A.x*B.y-A.y*B.x;
}
double getS(Point &a,Point &b,Point &c){
    return fabs(Cross(a-b,a-c)/2);
}
double getSX(Circle p,Point a,Point b)
{
    return p.r*p.r*Angle(Dis(a,b),p.r,p.r);
}
int main(){
    Point a,b,c;
    Point _a,_b,_c;
    double r1,r2,r3;
    double _ans;
//    a.init(0,0);b.init(1,0);c.init(0,-1);
    Circle aa,bb,cc;
//   aa.init(a,1);
//    cout<<getSX(aa,c,b)<<endl;
    while(~scanf("%lf%lf%lf%lf%lf%lf%lf%lf%lf",&a.x,&a.y,&r1,&b.x,&b.y,&r2,&c.x,&c.y,&r3))
    {

        aa = Circle(a,r1);
        bb = Circle(b,r2);
        cc = Circle(c,r3);
        ab.clear();ac.clear();bc.clear();
        getCircleCircleIntersection(aa,bb,ab);
        getCircleCircleIntersection(aa,cc,ac);
        getCircleCircleIntersection(cc,bb,bc);

//        bc[0].output();
//        bc[1].output();
//        ac[0].output();
//        ac[1].output();
//        ab[0].output();
//        ab[1].output();


        printf("%d  %d  %d\n",ac.size(),ab.size(),bc.size());

        if(isin(aa,bc[0])){
            _a = bc[0];
        }else{
            _a =bc[1];
        }


        if(isin(bb,ac[0])){
            _b = ac[0];
        }else{
            _b =ac[1];
        }
        if(isin(cc,ab[0])){
            _c = ab[0];
        }else{
            _c =ab[1];
        }

        _a.output();
        _b.output();
        _c.output();

        _ans = getS(_a,_b,_c);

//        printf("--%lf\n",_ans);

        _ans += getSX(aa,_b,_c) - getS(aa.c,_b,_c);
        _ans += getSX(bb,_a,_c) - getS(bb.c,_a,_c);
        _ans += getSX(cc,_b,_a) - getS(cc.c,_b,_a);

        printf("%.3f\n",_ans);
    }

    return 0;
}
