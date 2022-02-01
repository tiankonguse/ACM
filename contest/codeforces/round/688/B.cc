
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

ll str[max5];

ll dis(ll a, ll b) {
  if (a > b) {
    return a - b;
  } else {
    return b - a;
  }
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
      scanf("%lld", &str[i]);
    }

    ll sum = 0;
    for (int i = 2; i <= n; i++) {
      sum += dis(str[i], str[i - 1]);
    }

    ll maxAns = 0;
    maxAns = max(maxAns, dis(str[1], str[2]));      // 左边界
    maxAns = max(maxAns, dis(str[n - 1], str[n]));  // 右边界

    for (int i = 2; i < n; i++) {
      ll oldDis = dis(str[i - 1], str[i]) + dis(str[i], str[i + 1]);
      ll newDis = dis(str[i - 1], str[i + 1]);

      maxAns = max(maxAns, oldDis - newDis);
    }

    printf("%lld\n", sum - maxAns);
  }
  return 0;
}