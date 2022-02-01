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
typedef __int64 ll;
int const maxn = 105;
ll c[maxn][maxn];
ll dp[maxn][maxn];
int ans[maxn], ant;
int main() {
  int T, m, n;
	ll sal, a, b;
    for (scanf("%d", &T); T--; ) {
		scanf("%d%d%I64d", &m, &n, &sal);
		for (int i = 1; i <= m; ++i) {
			for (int j = 1; j <= n; ++j) {
				scanf("%I64d", &c[i][j]);
			}
			scanf("%I64d %I64d", &a, &b);
			c[i][0] = -100LL * b;
			for (int j = 1; j <= n; ++j) {
				c[i][j] = c[i][j] * (a - j * sal) - (100LL - c[i][j]) * b; 
			}
		}
		for (int i = 0; i <= m; ++i) 
			for (int j = 0; j <= n; ++j)
				dp[i][j] = -Inf;
		dp[0][0] = 0;
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j <= n; ++j) {
				if (dp[i][j] != -Inf) {
					for (int k = 0; j + k <= n; ++k) {
						dp[i + 1][j + k] = max(dp[i + 1][j + k], dp[i][j] + c[i + 1][k]);
					}
				}		
			}
		}
		ll ret = -Inf;
		for (int i = 0; i <= n; ++i) ret = max(ret, dp[m][i]);
		printf("%I64d\n", ret);
		ant = 0;
		for (int i = 0; i <= n; ++i) {
			if (dp[m][i] == ret) ans[ant++] = i;
		}
		for (int i = 0; i < ant; ++i) {
			if (i == ant - 1) printf("%d\n", ans[i]);
			else printf("%d ", ans[i]);
		}
	}
	return 0;
}
