#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <numeric>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <list>
#include <map>
#include <set>

using namespace std;

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<int, ll> pil;
typedef pair<ll, ll> pll;

void norm(int *f) {
  for (int m = (1 << 12) - 1; m >= 0; m--) {
    int res = 0;
    for (int sub = m;; sub = (sub - 1) & m) {
      res += f[sub];
      if (!sub) break;
    }
    f[m] = res;
  }
}

int fir[(1 << 12) + 10], las[(1 << 12) + 10];
int fpc[12][(1 << 12) + 10];
int lpc[12][(1 << 12) + 10];

int main() {
  #ifdef DEBUG
  freopen(".in", "r", stdin);
  freopen(".out", "w", stdout);
  #endif

  int n;
  while (scanf("%d", &n) >= 1) {
    memset(fir, 0, sizeof fir);
    memset(las, 0, sizeof las);
    memset(fpc, 0, sizeof fpc);
    memset(lpc, 0, sizeof lpc);

    const int FIM = (1 << 12) - 1;
    const int LAM = FIM << 12;

    vi msks(n);
    for (int i = 0; i < n; i++) {
      char s[4];
      scanf("%s", s);
      int msk = 0;
      for (int i2 = 0; s[i2]; i2++)
        msk |= 1 << (s[i2] - 'a');
      msks[i] = msk;

      int a = msk & FIM, b = (msk & LAM) >> 12;
      int apos = __builtin_ctz(a);
      int bpos = __builtin_ctz(b);

      if (__builtin_popcount(a) == 0) {
        las[b]++;
      } else if (__builtin_popcount(b) == 0) {
        fir[a]++;
      } else if (__builtin_popcount(a) == 1) {
        lpc[apos][b]++;
      } else if (__builtin_popcount(b) == 1) {
        fpc[bpos][a]++;
      } else {
        assert(false);
      }
    }
    eprintf("go\n");
    norm(fir);
    norm(las);
    for (int i = 0; i < 12; i++)
      norm(fpc[i]), norm(lpc[i]);
    eprintf("go2\n");

    int ans = 0;
    for (int m = 0; m < (1 << 24); m++) { // consonant is 1, vowel is 0
      int cnt = 0;
     
      // cnt <-- number of bad, that is, subsets if 'm'
      cnt += fir[m & FIM];
      cnt += las[(m & LAM) >> 12];
      for (int i = 0; i < 12; i++) if (m & (1 << i))
        cnt += lpc[i][(m & LAM) >> 12];
      for (int i = 0; i < 12; i++) if (m & (1 << (12 + i)))
        cnt += fpc[i][m & FIM];

//      eprintf("cnt=%d\n", cnt);
      cnt = n - cnt;

/*      int rcnt = 0;
      for (int i = 0; i < n; i++) {
        rcnt += ((~m & msks[i]) != 0);
      }
      if (cnt != rcnt) {
        eprintf("m=%d; found %d != expected %d\n", ~m & (FIM | LAM), cnt, rcnt);
        exit(0);
      }*/
      ans ^= cnt * cnt;
    }
    printf("%d\n", ans);
  }
  return 0;
}
