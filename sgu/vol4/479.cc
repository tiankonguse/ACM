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
int const N = 222;
int const dir[4][2] = { 0, 1, 0, -1, 1, 0, -1, 0 };
int mp[N][N];
int ans[N * N][2];
int main() {
	int n, m, s = 0, cnt = 0; scanf("%d%d", &n, &m);
	rep(i, n) rep(j, m) scanf("%d", &mp[i][j]);	
	rep(i, n) rep(j, m) if (mp[i][j]) ++s;
	bool f = 1;
	while (f) {
		f = 0;
		rep(i, n) rep(j, m) if (mp[i][j] == 1) {
			f = 1;
			mp[i][j] = 0;
			ans[cnt][0] = i, ans[cnt++][1] = j;
			rep(k, 4) {
				int tx = i + dir[k][0], ty = j + dir[k][1];
				if (tx >= 0 && tx < n && ty >= 0 && ty < m && mp[tx][ty]) {
					--mp[tx][ty];
					if (!mp[tx][ty]) goto skip;
				}
			}
		}
	}
	skip:;
	if (cnt == s) {
		for (int i = cnt - 1; ~i; --i) printf("%d %d\n", ans[i][0] + 1, ans[i][1] + 1);
	}
	else puts("No solution");
	return 0;
}

