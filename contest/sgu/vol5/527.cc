#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <ctime>
#include <map>

#define inf 0x3f3f3f3f
#define Inf 0x3FFFFFFFFFFFFFFFLL
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define Rep(i, n) for (int i = 1; i <= (n); ++i)
#define clr(x, a) memset(x, (a), sizeof x)
using namespace std;
typedef long long ll;
int const N = 25;
char g[N+1][N+1];
int star[N];
int main() {
  int n, m; scanf("%d%d", &n, &m);
  rep(i, n) scanf(" %s", g[i]);
  rep(i, n) {
    star[i] = 0;
    rep(j, m) star[i] = star[i] * 2 + (g[i][j] == '*');
  }
  int ans = inf;
  rep(i, 1 << m) {
    int t = 0;
    rep(j, n) {
      if ((i | star[j]) == i) continue;
      else ++t;
    }
    t = max(t, __builtin_popcount(i));
    ans = min(ans, t);
  }
  printf("%d\n", ans);
  return 0;
}

