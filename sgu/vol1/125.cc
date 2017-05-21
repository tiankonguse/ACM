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
int const maxn = 4;
int const maxm = 10;
int b[maxn][maxn];
int n, z;
int a[maxn][maxn];
int now[maxn][maxn];

bool dfs(int x, int y) {
	if (x == n) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (now[i][j] != b[i][j]) return false;
			}
		}
		return true;
	}
	int nx = x, ny = y + 1;
	if (ny == n) ny = 0, nx = x + 1;
	for (int i = 1; i <= z; ++i) {
		a[x][y] = i;
		int c = 0;
		if (x > 0) {
			if (a[x - 1][y] > i) {
				if (now[x - 1][y] != b[x - 1][y]) continue;
				++c;
			}
			else if (a[x - 1][y] < i && now[x - 1][y] + 1 != b[x - 1][y]) continue;
		}
		if (y > 0) {
			if (a[x][y - 1] > i) {
				if (now[x][y - 1] + 1 < b[x][y - 1]) continue;
				++c;
			}
			else if (a[x][y - 1] < i && (now[x][y - 1] + 1 > b[x][y - 1] || now[x][y - 1] + 2 < b[x][y - 1])) continue;
		}
		if (c > b[x][y]) continue;
		now[x][y] = c;
		if (x > 0 && a[x - 1][y] < i) ++now[x - 1][y];
		if (y > 0 && a[x][y - 1] < i) ++now[x][y - 1];
		if (dfs(nx, ny)) return true;
		if (x > 0 && a[x - 1][y] < i) --now[x - 1][y];
		if (y > 0 && a[x][y - 1] < i) --now[x][y - 1];
	}
	return false;
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			scanf("%d", &b[i][j]);
		}
	}
	z = n * n;
	bool ret = dfs(0, 0);
	if (!ret) puts("NO SOLUTION");
	else {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (j == n - 1) printf("%d\n", a[i][j]);
				else printf("%d ", a[i][j]);
			}
		}
	}
	return 0;
}
