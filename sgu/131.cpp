#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
using namespace std;
typedef long long LL;

int n , m , mask;
LL f[2][1 << 10];

void work()
{
    int i , j , k , l;
    scanf("%d%d",&n,&m);
    if (n < m) swap(n , m);
    if (m == 1) {
        if (n & 1)
            puts("0");
        else
            puts("1");
        return;
    }
    int cur = 0 , nxt = 1;
    memset(f[cur] , 0 , sizeof(f[cur]));
    mask = (1 << m + 1) - 1;
    f[cur][mask] = 1;
    for (i = 0 ; i < n ; ++ i) {
        for (j = 0 ; j < m ; ++ j) {
            memset(f[nxt] , 0 , sizeof(f[nxt]));
            for (k = 0 ; k < 1 << m + 1 ; ++ k)
                if (f[cur][k]) {
                    LL x = f[cur][k];
                    if (~k >> m & 1) {
                        if (!j) continue;
                        if (~k >> m - 1 & 1)
                            f[nxt][((k << 1) & mask) + 1 + (1 << m)] += x;
                        if (~k & 1)
                            f[nxt][((k << 1) & mask) + 3] += x;
                        continue;
                    }
                    f[nxt][(k << 1) & mask] += x;
                    if (~k >> m - 1 & 1)
                        f[nxt][((k << 1) & mask) + 1 + (1 << m)] += x;
                    if (j && (~k & 1))
                        f[nxt][((k << 1) & mask) + 3] += x;
                    if (j && (~k & 1) && (~k >> m - 1 & 1))
                        f[nxt][((k << 1) & mask) + 3 + (1 << m)] += x;
                    if (j + 1 < m && (~k >> m - 1 & 1) && (~k >> m - 2 & 1))
                        f[nxt][((k << 1) & mask) + 1 + (1 << m) + ((1 << m - 1))] += x;
                }
            swap(cur , nxt);
        }
    }
    printf("%lld\n" , f[cur][mask]);
}

int main()
{
    //freopen("1.txt" , "r" , stdin);
    //int _; scanf("%d",&_); while (_ --)
        work();
    return 0;
}

