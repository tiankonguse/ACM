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
int const N = 1010;
int a[N], b[N]; bool vis[N];
vector<pair<int, int> > ans1, ans2;
int main() {
  int n; scanf("%d", &n);
  Rep(i, n) scanf("%d", &a[i]);
  Rep(i, n) b[i] = a[i];
  sort(b + 1, b + n + 1);
  Rep(i, n) if (a[i] != b[i]) {
    Rep(j, n) if (a[i] == b[j] && a[j] == b[i]) {
      swap(a[i], a[j]);
      ans1.push_back(make_pair(i, j));
      break;
    }
  }
  Rep(i, n) if (a[i] != b[i]) {
     vector<int> v;
     int t = i;
     while (!vis[t] && a[t] != b[t]) {
       vis[t] = 1;
       v.push_back(t);
       if (v.size() > 1 && a[t] == b[i]) {
         break;
       }
       Rep(j, n) if (!vis[j] && a[t] == b[j] && a[j] != b[j]) {
         t = j; break;
       }
     }
     int sz = v.size();
     rep(j, sz / 2) ans1.push_back(make_pair(v[j], v[sz - j - 1]));
     rep(j, (sz - 1) / 2) ans2.push_back(make_pair(v[j + 1], v[sz - j - 1]));
  }
  if (ans1.size() == 0) puts("0");
  else if (ans2.size() == 0) {
    puts("1");
    printf("%d", (int)ans1.size());
    rep(i, ans1.size()) printf(" %d %d", ans1[i].first, ans1[i].second);
    puts("");
  } else {
    puts("2");
    printf("%d", (int)ans1.size());
    rep(i, ans1.size()) printf(" %d %d", ans1[i].first, ans1[i].second);
    puts("");
    printf("%d", (int)ans2.size());
    rep(i, ans2.size()) printf(" %d %d", ans2[i].first, ans2[i].second);
    puts("");
  }
  return 0;
}

