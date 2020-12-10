
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
using min_queue = priority_queue<T, vector<T>, greater<T> >;
template <class T>
using max_queue = priority_queue<T>;

const LL INF = 0x3f3f3f3f3f3f3f3fll;
const double PI = acos(-1.0), eps = 1e-7;
const int inf = 0x3f3f3f3f, ninf = 0xc0c0c0c0, mod = 1000000007;
const int max3 = 2100, max4 = 11100, max5 = 200100, max6 = 2000100;

ll prim[12];
int n;

LL myrongchi(int index, LL a) {
  LL r = 0, t;
  for (int i = index; i < n; i++) {
    t = a / prim[i];
    r += t - myrongchi(i + 1, t);
  }
  return r;
}

ll solver(ll x) {
  if (x == 1) {
    return 0;
  }
  return myrongchi(0, x);
}
int main() {
// #ifndef ONLINE_JUDGE
//   freopen("in.txt", "r", stdin);
//   freopen("out.txt", "w", stdout);
//   // freopen("out_std.txt", "w", stdout);
// #endif
  int t;
  while (scanf("%d", &t) != EOF) {
    while (t--) {
      ll x, y;
      scanf("%d%lld%lld", &n, &x, &y);
      for (int i = 0; i < n; i++) {
        scanf("%lld", &prim[i]);
      }
      printf("%lld\n", solver(y) - solver(x));
    }
  }
  return 0;
}