#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <queue>
#include <stack>
#include <set>
#include <map>
typedef long long LL;
typedef unsigned long long ULL;
using namespace std;
#define N 1000005
int n , a[N] , f[N] , g[N];

void work()
{
    int i;
    scanf("%d",&n);
    for (i = 1 ; i <= n ; ++ i)
        scanf("%d",&a[i]);
    a[0] = a[n + 1] = 1 << 30;
    f[0] = f[n + 1] = g[0] = g[n + 1] = 0;
    for (i = 1 ; i <= n ; ++ i) {
        if (a[i] > a[i - 1])
            f[i] = f[i - 1] + 1;
        else
            f[i] = 0;
    }
    for (i = n ; i > 0 ; -- i) {
        if (a[i] > a[i + 1])
            g[i] = g[i + 1] + 1;
        else
            g[i] = 0;
    }
    int ans = 0;
    for (i = 1 ; i <= n ; ++ i)
        ans = max(ans , min(f[i] , g[i]));
    printf("%d " , ans);
    a[0] = a[n + 1] = -1 << 30;
    f[0] = f[n + 1] = g[0] = g[n + 1] = 0;
    for (i = 1 ; i <= n ; ++ i) {
        if (a[i] < a[i - 1])
            f[i] = f[i - 1] + 1;
        else
            f[i] = 0;
    }
    for (i = n ; i > 0 ; -- i) {
        if (a[i] < a[i + 1])
            g[i] = g[i + 1] + 1;
        else
            g[i] = 0;
    }
    ans = 0;
    for (i = 1 ; i <= n ; ++ i)
        ans = max(ans , min(f[i] , g[i]));
    printf("%d\n" , ans);


}

int main()
{
    int _; scanf("%d",&_); while (_ --)
        work();
    return 0;
}
