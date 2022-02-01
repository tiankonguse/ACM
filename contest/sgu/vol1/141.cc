#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <ctime>
#include <map>

#define inf 0x3f3f3f3f
#define Inf 0x3FFFFFFFFFFFFFFFLL
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define Rep(i, n) for (int i = 1; i <= (n); ++i)
#define clr(x, a) memset(x, (a), sizeof x)
using namespace std;
typedef long long ll;
ll _abs(ll x) {
  return x < 0 ? -x : x;
}
ll x1, x2, p, k, p1, n1, p2, n2;

bool cal(ll t1, ll t2) {
  if (_abs(t1) + _abs(t2) <= k && (_abs(t1) + _abs(t2) - k) % 2 == 0) {
    if (t1 < 0) n1 = -t1;
    else p1 = t1;
    if (t2 < 0) n2 = -t2;
    else p2 = t2;
    ll rem = (k - _abs(t1) - _abs(t2)) / 2;
    n1 += rem, p1 += rem;
    cout << "YES" << endl;
    cout << p1 << " " << n1 << " " << p2 << " " << n2 << endl;
    return 1;
  }
  return 0;
}
int main() {
  cin >> x1 >> x2 >> p >> k;
  for (ll i = -40000; i <= 40000; ++i) {
    if ((p - i * x1) % x2 == 0) {
      if (cal(i, (p - i * x1) / x2)) return 0;
    }
    if ((p - i * x2) % x1 == 0) {
      if (cal((p - i * x2) / x1, i)) return 0;
    }
  }
  cout << "NO" << endl;
  return 0;
}

