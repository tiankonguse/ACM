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
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define Rep(i, n) for (int i = 1; i <= (n); ++i)
#define clr(x, a) memset(x, (a), sizeof x)
using namespace std;
typedef long long ll;
int const N = 2010;
int const M = 400010;
struct edges { int u, v, w, next; } e[M];
int p[N], idx;
void addedge(int u, int v, int w) { e[idx].u = v, e[idx].v = u, e[idx].w = w, e[idx].next = p[u], p[u] = idx++; }
void init() { idx = 0; clr(p, 0xff); }
int n, m, x, y;

priority_queue<pair<int, int> > q;
int dx[N], dy[N]; bool vis[N];
void dijkstra(int s, int dis[]) {
  int u, v, w;
  while (!q.empty()) q.pop(); clr(vis, 0); Rep(i, n) dis[i] = inf;
  q.push(make_pair(0, s)), dis[s] = 0;
  while (!q.empty()) {
    pair<int, int> tmp = q.top(); q.pop();
    if (vis[u = tmp.second]) continue;
    else vis[u] = true;
    for (int i = p[u]; ~i; i = e[i].next) {
      v = e[i].u, w = e[i].w;
      if (!vis[v] && dis[u] + w < dis[v]) {
        dis[v] = dis[u] + w;
        q.push(make_pair(-dis[v], v));
      }
    }
  }
}
bool inGraph[N];
struct Node {
  int id, dis, op;
  Node(int id = 0, int dis = 0, int op = 0): id(id), dis(dis), op(op) {}
  friend bool operator < (Node a, Node b) {
    if (a.dis == b.dis) return a.op < b.op;
    else return a.dis < b.dis;
  }
} od[M];
int ans[N];

int main() {
  int a, b, c;
  scanf("%d%d%d%d", &n, &x, &y, &m);
  init();
  rep(i, m) {
    scanf("%d%d%d", &a, &b, &c);
    addedge(a, b, c), addedge(b, a, c);
  }
  dijkstra(x, dx);
  dijkstra(y, dy);
  Rep(i, n) inGraph[i] = (dx[i] + dy[i] == dx[y]);
  int cnt = 0;
  for (int i = 0; i < idx; i += 2) {
    a = e[i].u, b = e[i].v;
    if (dx[a] > dx[b]) swap(a, b);
    if (inGraph[a] && inGraph[b] && dx[a] + e[i].w == dx[b]) {
      od[cnt++] = Node(a, dx[a], 1);
      od[cnt++] = Node(b, dx[b], -1);
    }
  }
  sort(od, od + cnt);
  int top = 0, acc = 0;
  rep(i, cnt) {
    if (od[i].op == 1) {
      ans[od[i].id] = top;
      ++acc;
    } else {
      --top;
    }
    if (od[i].dis != od[i + 1].dis) {
      top += acc;
      acc = 0;
    }
  }
  Rep(i, n) if (inGraph[i]) {
    Rep(j, n) if (inGraph[j]) {
      if (dx[i] == dx[j]) {
        ++ans[i];
      }
    }
  }
  Rep(i, n) {
    if (i == n) printf("%d\n", ans[i]);
    else printf("%d ", ans[i]);
  }
  return 0;
}

