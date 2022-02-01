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
int const maxn = 10;
int const dir[8][2] = { 0, -1, 0, 1, 1, 0, -1, 0, -1, -1, -1, 1, 1, 1, 1, -1};
inline bool check(int x, int y) { return x >= 0 && x < 8 && y >= 0 && y < 8; }
inline bool notF(int x1, int y1, int x2, int y2) {
  return !(x2 == x1 + 1 && (y2 == y1 - 1 || y2 == y1 + 1));
}
char mp[maxn][maxn];
int dp[maxn][maxn][maxn][maxn][2];

bool dfs(int x1, int y1, int x2, int y2, int p) {
	if (dp[x1][y1][x2][y2][p] != -1) return dp[x1][y1][x2][y2][p];
	bool flag = false;
	int tx, ty;
	if (p == 0) {
		for (int i = 0; i < 8; ++i) {
			tx = x1 + dir[i][0];
			ty = y1 + dir[i][1];
			if (check(tx, ty) && mp[tx][ty] != 'D' && mp[tx][ty] != 'F' && notF(x2, y2, tx, ty)) {
				if (tx == x2 && ty == y2) flag = true;
				else flag |= !dfs(tx, ty, x2, y2, p ^ 1);
				if (flag) break;
			}
		}
	}
	else {
		tx = x2 + 1;
		ty = y2;
		if (tx == 8) flag = true;
		else {
			if (mp[tx][ty] != 'F' && !(tx == x1 && ty == y1)) {
				flag |= !dfs(x1, y1, tx, ty, p ^ 1);
			}
		}
	}
	return dp[x1][y1][x2][y2][p] = flag;
}
int main() {
	int T;
	int x1, y1, x2, y2;
	for (scanf("%d", &T); T--; ) {
		for (int i = 0; i < 8; ++i) scanf(" %s", mp[i]);
		scanf("%d%d%d%d", &y1, &x1, &y2, &x2);
		--x1, --y1, --x2, --y2;
		x1 = 7 - x1, x2 = 7 - x2;
		memset(dp, 0xff, sizeof dp);
		bool ret = dfs(x1, y1, x2, y2, 0);
		puts(ret ? "White" : "Black");
	}
    return 0;
}
