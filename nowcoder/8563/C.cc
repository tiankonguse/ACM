
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

ll getSum(ll a, ll d, ll n) { return a * n + n * (n - 1) * d / 2; }

int main() {
  ll n, a, d, k, y;

  scanf("%lld%lld%lld%lld%lld", &n, &a, &d, &k, &y);

  ll ans = n * 2 * k;

  ll sum = getSum(a, d, n);

  if (sum <= y) {
    printf("%lld\n", 0);
    return 0;
  }

  // 如果 d 小于 0， 反转等差数列
  if (d < 0) {
    a = a + (n - 1) * d;
    d = -d;
  }

  // 如果 a 小于 0，缩小等差数列，使得其实位置大于等于 0
  if (a < 0) {
    ll k = (-a) / d + 1;
    y = y - getSum(a, d, k);
    a = a + k * d;
    n = n - k;
  }

  // 之后枚举左边界，二分右边界
  for (ll i = 1; i <= n; i++) {
    ll l = i, r = n;
    ll mid = (l + r) / 2;
  }

  printf("%lld\n", ans);

  return 0;
}