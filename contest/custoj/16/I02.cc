#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <deque>
#include <set>
#include <functional>
#include <unordered_map>
#include <unordered_set>
#include <cassert>
#include <ctime>
#include <queue>
#include <stack>
#include <iomanip>
#include <sstream>
#include <cmath>
#include <fstream>
#include <bitset>
#include <complex>
#include <numeric>
//#include "utils/haha.h"
//#include "utils/max_flow.h"
using namespace std;
typedef pair<int, int> PII;
typedef pair<string, string> PSS;
typedef pair<string, int> PSI;
typedef pair<int, PII> PIP;
typedef long long ll;
typedef pair<int, ll> PIL;
typedef pair<ll, ll> PLL;
typedef pair<double, double> PDD;
typedef pair<ll, PII> PLP;

template<typename T>
inline T read_by_char() {
  T s = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    s = (s << 3) + (s << 1) + ch - 48;
    ch = getchar();
  }
  return s * f;
}
#define ri() read_by_char<int>()
#define rl() read_by_char<ll>()

#define CLS(x, v) (memset((x), (v), sizeof((x))))

template<class TH>
void _dbg(const char *sdbg, TH h) { cerr << sdbg << '=' << h << endl; }
template<class TH, class... TA>
void _dbg(const char *sdbg, TH h, TA... a) {
  while (*sdbg != ',')cerr << *sdbg++;
  cerr << '=' << h << ',';
  _dbg(sdbg + 1, a...);
}

template<class T>
ostream &operator<<(ostream &os, vector<T> V) {
  os << "[";
  for (auto vv : V) os << vv << ",";
  return os << "]";
}
template<class L, class R>
ostream &operator<<(ostream &os, pair<L, R> P) {
  return os << "(" << P.first << "," << P.second << ")";
}

#ifdef _zzz_
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (__VA_ARGS__)
#define cerr if(0)cout
#endif

template<class T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;
template<class T>
using max_heap = priority_queue<T>;
//const int N = 1e6 + 1e5 + 10;
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

struct PairHash {
  template<typename T1, typename T2>
  std::size_t operator()(const pair<T1, T2> &p) const {
    return hash<T1>()(p.first) ^ hash<T2>()(p.second);
  }
};

template<unsigned MOD_>
struct ModInt {
  static constexpr unsigned MOD = MOD_;
  unsigned x;
  void undef() { x = (unsigned) -1; }
  bool isnan() const { return x == (unsigned) -1; }
  inline int geti() const { return (int) x; }
  ModInt() { x = 0; }
  ModInt(const ModInt &y) { x = y.x; }
  ModInt(int y) {
    if (y < 0 || (int) MOD <= y) y %= (int) MOD;
    if (y < 0) y += MOD;
    x = y;
  }
  ModInt(unsigned y) { if (MOD <= y) x = y % MOD; else x = y; }
  ModInt(long long y) {
    if (y < 0 || MOD <= y) y %= MOD;
    if (y < 0) y += MOD;
    x = y;
  }
  ModInt(unsigned long long y) { if (MOD <= y) x = y % MOD; else x = y; }
  ModInt &operator+=(const ModInt y) {
    if ((x += y.x) >= MOD) x -= MOD;
    return *this;
  }
  ModInt &operator-=(const ModInt y) {
    if ((x -= y.x) & (1u << 31)) x += MOD;
    return *this;
  }
  ModInt &operator*=(const ModInt y) {
    x = (unsigned long long) x * y.x % MOD;
    return *this;
  }
  ModInt &operator/=(const ModInt y) {
    x = (unsigned long long) x * y.inv().x % MOD;
    return *this;
  }
  ModInt operator-() const { return (x ? MOD - x : 0); }

  ModInt inv() const { return pow(MOD - 2); }
  ModInt pow(long long y) const {
    ModInt b = *this, r = 1;
    if (y < 0) {
      b = b.inv();
      y = -y;
    }
    for (; y; y >>= 1) {
      if (y & 1) r *= b;
      b *= b;
    }
    return r;
  }

  friend ModInt operator+(ModInt x, const ModInt y) { return x += y; }
  friend ModInt operator-(ModInt x, const ModInt y) { return x -= y; }
  friend ModInt operator*(ModInt x, const ModInt y) { return x *= y; }
  friend ModInt operator/(ModInt x, const ModInt y) { return x *= y.inv(); }
  friend bool operator<(const ModInt x, const ModInt y) { return x.x < y.x; }
  friend bool operator==(const ModInt x, const ModInt y) { return x.x == y.x; }
  friend bool operator!=(const ModInt x, const ModInt y) { return x.x != y.x; }
};
const int mod = (1e9) + 7;
typedef ModInt<mod> mod_int;

