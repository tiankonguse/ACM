
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

const int mod1 = 100000;

ll nums[max5];

void init() {
  nums[0] = 0;
  nums[1] = 1;
  for (int i = 2; i < max5; i++) {
    nums[i] = (nums[i - 1] + nums[i - 2] * 2) % mod1;
  }
}

int main() {
  init();
  ll n, x;
  while (~scanf("%lld%lld", &n, &x)) {
    printf("%lld\n", nums[n] * x % mod1);
  }

  return 0;
}