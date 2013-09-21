/*************************************************************************
    > File Name: B - Broken line.cpp
    > Author: tiankonguse
    > Mail: shen10000shen@gmail.com
    > Created Time: 2013/5/5 19:20:20
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<set>
#include<cmath>
#include<map>
#include<queue>
#include<stack>
#include<functional>
#include<algorithm>
using namespace std;

#define EP 1e-10
struct Lpoint{double x,y;}p[21000],tmp[11000];
struct Llineseg{Lpoint a,b;};
const double  inf = 1e20;
typedef pair<int,int>node_type;
map<node_type,int>m;

double xmulti(Lpoint p1, Lpoint p2, Lpoint p0){
    return (p1.x - p0.x)*(p2.y - p0.y) - (p2.x - p0.x)*(p1.y-p0.y);
}

double mx(double t1, double t2){
    return t1>t2?t1:t2;
}

double mn(double t1, double t2){
    return t1<t2?t1:t2;
}

int lsinterls(Llineseg u, Llineseg v){
    return (mx(u.a.x,u.b.x) >= mn(v.a.x,v.b.x)) &&
           (mx(v.a.x,v.b.x) >= mn(u.a.x,u.b.x)) &&
           (mx(u.a.y,u.b.y) >= mn(v.a.y,v.b.y)) &&
           (mx(v.a.y,v.b.y) >= mn(u.a.y,u.b.y)) &&
           (xmulti(v.a,u.b,u.a)*xmulti(u.b,v.b,u.a)>=0)&&
           (xmulti(u.a,v.b,v.a)*xmulti(v.b,u.b,v.a)>=0)
           ;
}

int ponls(Llineseg l, Lpoint p){
    return ((xmulti(l.b, p, l.a)==0) && (((p.x-l.a.x)*(p.x-l.b.x)<0) || ((p.y-l.a.y)*(p.y-l.b.y)<0)));
}

int Euqal_Point(Lpoint p1, Lpoint p2){
    return (fabs(p1.x-p2.x)<EP && (fabs(p1.y-p2.y)<EP));
}

int lsinterls_A(Llineseg u, Llineseg v){
    return (lsinterls(u,v)) && (!Euqal_Point(u.a,v.a)) && (!Euqal_Point(u.a,v.b)) && (!Euqal_Point(u.b,v.a)) && (!Euqal_Point(u.b,v.b));
}

int pinpg(int vcount, Lpoint Polygon[], Lpoint q){
    int c, i, n;
    Llineseg l1 ,l2;
    l1.a = q;
    l1.b = q;
    l1.b.x = inf;
    n = vcount;

    for(i=0;i<vcount;i++){
        l2.a = Polygon[i];
        l2.b = Polygon[(i+1)%n];

    if((lsinterls_A(l1,l2)) ||
       (
        ponls(l1,Polygon[(i+1)%n]) &&
        (
         !ponls(l1, Polygon[(i+2)%n]) &&
         (xmulti(Polygon[i], Polygon[(i+1)%n],l1.a)*xmulti(Polygon[(i+1)%n], Polygon[(i+2)%n],l1.a)>0)
         ||
         ponls(l1, Polygon[(i+2)%n]) &&
         (xmulti(Polygon[i], Polygon[(i+2)%n],l1.a)*xmulti(Polygon[(i+2)%n], Polygon[(i+3)%n],l1.a)>0)

         ) ))c++;
    }

return (c%2!=0);

}

int main() {

    int n,i,x,y;
    while(~scanf("%d",&n)){
        m.clear();
        for(i=0;i<n;i++){
            scanf("%d%d",&x,&y);
            tmp[i].x = x;
            tmp[i].y = y;
            node_type = make_pair(x,y);

        }
    }


    return 0;
}
