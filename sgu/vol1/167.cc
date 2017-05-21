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
#include <map>
#include <ctime>

#define inf 0x3f3f3f3f
#define Inf 0x3FFFFFFFFFFFFFFFLL
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define Rep(i, n) for (int i = 1; i <= (n); ++i)
#define clr(x, a) memset(x, (a), sizeof x)
using namespace std;
typedef long long ll;
int const N = 15;
int f[N][2][2][N][N][N*N+1];
int pre[N][2][2][N][N][N*N+1][4];
int a[N][N], s[N][N], sum[N][N][N];
int main() {
  int n, m, k; scanf("%d%d%d", &n, &m, &k);
  rep(i, n) rep(j, m) scanf("%d", &a[i][j]);
  if (k == 0) {
    puts("Oil : 0");
    return 0;
  }
  
  rep(i, n) rep(j, m) {
    if (j == 0) s[i][j] = a[i][j];
    else s[i][j] = s[i][j - 1] + a[i][j];
  }
  rep(i, n) rep(l, m) for (int r = l; r < m; ++r) {
    if (l == 0) sum[i][l][r] = s[i][r];
    else sum[i][l][r] = s[i][r] - s[i][l - 1];
  }
  int ans = -1, ai, aul, aur, al, ar, ak;
  clr(f, 0xff);
  rep(t, n) rep(i, m) for (int j = i; j < m; ++j) {
    f[t][0][0][i][j][j - i + 1] = sum[t][i][j];
    if (j - i + 1 == k) {
      if (sum[t][i][j] > ans){
        ai = t, aul = aur = 0, al = i, ar = j, ak = j - i + 1;
        ans = sum[t][i][j];
      }
    }
  }
  rep(i, n - 1) {
    int mk = min(k, i * m + m);
    rep(ul, 2) rep(ur, 2) rep(l, m) for (int r = l; r < m; ++r) rep(t, mk + 1) {
      if (f[i][ul][ur][l][r][t] > 0) {
        int tl = 0, tr = m - 1;
        if (ul == 1) tl = l;
        if (ur == 1) tr = r;
        for (int x = tl; x <= r; ++x) for (int y = max(x, l); y <= tr; ++y) {
          int ttl = ul, ttr = ur;
          if (x > l) ttl = 1;
          if (y < r) ttr = 1;
          int ttt = t + y - x + 1;
          if (ttt <= k) {
            if (f[i][ul][ur][l][r][t] + sum[i + 1][x][y] > f[i + 1][ttl][ttr][x][y][ttt]) {
              f[i + 1][ttl][ttr][x][y][ttt] = f[i][ul][ur][l][r][t] + sum[i + 1][x][y];
              pre[i + 1][ttl][ttr][x][y][ttt][0] = l;
              pre[i + 1][ttl][ttr][x][y][ttt][1] = r;
              pre[i + 1][ttl][ttr][x][y][ttt][2] = ul;
              pre[i + 1][ttl][ttr][x][y][ttt][3] = ur;
            }
            if (ttt == k && f[i + 1][ttl][ttr][x][y][ttt] > ans) {
              ans = f[i + 1][ttl][ttr][x][y][ttt];
              ai = i + 1, aul = ttl, aur = ttr, al = x, ar = y, ak = ttt;
            }
          }
        }
      }
    }
  }
  vector<pair<int, int> > v;
  while (ai >= 0 && ak > 0) {
    for (int i = al; i <= ar; ++i) {
      v.push_back(make_pair(ai + 1, i + 1));
    }
    int pl = pre[ai][aul][aur][al][ar][ak][0];
    int pr = pre[ai][aul][aur][al][ar][ak][1];
    int pul = pre[ai][aul][aur][al][ar][ak][2];
    int pur = pre[ai][aul][aur][al][ar][ak][3];
    int pk = ak - (ar - al + 1);
    --ai;
    aul = pul, aur = pur, al = pl, ar = pr, ak = pk;
  }
  sort(v.begin(), v.end());
  printf("Oil : %d\n", ans);
  rep(i, v.size()) {
    printf("%d %d\n", v[i].first, v[i].second);
  }
  return 0;
}

