#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
#include <sstream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <ctime>

#define inf 0x3f3f3f3f
#define Inf 0x3FFFFFFFFFFFFFFFLL
using namespace std;
typedef long long ll;
int a[11];
int dp[2525][2];
int m;
int dfs(int n, int p) {
	if (~dp[n][p]) return dp[n][p];
	if (n == 0) return dp[n][p] = 1;
	int ret = 0;
	for (int i = 0; i < m && a[i] <= n; ++i) {
		ret |= !dfs(n - a[i], p ^ 1);
	}
	return dp[n][p] = ret;
}
int main() {
	int T;
	int n;
	for (scanf("%d", &T); T--; ) {
		scanf("%d%d", &n, &m);
		for (int i = 0; i < m; ++i) scanf("%d", &a[i]);
		a[m++] = 1;
		sort(a, a + m);
		memset(dp, 0xff, sizeof dp);
		for (int i = 1; i <= 1000; ++i) dfs(i, 0);
		int cir = -1;
		for (int len = 1; len <= 20; ++len) {
			bool flag = true;
			for (int j = 0; j < 30; ++j) {
				int beg = j * len;
				for (int k = 0; k < len; ++k) {
					if (dp[beg + k][0] != dp[beg + k + len][0]) {
						flag = false;
						break;
					}
				}
				if (!flag) break;
			}
			if (flag) {
				cir = len;
				break;
			}
		}
		int ret = dp[(n - 1) % cir + 1][0];
		if (!ret) puts("SECOND PLAYER MUST WIN");
		else puts("FIRST PLAYER MUST WIN");
	}	
	return 0;
}

