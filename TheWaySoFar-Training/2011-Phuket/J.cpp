#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>
#include <vector>
#include <stack>
#include <cmath>
using namespace std;
typedef long long LL;
#define N 10000005
int n;
LL q;
bool f[N];
int p[N / 10] , t;

void work(LL n)
{
    LL p , q = n , a;
    LL ans = 0;
    for (p = q + 1 ; p <= 100000000 ; ++ p) {
        LL x = p * p + q * q;
        LL y = p - q;
        if (x % y == 0) {
            printf("%lld %d\n" , x / y , p);
            ++ ans;
        }
    }
    printf("%lld : %lld\n" ,n ,  ans);
}

void work()
{
    LL ans = 2;
    while (q % 2 == 0) q /= 2;
    for (int i = 0 ; i < t && (LL)p[i] * p[i] <= q ; ++ i) {
        if (q % p[i] == 0) {
            int x = 1;
            while (q % p[i] == 0) {
                q /= p[i];
                x += 2;
            }
            ans *= x;
        }
    }
    if (q > 1) {
        ans *= 3;
    }
    printf("%lld\n" , ans);
}

int main()
{
    //freopen("1.txt" , "w" , stdout);
    int i , j , n = 1e7;
    for (i = 2 ; i * i <= n ; ++ i) if (!f[i])
        for (j = i * i ; j <= n ; j += i) f[j] = 1;
    for (i = 2 ; i <= n ; ++ i) if (!f[i]) p[t ++] = i;
    //cout << t << endl;
    while (scanf("%lld",&q) , q)
        work();
    return 0;
}
