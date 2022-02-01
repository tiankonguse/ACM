#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#define MAXP 16
#define inf 0x7f7f7f7f
using namespace std;
int data[16]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768};
struct Point{
    int x,y,v;
    double l;
    friend bool operator<(Point a,Point b){
        if(a.y==b.y)return a.x<b.x;
        else return a.y<b.y;
    }
}ori[MAXP],pnt[MAXP],res[MAXP];
double dist(double x1,double y1,double x2,double y2){
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
int Xmul(Point a, Point b, Point c)  { return (b.x - a.x)*(c.y-a.y) - (c.x-a.x)*(b.y-a.y);}
int ab(int x){return x>0?x:-x;}
int graham(int n){
    int i,j, top = 1;
    sort(pnt, pnt+n);//排序，先y在x
    pnt[n] = pnt[0];
    if (n==0) return 0; res[0] = pnt[0];
    if (n==1) return 1; res[1] = pnt[1];
    if (n==2) return 2; res[2] = pnt[2];
    for (i = 2; i < n; i++) {
        while (top && Xmul(res[top-1],res[top],pnt[i]) <= 0)  top--; //等于0也pop
        res[++top] = pnt[i];
    }
    j = top;
    res[++top] = pnt[n-2];
    for (i = n-3; i >= 0; i--)
    {
        while (top!=j && Xmul(res[top-1],res[top],pnt[i])<= 0)  top--;
        res[++top] = pnt[i];
    }
    res[top] = res[0];
    return top;
}
int main(){
    int N,fo=1;
    while(scanf("%d",&N)&&N){
        for(int i=0;i<N;i++){
            scanf("%d %d  %d %lf",&ori[i].x,&ori[i].y,&ori[i].v,&ori[i].l);
        }
        int re=-1,mv=inf,mn=0,cnt,uv;
        double ul,tl,ext=-1;
        int total=(1<<N),un;
        for(int i=0;i<total;i++){
            un=__builtin_popcount(i);
            //if(un<=1)continue;
            cnt=0,ul=0,uv=0;
            for(int j=0;j<N;j++){
                if((data[j]&i)==0){
                    ul+=ori[j].l;
                    uv+=ori[j].v;
                }
                else{
                    pnt[cnt++]=ori[j];
                }
            }
            int ln=graham(cnt);
            res[ln]=res[0];
            tl=0;
            for(int j=0;j<ln;j++){
                tl+=dist((double)res[j].x,(double)res[j].y,(double)res[j+1].x,(double)res[j+1].y);
            }
            if(tl<=ul){
                if(uv==mv){
                    if(un>mn){
                        mn=un;
                        re=i;
                        ext=ul-tl;
                    }
                }
                else if(uv<mv){
                    mv=uv;
                    mn=un;
                    re=i;
                    ext=ul-tl;
                }
            }
        }
        if(fo>1)printf("\n");
        printf("Forest %d\nCut these trees:",fo++);
        for(int i=0;i<N;i++){
            if((data[i]&re)==0){
                printf(" %d",i+1);
            }
        }
        printf("\nExtra wood: %.2f\n",ext);
    }
    return 0;
}
