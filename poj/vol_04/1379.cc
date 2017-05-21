#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<ctime>
#define MAXM 1005
#define max(a,b) (a>b?a:b)
using namespace std;
const int N=10,L=30;
const double eps=1e-3;
struct point{
    double x,y,d;
}p[MAXM],s[N],st;
int T,W,H,M;
double dist(point a,point b){
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
double cal(point t){
    if(t.x<0 || t.x>W || t.y<0 || t.y>H)return 0;
    double r=1e10,d;
    for(int i=0;i<M;i++){
        d=dist(t,p[i]);
        if(d<r)r=d;
    }
    return r;
}
int main(){
    double delta,phi;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d",&W,&H,&M);
        for(int i=0;i<M;i++)scanf("%lf %lf",&p[i].x,&p[i].y);
        for(int i=0;i<N;i++){
            s[i].x=rand()%(W+1);
            s[i].y=rand()%(H+1);
            s[i].d=cal(s[i]);
           // printf("%lf,%lf %lf\n",s[i].x,s[i].y,s[i].d);
        }
        delta=max(W,H);
        while(delta>eps){
            for(int i=0;i<N;i++){
                for(int j=0;j<L;j++){
                    phi=rand();
                    st.x=s[i].x+delta*cos(phi);
                    st.y=s[i].y+delta*sin(phi);
                    //printf("%lf %lf\n",st.x,st.y);system("pause");
                    st.d=cal(st);
                    if(st.d>s[i].d){
                        s[i]=st;
                    }
                }
            }
            delta*=0.8;
        }
        int res=0;
        for(int i=0;i<N;i++){
            if(s[i].d>s[res].d)res=i;
        }
        printf("The safest point is (%.1lf, %.1lf).\n",s[res].x,s[res].y);
    }
    return 0;
}
