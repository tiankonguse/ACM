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
int const N = 100100;
char a[N], b[N];
int nxt[N][26], cur[26];
int main() {
  scanf(" %s %s", a, b);
  int n = strlen(a), m = strlen(b);
  rep(i, 26) cur[i] = -1;
  for (int i = n - 1; i >= 0; --i) {
    rep(j, 26) nxt[i][j] = cur[j];
    cur[a[i] - 'a'] = i;
  }
  ll ans = 0; int pre = -1;
  rep(i, n) if (a[i] == b[0]) {
    int pos = i;
    Rep(j, m - 1) {
      pos = nxt[pos][b[j] - 'a'];
      if (pos == -1) break;
    }
    if (pos == -1) break;
    ans += 1LL * (i - pre) * (n - pos);
    pre = i;
  }
  printf("%I64d\n", ans);
  return 0;
}

