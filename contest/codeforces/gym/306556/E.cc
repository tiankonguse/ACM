
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

ll vals[max5];  //代价

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  // freopen("out_std.txt", "w", stdout);
#endif
  ll n, m, k;
  while (scanf("%lld%lld%lld", &n, &m, &k) != EOF) {
    unordered_map<int, vector<int>> edges;
    max_queue<pair<ll, int>> maxQue;
    unordered_set<int> dst;
    unordered_set<int> flag;

    for (int i = 1; i <= n; i++) {
      scanf("%lld", &vals[i]);
    }
    ll ans = -1;
    for (int i = 1; i <= n; i++) {
      int v;
      scanf("%d", &v);

      //目的地 炎或者虚无 炎(bi = 1)
      if (v == 0 || v == 1) {
        dst.insert(i);
      }

      //出发地
      if (v == 0) {  //无属性，可以直接到达目的地
        if (vals[i] < k) {
          ans = max(ans, k - vals[i]);
        }
        flag.insert(i);
      }

      // 入口 无属性或者冰属性的 冰(bi = 2)
      if (v == 2) {
        if (vals[i] < k) {
          maxQue.push({k - vals[i], i});
        }
        flag.insert(i);
      }
    }

    for (int i = 1; i <= m; i++) {
      int a, b;
      scanf("%d%d", &a, &b);
      edges[a].push_back(b);
      edges[b].push_back(a);
    }

    while (!maxQue.empty()) {
      auto p = maxQue.top();
      maxQue.pop();
      const ll val = p.first;
      const ll now = p.second;

      for (auto v : edges[now]) {
        if (flag.count(v)) {
          continue;
        }
        ll leftVal = val - vals[v];
        if (leftVal < 0) {  //不可到达
          continue;
        }

        if (dst.count(v)) {
          ans = max(ans, leftVal);  //找到一个答案
          continue;
        }

        //继续搜索
        flag.insert(v);
        maxQue.push({leftVal, v});
      }
    }
    if (ans == -1) {
      printf("Sakura Fade\n");
    } else {
      printf("%lld\n", ans);
    }
  }

  return 0;
}