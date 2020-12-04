
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

// lower_bound 大于等于
// upper_bound 大于

const LL INF = 0x3f3f3f3f3f3f3f3fll;
const double PI = acos(-1.0), eps = 1e-7;
const int inf = 0x3f3f3f3f, ninf = 0xc0c0c0c0, mod = 1000000007;
const int max3 = 2100, max4 = 11100, max5 = 200100, max6 = 2000100;

ll vec[max6];
unordered_map<int, unordered_map<int, ll>> m;

ll sum;
ll n, k;

ll dfs(int root, int pre = 0) {
//   printf("root=%d pre=%d\n", root, pre);
  auto& m0 = m[root];

  ll now = vec[root];

  for (auto& p : m0) {
    int u = p.first;
    ll val = p.second;

    if (u == pre) {
      continue;
    }

    ll tmp = dfs(u, root);
    if (tmp == 0) {
      continue;
    }

    sum += val;
    now += tmp;
  }

  if (now % k == 0) {
    now = 0;
  }
  return now;
}

int main() {
  sum = 0;

  scanf("%lld%lld", &n, &k);
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &vec[i]);
  }
  for (int i = 1; i < n; i++) {
    ll u, v, val;
    scanf("%lld%lld%lld", &u, &v, &val);
    m[u][v] = val;
    m[v][u] = val;
  }

//   printf("begin\n");
  dfs(1);

  printf("%lld\n", sum);

  return 0;
}