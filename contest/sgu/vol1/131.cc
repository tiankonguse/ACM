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
int const maxn = 11;
int n, m;
ll dp[maxn][1 << 9];

void dfs(int pos, int msk, int now, int row) {
	if (pos == m) {
		dp[row][now] += dp[row - 1][msk];
		return;
	}
	if (msk >> pos & 1) dfs(pos + 1, msk, now, row);
	else {
		dfs(pos + 1, msk, now ^ (1 << pos), row);
		if (pos + 1 < m && !(msk >> (pos + 1) & 1)) {
			dfs(pos + 2, msk, now, row);
			dfs(pos + 2, msk, now ^ (1 << pos), row);
			dfs(pos + 2, msk, now ^ (1 << (pos + 1)), row);
		
			if (pos + 2 < m && !(msk >> (pos + 2) & 1)) {
				dfs(pos + 3, msk, now ^ (1 << pos) ^ (1 << (pos + 1)), row);
				dfs(pos + 3, msk, now ^ (1 << pos) ^ (1 << (pos + 1)) ^ (1 << pos + 2), row);
			}
		}
		if (pos + 1 < m && (msk >> (pos + 1) & 1)) {
			dfs(pos + 2, msk, now ^ (1 << pos) ^ (1 << (pos + 1)), row);
		}
		if (pos > 0 && !(now >> (pos - 1) & 1)) {
			dfs(pos + 1, msk, now ^ (1 << (pos - 1)) ^ (1 << pos), row);
		}
	}
}
int main() {
	scanf("%d%d", &n, &m);
	int mx = 1 << m;
	dp[0][0] = 1;
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < mx; ++j) {
			if (dp[i - 1][j] > 0) dfs(0, j, 0, i);
		}
	}
	printf("%I64d\n", dp[n][0]);
	return 0;
}

