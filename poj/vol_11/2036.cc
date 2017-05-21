#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define MAXN 10005
#define inf 1e10
using namespace std;
const double eps=1e-8;
inline int sgn(double x){
    return (x<-eps?-1:x>eps?1:0);
}
struct Point{
    double x,y;
    friend bool operator<(Point a,Point b){
        return (a.x==b.x?a.y<b.y:a.x<b.x);
    }
    friend bool operator>(Point a,Point b){
        return (a.x==b.x?a.y>b.y:a.x>b.x);
    }
};
struct Line{
    double d;
    Point p[2];
    friend bool operator<(Line a,Line b){
        int k=sgn(a.d-b.d);
        if(k==0){
            if(a.d==inf){
                return a.p[0].x==b.p[0].x?a.p[0].y<b.p[0].y:a.p[0].x<b.p[0].x;
            }
            else if(a.d==0){
                return a.p[0].y==b.p[0].y?a.p[0].x<b.p[0].x:a.p[0].y<b.p[0].y;
            }
            else return a.p[0]<b.p[0];
        }
        else return k<0;
    }
}l[MAXN],pl;
bool xmul(Point a,Point b,Point c){
    double x1=b.x-a.x;
    double y1=b.y-a.y;
    double x2=c.x-a.x;
    double y2=c.y-a.y;
    return sgn(x1*y2-x2*y1)==0;
}
int main(){
    int N;
   // freopen("2036in.txt","r",stdin);
   // freopen("2036out.txt","w",stdout);
    while(scanf("%d",&N)&&N){
        for(int i=0;i<N;i++){
            scanf("%lf %lf %lf %lf",&l[i].p[0].x,&l[i].p[0].y,&l[i].p[1].x,&l[i].p[1].y);
            sort(l[i].p,l[i].p+2);
            if(sgn(l[i].p[0].x-l[i].p[1].x)==0)l[i].d=inf;
            else l[i].d=(l[i].p[1].y-l[i].p[0].y)/(l[i].p[1].x-l[i].p[0].x);
        }
        sort(l,l+N);
      //  for(int i=0;i<N;i++)printf("%lf\n",l[i].d);
      //  for(int i=0;i<N;i++)printf("%.2lf %.2lf %.2lf %.2lf\n",l[i].p[0].x,l[i].p[0].y,l[i].p[1].x,l[i].p[1].y);

        int res=0;
        double d=-inf;
        for(int i=0;i<N;i++){
            if(sgn(l[i].d-d)!=0 || !xmul(pl.p[0],pl.p[1],l[i].p[0])){
                res++;
                d=l[i].d;
                pl=l[i];
            }
            else{
                if(pl.p[1]<l[i].p[0]){
                    res++;
                }
                if(pl.p[1]<l[i].p[1])pl=l[i];
            }
        }
        printf("%d\n",res);
    }
    return 0;
}
