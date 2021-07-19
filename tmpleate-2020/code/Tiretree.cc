
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long long LL;
typedef unsigned long long ull;
typedef unsigned long long ULL;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
// const int mod = 1e9 + 7;

template <class T>
using min_queue = priority_queue<T, vector<T>, greater<T> >;
template <class T>
using max_queue = priority_queue<T>;

const LL INF = 0x3f3f3f3f3f3f3f3fll;
const double PI = acos(-1.0), eps = 1e-7;
const int inf = 0x3f3f3f3f, ninf = 0xc0c0c0c0, mod = 1000000007;
const int max3 = 2100, max4 = 11100, max5 = 200100, max6 = 2000100;

const int kind = 2, N = max5;

class TireTree {
 public:
  int tire[N][kind], word[N], tireVal[N];
  int num = 0;

  void init() {
    memset(tire[0], 0, sizeof(tire[0]));
    memset(tire[1], 0, sizeof(tire[1]));
    tireVal[1] = 1;
    num = 2;
  }
  void insert(ll n, ll val) {
    int p = 1;
    while (n) {
      int i = n % 2;
      if (!tire[p][i]) {
        memset(tire[num], 0, sizeof(tire[num]));
        word[num] = 0;
        tireVal[num] = tireVal[p] * 2 + i;
        tire[p][i] = num++;
      }
      p = tire[p][i];
      n = n / 2;
    }
    word[p] = val;
  }
};

TireTree tireTreeAll;


int main() {
  int n;

  return 0;
}