#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
using namespace std;
const int N=1000001;
const int M=150000;

bool judge[432][432];
long long rest[432][432];
int prm[M],np,p1[M],p2[M],p3[M],c=20100501;
bool is[N*2];

int getprm(int n)//素数打标
{
    int i,j,k=0;
    int s,e=(int)(sqrt(0.0+n)+1);
     memset(is,1,sizeof(is));
     prm[k++]=2;
     is[0]=is[1]=0;
    for(i=4;i<n;i+=2)
         is[i]=0;
    for(i=3;i<e;i+=2)
        if(is[i])
        {
             prm[k++]=i;
            for(s=i*2,j=i*i;j<n;j+=s)
                 is[j]=0;
        }
    for(; i<n; i+=2)
        if(is[i])
             prm[k++]=i;
    return k;
}

int div(int *arr,int n)//幂整数拆分(n!)
{
    int i,tmp;

    for(i=0;i<np;i++)
         arr[i]=0;
    for(i=0; i<np && n>=prm[i]; i++)
    {
         tmp=n;
        while(tmp)
        {
             arr[i]+=tmp/prm[i];
             tmp/=prm[i];
        }
    }
    return i;
}
long long C(int a,int b)
{
    int len,i,r;
     len=div(p1,a);
     div(p2,a-b);
     div(p3,b);
    for(i=0;i<len;i++)//分母和分子的指数相减
         p1[i]-=(p2[i]+p3[i]);
    long long res=1;
    for(i=0;i<len;i++){
       res*=(p1[i]+1);
    }
    return res;
}

int main()
{
    int m,n,t;
    long long res;
     np=getprm(1000);
    while(~scanf("%d%d",&n,&m))
    {
        if(m>n/2)m=n-m;
        if(judge[n][m])                 
        printf("%I64d\n",rest[n][m]);
        else{
           rest[n][m]=C(n,m);
           judge[n][m]=true;
           printf("%I64d\n",rest[n][m]);
        }
    }
    return 0;
}
