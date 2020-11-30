
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

ll Cal(ll a) {
  if (a == 1) {
    return 0;
  }
  if (a == 2) {
    return 1;
  }
  if(a == 3){
      return 2;
  }
  if (a % 2 == 0) {
    return 2;
  }
  return 3;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    ll a;
    scanf("%lld", &a);
    printf("%lld\n", Cal(a));
  }
  return 0;
}