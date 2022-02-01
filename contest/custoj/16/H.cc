
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

// lower_bound 大于等于
// upper_bound 大于

const LL INF = 0x3f3f3f3f3f3f3f3fll;
const double PI = acos(-1.0), eps = 1e-7;
const int inf = 0x3f3f3f3f, ninf = 0xc0c0c0c0, mod = 1000000007;
const int max3 = 2100, max4 = 11100, max5 = 200100, max6 = 2000100;

int MOD = 114514199;

int dp[max3][max3];

void init() {
  memset(dp, 0, sizeof(dp));
  for (int i = 0; i <= 1000; i++) {
    for (int j = 0; j <= 2000; j++) {
      if (i == 0) {
        dp[i][j] = 1;
      } else if (j == 0) {
        dp[i][j] = dp[i - 1][1];
      } else {
        dp[i][j] = (dp[i][j - 1] + dp[i - 1][j + 1]) % MOD;
      }
    }
  }
}

int main() {
  init();
  int n, m;
  while (~scanf("%d%d", &n, &m)) {
    printf("%d\n", dp[n][m]);
  }

  return 0;
}