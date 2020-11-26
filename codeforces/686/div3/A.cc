
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

int main() {
  int t, n;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    for (int i = 2; i <= n; i += 2) {
      str[i] = i - 1;
      str[i - 1] = i;
    }
    if (n % 2 == 1) {
      str[n] = str[n - 1];
      str[n - 1] = n;
    }
    for (int i = 1; i <= n; i++) {
      printf("%d%c", str[i], i == n ? '\n' : ' ');
    }
  }
  return 0;
}