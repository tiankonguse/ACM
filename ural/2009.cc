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
int const N = 1010;
bool mp[N][N];
bool inq[N];
int n, m;
int QL[N], QR[N];
int lc, rc;
int ans[N][2];
int main() {
	int x;
	scanf("%d%d", &n, &m);
	Rep(i, n) {
		while (scanf("%d", &x) && x) {
			mp[x][i] = 1;
		}
	}
	int t, k, now = 0;
	lc = rc = 0;
	while (m--) {
		scanf("%d%d", &t, &k);
		while (now < t && !(lc == 0 && rc == 0)) {
			++now;
			if (lc != 0) {
				ans[QL[0]][0] = now;
				ans[QL[0]][1] = 0;
				rep(i, lc - 1) QL[i] = QL[i + 1];
				--lc;	
			}
			if (rc != 0) {
				ans[QR[0]][0] = now;
				ans[QR[0]][1] = 1;
				rep(i, rc - 1) QR[i] = QR[i + 1];
				--rc;
			}
		}
		now = t;
		rep(i, k) {
			scanf("%d", &x);
			int mi = rc, sel = 1;
			rep(j, rc) {
				if (mp[QR[j]][x] && j + 1 < mi) {
					mi = j + 1;
					sel = 1;
				}
			}
			rep(j, lc) {
				if (mp[QL[j]][x] && j + 1 < mi) {
					mi = j + 1;
					sel = 0;
				}
			}
			if (lc < mi) {
				mi = lc;
				sel = 0;
			}
			if (sel == 0) {
				for (int j = lc; j > mi; --j) QL[j] = QL[j - 1];
				QL[mi] = x;
				++lc;
			}
			else {
				for (int j = rc; j > mi; --j) QR[j] = QR[j - 1];
				QR[mi] = x;
				++rc;
			}
		}
	}
	while (!(lc == 0 && rc == 0)) {
		++now;
		if (lc != 0) {
			ans[QL[0]][0] = now;
			ans[QL[0]][1] = 0;
			rep(i, lc - 1) QL[i] = QL[i + 1];
			--lc;	
		}
		if (rc != 0) {
			ans[QR[0]][0] = now;
			ans[QR[0]][1] = 1;
			rep(i, rc - 1) QR[i] = QR[i + 1];
			--rc;
		}
	}
	Rep(i, n) {
		printf("%d ", ans[i][0]);
		if (ans[i][1] == 1) puts("right");
		else puts("left");
	}
	return 0;
}

