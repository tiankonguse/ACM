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
#include <cassert>
using namespace std;
typedef long long LL;
#define N 605
int n , m , K;
LL f[2][1 << 15];
int cnt[1 << 15];
void work()
{
    int i , j , mask;
    cin >> n >> m >> K;
    for (i = 1 ; i < 1 << m ; ++ i)
        cnt[i] = cnt[i & (i - 1)] + 1;
    mask = (1 << m) - 1;
    int cur = 0 , nxt = 1;
    f[cur][0] = 1;
    for (i = 1 ; i <= n ; ++ i) {
        memset(f[nxt] , 0 , sizeof(f[nxt]));
        for (j = 0 ; j < 1 << m ; ++ j) {
            if (!f[cur][j]) continue;
            if (i < m) {
                f[nxt][(j << 1) & mask] += f[cur][j];
                f[nxt][(j << 1 | 1) & mask] += f[cur][j];
            } else {
                if (cnt[(j << 1) & mask] == K - 1)
                    f[nxt][(j << 1 | 1) & mask] += f[cur][j];
                else if (cnt[(j << 1) & mask] >= K) {
                    f[nxt][(j << 1) & mask] += f[cur][j];
                    f[nxt][(j << 1 | 1) & mask] += f[cur][j];
                }
            }
        }
        swap(nxt , cur);
    }
    LL ans = 0;
    for (i = 0 ; i < 1 << m ; ++ i)
        if (cnt[i] >= K)
            ans += f[cur][i];
    cout << ans << endl;
}

int main()
{
    freopen("1.txt" , "r" , stdin);
    work();
    return 0;
}

