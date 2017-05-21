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
int const N = 55;
int const n = 20, m = 50;
char const fr[6] = { 218, 191, 192, 217, 179, 196 };
char mp[N][N]; int s[N][N]; bool wp[N][N]; int ans[2020][3], ant;
bool f(char c) { rep(i, 6) if (c == fr[i]) return 1; return 0; }
bool check(int x1, int y1, int x2, int y2) {
	bool f = 0;
	for (int i = x1; !f && i <= x2; ++i) if (!wp[i][y1] || !wp[i][y2]) f = 1;
	for (int i = y1; !f && i <= y2; ++i) if (!wp[x1][i] || !wp[x2][i]) f = 1;
	if (!f) return 0;	
	if (!wp[x1][y1] && mp[x1][y1] != fr[0]) return 0;
	if (!wp[x1][y2] && mp[x1][y2] != fr[1]) return 0;
	if (!wp[x2][y1] && mp[x2][y1] != fr[2]) return 0;
	if (!wp[x2][y2] && mp[x2][y2] != fr[3]) return 0;
	for (int i = x1 + 1; i < x2; ++i) if ((!wp[i][y1] && mp[i][y1] != fr[4]) || (!wp[i][y2] && mp[i][y2] != fr[4])) return 0;
	for (int i = y1 + 1; i < y2; ++i) if ((!wp[x1][i] && mp[x1][i] != fr[5]) || (!wp[x2][i] && mp[x2][i] != fr[5])) return 0;
	return 1;
}
void era(int x1, int y1, int x2, int y2) {
	for (int i = x1; i <= x2; ++i) mp[i][y1] = mp[i][y2] = '.', wp[i][y1] = wp[i][y2] = 1;
	for (int i = y1; i <= y2; ++i) mp[x1][i] = mp[x2][i] = '.', wp[x1][i] = wp[x2][i] = 1;
}
int main() {
	Rep(i, n) gets(mp[i] + 1);

again:
	for (int k = 1; k < n; ++k) {
		Rep(i, n - k) Rep(j, m - k) {
			if (check(i, j, i + k, j + k)) {
				ans[ant][0] = j - 1, ans[ant][1] = i - 1, ans[ant][2] = k + 1;
				++ant;
				era(i, j, i + k, j + k);
				goto skip;
			}
		}
	}
skip:
	 Rep(i, n) Rep(j, m) if (f(mp[i][j])) goto again;
	 
	 printf("%d\n", ant);
	 for (int i = ant - 1; ~i; --i) {
		 printf("%d %d %d\n", ans[i][0], ans[i][1], ans[i][2]);
	 }
	 return 0;
}
