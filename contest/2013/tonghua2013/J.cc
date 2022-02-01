#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
#include <sstream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <ctime>

#define inf 0x3f3f3f3f
#define Inf 0x3FFFFFFFFFFFFFFFLL
using namespace std;
typedef long long ll;
ll const mod = 2011;
ll ext_gcd(ll a, ll b, ll &x, ll &y) {
  ll t, ret;
  if (!b) {
    x = 1, y = 0;
    return a;
  }
  ret = ext_gcd(b, a % b, x, y);
  t = x, x = y, y = t - a / b * y;
  return ret;
}

ll inv(ll a, ll b, ll c) {
  ll x, y;
  ext_gcd(a, c, x, y);
  return (1LL * x * b % c + c) % c;
}
ll powMod(ll a, ll b, ll c) {
  ll ret = 1 % c;
  for (; b; a = a * a % c, b >>= 1)
    if(b & 1) ret = ret * a % c;
  return ret;
}

int main() {
  ll n;
	while (~scanf("%lld", &n) && n) {
		ll r1 = inv(5LL, powMod(6LL, n, mod) - 1, mod);
		ll r2 = inv(30LL, powMod(6LL, n, mod) + 24, mod);
		printf("%lld %lld\n", r2, r1);
	}
	return 0;
}

