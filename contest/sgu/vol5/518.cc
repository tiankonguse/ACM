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
int const N = 202;
int g[N][N];
int r[N];
bool f[N][N];
int main() {
  int n, m; scanf("%d", &n);
  rep(i, n) rep(j, n) scanf("%d", &g[i][j]);
  scanf("%d", &m);
  rep(i, m) scanf("%d", &r[i]);
  f[0][0] = 1;
  rep(i, m) rep(j, n) if (f[i][j]) {
    rep(k, n) if (r[i] == g[j][k]) {
      f[i + 1][k] = 1;
    }
  }
  vector<int> ans;
  rep(i, n) if (f[m][i]) ans.push_back(i + 1);
  int cnt = ans.size();
  printf("%d\n", cnt);
  rep(i, cnt) {
    if (i == cnt - 1) printf("%d\n", ans[i]);
    else printf("%d ", ans[i]);
  }
  return 0;
}

