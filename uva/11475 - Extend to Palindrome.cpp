#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define N 100005
int n , m , ca;
ULL power[N] , MAGIC = 10007;
char str[N];
ULL pre[N] , suf[N];

void work()
{
    int i;
    n = strlen(str + 1);
    for (i = 1 ; i <= n ; ++ i)
        pre[i] = pre[i - 1] + power[i - 1] * str[n - i + 1];
    for (i = 1 ; i <= n ; ++ i)
        suf[i] = suf[i - 1] * MAGIC + str[n - i + 1];
    for (i = n ; i >= 0 ; -- i)
        if (pre[i] == suf[i])
        {
            m = i;
            for (i = 1 ; i <= n - m ; ++ i)
                putchar(str[i]);
            reverse(str + 1 , str + 1 + n);
            puts(str + 1);
            break;
        }

}
int main()
{
    freopen("~input.txt" , "r" , stdin);

    power[0] = 1;
    for (int i = 1 ; i <= 100000 ; ++ i)
        power[i] = power[i - 1] * MAGIC;
    //int _; scanf("%d",&_); while (_ --)
    while (~scanf("%s", str + 1))
        work();
    return 0;
}
