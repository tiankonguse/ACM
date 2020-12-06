
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

LL muti_mod(LL a, LL b, LL c) {
  a %= c;
  b %= c;
  LL ret = 0;
  while (b) {
    if (b & 1) {
      ret += a;
      if (ret >= c) ret -= c;
    }
    a <<= 1;
    if (a >= c) a -= c;
    b >>= 1;
  }
  return ret;
}
LL pow_mod(LL a, LL b, LL c) {
  LL ret = 1;
  for (a %= c; b; b >>= 1, a = muti_mod(a, a, c)) {
    if (b & 1) ret = muti_mod(ret, a, c);
  }
  return ret;
}

ll solver(ll n) {
  if (n == 1) return 1;
  ll zzz = pow_mod(2, n, mod);
  if (n % 2 == 0) {
    return muti_mod(n / 2, zzz, mod);
  } else {
    ll a = muti_mod(n / 2, zzz, mod);
    ll b = pow_mod(2, n - 1, mod);
    return (a + b) % mod;
  }
}

int main() {
  // #ifndef ONLINE_JUDGE
  //   freopen("in.txt", "r", stdin);
  //   freopen("out.txt", "w", stdout);
  //   // freopen("out_std.txt", "w", stdout);
  // #endif
  ll n;
  while (scanf("%lld", &n) != EOF) {
    printf("%lld\n", solver(n));
  }
  return 0;
}