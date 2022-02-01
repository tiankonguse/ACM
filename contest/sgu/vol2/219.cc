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
struct Edges {
  int u, w, next;
} e[M];
int p[N], idx;
void addedge(int u, int v, int w) {
  e[idx].u = v, e[idx].w = w, e[idx].next = p[u], p[u] = idx++;
}
void init() {
  idx = 0; clr(p, 0xff);
}
int deg[N];
int ans[N];
bool vis[N];
bool cyc[N];

void go(int u, int s) {
  vis[u] = 1;
  for (int i = p[u]; ~i; i = e[i].next) {
    int v = e[i].u;
    if (v == s && e[i].w == 0) {
      cyc[s] = 1;
      return;
    }
    if (!vis[v] && e[i].w == 0) {
      go(v, s);
    }
  }  
}

void dfs(int u) {
  ans[u] = 0;
  vis[u] = 1;
  for (int i = p[u]; ~i; i = e[i].next) {
    int v = e[i].u;
    if (!vis[v]) {
      dfs(v);
    }
  }
}

int main() {
  int n, m; scanf("%d %d", &n, &m);
  init();
  rep(i, m) {
    int a, b, c; scanf("%d%d%d", &a, &b, &c);
    addedge(a, b, c);
    ++deg[b];
  }
  clr(ans, 0xff);
  Rep(i, n) ans[i] = 1;
  Rep(i, n) {
    Rep(j, n) vis[j] = 0;
    go(i, i);
  }
  Rep(i, n) vis[i] = 0;
  Rep(i, n) if (cyc[i] && !vis[i]) {
    dfs(i);
  }
  Rep(i, n) printf("%d\n", ans[i]);
  return 0;
}
