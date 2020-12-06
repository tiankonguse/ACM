
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

ll gcd(ll a, ll b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  // freopen("out_std.txt", "w", stdout);
#endif
  int t;
  while (scanf("%d", &t) != EOF) {
    while (t--) {
      ll x, y;
      scanf("%lld%lld", &x, &y);
      ll d = gcd(x, y);
      ll cnt = 0;
      ll xx = x, yy = y;
      while (yy != 0) {
        if (xx < yy) {
          swap(xx, yy);
          continue;
        }
        cnt += xx / yy;
        xx = xx % yy;
      }
      printf("gcd(%lld, %lld) = %lld, cnt = %lld\n", x, y, d, cnt);
    }
  }
  return 0;
}