#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<algorithm>
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define MAXN 101
using namespace std;
const int M=30,L=30;
const double eps=1e-5;
int N, XL,XH,YL,YH;
struct point{
    double x,y,d;
}p[MAXN],s[M],st;
double dist(point a,point b){
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
double calc(point t){
    if(t.x<XL || t.x>XH || t.y<YL || t.y>YH)return 1e10;
    double r=0;
    for(int i=0;i<N;i++){
        r+=dist(t,p[i]);
    }
    return r;
}
int main(){
    while(~scanf("%d",&N)){
        XL=YL=1e10;
        XH=YH=0;
        for(int i=0;i<N;i++){
            scanf("%lf %lf",&p[i].x,&p[i].y);
            if(p[i].x<XL)XL=p[i].x;
            if(p[i].x>XH)XH=p[i].x;
            if(p[i].y<YL)YL=p[i].y;
            if(p[i].y>YH)YH=p[i].y;
        }
        //cout<<XL<<","<<XH<<endl;
        for(int i=0;i<M;i++){
            s[i].x=rand()%(XH-XL+1);
            s[i].y=rand()%(YH-YL+1);
            s[i].d=calc(s[i]);
        }
        double delta=max(XH-XL,YH-YL),phi;
        while(delta>eps){
            for(int i=0;i<N;i++){
                for(int j=0;j<M;j++){
                    phi=rand();
                    st.x=s[i].x+delta*cos(phi);
                    st.y=s[i].y+delta*sin(phi);
                    st.d=calc(st);
                    if(st.d<s[i].d)s[i]=st;
                }
            }
            delta*=0.8;
        }
        int idx=0;
        for(int i=1;i<M;i++){
            if(s[i].d<s[idx].d)idx=i;
        }
        printf("%.0lf\n",s[idx].d);
    }
    return 0;
}
