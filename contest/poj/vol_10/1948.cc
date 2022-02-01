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
#define maxn 41
#define maxm 808
using namespace std;
bool dp[maxm][maxm];
int a[maxn];

int main() {
    int n;
    while (~scanf("%d", &n)) {
        int s = 0;
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &a[i]);
            s += a[i];
        }
        int mx = s >> 1;
        memset(dp, 0, sizeof dp);
        dp[0][0] = true;
        for (int i = 1; i <= n; ++i) {
            for (int j = mx; j >= 0; --j) {
                for (int k = mx; k >= 0; --k) {
                    if ((j >= a[i] && dp[j - a[i]][k]) || (k >= a[i] && dp[j][k - a[i]])) {
                        dp[j][k] = true;
                    }
                }
            }
        }
        int c;
        double r, p, q; int ret = -1;
        for (int i = 1; i <= mx; ++i) {
            for (int j = 1; j <= mx; ++j) {
                if (dp[i][j]) {
                    c = s - i - j;
                    p = 0.5 * s;
                    q = p * (p - i) * (p - j) * (p - c);
                    if (q > 0) {
                        ret = max(ret, (int) (sqrt(q) * 100.0));
                    }
                }
            }
        }
        printf("%d\n", ret);
    }
    return 0;
}
