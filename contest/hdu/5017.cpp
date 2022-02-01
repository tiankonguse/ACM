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

double esp = 10e-6;

typedef struct Point {
    double a,b,c;
    double l;
    inline double dis (const Point&p)const {
        return (p.a-a)*(p.a-a) + (p.b-b)*(p.b-b) +(p.c-c)*(p.c-c);
    }
    inline double dis()const {
        return l;
    }
    void init(double a,double b,double c) {
        this->a=a;
        this->b=b;
        this->c=c;
        l = a*a + b*b + c*c;
    }
    inline bool less(const Point&p)const {
        return l < p.l;
    }
} Point;

typedef struct {
    double a,b,c,d,e,f;
    Point ans;
    double r;
    vector<Point> testPoint;
    bool read() {
        return ~scanf("%lf%lf%lf%lf%lf%lf",&a,&b,&c,&d,&e,&f);
    }
    //随意找到一个局部最优的
    void getFirstAns() {
        r = max(a,b);
        r = max(r,c);
        ans.init(0,0,sqrt(1/r));
    }

    //得到一个范围半径
    void initRadius() {
        r = min(a,b);
        r = min(r,c);
        r = 1/r;
    }

    //模拟退火得到答案
    void solve() {

        int size;
        bool ok = false;
        while(r>esp) {
            ok = false;
            testPoint.clear();
            getTestPoint();
            size = testPoint.size();
            for(int i=0; i<size; i++) {
                if(testPoint[i].less(ans)) {
                    ans = testPoint[i];
                    ok = true;
                }
            }
            if(ok == false) {
                r = r/2;
            }

        }
    }


    void getZ(double x, double y) {
        double z;
        double a0,b0,c0;
        a0 = c;
        b0 = d*y + e*x;
        c0 = a*x*x + b*y*y + f*x*y - 1;
        double d0 = b0*b0 - 4*a0*c0;
        Point point;
        if(d0 >= 0) {
            d0 = sqrt(d0);
            z = (-b0+d0)/(2*a0);
            point.init(x,y,z);
            testPoint.push_back(point);
            z = (-b0-d0)/(2*a0);
            point.init(x,y,z);
            testPoint.push_back(point);
        }
    }
    void getY(double x,double z) {
        double y;
        double a0,b0,c0;
        a0 = b;
        b0 = d*z+f*x;
        c0 = a*x*x+c*z*z+e*x*z-1;
        double d0 = b0*b0 - 4*a0*c0;
        Point point;
        if(d0 >= 0) {
            d0 = sqrt(d0);
            y = (-b0+d0)/(2*a0);
            point.init(x,y,z);
            testPoint.push_back(point);
            y = (-b0-d0)/(2*a0);
            point.init(x,y,z);
            testPoint.push_back(point);
        }
    }
    void getX(double y,double z) {
        double x;
        double a0,b0,c0;
        a0 = a;
        b0 = e*z+f*y;
        c0 = b*y*y+c*z*z+d*y*z-1;
        double d0 = b0*b0 - 4*a0*c0;
        Point point;
        if(d0 >= 0) {
            d0 = sqrt(d0);
            x = (-b0+d0)/(2*a0);
            point.init(x,y,z);
            testPoint.push_back(point);
            x = (-b0-d0)/(2*a0);
            point.init(x,y,z);
            testPoint.push_back(point);
        }
    }

    //找目前最优解周围的若干点
    //为了简单，采用以目前最优解为中心的立方体的26*2个点作为周围点
    //任意确定两个方向的值，可以用方程求出第三个方向的值。
    void getTestPoint() {
        double x,y,z;
        x = ans.a;
        y = ans.b;
        z = ans.c;
        for(int i=-1; i<=1; i++) {
            for(int j=-1; j<=1; j++) {
                getZ(x+r*i,y+r*j);
                getX(y+r*i,z+r*j);
                getY(x+r*i,z+r*j);
            }

        }
    }

    double getAns() {
        return sqrt(ans.l);
    }

} Ellipsoid;

int main() {

    Ellipsoid ellipsoid;
    while(ellipsoid.read()) {
        ellipsoid.getFirstAns();
        ellipsoid.initRadius();
        ellipsoid.solve();
        printf("%.8f\n",ellipsoid.getAns());
    }

    return 0;
}
