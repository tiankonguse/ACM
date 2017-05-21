#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>

#define inf 0x3f3f3f3f
#define Inf 0x3FFFFFFFFFFFFFFFLL
#define maxn 16
#define maxm 1010
using namespace std;
int n, m;
int mp[maxn][maxn];
void floyd() {
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            if (k == i) continue;
            for (int j = 0; j < n; ++j) {
                if (mp[i][k] + mp[k][j] < mp[i][j]) {
                    mp[i][j] = mp[i][k] + mp[k][j];
                }
            }
        }
    }
}

int deg[maxn];
int ori[maxn], _mp[maxn][maxn];
int dp[1 << maxn];

int main() {
    int ret;
    int a, b, c;
    int cnt;
    while (scanf("%d", &n) && n) {
        scanf("%d", &m);
        ret = 0;
        memset(mp, 0x3f, sizeof mp);
        for (int i = 0; i < n; ++i) mp[i][i] = 0;
        memset(deg, 0, sizeof deg);

        for (int i = 0; i < m; ++i) {
            scanf("%d%d%d", &a, &b, &c);
            deg[--a] ^= 1, deg[--b] ^= 1;
            mp[a][b] = mp[b][a] = min(mp[a][b], c);
            ret += c;
        }
        floyd();
        cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (deg[i]) ori[cnt++] = i;
        }
        for (int i = 0; i < cnt; ++i) {
            for (int j = 0; j < cnt; ++j) {
                _mp[i][j] = mp[ ori[i] ][ ori[j] ];
            }
        }
        memset(dp, 0x3f, sizeof dp);
        dp[0] = 0;
        int mx = 1 << cnt;
        int next;
        for (int i = 0; i < cnt; ++i) {
            for (int j = 0; j < mx; ++j) {
                if (dp[j] == inf || ((1 << i) & j)) continue;
                for (int k = 0; k < cnt; k++) {
                    if (i == k || ((1 << k) & j)) continue;
                    next = j | (1 << i) | (1 << k);
//                    printf("dp[%d] = min(%d, %d)\n", next, dp[next], dp[j] + _mp[i][k]);
                    dp[next] = min(dp[next], dp[j] + _mp[i][k]);
                }
            }
        }
        ret += dp[mx - 1];
        printf("%d\n", ret);
    }
    return 0;
}
