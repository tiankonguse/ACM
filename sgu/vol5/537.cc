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
char s[110]; int cc[110];
vector<ll> ans;
ll fac[110], fnt;
struct Node {
  ll f; int c;
} p[110];
int pnt;

void gen(int d, ll s) {
  if (d == pnt) {
    ans.push_back(s);
    return;
  }
  rep(i, p[d].c + 1) {
    gen(d + 1, s);
    s *= p[d].f;
  }
}

int main() {
  int T, ca = 1; scanf("%d", &T);
  while (T--) {
    scanf(" %s", s);
    ll g = 0; int cnt = 0;
    int n = strlen(s);
    rep(i, 26) {
      ll b = 1, w = 0;
      for (int j = n - 1; j >= 0; --j) {
        if (s[j] == 'a' + i) {
          w += b;
        }
        b *= 10LL;
      } 
      if (w > 0) g = __gcd(g, w), cnt++;
    }
    ans.clear(); fnt = 0;
    for (ll i = 2; i * i <= g; ++i) {
      while (g % i == 0) {
        fac[fnt++] = i;
        g /= i;
      }
    }
    if (g > 1) fac[fnt++] = g;
    sort(fac, fac + fnt);
    pnt = 0;
    rep(i, fnt) {
      if (i == 0 || fac[i] != fac[i - 1]) {
        p[pnt].f = fac[i];
        p[pnt++].c = 1;
      } else p[pnt - 1].c++;
    }
    gen(0, 1);

    if (cnt == 10) {
      if (n == 10) {
        ans.push_back(3);
        ans.push_back(9);
      } else {
        bool ok = 1;
        rep(i, 26) cc[i] = 0;
        rep(i, n) cc[s[i] - 'a']++;
        rep(i, 26) if (cc[i] > 0 && cc[i] % 3 != 1) ok = 0;
        if (ok) ans.push_back(3);
      }
    }
    sort(ans.begin(), ans.end());
    printf("Case %d:", ca++);
    rep(i, ans.size()) printf(" %lld", ans[i]);
    puts("");
  }
  return 0;
}

