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
typedef long long ll;
int a[maxn];
int dp[maxn][maxn];
int dfs(int l, int r) {
  if (dp[l][r] != inf) return dp[l][r];
	if (l > r) return dp[l][r] = 0;
	else if (l == r) return dp[l][r] = a[l];
	else {
		int ret = -inf;
		if (a[l + 1] >= a[r]) {
			ret = max(ret, a[l] - a[l + 1] + dfs(l + 2, r));
		}
		else {
			ret = max(ret, a[l] - a[r] + dfs(l + 1, r - 1));
		}
		if (a[l] >= a[r - 1]) {
			ret = max(ret, a[r] - a[l] + dfs(l + 1, r - 1));
		}
		else {
			ret = max(ret, a[r] - a[r - 1] + dfs(l, r - 2));
		}
		return dp[l][r] = ret;
	}
}
int main() {
	int n, ca = 1;
	while (~scanf("%d", &n) && n) {
		for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
		memset(dp, 0x3f, sizeof dp);
		printf("In game %d, the greedy strategy might lose by as many as %d points.\n", ca++, 
				dfs(0, n - 1));
	}
    return 0;
}
