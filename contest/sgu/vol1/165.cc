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
int const N = 6060;
int ans[N];
pair<double, int> a[N];
int main() {
  int n; scanf("%d", &n);
  rep(i, n) {
    double x; scanf("%lf", &x);
    a[i] = make_pair(x - 2, i + 1);
  }
  sort(a, a + n);
  int l = 0, r = n - 1, idx = 0;
  double s = 0;
  while (l <= r) {
    int pdx = idx;
    while (l <= r && s + a[l].first >= -0.05 && s + a[l].first <= 0.05) {
      ans[idx++] = a[l].second;
      s += a[l].first;
      ++l;
    }
    while (l <= r && s + a[r].first >= -0.05 && s + a[r].first <= 0.05) {
      ans[idx++] = a[r].second;
      s += a[r].first;
      --r;
    }
    if (idx == pdx) break;
  }
  puts("yes");
  rep(i, idx) {
    if (idx == n - 1) printf("%d\n", ans[i]);
    else printf("%d ", ans[i]);
  }
  return 0;
}

