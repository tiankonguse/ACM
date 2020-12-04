
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

vector<ull> str;

void init() {
  ll base = 1;
  for (int i = 1; i < 64; i++) {
    base = base * 2;
    str.push_back(2 * (base - 1));
  }
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  // freopen("out_std.txt", "w", stdout);
#endif
  init();
  int t;
  scanf("%d", &t);
  while (t--) {
    ll n;
    scanf("%lld", &n);
    if (n % 2 == 1) {
      printf("-1\n");
    } else {
      vector<int> ans;

      while (n > 0) {
        auto it = std::upper_bound(str.begin(), str.end(), n);
        int num = it - str.begin();
        n -= str[num - 1];
        
        ans.push_back(1);
        while (--num) {
          ans.push_back(0);
        }
      }

      printf("%d\n", ans.size());
      for (int i = 0; i < ans.size(); i++) {
        printf("%d%c", ans[i], i == ans.size() - 1 ? '\n' : ' ');
      }
    }
  }
  return 0;
}
