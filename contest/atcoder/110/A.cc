
#include <bits/stdc++.h>
#include<atcoder/modint>

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

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  // freopen("out_std.txt", "w", stdout);
#endif
  vector<int> str = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
  ll n;
  while (~scanf("%lld", &n)) {
    map<int, int> m;
    for (int j = 2; j <= n; j++) {
      int k = j;
      map<int, int> tmp;
      for (int i = 0; k && i < str.size(); i++) {
        int v = str[i];
        while (k % str[i] == 0) {
          tmp[v]++;
          k /= str[i];
        }
      }

      for (auto& [v, num] : tmp) {
        if (m[v] < num) {
          m[v] = num;
        }
      }
    }
    ll sum = 1;
    for (auto& [v, num] : m) {
      while (num--) {
        sum *= v;
      }
    }

    printf("%lld\n", sum + 1);
  }
  return 0;
}
