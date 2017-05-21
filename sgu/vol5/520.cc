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
int const N = 1010, M = 10101;
struct Edges {
  int u, next;
} e[M];
int n, m, p[N], idx;
void addedge(int u, int v) {
  e[idx].u = v, e[idx].next = p[u], p[u] = idx++;
}
void init() {
  clr(p, 0xff); idx = 0;
}
int dis[N];
queue<int> q;
int f[N][N][2];
bool dfs(int u, int d, int t) {
  if (f[u][d][t] != -1) return f[u][d][t];
  bool ret = 0;
  for (int i = p[u]; ~i; i = e[i].next) {
    int v = e[i].u;
    if (dis[v] >= d + 1) {
      ret |= !dfs(v, d + 1, t ^ 1);
    }
  }
  return f[u][d][t] = ret;
}

int main() {
  scanf("%d%d", &n, &m);
  init();
  rep(i, m) {
    int a, b; scanf("%d%d", &a, &b);
    addedge(a, b); addedge(b, a);
  }  
  clr(dis, 0x3f); dis[1] = 0;
  q.push(1);
  while (!q.empty()) {
    int u = q.front(); q.pop();
    for (int i = p[u]; ~i; i = e[i].next) {
      int v = e[i].u;
      if (dis[u] + 1 < dis[v]) {
        dis[v] = dis[u] + 1;
        q.push(v);
      }
    }
  }
  clr(f, 0xff);
  if (dfs(1, 0, 0)) puts("Vladimir");
  else puts("Nikolay");
  return 0;
}

