#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>

#define inf 0x3f3f3f3f
#define Inf 0x3FFFFFFFFFFFFFFFLL

#define maxn 111
using namespace std;
const double eps=1e-9;
struct Point{
    double x,y;
};
struct Poly{
    int n;
    Point p[maxn];
}ori,res;
double cross(Point a,Point b,Point c){
    return (b.x-a.x)*(c.y-a.y)-(c.x-a.x)*(b.y-a.y);
}
void getLine(Point a,Point b,double &a1,double &b1,double &c1){
    a1=b.y-a.y;
    b1=a.x-b.x;
    c1=a.y*(b.x-a.x)-a.x*(b.y-a.y);
}
Point intersect(double a1,double b1,double c1,double a2,double b2,double c2){
    Point res;
    res.y=(a1*c2-a2*c1)/(a2*b1-a1*b2);
    if(fabs(a1)<eps)res.x=(-c2-b2*res.y)/a2;
    else res.x=(-c1-b1*res.y)/a1;
    return res;
}
Poly cut(Point p1,Point p2,Poly s){
    Poly t;
    t.n=0;
    double a,b,c,a1,b1,c1;
    getLine(p1,p2,a,b,c);
    for(int i=1;i<=s.n;i++){
        if(a*s.p[i].x+b*s.p[i].y+c>-eps){
            t.p[t.n++]=s.p[i];
        }
        else{
            if(a*s.p[i-1].x+b*s.p[i-1].y+c>-eps){
                getLine(s.p[i-1],s.p[i],a1,b1,c1);
                t.p[t.n++]=intersect(a,b,c,a1,b1,c1);
            }
            if(a*s.p[i+1].x+b*s.p[i+1].y+c>-eps){
                getLine(s.p[i],s.p[i+1],a1,b1,c1);
                t.p[t.n++]=intersect(a,b,c,a1,b1,c1);
            }
        }
    }
    t.p[t.n]=t.p[0];
    t.p[t.n+1]=t.p[1];
    return t;
}

int main(){
    while (scanf("%d",&ori.n) && ori.n) {
        for(int i=ori.n- 1;i >= 0;i--){
            scanf("%lf%lf",&ori.p[i].x,&ori.p[i].y);
        }
        ori.p[ori.n]=ori.p[0];
        ori.p[ori.n+1]=ori.p[1%ori.n];
        res=ori;
        for(int i=0;i<ori.n;i++){
            res=cut(ori.p[i],ori.p[i+1],res);
        }
        if (res.n) puts("1");
        else puts("0");
    }
    return 0;
}
