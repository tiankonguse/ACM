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
int const N = 210;
int const M = 410;
int n, m;
struct edges{ int u, w, next; } e[M];
int p[N], idx;
void addedge(int u, int v, int c, int r = 0) {
	e[idx].u = v, e[idx].w = c, e[idx].next = p[u], p[u] = idx++;
	e[idx].u = u, e[idx].w = r, e[idx].next = p[v], p[v] = idx++;
}
void init() { idx = 0; clr(p, 0xff); }
bool vis[N]; 
int dfs(int u, int t, int f) {
	if (u == t) return f;
	vis[u] = 1;
	for (int i = p[u]; ~i; i = e[i].next) {
		int v = e[i].u, c = min(f, e[i].w);;
		if (!vis[v] && c > 0) {
			int r = dfs(v, t, c);
			if (r > 0) {
				e[i].w -= r, e[i ^ 1].w += r;
				return r;
			}
		}
	}
	return 0;
}
int cal(int s, int t) {
	int ret = 0, c = 0;
	do {
		clr(vis, 0);
		c = dfs(s, t, inf);
		ret += c;
	} while (c > 0);
	return ret;
}
int main() {
	int a, b, c;
	while (~scanf("%d%d", &m, &n)) {
		init();
		rep(i, m) {
			scanf("%d%d%d", &a, &b, &c);
			addedge(a, b, c);
		}
		printf("%d\n", cal(1, n));
	}
	return 0;
}

