
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long long LL;
typedef unsigned long long ull;
typedef unsigned long long ULL;
typedef std::pair<int, int> pii;
typedef std::pair<ll, ll> pll;
// const int mod = 1e9 + 7;

template <class T>
using min_queue = priority_queue<T, vector<T>, greater<T> >;
template <class T>
using max_queue = priority_queue<T>;

const LL INF = 0x3f3f3f3f3f3f3f3fll;
const double PI = acos(-1.0), eps = 1e-7;
const int inf = 0x3f3f3f3f, ninf = 0xc0c0c0c0, mod = 1000000007;
const int max3 = 2100, max4 = 11100, max5 = 200100, max6 = 2000100;

std::unordered_map<ll, ll> cacheF;
std::unordered_map<ll, ll> cacheC;

ll myhash(ll n, ll m) { return n * 1000000 + m; }

LL C(ll m, ll n) {
  auto p = myhash(n, m);
  if (cacheC.count(p) != 0) {
    return cacheC[p];
  }

  if (m == n || n == 0) {
    return cacheC[p] = 1;
  }
  if (m < n) {
    return cacheC[p] = 0;
  }

  ll ans = (C(m - 1, n - 1) + C(m - 1, n)) % mod;

  return cacheC[p] = ans;
}

// n 个数字，允许重复选，选 m 个
ll F(ll n, ll m) {
  //   printf("--n=%lld m=%lld\n", n, m);
  auto p = myhash(n, m);
  if (cacheF.count(p) != 0) {
    return cacheF[p];
  }

  if (n == 1) {
    return cacheF[p] = 1;
  }

  if (m == 0) {
    return cacheF[p] = 0;
  }

  ll ans = 0;

  ll maxK = min(n, m);
  //   printf("-- maxK = %lld\n", maxK);
  for (int k = 1; k <= maxK; k++) {
    ll tmp = C(n, k) * F(k, m - k) % mod;
    // printf(
    //     "-- n = %lld m = %lld k = %lld C(%lld, %lld) = %lld F(%lld, %lld)  =
    //     "
    //     "%lld tmp = %lld\n",
    //     n, m, k, n, k, C(n, k), k, m - k, F(k, m - k), tmp);
    ans = (ans + tmp) % mod;
  }

  return cacheF[p] = ans;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    ll m, lo, hi;
    scanf("%lld %lld %lld", &m, &lo, &hi);

    ll n = hi - (lo - 1);
    printf("%lld\n", F(n, m));
  }

  return 0;
}