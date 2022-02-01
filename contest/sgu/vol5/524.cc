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
int const N = 404;
double a[N], b[N], ans[N];
int main() {
  int n; scanf("%d", &n);
  rep(i, n) scanf(" %lf", &a[i]);
  double best = 1e11;
  rep(i, n) for (int j = i + 1; j < n; ++j) {
    double dis = (a[j] - a[i]) / (j - i);
    rep(k, n) b[k] = a[i] + dis * (k - i);
    double ts = 0;
    rep(k, n) ts += fabs(a[k] - b[k]);
    if (ts < best) {
      best = ts;
      rep(k, n) ans[k] = b[k];
    }
  }
  printf("%.10lf\n", best);
  rep(i, n) {
    if (i == n - 1) printf("%.10lf\n", ans[i]);
    else printf("%.10lf ", ans[i]);
  }
  return 0;
}

