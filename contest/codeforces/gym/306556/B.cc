
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long long LL;
typedef unsigned long long ull;
typedef unsigned long long ULL;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
// const int mod = 1e9 + 7;

template <class T>
using min_queue = priority_queue<T, vector<T>, greater<T>>;
template <class T>
using max_queue = priority_queue<T>;

const LL INF = 0x3f3f3f3f3f3f3f3fll;
const double PI = acos(-1.0), eps = 1e-7;
const int inf = 0x3f3f3f3f, ninf = 0xc0c0c0c0, mod = 1000000007;
const int max3 = 2100, max4 = 11100, max5 = 200100, max6 = 2000100;

// <node, map<val, [nodelist]>>
unordered_map<int, map<int, set<int>>> m;
int vals[max5];
int n, k;

ll dfs(int now, int pre) {
//   printf("node=%d pre=%d\n", now, pre);
  ll ans = vals[now];

  if (m.count(now) == 0) {
    return ans;
  }
  auto& m1 = m[now];

  // 删除父节点
  if (pre != 0) {
    int preVal = vals[pre];
    m1[preVal].erase(pre);
    if (m1[preVal].size() == 0) {
      m1.erase(preVal);
    }
  }

  int num = 1;
  for (auto it = m1.rbegin(); num <= k && it != m1.rend(); it++, num++) {
    for (auto v : it->second) {
      ans += dfs(v, now);
    }
  }

  return ans;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  // freopen("out_std.txt", "w", stdout);
#endif
  while (scanf("%d%d", &n, &k) != EOF) {
    m.clear();
    for (int i = 1; i <= n; i++) {
      scanf("%d", &vals[i]);
    }
    for (int i = 1; i < n; i++) {
      int a, b;
      scanf("%d%d", &a, &b);
      m[a][vals[b]].insert(b);
      m[b][vals[a]].insert(a);
    }
    printf("%lld\n", dfs(1, 0));
  }
  return 0;
}