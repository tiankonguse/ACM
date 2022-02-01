#include <bits/stdc++.h>
using namespace std;
int const inf = 0x3f3f3f3f;
struct Node {
  int idx, cost;
  Node(int idx = 0, int cost = 0) : idx(idx), cost(cost) {}
  friend bool operator < (Node a, Node b) {
    return a.cost < b.cost;
  }
} p1[1010], p2[1010];
int s1[1010], s2[1010];
int dp[2][2][1010][1010];
int pre[2][2][1010][1010][4];

vector<int> v;

int main() {
  cout<<(sizeof pre / 1024 / 1024) << endl;
  int k, n, x, y; scanf("%d%d", &k, &n);
  int c1 = 0, c2 = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%d%d", &x, &y);
    if (y == 0) p1[c1++] = Node(i + 1, x);
    else p2[c2++] = Node(i + 1, x);
  }
  sort(p1, p1 + c1), sort(p2, p2 + c2);
  for (int i = 1; i <= c1; ++i) {
    s1[i] = s1[i - 1] + p1[i - 1].cost;
  }
  for (int i = 1; i <= c2; ++i) {
    s2[i] = s2[i - 1] + p2[i - 1].cost;
  }
  int ans = inf, ri = 0;
  for (int i = 0; i <= c1; ++i) {
    int t1 = i, t2 = k - i;
    if (t2 <= c2 && t1 * 2 + 2 >= t2 && t2 * 2 + 2 >= t1) {
      int tr = s1[t1] + s2[t2];
      if (tr < ans) {
        ans = tr;
        ri = i;
      }
    }
  }
  if (ans == inf) {
    puts("Impossible");
    return 0;
  }
  for (int i = 0; i < ri; ++i) v.push_back(p1[i].idx);
  for (int i = 0; i < k - ri; ++i) v.push_back(p2[i].idx);
  sort(v.begin(), v.end());
  for (int i = 0; i < v.size(); ++i) {
    if (i == 0) printf("%d", v[i]);
    else printf(" %d", v[i]);
  }
  puts("");
  return 0;
}
