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
int const N = 55;
int const M = 2525;
int n, m;
struct edges{ int u, next; double c, t, w; } e[M];
int p[N], idx;
void addedge(int u, int v, double c, double t) {
	e[idx].u = v, e[idx].next = p[u], e[idx].c = c, e[idx].t = t, p[u] = idx++;
}
void init() { idx = 0; clr(p, 0xff); }
vector<int> v;
queue <int> q;
double dis[N];
bool used[N];
int cct[N];
int pre[N], ans[N];
bool vis[N];

int spfa() {
	int t, u; double w;
	while (!q.empty()) q.pop();
	memset(used, 0, sizeof used);
	for (int i = 1; i <= n; ++i) {
		dis[i] = 1e10;
		cct[i] = 0;
	}
	dis[1] = 0;
	q.push(1);
	while (!q.empty()) {
		t = q.front(); q.pop();
		used[t] = false;
		for (int i = p[t]; ~i; i = e[i].next) {
			u = e[i].u, w = e[i].w;
			if (dis[t] + w < dis[u]) {
				pre[u] = t;
				dis[u] = dis[t] + w;
				if (!used[u]) {
					used[u] = true;
					if (++cct[u] == n) return u;
					q.push(u);
				}
			}
		}
	}
	return 0;
}


int main() {
	int a, b;
	double x, y;
	init();
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i) {
		scanf("%d %d %lf %lf", &a, &b, &x, &y);
		addedge(a, b, x - 1, y);
	}
	double low = 0, high = 1e4, mid;
	int ret = -1, tmp;
	for (int k = 0; k < 50; ++k) {
		mid = (low + high) * 0.5;
		for (int i = 0; i < idx; ++i) {
			e[i].w = mid * e[i].t - e[i].c;
		}
		if ((tmp = spfa()) > 0) {
			for (int i = 1; i <= n; ++i) {
				ans[i] = pre[i];
			}
			ret = tmp;
			low = mid;
		} else {
			high = mid;
		}
	}
	if (ret < 0) {
		puts("0");
	} else {
		int now = ret;
		while (!vis[now]) {
			vis[now] = 1;
			now = ans[now];
		}
		ret = now;
		do {
			v.push_back(now);
			now = ans[now];
		} while (now != ret);
		printf("%d\n", v.size());
		for (int i = v.size() - 1; i >= 0; --i) {
			if (i == 0) printf("%d\n", v[i]);
			else printf("%d ", v[i]);
		}
	}

	return 0;
}

