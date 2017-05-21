#include <stdio.h>
#include <string.h>
#include <math.h>

const int N=1000001;
const __int64 M=150000;

__int64 prm[M],np,p1[M],p2[M],p3[M];//c=20100501;
bool is[N*2];

__int64 getprm(__int64 n)//素数打标
{
    __int64 i,j,k=0;
    __int64 s,e=(__int64)(sqrt(0.0+n)+1);
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

__int64 div(__int64 *arr,__int64 n)//幂整数拆分(n!)
{
    __int64 i,tmp;

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

__int64 b_pow(__int64 *arr,__int64 n)//快速幂模
{
    __int64 i;
    long long res=1,a,b,d;
    for(i=0;i<n;i++)
    {
        if(arr[i])
        {
             a=prm[i];
             b=arr[i];
             d=1;
            while(b)
            {
                if(b%2) d=(a*d);
                 a=(a*a);
                 b>>=1;
            }
             res=(res*d);
        }
    }
    return (__int64)res;
}

__int64 C(__int64 a,__int64 b)
{
    __int64 len,i,r;
     len=div(p1,a);
     div(p2,a-b);
     div(p3,b);
    for(i=0;i<len;i++)//分母和分子的指数相减
         p1[i]-=(p2[i]+p3[i]);
    return b_pow(p1,len);
}

int main()
{
    __int64 m,n,res;
     np=getprm(2000002);
    while(scanf("%I64d%I64d",&n,&m))
    {
        if(n==0 && m==0)break;
        res=C(n,m);
        printf("%I64d\n",res);
    }
    return 0;
}

