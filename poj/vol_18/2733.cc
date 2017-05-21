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
int const maxn(17);
typedef long long ll;
bool mp[maxn][maxn];
int const dir[8][2] = { -1, -1, -1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1 };
int id[maxn][maxn];
bool mt[maxn][maxn];
int n, m, k, x, y;

bool check() {
  for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			int tx, ty, cc = 0;
			for (int z = 0; z < 8; ++z) {
				tx = i + dir[z][0]; if (tx == n) tx = 0; else if (tx < 0) tx = n - 1;
				ty = j + dir[z][1]; if (ty == m) ty = 0; else if (ty < 0) ty = m - 1;
				cc += mt[tx][ty];
			}
			bool live = 0;
			if (cc == 2) live = mt[i][j];
			if (cc == 3) live = 1;
			if (live != mp[i][j]) return false;
		}
	}
	return true;
}
int main() {
	int ca = 1;
	while (~scanf("%d%d", &n, &m)) {
		if (n == 0 && m == 0) break;
		memset(mp, 0, sizeof mp);
		for (scanf("%d", &k); k--; ) {
			scanf("%d%d", &x, &y);
			mp[x][y] = true;
		}
		int s = n * m;
		int mx = 1 << s;
		int ret = 0;
		for (int i = 0; i < mx; ++i) {
			for (int j = 0; j < s; ++j) {
				if (i >> j & 1) mt[j / m][j % m] = true;
				else mt[j / m][j % m] = false;
			}
			if (check()) ++ret;
		}
		if (ret == 0) printf("Case %d: Garden of Eden.\n", ca++);
		else printf("Case %d: %d possible ancestors.\n", ca++, ret);
	}
    return 0;
}
