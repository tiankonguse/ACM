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
int const maxn = 22;
int a[maxn], b[maxn], sa[maxn], sb[maxn];
int dp[maxn][maxn][maxn][maxn];
inline int s1(int l, int r) { return sa[r] - sa[l - 1]; }
inline int s2(int l, int r) { return sb[r] - sb[l - 1]; }
int dfs(int l1, int r1, int l2, int r2) {
  if (~dp[l1][r1][l2][r2]) return dp[l1][r1][l2][r2];
	if (l1 > r1 && l2 > r2) return dp[l1][r1][l2][r2] = 0;
	int ret = 0, ss = s1(l1, r1) + s2(l2, r2);
	if (l1 <= r1) {
		ret = max(ret, ss - dfs(l1 + 1, r1, l2, r2));
		ret = max(ret, ss - dfs(l1, r1 - 1, l2, r2));
	}
	if (l2 <= r2) {
		ret = max(ret, ss - dfs(l1, r1, l2 + 1, r2));
		ret = max(ret, ss - dfs(l1, r1, l2, r2 - 1));
	}
	return dp[l1][r1][l2][r2] = ret;
}
int main() {
	int T, n;
	for (scanf("%d", &T); T--; ) {
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &a[i]);
			sa[i] = sa[i - 1] + a[i];
		}
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &b[i]);
			sb[i] = sb[i - 1] + b[i];
		}
		memset(dp, 0xff, sizeof dp);
		printf("%d\n", dfs(1, n, 1, n));
	}
	return 0;
}

