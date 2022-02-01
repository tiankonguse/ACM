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
char s[111][111];
int main() {
  int n, m; scanf("%d%d", &n, &m);
  rep(i, n) scanf(" %s", s[i]);
  int ans = 0;
  rep(i, n) rep(j, m) {
    int h = s[i][j] - '0';
    if (h > 0) {
      ans += 2;
    }
    if (i == 0) ans += h;
    if (i == n - 1) ans += h;
    if (j == 0) ans += h;
    if (j == m - 1) ans += h;
    if (j > 0) ans += max(s[i][j] - s[i][j-1], s[i][j-1] - s[i][j]);
    if (i > 0) ans += max(s[i][j] - s[i-1][j], s[i-1][j] - s[i][j]);
  }
  printf("%d\n", ans);
  return 0;
}

