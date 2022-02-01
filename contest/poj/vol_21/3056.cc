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

using namespace std;
int const maxn = 1010;
int T, n;
int p[maxn];
int dp[maxn][maxn];

int main() {
    for (scanf("%d", &T); T--; ) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) scanf("%d", &p[i]);
        memset(dp, 0, sizeof dp);
        int ret = 0;
        for (int len = 1; len < n; len += 2) {
            for (int i = 0; i + len < n; ++i) {
                int j = i + len;
                dp[i][j] = dp[i + 1][j - 1] + (p[i] == p[j]);
                for (int k = i + 1; k < j; k += 2) {
                    dp[i][j] = max(dp[i][j], dp[i][k] + dp[k + 1][j]);
                }
            }
        }
        printf("%d\n", dp[0][n - 1]);
    }
    return 0;
}
