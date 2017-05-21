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
int const maxn(1010);
typedef long long ll;
bool mp[maxn][maxn];
bool da[maxn][maxn];
int n, m;
struct point {
  int x, y;
} q[maxn], k[maxn], p[maxn];
int qc, kc, pc;
int const dirk[8][2] = {
	-2, -1, -2, 1, -1, 2, 1, 2, 2, 1, 2, -1, 1, -2, -1, -2
};
int dirq[8][2] = {
	-1, -1, -1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1
};
bool check(int x, int y) {
	return x >= 1 && x <= n && y >= 1 && y <= m;
}
int main() {
	int ca = 1;
	while (scanf("%d%d", &n, &m)) {
		if (n == 0 && m == 0) break;
		memset(mp, 0, sizeof mp);
		memset(da, 0, sizeof da);
		scanf("%d", &qc); for (int i = 0; i < qc; ++i) scanf("%d%d", &q[i].x, &q[i].y);
		scanf("%d", &kc); for (int i = 0; i < kc; ++i) scanf("%d%d", &k[i].x, &k[i].y);
		scanf("%d", &pc); for (int i = 0; i < pc; ++i) scanf("%d%d", &p[i].x, &p[i].y);
		int tx, ty;
		for (int i = 0; i < pc; ++i) { mp[p[i].x][p[i].y] = true; }
		for (int i = 0; i < kc; ++i) { mp[k[i].x][k[i].y] = true; }
		for (int i = 0; i < qc; ++i) { mp[q[i].x][q[i].y] = true; }
		for (int i = 0; i < qc; ++i) {
			for (int j = 0; j < 8; ++j) {
				int x = q[i].x + dirq[j][0], y = q[i].y + dirq[j][1];
				while (check(x, y) && !mp[x][y]) {
					da[x][y] = true;
					x += dirq[j][0];
					y += dirq[j][1];
				}
			}
		}
		for (int i = 0; i < kc; ++i) {
			for (int j = 0; j < 8; ++j) {
				tx = k[i].x + dirk[j][0];
				ty = k[i].y + dirk[j][1];
				if (check(tx, ty)) da[tx][ty] = true;
			}
		}
		int ret = 0;
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j) {
				ret += !mp[i][j] && !da[i][j];
			}
		}
		printf("Board %d has %d safe squares.\n", ca++, ret);
	}
    return 0;
}
