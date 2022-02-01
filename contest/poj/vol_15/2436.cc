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
int const maxm = 1 << 15;
int a[maxn];
bool ok[maxm];
int dp[2][maxm];

int main() {
  int n, d, k;
	while (~scanf("%d%d%d", &n, &d, &k)) {
		for (int i = 1; i <= n; ++i) {
			int m, v;
			for (scanf("%d", &m); m--; ) {
				scanf("%d", &v);
				a[i] |= (1 << (v - 1));
			}
		}
		int mx = 1 << d;
		for (int i = 0; i < mx; ++i) {
			if (__builtin_popcount(i) <= k) ok[i] = true;
		}
		int pre = 0, now = 1;
		memset(dp, 0xff, sizeof dp);
		dp[pre][0] = 0;
		for (int i = 1; i <= n; ++i) {
			memcpy(dp[now], dp[pre], sizeof dp[pre]);
			for (int j = 0; j < mx; ++j) {
				if (ok[j | a[i]] && dp[pre][j] >= 0) {
					dp[now][j | a[i]] = max(dp[now][j | a[i]], dp[pre][j] + 1);
				}
			}
			swap(pre, now);
		}		
		int ret = 0;
		for (int i = 0; i < mx; ++i) ret = max(ret, dp[pre][i]);
		printf("%d\n", ret);
	}
    return 0;
}
