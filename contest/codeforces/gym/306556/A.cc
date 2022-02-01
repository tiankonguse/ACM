
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

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  // freopen("out_std.txt", "w", stdout);
#endif
  int n;
  while (scanf("%d", &n) != EOF) {
    for (int i = 0; i < n; i++) {
      scanf("%lld", &str[i]);
    }
    ll x;
    scanf("%lld", &x);

    sort(str, str + n);

    ll ans = 0;
    ll now = 0;  // [0, now]
    int index = 0;
    while (now < x) {
      ll nextVal = now + 1;
      if (index < n && str[index] <= nextVal) {
        now += str[index];  // 新增 [nextVal, now + str[index]]
        index++;
        continue;
      }

      // 剩余的值都大于 nextVal
      // 借一个 nextVal
      ans++;
      now += nextVal; // add [nextVal, now+nextVal]
    }

    printf("%lld\n", ans);
  }
  return 0;
}