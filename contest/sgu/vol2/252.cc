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
int const M = 44444;
int n, m;
struct edges{ int u, c, f, next; int ru,rv;} e[M];
int p[N], idx;
void addedge(int u, int v, int c, int f) {
  e[idx].u = v, e[idx].c = c, e[idx].f =  f, e[idx].next = p[u], p[u] = idx++;
  e[idx].u = u, e[idx].c = 0, e[idx].f = -f, e[idx].next = p[v], p[v] = idx++;
}
void init() { idx = 0; clr(p, 0xff); }
struct SSP {
  int mc, mf;
  int pre[N][2], Q[N], dis[N]; bool vis[N];
  bool spfa(int s, int t) {
    clr(dis, 0x3f), clr(vis, 0); dis[s] = 0, Q[0] = s, vis[s] = 1;
    int u, v, w;
    for (int l = 0, h = 1; l != h; ) {
      vis[u = Q[l++]] = 0; if (l == N) l = 0;
      for (int i = p[u]; ~i; i = e[i].next) {
        v = e[i].u, w = e[i].f;
        if (e[i].c && dis[u] + w < dis[v]) {
          dis[v] = dis[u] + w;
          pre[v][0] = u, pre[v][1] = i;
          if (!vis[v]) {
            vis[v] = 1;
            Q[h++] = v; if (h == N) h = 0;
          }
        }
      }
    }
    return dis[t] < 0; // return dis[t] < 0: any flow
  }
  void solve(int s, int t) {
    mc = mf = 0; int u, step;
    while (spfa(s, t)) {
      step = inf;
      for (u = t; u != s; u = pre[u][0]) {
        step = min(step, e[pre[u][1]].c);
      }
      for (u = t; u != s; u = pre[u][0]) {
        e[pre[u][1]].c -= step;
        e[pre[u][1] ^ 1].c += step;
      }
      mf += step;
      mc += dis[t] * step;
    }
  }
} mcf;
bool vis[N];

int main() {
	scanf("%d%d", &n, &m);
	int S = n * 2 + 1, T = S + 1;
	init();
	Rep(i, n) {
		addedge(S, i, 1, 100000);
		addedge(i + n, T, 1, 100000);
		addedge(i, i + n, 1, -300000);
	}
	rep(i, m) {
		int a, b, c; scanf("%d%d%d", &a, &b, &c);
		addedge(a + n, b, 1, c);
	}
	int rn = n;
	n = n * 2 + 2;
	mcf.solve(S, T);
	printf("%d %d\n", mcf.mf, mcf.mc - mcf.mf * 200000 + 300000 * rn);
	Rep(i, rn) if (!vis[i]) {
		bool prix = 0;
		for (int j = p[i]; ~j; j = e[j].next) {
			if (e[j].c > 0 && e[j].u != S) {
				prix = 1;
				break;
			}
		}
		if (prix) continue;
		int nxt = i;
		vector<int> v;
		while (!vis[nxt]) {
			if (nxt == S || nxt == T) break;
			v.push_back(nxt);
			vis[nxt] = 1;
			for (int j = p[nxt+rn]; ~j; j = e[j].next) {
				if (e[j^1].c == 1) {
					e[j^1].c = 0;
					nxt = e[j].u;
					break;
				}
			}
		}
		printf("%d", v.size());
		rep(j, v.size()) printf(" %d", v[j]);
		puts("");
	}
	return 0;
}

