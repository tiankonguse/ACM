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
#include <ctime>

#define inf 0x3f3f3f3f
#define Inf 0x3FFFFFFFFFFFFFFFLL
#define maxn 11
#define maxm 111
using namespace std;
char mp[maxn][maxn][maxn];
int msk[maxm];
int ids[maxn][maxn];
int inv[maxm][2];
bool mark[65536];
int dp[65536];
int pre[65536][2];
bool res[maxn][maxn];

int main() {
    int n, m, k;
    while (~scanf("%d%d%d", &n, &m, &k)) {
        int idx = 0;
        for (int i = 0; i < k; ++i) {
            for (int j = i + 1; j < k; ++j) {
                ids[i][j] = idx;
                inv[idx][0] = i;
                inv[idx][1] = j;
                ++idx;
            }
        }

        for (int _t = 0; _t < k; ++_t) {
            for (int i = 0; i < n; ++i) {
                scanf(" %s", mp[_t][i]);
            }
        }
        int cnt = 0;
        memset(msk, 0, sizeof msk);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                for (int it = 0; it < k; ++it) {
                    for (int jt = it + 1; jt < k; ++jt) {
                        if (mp[it][i][j] != mp[jt][i][j]) {
                            msk[cnt] |= (1 << ids[it][jt]);
                        }
                    }
                }
                ++cnt;
            }
        }
        int mx = 1 << (k * (k - 1) / 2);
        memset(dp, 0x3f, sizeof dp);
        memset(mark, 0, sizeof mark);
        dp[0] = 0;
        mark[0] = true;
        pre[0][0] = -1;

        for (int i = 0; i < mx; ++i) {
            if (dp[i] != inf) {
                for (int j = 0; j < cnt; ++j) {
                    if (i | msk[j] > i) {
                       if (dp[i] + 1 < dp[i | msk[j]]) {
                            dp[i | msk[j]] = dp[i] + 1;
                            pre[i | msk[j]][0] = i;
                            pre[i | msk[j]][1] = j;
                       }
                    }
                }
            }
        }
        printf("%d\n", dp[mx - 1]);
        memset(res, 0, sizeof res);
        int p = mx - 1;
        while (p != 0) {
            int x = pre[p][1] / m;
            int y = pre[p][1] % m;
            p = pre[p][0];
            res[x][y] = true;
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (res[i][j]) putchar('1');
                else putchar('0');
            }
            puts("");
        }
    }
    return 0;
}
