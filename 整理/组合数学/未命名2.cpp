#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

typedef long long llg;

const int N =150000;

llg n, m, p, fac[N];

void init()
{
    int i;
    fac[0] =1;
    for(i =1; i <= p; i++)
        fac[i] = fac[i-1]*i % p;
}

llg pow(llg a, llg b)
{
    llg tmp = a % p, ans =1;
    while(b)
    {
        if(b &1)  ans = ans * tmp % p;
        tmp = tmp*tmp % p;
        b >>=1;
    }
    return  ans;
}

llg C(llg n, llg m)
{
    if(m > n)  return 0;
    return  fac[n]*pow(fac[m]*fac[n-m], p-2) % p;
}

llg Lucas(llg n, llg m)
{
    if(m ==0)  return 1;
    else return  (C(n%p, m%p)*Lucas(n/p, m/p))%p;
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%I64d%I64d%I64d", &n, &m, &p);
        init();
        printf("%I64d\n", Lucas(n+m+1, m)+n-m);
    }
    return 0;
}
