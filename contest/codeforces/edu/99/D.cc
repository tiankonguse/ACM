
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

int str[max3];
int order[max3];

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  // freopen("out_std.txt", "w", stdout);
#endif

#ifndef ONLINE_JUDGE
  // diff out.txt out_std.txt
#endif
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, x;
    scanf("%d%d", &n, &x);
    for (int i = 0; i < n; i++) {
      scanf("%d", &str[i]);
      order[i] = 0;
    }

    order[n - 1] = 1;
    for (int i = n - 2; i >= 0; i--) {
      if (order[i + 1] == 1 && str[i] <= str[i + 1]) {
        order[i] = 1;
      }
    }

    int ans = 0;
    if (order[0] == 0) {
      for (int i = 0; i < n; i++) {
        if (i > 0 && str[i] >= str[i - 1] && order[i]) {
          //如果已经满足有序了，需要结束循环
          break;
        }
        if (str[i] > x) {
          swap(str[i], x);
          ans++;
        }
      }
    }

    for (int i = 1; i < n; i++) {
      if (str[i] < str[i - 1]) {
        ans = -1;
        break;
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}