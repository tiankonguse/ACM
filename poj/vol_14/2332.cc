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
#define up _up
#define down _down
#define right _right
#define left _left
using namespace std;
int const N = 52;
int const M = 8;
int n, m;
int uu[N], ud[N], du[N], dd[N], ll[N], lr[N], rl[N], rr[N];
int ul[N], ur[N], dl[N], dr[N], lu[N], ld[N], ru[N], rd[N];
int mp[N][N];
int sum[N][N];
int cal(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
	if (x4 < x3 || y4 < y3) return (x2 - x1 + 1) * (y2 - y1 + 1);
	if (sum[x4][y4] - sum[x3 - 1][y4] - sum[x4][y3 - 1] + sum[x3 - 1][y3 - 1] != 0) return inf;
	int h[4], w[4];
	h[0] = x1, h[1] = x2, h[2] = x3, h[3] = x4;
	w[0] = y1, w[1] = y2, w[2] = y3, w[3] = y4;
	sort(h, h + 4), sort(w, w + 4);
	int s1 = (x2 - x1 + 1) * (y2 - y1 + 1);
	int s2 = (x4 - x3 + 1) * (y4 - y3 + 1);
	int s3 = (h[2] - h[1] + 1) * (w[2] - w[1] + 1);
	if (x2 < x3 || x4 < x1) s3 = 0;
	if (y2 < y3 || y4 < y1) s3 = 0;
	return s1 + s2 - s3;
}
inline int getint() {
	int ret = 0;
	char c;
	while (!isdigit(c = getchar()));
	do ret = (ret << 3) + (ret << 1) + c - '0';
	while (isdigit(c = getchar()));
	return ret;
}

int main() {
	n = getint(), m = getint();
	Rep(i, n) Rep(j, m) mp[i][j] = getint();
	Rep(i, n) Rep(j, m) sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + (mp[i][j] == 1);
	clr(uu, 0), clr(ud, 0x3f), clr(ul, 0x3f), clr(ur, 0);
	for (int i = n; i >= 1; --i) {
		uu[i] = uu[i + 1], ud[i] = ud[i + 1], ul[i] = ul[i + 1], ur[i] = ur[i + 1];
		Rep(j, m) if (mp[i][j] == 2) {
			uu[i] = max(uu[i], i);
			ud[i] = min(ud[i], i);
			ul[i] = min(ul[i], j);
			ur[i] = max(ur[i], j);
		}
	}
	clr(du, 0), clr(dd, 0x3f), clr(dl, 0x3f), clr(dr, 0);
	for (int i = 1; i <= n; ++i) {
		du[i] = du[i - 1], dd[i] = dd[i - 1], dl[i] = dl[i - 1], dr[i] = dr[i - 1];
		Rep(j, m) if (mp[i][j] == 2) {
			du[i] = max(du[i], i);
			dd[i] = min(dd[i], i);
			dl[i] = min(dl[i], j);
			dr[i] = max(dr[i], j);
		}
	}
	clr(ll, 0x3f), clr(lr, 0), clr(lu, 0), clr(ld, 0x3f);
	for (int j = 1; j <= m; ++j) {
		ll[j] = ll[j - 1], lr[j] = lr[j - 1], lu[j] = lu[j - 1], ld[j] = ld[j - 1];
		Rep(i, n) if (mp[i][j] == 2) {
			ll[j] = min(ll[j], j);
			lr[j] = max(lr[j], j);
			lu[j] = max(lu[j], i);
			ld[j] = min(ld[j], i);
		}
	}
	clr(rl, 0x3f), clr(rr, 0), clr(ru, 0), clr(rd, 0x3f);
	for (int j = m; j >= 1; --j) {
		rl[j] = rl[j + 1], rr[j] = rr[j + 1], ru[j] = ru[j + 1], rd[j] = rd[j + 1];
		Rep(i, n) if (mp[i][j] == 2) {
			rl[j] = min(rl[j], j);
			rr[j] = max(rr[j], j);
			ru[j] = max(ru[j], i);
			rd[j] = min(rd[j], i);
		}
	}
	int ret = inf;
	Rep(i, n) Rep(j, m) {
		for (int it = i; it <= n; ++it) for (int jt = j; jt <= m; ++jt) {
			if (sum[it][jt] - sum[i - 1][jt] - sum[it][j - 1] + sum[i - 1][j - 1] == 0) {
				int _u = 0, _d = inf, _r = 0, _l = inf;
				if (j > 1) {
					_u = max(_u, lu[j - 1]);
					_d = min(_d, ld[j - 1]);
					_l = min(_l, ll[j - 1]);
					_r = max(_r, lr[j - 1]);
				}
				if (i > 1) {
					_u = max(_u, du[i - 1]);
					_d = min(_d, dd[i - 1]);
					_l = min(_l, dl[i - 1]);
					_r = max(_r, dr[i - 1]);
				}
				if (it < n) {
					_u = max(_u, uu[it + 1]);
					_d = min(_d, ud[it + 1]);
					_l = min(_l, ul[it + 1]);
					_r = max(_r, ur[it + 1]);
				}
				if (jt < m) {
					_u = max(_u, ru[jt + 1]);
					_d = min(_d, rd[jt + 1]);
					_l = min(_l, rl[jt + 1]);
					_r = max(_r, rr[jt + 1]);
				}
				if (_l < j) continue;
				int r = cal(i, j, it, jt, _d, _l, _u, _r);
				ret = min(ret, cal(i, j, it, jt, _d, _l, _u, _r));
			}
		}
	}
	if (ret == inf) puts("-1");
	else printf("%d\n", ret);
	return 0;
}

