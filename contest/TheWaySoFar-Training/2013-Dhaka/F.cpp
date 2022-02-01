#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;

int gcd(int a,int b){
    return (b==0)?a:gcd(b,a%b);
}

int main(){
    int T,num=0;
    scanf("%d",&T);
    for (;T;--T){
        int x1,y1,x2,y2;
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        int c=max(max(x1,y1),max(x2,y2));
        int xx=x2-x1,yy=y2-y1;
        printf("Case %d: ",++num);
        if(xx==0) {
            printf("0 0 1 0\n");
            continue;
        }
        if (yy==0){
            printf("0 0 0 1\n");
            continue;
        }
        int k=gcd(abs(xx),abs(yy));
        xx/=k,yy/=k;
        y1=xx,x1=-yy;
        x2=0,y2=0;
        if (x1<0) x2=-x1,x1=0;
        if (y1<0) y2=-y1,y1=0;
        printf("%d %d %d %d\n",x1,y1,x2,y2);
    }
}
