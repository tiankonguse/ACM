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
int const N = 111, M = 11111;
struct Edges {
  int u, next;
} e[M];
int p[N], idx;
void addedge(int u, int v) {
  e[idx].u = v, e[idx].next = p[u], p[u] = idx++;
}
void init() {
  idx = 0; 
  clr(p, 0xff);
}
int g[N][N];
int n, m; 
int mark[N][N];
bool ok[N];
bool vis[N];
bool deny[N][N];

bool dfs(int u, int v) {
  if (u == v) return 1;
  vis[u] = 1;
  for (int i = p[u]; ~i; i = e[i].next) {
    int t = e[i].u;
    if (!deny[u][t] && !vis[t]) {
      if (dfs(t, v)) return 1;
    }
  }
  return 0;
}

bool check(int u, int v) {
  if (mark[u][v] != -1) return mark[u][v];
  deny[u][v] = deny[v][u] = 1;
  clr(vis, 0);
  bool ret = dfs(u, v);
  deny[u][v] = deny[v][u] = 0;
  return mark[u][v] = ret;
}

bool judge(int u, int v) {
  if (check(u, v)) return 1;
  else if (g[u][v] % 2 != 0) return 1;
  else if (g[u][v] > 0) {
    Rep(j, n) if (j != u && j != v) {
      if (g[u][j] > 0 && (g[u][j] >= 2 || check(u, j))) return 1;
      else if ((g[v][j] > 0 && (g[v][j] >= 2 || check(v, j)))) return 1;
    }
  }
  return 0;
}

int main() {
  cin >> n >> m;
  init(); clr(mark, 0xff);
  rep(i, m) {
    int x, y; cin >> x >> y;
    addedge(x, y); addedge(y, x);
    g[x][y]++, g[y][x]++;    
  }
  for (int i = 2; i <= n; ++i) {
    ok[i] = judge(1, i);
  }
  bool f = 0;
  for (int i = 2; i <= n; ++i) {
    if (g[1][i] > 0) {
      f = 1;
      --g[1][i], --g[i][1];
      ok[1] = judge(i, 1);
      ++g[1][i], ++g[i][1];
      if (ok[1]) break;
    }
  }
  if (!f) ok[1] = 1;
  vector<int> ans;
  Rep(i, n) if (ok[i]) ans.push_back(i);
  rep(i, ans.size()) {
    if (i == ans.size() - 1) printf("%d\n", ans[i]);
    else printf("%d ", ans[i]);
  }
  return 0;
}

