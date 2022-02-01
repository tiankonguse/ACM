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
#define maxn 22
using namespace std;
int dp[maxn][maxn][maxn];

int dfs(int w, int h, int m) {
//    if (w == 1 && h == 1) return 1;
    if (dp[w][h][m] != -1) return dp[w][h][m];
    if (m == 1) return dp[w][h][m] = w * h;

    int ret = inf;
    for (int i = 1; i <= (w >> 1); ++i) {
        for (int j = 1; j < m; ++j) {
            if (i * h >= j && (w - i) * h >= (m - j)) {
                ret = min(ret, max(dfs(i, h, j), dfs(w - i, h, m - j)));
            }
        }
    }
    for (int i = 1; i <= (h >> 1); ++i) {
        for (int j = 1; j < m; ++j) {
            if (i * w >= j && (h - i) * w >= (m - j)) {
                ret = min(ret, max(dfs(w, i, j), dfs(w, h - i, m - j)));
            }
        }
    }
//    printf("dp[%d][%d][%d] = %d\n", w, h, m, ret);
    return dp[w][h][m] = ret;
}
int main() {
    int w, h, m;
    memset(dp, 0xff, sizeof dp);
    while (~scanf("%d%d%d", &w, &h, &m)) {
        if (w == 0 && h == 0 && m == 0) break;
        printf("%d\n", dfs(w, h, m));
    }
    return 0;
}
