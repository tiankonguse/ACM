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
struct Node {
	char s[10][10];
	int w, h, sz; char c;
	friend bool operator<(Node a, Node b) {
		if (a.sz == b.sz) {
			return a.w * a.h > b.w * b.h;
		} else {
			return a.sz > b.sz;
		}
	}		
} p[30];
char s[22][22];

bool vis[10][10];
char g[10][10];
int n, k;

Node rot(Node x) {
	Node ret;
	ret.w = x.h, ret.h = x.w, ret.sz = x.sz, ret.c = x.c;
	rep(i, ret.h) rep(j, ret.w) {
		ret.s[i][j] = x.s[j][x.w - i - 1];
	}
	return ret;
}

bool ck(int x, int y, Node t) {
	int w = t.w, h = t.h;
	if (x + t.h > n || y + t.w > n) return 0;
	rep(i, h) rep(j, w) {
		if (t.s[i][j] != '.' && g[x + i][y + j] != '.') {
			return 0;
		}
	}
	return 1;
}

void put(int x, int y, Node t, bool add) {
	int w = t.w, h = t.h;
	rep(i, h) rep(j, w) if (t.s[i][j] != '.') {
		if (add) g[x + i][y + j] = t.c;
		else g[x + i][y + j] = '.';
	}
}
bool dfs(int d, int px, int py) {
	if (d == k || p[d].sz == 1) return 1;
	Node t = p[d];
	bool same = 0;
	if (d > 0 && p[d].sz == 2 && p[d - 1].sz == 2) {
		same = 1;
	}
	if (d > 0 && p[d].sz == 3 && p[d - 1].sz == 3 && p[d].w * p[d].h == p[d - 1].w * p[d - 1].h) {
		same = 1;
	}
	rep(w, 4) {
		if (w > 0) t = rot(t);
		int startI = same ? px : 0;
		for (int i = startI; i < n; ++i) {
			int startJ = (same && i == startI) ? py : 0;
			for (int j = startJ; j < n; ++j) {
				if (ck(i, j, t)) {
					put(i, j, t, 1);
					if (dfs(d + 1, i, j)) return 1;
					put(i, j, t, 0);
				}
			}
		}
		if (p[d].sz == 2 && w == 1) break;
	}	
	return 0;
}

int main() {
	scanf("%d", &n);
	rep(i, 20) scanf(" %s", s[i]);
	for (char c = 'A'; c <= 'Z'; ++c) {
		int lx = inf, ly = inf, rx = 0, ry = 0;
		rep(i, 20) rep(j, 20) if (s[i][j] == c) {
			lx = min(lx, i), ly = min(ly, j);
			rx = max(rx, i), ry = max(ry, j);
		}
		if (lx != inf) {
			p[k].h = rx - lx + 1, p[k].w = ry - ly + 1, p[k].sz = 0, p[k].c = c;
			for (int i = lx; i <= rx; ++i) for (int j = ly; j <= ry; ++j) {
				if (s[i][j] == c) {
					++p[k].sz; p[k].s[i - lx][j - ly] = c;
				} else {
					p[k].s[i - lx][j - ly] = '.';
				}
			}
			++k;
		}
	}
	sort(p, p + k);
	rep(i, n) rep(j, n) g[i][j] = '.';
	rep(i, n) g[i][n] = 0;
	bool ok = dfs(0, 0, 0);
	rep(i, k) if (p[i].sz == 1) {
		bool filled = 0;
		rep(u, n) {
			rep(v, n) {
				if (g[u][v] == '.') {
					g[u][v] = p[i].c;
					filled = 1;
					break;
				}
			}
			if (filled) break;
		}
	}
	rep(i, n) puts(g[i]);
	return 0;
}

