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
int const N = 2010;
int g[N][N];
int cal(int l, int r, int s) {
  int m = r - l + 1;
  if (m % 2 == 0) {
    int mid = (l + r) / 2;
    int c = cal(l, mid, s);
    for (int i = mid + 1; i <= r; ++i) {
      for (int j = mid + 1; j <= r; ++j) {
        g[i][j] = g[j][i] = g[i - r + mid][j - r + mid];
      }
    }
    if ((r - mid) % 2 != 0) {
      rep(i, r - mid) {
        int x = l + i, y = mid + i + 1;
        g[x][y] = g[y][x] = s + i + 1;
      }
    } else {
      ++c;
      rep(i, r - mid) {
        int x = l + i, y = mid + i + 1;
        g[x][y] = g[y][x] = c;
      }
    }
    for (int i = 1; i < r - mid; ++i) {
      ++c;
      int x = l, y = mid + i + 1;
      rep(j, r - mid) {
        g[x][y] = g[y][x] = c;
        ++x; ++y; if (y > r) y = mid + 1; 
      }
    }
    return c;
  } else {
    int t = s;
    for (int i = l; i <= r; ++i) {
      int x = i, y = i;
      ++t;
      Rep(j, m / 2) {
        --x; if (x < l) x = r;
        ++y; if (y > r) y = l;
        g[x][y] = g[y][x] = t;
      }
    }
    return t;
  }
}

int main() {
  int n; scanf("%d", &n);
  if (n == 1) {
    puts("0\n0");
    return 0;
  }

  int ans = cal(0, n - 1, 0);
  printf("%d\n", ans);
  rep(i, n) {
    rep(j, n) {
      if (j == n - 1) printf("%d\n", g[i][j]);
      else printf("%d ", g[i][j]);
    }
  }
  return 0;
}

