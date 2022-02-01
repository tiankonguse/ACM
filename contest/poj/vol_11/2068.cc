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
int const maxn = 22, maxs = 9000;
int n, S, a[maxn];
int dp[maxn][maxs];
int dfs(int p, int s) {
  if (dp[p][s] != -1) return dp[p][s];
	if (s == 0) return dp[p][s] = 1;
	int ret = 0;
	for (int i = 1; i <= a[p] && i <= s; ++i) {
		ret |= !dfs((p + 1) % n, s - i);
		if (ret) break;
	}
	return dp[p][s] = ret;
}
int main() {
	while (scanf("%d", &n) && n) {
		scanf("%d", &S);
		n += n;
		for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
		memset(dp, 0xff, sizeof dp);
		printf("%d\n", dfs(0, S));
	}
    return 0;
}
