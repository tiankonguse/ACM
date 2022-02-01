#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
#include <sstream>
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
int const N = 505;
int n, m;
int mp[N][N], matx[N], maty[N]; bool fy[N];

int path(int u) {
  rep(v, m) if (mp[u][v] && !fy[v]) {
    fy[v] = 1;
    if (!~maty[v] || path(maty[v])) {
      matx[u] = v, maty[v] = u;
      return 1;
    }
  }
  return 0;
}
int hungary() {
  int ret = 0;
  clr(matx, 0xff), clr(maty, 0xff);
  rep(i, n) if (!~matx[i]) {
    clr(fy, 0);
    ret += path(i);
  }
  return ret;
}
int val[N * N];
int g[N][N];
int rmx[N];

int main() {
	scanf("%d", &n); m = n;
	int k = 0, h = 1;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			scanf("%d", &g[i][j]);
			val[k++] = g[i][j];
		}
	}
	sort(val, val + k);
	for (int i = 1; i < k; ++i) if (val[i] != val[i - 1]) {
		val[h++] = val[i];
	}
	int low = 0, high = h - 1, mid;
	int ret;
	while (low <= high) {
		mid = (low + high) / 2;
		clr(mp, 0);
		rep(i, n) rep(j, n) {
			if (g[i][j] <= val[mid]) {
				mp[i][j] = 1;
			}
		}
		int sz = hungary();
		if (sz == n) {
			ret = val[mid];
			high = mid - 1;
			rep(i, n) {
				rmx[i] = matx[i];
			}
		} else {
			low = mid + 1;
		}
	}
	printf("%d\n", ret);
	rep(i, n) {
		printf("%d %d\n", i + 1, rmx[i] + 1);
	}
	return 0;
}

