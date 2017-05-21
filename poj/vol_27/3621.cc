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
int const maxn = 1010;
int const maxm = 10010;
double const eps = 1e-3;
struct edges {
  int u, next;
	double w;
} e[maxm];
int n, m;
int p[maxn], idx;
void addedge(int u, int v, double w) {
	e[idx].u = v;
	e[idx].w = w;
	e[idx].next = p[u];
	p[u] = idx++;
}
void init() {
	idx = 0;
	memset(p, 0xff, sizeof p);
}
double F[maxn];
double dist[maxn]; 
bool used[maxn];
int num[maxn];
int q[maxn * maxn];
bool spfa(double mid) {
	int l = 0, h = 0;
	for (int i = 1; i <= n; ++i) {
		used[i] = true;
		q[h++] = i;
		dist[i] = 0;
		num[i] = 0;
	}
	while (l < h) {
		int u = q[l++];
		used[u] = false;
		for (int i = p[u]; ~i; i = e[i].next) {
			int v = e[i].u;
			double w = F[u] - mid * e[i].w;
			if (dist[u] + w > dist[v]) {
				dist[v] = dist[u] + w;
				if (!used[v]) {
					used[v] = true;
					q[h++] = v;
					if (++num[v] > n) return true;
				}
			}
		}
	}
	return false;
}
int main() {
	int u, v; double w;
	while (~scanf("%d%d", &n, &m)) {
		for (int i = 1; i <= n; ++i) scanf("%lf", &F[i]);
		init();
		for (int i = 0; i < m; ++i) {
			scanf("%d%d%lf", &u, &v, &w);
			addedge(u, v, w);
		}
		double low = 0, high = 1e6, mid;
		while (low + eps < high) {
			mid = 0.5 * (low + high);
			if (spfa(mid)) {
				low = mid;
			}
			else {
				high = mid;
			}
		}
		printf("%.2lf\n", low);
	}
	return 0;
}
