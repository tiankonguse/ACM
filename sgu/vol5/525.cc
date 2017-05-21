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
#include <ctime>
#include <map>

#define inf 0x3f3f3f3f
#define Inf 0x3FFFFFFFFFFFFFFFLL
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define Rep(i, n) for (int i = 1; i <= (n); ++i)
#define clr(x, a) memset(x, (a), sizeof x)
using namespace std;
typedef long long ll;
int const N = 1010, M = 100100;
struct Graph {
  int n, m, p[N], idx;
  struct Edge {
    int u, next;
  } e[M];
  void addedge(int u, int v) { e[idx].u = v, e[idx].next = p[u], p[u] = idx++; }
  void init() { idx = 0; clr(p, 0xff); }

  int top, cnt, cc, t;
  int st[N], dfn[N], low[N], col[N]; bool vis[N];
  void tarjan(int u) {
    dfn[u] = low[u] = ++cnt;
    st[++top] = u, vis[u] = 1;
    for (int i = p[u]; ~i; i = e[i].next) {
      int v = e[i].u;
      if (!dfn[v]) {
        tarjan(v);
        low[u] = min(low[u], low[v]);
      } else if (vis[v]) low[u] = min(low[u], dfn[v]);
    }
    if (dfn[u] == low[u]) {
      do {
        t = st[top--];
        col[t] = cc + 1;
        vis[t] = 0;
      } while (t != u);
      ++cc;
    }
  }
  void solve() {
    top = cnt = cc = 0;
    clr(vis, 0), clr(col, 0), clr(dfn, 0);
    Rep(i, n) if (!dfn[i]) tarjan(i);
  }
} g1, g2;
int sz[N];
bool vis[N][N];
int raw[M][2], ans[N];
void dfs(int s, int u) {
  vis[s][u] = 1;
  for (int i = g2.p[u]; ~i; i = g2.e[i].next) {
    int v = g2.e[i].u;
    if (!vis[s][v]) {
      dfs(s, v);
    }
  }
}
int main() {
  scanf("%d%d", &g1.n, &g1.m);
  g1.init();
  rep(i, g1.m) {
    int a, b; scanf("%d%d", &a, &b);
    g1.addedge(a, b);
    raw[i][0] = a, raw[i][1] = b;
  }
  g1.solve();
  g2.init(); g2.n = g1.cc;
  Rep(u, g1.n) {
    int cu = g1.col[u];
    ++sz[cu];
    for (int i = g1.p[u]; ~i; i = g1.e[i].next) {
      int v = g1.e[i].u;
      int cv = g1.col[v];
      if (cv != cu && !vis[cu][cv]) {
        g2.addedge(cu, cv);
      }
    }
  }
  clr(vis, 0);
  Rep(i, g1.cc) dfs(i, i);
  int w = 0, cnt = 0;
  Rep(i, g1.cc) w = max(w, sz[i]);
  rep(i, g1.m) {
    int u = raw[i][0], v = raw[i][1];
    int cu = g1.col[u], cv = g1.col[v];
    int cw = 0;
    Rep(j, g1.cc) {
      if (vis[cu][j] && vis[j][cv]) {
        cw += sz[j];
      }
    }
    if (cw > w) {
      w = cw;
      ans[cnt = 0] = i + 1;
      ++cnt;
    } else if (cw == w) {
      ans[cnt++] = i + 1;
    }
  }
  printf("%d\n%d\n", w, cnt);
  rep(i, cnt) {
    if (i == cnt - 1) printf("%d\n", ans[i]);
    else printf("%d ", ans[i]);
  }
  return 0;
}

