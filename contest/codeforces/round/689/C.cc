
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

int str[max5];

bool deq(double a, double b) {
  if (a - b <= eps && b - a <= eps) {
    return true;
  } else {
    return false;
  }
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
      scanf("%d", &str[i]);
    }
    int lastPos = 1;
    for (int i = n; i >= 1; i--) {
      if (str[i] != i) {
        lastPos = i;
        break;
      }
    }

    double ans = 0;
    double noAns = 1.0;
    if (lastPos == 1) {
      ans = 1;
    }

    while (m--) {
      int r;
      double p;
      scanf("%d%lf", &r, &p);
      if (deq(ans, 1.0)) continue;

      if (r < lastPos) {
        continue;  // 之前的都是无用功
      }

      ans += noAns * p;
      noAns *= (1 - p);
    }
    printf("%.6f\n", ans);
  }
  return 0;
}