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
int const N = 11;
int const M = 1111;
int n, m;
int dp[504][14641];
int a[N], b[N];
vector<pair<int, int> > v[14641];
int x[N];
int ans;

void dfs(int dep, int s) {
	if (s >= m) {
		ans = min(ans, dep);
		return;
	}
	rep(i, n + 1) {
		bool ok = 1;
		rep(j, dep) {
			if (x[j] == i && j + b[i] >= dep) {
				ok = 0;
				break;
			}
		}
		if (ok) {
			x[dep] = i;
			if (dep == 4) {
				int s1 = 0, s2 = 0;
				rep(j, dep) s1 = s1 * (n + 1) + x[j];
				Rep(j, dep) s2 = s2 * (n + 1) + x[j];
				dp[0][s1] = s;
				v[s1].push_back(make_pair(s2, a[i]));
			} else {
				dfs(dep + 1, s + a[i]);
			}
		}
	}
}

int main() {
	scanf("%d%d", &m, &n);
	Rep(i, n) scanf("%d%d", &a[i], &b[i]);
	ans = inf;
	dfs(0, 0);
	if (ans != inf) printf("%d\n", ans);
	else {
		int t = 1;
		rep(i, 4) t *= (n + 1);
		rep(i, inf) rep(j, t) if (dp[i][j] > 0) {
			int sz = v[j].size();
			rep(k, sz) {
				int nState = v[j][k].first;
				int nCost = v[j][k].second;
				dp[i + 1][nState] = max(dp[i + 1][nState], dp[i][j] + nCost);
				if (dp[i + 1][nState] >= m) {
					printf("%d\n", i + 5);
					return 0;
				}
			}
		}
	}
	return 0;
}

