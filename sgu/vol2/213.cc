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
int const N = 1010;
int const M = 1001000;
int n, m;
struct edges{ int u, w, next; } e[M];
int p[N], idx;
void addedge(int u, int v, int w) {
	e[idx].u = v, e[idx].w = w, e[idx].next = p[u], p[u] = idx++;
}
void init() { idx = 0; clr(p, 0xff); }
queue <int> q;
int dis[N];
bool used[N];
void spfa(int s){
    int t, u, w;
    while (!q.empty()) q.pop();
    memset(used, 0, sizeof used);
    memset(dis, 0x3f, sizeof dis);
    dis[s] = 0;
    q.push(s);
    while (!q.empty()) {
        t = q.front(); q.pop();
        used[t] = false;
        for (int i = p[t]; ~i; i = e[i].next) {
            u = e[i].u, w = e[i].w;
            if (dis[t] + w < dis[u]) {
                dis[u] = dis[t] + w;
                if (!used[u]) {
                    used[u] = true;
                    q.push(u);
                }
            }
        }
    }
}
struct ansE {
	int a, b, c;
} ae[M];
vector<int> ans[404];

int main() {
	int s, t; scanf("%d%d%d%d", &n, &m, &s, &t);
	init();
	rep(i, m) {
		int a, b; scanf("%d%d", &a, &b);
		ae[i].a = a, ae[i].b = b;
		addedge(a, b, 1); addedge(b, a, 1);
	}
	spfa(s);
	int dt = dis[t];
	rep(i, m) {
		int da = dis[ae[i].a], db = dis[ae[i].b];
		int d = max(da, db);
		d = min(d, dt);
		ans[d].push_back(i + 1);
	}	
	printf("%d\n", dt);
	Rep(i, dt) {
		printf("%d", ans[i].size());
		rep(j, ans[i].size()) printf(" %d", ans[i][j]);
		puts("");
	}
	return 0;
}

