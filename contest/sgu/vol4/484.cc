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
int const N = 111;
char mp[N][N];
int n, m;
int go(int x, int y, int d) {
	if (x >= n) return y + 1;
	if (y < 0 || y >= m) return -1;
	if (mp[x][y] == 'P' || mp[x][y] == '.') return go(x + 1, y, 0);
	else if (mp[x][y] == '/') {
		if (d == 0) return go(x, y - 1, -1);
		else if (d == -1) return go(x + 1, y, 0);
		else return -1;
	}
	else {
		if (d == 0) return go(x, y + 1, 1);
		else if (d == 1) return go(x + 1, y, 0);
		else return -1;
	}
}
int main() {
	scanf("%d%d", &n, &m); rep(i, n) scanf(" %s", mp[i]);
	rep(i, n) rep(j, m) if (mp[i][j] == 'P') {
		printf("%d\n", go(i, j, 0));
		return 0;
	}
	return 0;
}

