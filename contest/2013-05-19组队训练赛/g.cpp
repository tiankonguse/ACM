
#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
#include<time.h>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
typedef    unsigned long long LL;
const int S = 20;
LL muti_mod(LL a,LL b,LL c)
{
    a%=c;
    b%=c;
    LL ret = 0;
    while(b)
    {
        if(b&1)
        {
            ret +=a;
            if(ret>=c)ret-=c;
        }
        a<<=1;
        if(a>=c)a-=c;
        b>>=1;
    }
    return ret;
}
LL pow_mod(LL x,LL n,LL mod)
{
    if(n==1)return x%mod;
    int bit[64],k=0;
    while(n)
    {
        bit[k++]=n&1;
        n>>=1;
    }
    LL ret=1;
    for(k=k-1; k>=0; k--)
    {
        ret = muti_mod(ret,ret,mod);
        if(bit[k]==1)ret=muti_mod(ret,x,mod);
    }
    return ret;
}
bool check(LL a,LL n,LL x,LL t)
{
    LL ret = pow_mod(a,x,n),last=ret;
    for(int i=1; i<=t; i++)
    {
        ret = muti_mod(ret,ret,n);
        if(ret==1&&last!=1&&last!=n-1)return 1;
        last = ret;
    }
    if(ret!=1)return 1;
    return 0;
}
bool Miller_Rabin(LL n)
{
    LL x=n-1,t=0;
    while((x&1)==0)x>>=1,t++;
    bool flag=1;
    if(t>=1&&(x&1))
    {
        for(int k=0; k<S; k++)
        {
            LL a = rand()%(n-1)+1;
            if(check(a,n,x,t))
            {
                flag=1;
                break;
            }
            flag=0;
        }
    }
    if(!flag||n==2)return 0;
    return 1;
}
LL gcd(LL x,LL y)
{
    if(!x||!y)return x?x:y;
    for(LL t; t=x%y; x=y,y=t);
    return y;
}
vector<LL>factor[65];
LL Pollard_rho(LL x,LL c)
{
    LL i = 1,x0 = rand()%x,y=x0,k=2;
    while(1)
    {
        i++;
        x0=(muti_mod(x0,x0,x)+c)%x;
        LL d = gcd(y-x0,x);
        if(d!=1&&d!=x)return d;
        if(y==x0)return x;
        if(i==k)y=x0,k+=k;
    }
}
void findfac(int __i,LL n)
{
//    printf("   1-%d-%I64d\n",__i,n);

    if(!Miller_Rabin(n))
    {
//        printf("-%d-%lld\n",__i,n);
        factor[__i].push_back(n);
        return;
    }
//    printf("   2-%d-%I64d\n",__i,n);
    LL p =n;
    while(p>=n)p=Pollard_rho(p, rand()%(n-1)+1);
//    printf("  p=%I64d\n",p);
    findfac(__i,p);
    findfac(__i,n/p);
}


char ans[64][2][10000];

int main()
{
    srand(( int)(time(0)));
    int i;
    LL n;
    n = 1;
//    findfac(1,63);
//    cout<<factor[1].size()<<endl;
//    for(i=0;i<factor[1].size();i++)
//        cout<<i<< " "<<factor[1][i]<<endl;

    LL tmp;
    LL _str[65];
    int j;
    for(i=2; i<=64; i++)
    {
        factor[i].clear();

        n <<=1;
        n |= 1;
        _str[i] = n;
        findfac(i,n);
//            ___n = Miller_Rabin(n);
//            printf("%02d %llu  %d\n",i, n,factor[i].size());
        sort(factor[i].begin(),factor[i].end());

//            puts("");
//            printf("%d--%lld %d\n",i,n,factor[i].size());
//            printf("%ulld n=%ulld---%d\n",i,n,Miller_Rabin(n));
    }

    for(i=2;i<=64;j++)
    {
        if(factor[j].size() == 1)
        {
            printf("%llu is Mersenne prime.\n",_str[j]);
        }
        else
        {
            printf("%llu is NOT Mersenne prime.\n",_str[j]);
            tmp = -1;
            for(i=0; i<factor[j].size(); i++)
            {

                if(tmp != factor[j][i])
                {
                    if(i)putchar(' ');
                    printf("%llu",factor[j][i]);
                }

                tmp = factor[j][i];
            }
            puts("");
        }

    }


}
