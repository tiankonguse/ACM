
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
using min_queue = priority_queue<T, vector<T>, greater<T>>;
template <class T>
using max_queue = priority_queue<T>;

const LL INF = 0x3f3f3f3f3f3f3f3fll;
const double PI = acos(-1.0), eps = 1e-7;
const int inf = 0x3f3f3f3f, ninf = 0xc0c0c0c0, mod = 1000000007;
const int max3 = 2100, max4 = 11100, max5 = 200100, max6 = 2000100;

int dp[max6];
int n;
const int MaxN = 1000000;

void init() {
  memset(dp, -1, sizeof(dp));
  queue<pair<int, int>> que;
  dp[0] = 0;
  int x = 0;
  n = 0;

  que.push({0, 0});
  while (!que.empty() && n < MaxN) {
    auto p = que.front();
    int x = p.first;
    for (int i = p.second + 1; i < max6; i++) {
      x += i;
      if (x >= 0 && x <= MaxN && dp[x] == -1) {
        dp[x] = i;
        n++;
      }
      que.push({x, i});
    }

    x = p.first - 1;
    if (x >= 0 && x <= MaxN && dp[x] == -1) {
      dp[x] = p.second + 1;
      n++;
    }
    que.push({x, p.second + 1});
  }
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  // freopen("out_std.txt", "w", stdout);
#endif

#ifndef ONLINE_JUDGE
  // diff out.txt out_std.txt
#endif
  init();
  int t;
  scanf("%d", &t);
  while (t--) {
    int x;
    scanf("%d", &x);
    printf("%d\n", dp[x]);
  }
  return 0;
}