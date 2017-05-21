#include <bits/stdc++.h>
using namespace std;
int const L = 610, N = 360010, M = 1440010;
struct edges {
  int u, next;
} e[M];
int n, p[N], deg[N], idx;
void init() {
  idx = 0;
  memset(p, 0xff, sizeof p);
}
void addedge(int u, int v) {
  ++deg[v];
  e[idx].u = v;
  e[idx].next = p[u];
  p[u] = idx++;
}

int top[L][L], lft[L][L];
int r, arr[L], ans[L][L], st[N];
vector<int> v;

bool cal() {
  v.clear(); v.push_back(1);
  if (arr[1] != 0) return 0;
  for (int i = 2; i <= r; ++i) {
    int t = i - arr[i] - 1;
    if (t < 0 || t >= i) return 0; 
    v.insert(v.begin() + t, i);
  }
  return 1;
}

int main() {
  scanf("%d", &r);
  for (int i = 1; i <= r; ++i) {
    for (int j = 1; j <= r; ++j) {
      scanf("%d", &top[i][j]);
    }
  }
  for (int i = 1; i <= r; ++i) {
    for (int j = 1; j <= r; ++j) {
      scanf("%d", &lft[i][j]);
    }
  }
  init();
  for (int i = 1; i <= r; ++i) {
    for (int j = 1; j <= r; ++j) {
      arr[j] = lft[i][j];
    }
    if (!cal()) {
      puts("0");
      return 0;
    }
    for (int j = 1; j < r; ++j) {
      addedge((i - 1) * r + v[j - 1], (i - 1) * r + v[j]);
    }
    for (int j = 1; j <= r; ++j) {
      arr[j] = top[j][i];
    }
    if (!cal()) {
      puts("0");
      return 0;
    }
    for (int j = 1; j < r; ++j) {
      addedge((v[j - 1] - 1) * r + i, (v[j] - 1) * r + i);
    }
  }
  n = r * r; int top = 0, cur = 0;
  for (int i = 1; i <= n; ++i) {
    if (deg[i] == 0) {
      st[++top] = i;
      deg[i] = -1;
    }
  }
  while (top > 0) {
    int u = st[top--];
    ans[(u - 1) / r][(u - 1) % r] = ++cur;
    for (int i = p[u]; ~i; i = e[i].next) {
      int t = e[i].u;
      if (deg[t] != -1) {
        --deg[t];
        if (deg[t] == 0) st[++top] = t;
      }
    }
  }
  if (cur != n) puts("0");
  else {
    for (int i = 0; i < r; ++i) {
      for (int j = 0; j < r; ++j) {
        if (j == r - 1) printf("%d\n", ans[i][j]);
        else printf("%d ", ans[i][j]);
      }
    }
  }
  return 0;
}

