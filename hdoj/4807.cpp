#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
const int N = 2505;
const int M = 5005 * 10;
const int INF = 1000000000;
int n, m, p, e, maxv;
int d[N], f[N];
struct edge {
	int x, y, c, w;
	edge *nxt, *op;
}g[M], *ls[N], *fa[N];

void addedge(int x, int y, int c, int w) {
	g[e].x = x; g[e].y = y; g[e].c = c; g[e].w = w; g[e].nxt = ls[x]; ls[x] = &g[e]; g[e].op = &g[e + 1];
	e++;
	g[e].x = y; g[e].y = x; g[e].c = 0; g[e].w =-w; g[e].nxt = ls[y]; ls[y] = &g[e]; g[e].op = &g[e - 1];
	e++;
}

bool spfa() {
	queue <int> Q;
	static bool inQ[N];
	rep (i, n) {
		d[i] = INF;
		inQ[i] = 0;
	}
	inQ[0] = 1;
	d[0] = 0;
	Q.push(0);
	while (!Q.empty()) {
		int x = Q.front();
		Q.pop();
		for (edge *t = ls[x]; t; t = t->nxt) {
			if (t->c && d[t->x] + t->w < d[t->y]) {
				d[t->y] = d[t->x] + t->w;
				fa[t->y] = t;
				if (!inQ[t->y]) {
					inQ[t->y] = 1;
					Q.push(t->y);
				}
			}
		}
		inQ[x] = 0;
	}
	return d[n - 1] != INF;
}

void aug() {
//	printf("%d\n", d[n - 1]);
	int nf = INF;
	for (int i = n - 1; i; i = fa[i]->x) {
		nf = min(nf, fa[i]->c);
	}
	f[d[n - 1]] += nf;
	for (int i = n - 1; i; i = fa[i]->x) {
		fa[i]->c -= nf;
		fa[i]->op->c += nf;
	}
	maxv = max(maxv, d[n - 1]);
}

int main() {
	while (scanf("%d%d%d", &n, &m, &p) != EOF) {
		e = 0;
		memset(ls, 0, sizeof(ls));
		memset(f, 0, sizeof(f));
		int a, b, c;
		rep (i, m) {
			scanf("%d%d%d", &a, &b, &c);
			addedge(a, b, c, 1);
		}
		maxv = 0;
		if (p == 0) {
			puts("0");
			continue;
		}
		while (spfa()) {
			aug();
		}
		int res = -1;
		for (int i = 1; i <= n; i++) {
			f[i] += f[i - 1];
			p -= f[i];
			if (p <= 0) {
				res = i;
				break;
			}
		}
		if (res == -1 && f[n]) {
			res = n + (p + f[n] - 1) / f[n];
		}
		if (~res) {
			printf("%d\n", res);
		} else {
			puts("No solution");
		}
	}
}
