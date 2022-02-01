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
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define Rep(i, n) for (int i = 1; i <= (n); ++i)
#define clr(x, a) memset(x, (a), sizeof x)
using namespace std;
typedef long long ll;
int const N = 61, M = 1 << 15;
ll dp[N][M];
int main() {
	int n, m, k, s, msk, t;
	scanf("%d%d%d", &n, &m, &k); s = 1 << m, msk = s - 1;
	dp[0][0] = 1LL;
	rep(i, n) rep(j, s) if (dp[i][j]) {
		t = j << 1 & msk;
		if (i + 1 < m || __builtin_popcount(t) >= k) {
			dp[i + 1][t] += dp[i][j];
		}
		t |= 1;
		if (i + 1 < m || __builtin_popcount(t) >= k) {
			dp[i + 1][t] += dp[i][j];
		}
	}

	ll ret = 0;
	rep(i, s) ret += dp[n][i];
	printf("%I64d\n", ret);
	return 0;
}

