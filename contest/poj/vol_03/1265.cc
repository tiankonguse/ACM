#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#define MAXN 110
using namespace std;
int gcd(int a,int b){
    return b?gcd(b,a%b):a;
}
int ab(int x){
    return x>0?x:-x;
}
struct point{
    int x,y;
}p[MAXN];
int cross(int x1,int y1,int x2,int y2){
    return x1*y2-x2*y1;
}
int main(){
    int T,N,tx,ty,x,y,b,c,s;
    scanf("%d",&T);
    for(int sc=1;sc<=T;sc++){
        scanf("%d",&N);
        x=y=b=s=0;
        for(int i=0;i<N;i++){
            scanf("%d%d",&tx,&ty);
            b+=gcd(ab(tx),ab(ty));
            p[i].x=x,p[i].y=y;
            x+=tx,y+=ty;
        }
        p[N].x=x,p[N].y=y;
        for(int i=0;i<N;i++){
            s+=cross(p[i].x,p[i].y,p[i+1].x,p[i+1].y);
        }
        s=ab(s);
        c=(s-b+2)/2;
        printf("Scenario #%d:\n%d %d %d",sc,c,b,s/2);
        if(s&1)printf(".5\n");
        else printf(".0\n");
        if(sc!=T)printf("\n");
    }
    return 0;
}
