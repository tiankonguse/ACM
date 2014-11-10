#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
using namespace std;
typedef long long LL;
#define N 10005
bool f[N];
int fac[N];
int prime[N] , tot;
int n , m , ca;

void work()
{
    int i , j , x , y , ans = 1 << 30;
    scanf("%d%d",&n,&m);
    printf("Case %d:\n" , ++ ca);
    for (i = 0 ; i < tot ; ++ i)
    {
        x = 0 , j = prime[i];
        while (j <= m)
            x += m / j , j *= prime[i];
        y = 0 , j = n;
        while (j % prime[i] == 0)
            ++ y , j /= prime[i];
        if (y)
            ans = min(ans , x / y);
    }
    if (ans == 1 << 30 || ans == 0)
        puts("Impossible to divide");
    else
        printf("%d\n" , ans);
}

void init()
{
    n = 10000;
    int i , j , x;
    for (i = 2 ; i <= n ; ++ i)
    {
        if (!f[i]) prime[tot ++] = i , fac[i] = i;
        for (j = 0 ; j < tot ; ++ j)
        {
            x = i * prime[j];
            if (x > n) break;
            f[x] = 1 , fac[x] = prime[j];
            if (i % prime[j] == 0) break;
        }
    }
}

int main()
{
    init();
    int _; scanf("%d",&_); while (_ --)
        work();
    return 0;
}
