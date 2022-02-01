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
int const maxn = 510;
int const maxm = 1010;
int const maxl = 1500;
char dat[maxn][maxn];

int p[maxm][maxl], len[maxm];
char mp[maxm][maxl];
void pk(int r, int *p, char *str, int len){
  int id, mx = 0;
	for(int i=0;i<len;i++){
		if(mx > i) p[i] = min(p[2*id-i], mx-i);
		else p[i] = 1;
		for(;str[i+p[i]]==str[i-p[i]];p[i]++);
		if(p[i] + i > mx){
			mx = p[i] + i;
			id = i;
		}
	}
}
char tmp[maxn][maxn];
void rotate(char dat[maxn][maxn], int &n, int &m) {
	for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) tmp[i][j] = dat[i][j];
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			dat[j][n - i - 1] = tmp[i][j];
		}
	}
	swap(n, m);
}
int main() {
	int T, n, m, R, ret;
	for (scanf("%d", &T); T--; ) {
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; ++i) scanf(" %s", dat[i]);
		R = n + m - 1;
		ret = 1;
		for (int q = 0; q < 4; ++q) {
			int x, y, l;
			for (int i = 0; i < n; ++i) {
				x = i, y = 0, l = 0;
				mp[i][l++] = '!'; mp[i][l++] = '#';
				while (x >= 0 && y < m) {
					mp[i][l++] = dat[x][y];
					mp[i][l++] = '#';
					--x, ++y;
				}
				mp[i][ len[i] = l ] = 0;
			}
			for (int i = 1; i < m; ++i) {
				x = n - 1, y = i, l = 0;
				for (int j = 0; j < i; ++j) {
					mp[n + i - 1][l++] = '!';
					mp[n + i - 1][l++] = '!';
				}
				mp[n + i - 1][l++] = '!'; 
				mp[n + i - 1][l++] = '#';
				while (x >= 0 && y < m) {
					mp[n + i - 1][l++] = dat[x][y];
					mp[n + i - 1][l++] = '#';
					--x, ++y;
				}
				mp[n + i - 1][len[n + i - 1] = l] = 0;
			}
			for (int i = 0; i < R; ++i) pk(i, p[i], mp[i], len[i]);
			//for (int i = 0; i < R; ++i) puts(mp[i]);
			for (int i = 0; i < R; ++i) {
				x = i + 1, y = 3;
				int now = 1, h = 1, t;
				while (x < R && y < len[x] && mp[x][y] != '!') {
					if (y & 1) t = p[x][y] / 2 * 2;
					else t = p[x][y] / 2 * 2 - 1;
					if (t >= h + 1) {
						++h, ++now;
					}
					else {
						now = t;
						h = t;
					}
					ret = max(ret, now);
					++x, ++y;
				}
				x = i + 2, y = len[i] + 1;
				now = 1, h = 1;
				while (x < R && y < len[x] && mp[x][y] != '!') {
					if (y & 1) t = p[x][y] / 2 * 2;
					else t = p[x][y] / 2 * 2 - 1;
					if (t >= h + 1) {
						++h, ++now;
					}
					else {
						now = t;
						h = t;
					}
					ret = max(ret, now);
					++x, ++y;
				}
			}
			rotate(dat, n, m);
		}
		printf("%d\n", ret * (ret + 1) / 2);
	}
	return 0;
}

