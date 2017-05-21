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
#define maxn 505
using namespace std;
int a[maxn], b[maxn];
int dp[maxn][maxn];
int path[maxn][maxn];
int res[maxn];

int main() {
    int n, m;
    while (~scanf("%d", &n)) {
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &a[i]);
        }
        scanf("%d", &m);
        for (int i = 1; i <= m; ++i) {
            scanf("%d", &b[i]);
        }
        memset(dp, 0, sizeof dp);
        int mx, pre, last;
        int ret = 0;
        for (int i = 1; i <= n; ++i) {
            mx = pre = 0;
            for (int j = 1; j <= m; ++j) {
                dp[i][j] = dp[i - 1][j];
                if (b[j] < a[i]) {
                    if (dp[i - 1][j] > mx) {
                        mx = dp[i - 1][j];
                        pre = j;
                    }
                }
                else if (b[j] == a[i]) {
                    if (mx + 1 > dp[i][j]) {
                        dp[i][j] = mx + 1;
                        path[mx + 1][j] = pre;
                    }
                }
                if (dp[i][j] > ret) {
                    ret = dp[i][j];
                    last = j;
                }
            }
        }
        printf("%d\n", ret);
        if (ret == 0) { puts(""); continue;}
        for (int i = 0; i < ret; ++i) {
            res[i] = b[last];
            last = path[ret - i][last];
        }
        for (int i = ret - 1; i >= 0; --i) {
            if (i == 0) printf("%d\n", res[i]);
            else printf("%d ", res[i]);
        }
    }
    return 0;
}
