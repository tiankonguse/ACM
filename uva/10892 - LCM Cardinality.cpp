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
    int i , j;
    unsigned int ans = 1;
    printf("%d " , n);
    for (i = 2 ; i * i <= n ; ++ i)
        if (n % i == 0)
        {
            j = 0;
            while (n % i == 0)
                ++ j , n /= i;
            ans *= j << 1 | 1;
        }
    if (n > 1)
        ans *= 3;
    printf("%u\n" , ans / 2 + 1);
}

int main()
{
    while (scanf("%d",&n) , n)
        work();
    return 0;
}