vector<vector<string>> nets{
    {
        "x...",
        "xxxx",
        "x...",
        "...."
    },
    {
        "x...",
        "xxxx",
        ".x..",
        "...."
    },
    {
        "x...",
        "xxxx",
        "..x.",
        "...."
    },
    {
        "x...",
        "xxxx",
        "...x",
        "...."
    },
    {
        ".x..",
        "xxxx",
        "..x.",
        "...."
    },
    {
        "xx..",
        ".xxx",
        ".x..",
        "...."
    },
    {
        "xx..",
        ".xxx",
        "..x.",
        "...."
    },
    {
        "xx..",
        ".xxx",
        "...x",
        "...."
    },
    {
        "xx..",
        ".xx.",
        "..xx",
        "...."
    },
    {
        "xxx.",
        ".xxx",
        "....",
        "...."
    },
    {
        ".x..",
        "xxxx",
        ".x..",
        "...."
    },

};

vector<string> flip(const vector<string> &net) {
  vector<string> ret = net;
  for (int i = 0; i < 2; i++) {
    swap(ret[i], ret[4 - i - 1]);
  }
  return ret;
}
vector<string> rotate_clockwise(const vector<string> &net) {
  vector<string> ret = net;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      ret[j][3 - i] = net[i][j];
    }
  }
  return ret;
}

vector<string> rotate(const vector<string> &net, int k) {
  vector<string> ret = net;
  for (int i = 0; i < k; i++) {
    ret = rotate_clockwise(net);
  }
  return ret;
}

int n, m;
int ret;

vector<string> a;
void get_o(int x, int y, vector<string> &b) {
  if (x < 0 || x >= n || y < 0 || y >= m || a[x][y] == '.') return;
  b[x][y] = a[x][y];
  a[x][y] = '.';
  get_o(x - 1, y, b);
  get_o(x + 1, y, b);
  get_o(x, y - 1, b);
  get_o(x, y + 1, b);

}

bool can_put1(vector<string> &b, int x, int y, vector<string> &net, int dx, int dy) {
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      if (net[i][j] == '.') continue;
      int tx = x - dx + i;
      int ty = y - dy + j;
      if (tx < 0 || tx >= n || ty < 0 || ty >= m || b[tx][ty] == '.') return false;
    }
  }
  return true;
}

bool can_put(vector<string> &b, int x, int y, vector<string> &net) {
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      if (net[i][j] == '.') continue;
      return can_put1(b, x, y, net, i, j);
    }
  }
}

int check(vector<string> &b) {
  for (int i = 0; i < b.size(); i++) {
    for (int j = 0; j < b[i].size(); j++) {
      if (b[i][j] != '.') {
        for (int k = 0; k < nets.size(); k++) {
          if (can_put(b, i, j, nets[k])) return 1;
        }
      }
    }
  }
  return 0;
}
int dfs() {
  for (int x = 0; x < n; x++)
    for (int y = 0; y < m; y++)
      if (a[x][y] != '.') {
        vector<string> b(n, string(m, '.'));
        get_o(x, y, b);
        ret += check(b);
      }
}

void solve(int ncase) {
  int N = 11;
  for (int i = 0; i < N; i++) {
    nets.push_back(flip(nets[i]));
  }
  //debug(nets.size());
  for (int i = 0; i < N + N; i++) {
    //debug(i, nets[i]);
    for (int k = 1; k <= 3; k++) {
      nets.push_back(rotate(nets[i], k));
    }
  }

  cin >> n >> m;
  a.assign(n, "");
  for (int i = 0; i < n; i++) {
    string s;
    cin >> a[i];
  }
  dfs();
  cout << ret << endl;
}

void solve_all_cases() {
  int T = 1;
  //scanf("%d", &T);
  //cin >> T;
  int ncase = 0;
  //pre_calc();
  while (T--) {
    solve(++ncase);
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout << std::fixed;
  cout << setprecision(2);
#ifdef _zzz_
  //ios_base::sync_with_stdio(true);
  freopen("C:\\Users\\grain\\Desktop\\in.txt", "r", stdin);
  //auto x = freopen("C:\\Users\\grain\\Desktop\\out.txt", "w", stdout);
  //cerr << x << " " << errno << endl;
  auto start_time = clock();
#endif
  solve_all_cases();
  //test();
#ifdef _zzz_
  cout << (clock() - start_time) * 1.0 / CLOCKS_PER_SEC << " seconds" << endl;
#endif
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/