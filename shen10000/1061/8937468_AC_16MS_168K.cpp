#include<stdio.h>
int gcd(int a,int b)
{if(b==0)return a;else return gcd(b,a%b);}
void extend_gcd(int a,int b,__int64 &x,__int64 &y)
{if(b==0){x=1;y=0;return ;}extend_gcd(b,a%b,x,y);__int64 temp=x;x=y;y=temp-a/b*y;}
int main (void){int x,y,m,n;__int64 x1,y1;int a,b,c;
while(scanf("%d %d %d %d %d",&x,&y,&m,&n,&b)!=EOF)
{a=m-n;c=y-x;int r=gcd(a,b);if(c%r)printf("Impossible\n");
else{extend_gcd(a,b,x1,y1);x1=(c*x1/r)%b;if(x1<0)x1+=b;printf("%I64d\n",x1);}}return 0;}