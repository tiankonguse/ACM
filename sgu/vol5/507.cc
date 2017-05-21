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
int const N = 50500, M = 100100;
struct Edges { int u, next; } e[M];
int p[N], val[N], idx, n, m;
void init() { clr(p, 0xff); idx = 0; }
void addedge(int u, int v) { e[idx].u = v, e[idx].next = p[u], p[u] = idx++; }
int ans[N];

set<int> dfs(int u) {
  set<int> s;
  if (u > n - m) {
    s.insert(val[u]);
    return s;
  }
  
  for (int i = p[u]; ~i; i = e[i].next) {
    int v = e[i].u;
    set<int> t = dfs(v);
    if (s.size() < t.size()) swap(s, t);
    ans[u] = min(ans[u], ans[v]);
    for (set<int>::iterator it = t.begin(); it != t.end(); ++it) {
      int x = *it;
      set<int>::iterator pos = s.lower_bound(x);
      if (pos != s.end()) {
        ans[u] = min(ans[u], (*pos) - x);
      }  
      if (pos != s.begin()) {
        --pos; ans[u] = min(ans[u], x - (*pos));
      }
    }
    for (set<int>::iterator it = t.begin(); it != t.end(); ++it) {
      s.insert(*it);
    } 
  }  
  return s;
}

int main() {
  scanf("%d%d", &n, &m);
  init();
  for (int i = 2; i <= n; ++i) {
    int a; scanf("%d", &a);
    addedge(a, i);
  }
  for (int i = n - m + 1; i <= n; ++i) {
    scanf("%d", &val[i]);
  }
  clr(ans, 0x3f);
  dfs(1);
  Rep(i, n - m) {
    if (ans[i] == inf) ans[i] = 0x7fffffff;
    if (i == n - m) printf("%d\n", ans[i]);
    else printf("%d ", ans[i]);
  }
  return 0;
}

