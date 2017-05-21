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
int const N = 200;
int a[N][N], s[N][N];
int l[N][N], r[N][N], mi[N][N];
int lt[N][N], rt[N][N];
int main() {
	int n, m; scanf("%d%d", &n, &m);
	Rep(i, n) Rep(j, m) scanf("%d", &a[i][j]);
	for (int j = m; j >= 1; --j) {
		Rep(i, n) {
			if (a[i][j] == 1) s[i][j] = 0;
			else s[i][j] = s[i][j + 1] + 1;
		}
	}
	int ans = 0, ak, al, ar, at, alt, art;
	Rep(k, m) {
		Rep(i, n) Rep(j, n) l[i][j] = r[i][j] = 0;
		Rep(i, n) {
			int t = inf;
			for (int j = i; j >= 1; --j) {
				t = min(t, s[j][k]);
				l[i][t] = t * (i - j + 1);
			}
			t = inf;
			for (int j = i; j <= n; ++j) {
				t = min(t, s[j][k]);
				r[i][t] = t * (j - i + 1);
			}
			int now = s[i][k];
			for (int j = s[i][k]; j >= 1; --j) {
				lt[i][j] = now;
				if (l[i][j] >= l[i][j - 1]) {
					l[i][j - 1] = l[i][j];
				} else {
					now = j - 1;
				}
			}
			now = s[i][k];
			for (int j = s[i][k]; j >= 1; --j) {
				rt[i][j] = now;
				if (r[i][j] >= r[i][j - 1]) {
					r[i][j - 1] = r[i][j];
				} else {
					now = j - 1;
				}
			}
		}
		Rep(i, n) {
			int t = inf;
			for (int j = i; j <= n; ++j) {
				t = min(t, s[j][k]);
				mi[i][j] = t;
			}
		}
		for (int i = 2; i <= n - 1; ++i) for (int j = i; j <= n - 1; ++j) {
			if (i == j) {
				for (int t = s[i][k]; t >= 1; --t) {
					if (l[i - 1][t + 1] == 0 || r[i + 1][t + 1] == 0) continue;
					int ret = t + l[i - 1][t + 1] + r[i + 1][t + 1];
					if (ret > ans) {
						ans = ret, ak = k, al = i, ar = j, at = t, alt = lt[i - 1][t + 1], art = rt[j + 1][t + 1];
					}
				}
			} else {
				int t = mi[i][j];
				if (t == 0 || l[i - 1][t + 1] == 0 || r[j + 1][t + 1] == 0) continue;
				int ret = t * (j - i + 1) + l[i - 1][t + 1] + r[j + 1][t + 1];
				if (ret > ans) {
					ans = ret, ak = k, al = i, ar = j, at = t, alt = lt[i - 1][t + 1], art = rt[j + 1][t + 1];
				}
			}
		}
	}
	
	if (ans == 0) {
		puts("-1");
		return 0;
	}
	for (int i = al; i <= ar; ++i) {
		rep(j, at) a[i][j + ak] = 8;
	}
	for (int i = al - 1; i >= 1; --i) {
		bool z = 1;
		rep(j, alt) if (a[i][j + ak] != 0) z = 0;
		if (!z) break;
		rep(j, alt) a[i][j + ak] = 8;
	}
	for (int i = ar + 1; i <= n; ++i) {
		bool z = 1;
		rep(j, art) if (a[i][j + ak] != 0) z = 0;
		if (!z) break;
		rep(j, art) a[i][j + ak] = 8;
	}
	
	printf("%d\n", ans);
	Rep(i, n) {
		Rep(j, m) {
			if (j == m) printf("%d\n", a[i][j]);
			else printf("%d ", a[i][j]);
		}
	}
	
	return 0;
}

