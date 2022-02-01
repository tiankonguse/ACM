#include <algorithm>
#include <bitset>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef pair<long long, long long> pll;
typedef vector<pll> vpll;

typedef long double ld;
typedef vector<ld> vld;

typedef vector<bool> vb;

#define rep(i, n) for (ll i = 0; i < (n); i++)
#define reps(i, n) for (ll i = 1; i <= (n); i++)
#define rrep(i, n) for (ll i = (n)-1; i >= 0; i--)
#define rreps(i, n) for (ll i = (n); i >= 1; i--)
#define all(v) (v).begin(), (v).end()

template <class T>
void chmin(T& a, T b) {
  a = min(a, b);
}
template <class T>
void chmax(T& a, T b) {
  a = max(a, b);
}

constexpr int INF = 1 << 30;
constexpr ll INFL = 1LL << 60;
constexpr ll MOD = 1000000007;
constexpr ld EPS = 1e-12;
ld PI = acos(-1.0);

struct mint {
  static const long long mod = 1000000007;
  long long x;
  mint(long long x = 0) : x((x % mod + mod) % mod) {}
  mint operator-() const { return mint(-x); }
  mint& operator+=(const mint& a) {
    if ((x += a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator-=(const mint& a) {
    if ((x += mod - a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator*=(const mint& a) {
    (x *= a.x) %= mod;
    return *this;
  }

  friend const mint operator+(const mint& a, const mint& b) {
    mint ret = a;
    return ret += b;
  }
  friend const mint operator-(const mint& a, const mint& b) {
    mint ret = a;
    return ret -= b;
  }
  friend const mint operator*(const mint& a, const mint& b) {
    mint ret = a;
    return ret *= b;
  }
  friend ostream& operator<<(ostream& s, const mint& a) { return s << a.x; }

  mint pow(long long t) const {
    if (!t) return 1;
    mint a = pow(t >> 1);
    a *= a;
    if (t & 1) a *= *this;
    return a;
  }

  // for prime mod
  mint inv() const { return pow(mod - 2); }
  mint& operator/=(const mint a) { return (*this) *= a.inv(); }
  friend const mint operator/(const mint& a, const mint& b) {
    mint ret = a;
    return ret /= b;
  }
};

struct combi {
  const static long long mod = mint::mod;
  int n;
  vector<mint> fac, finv, inv;

  combi(int _n) : n(_n + 1), fac(n, 1), finv(n, 1), inv(n, 1) {
    for (int i = 2; i < n; ++i) {
      fac[i] = fac[i - 1] * i;
      inv[i] = -inv[mod % i] * (mod / i);
      finv[i] = finv[i - 1] * inv[i];
    }
  };

  mint get(int n, int k) {
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    mint ret = fac[n] * finv[k] * finv[n - k];
    return ret;
  }
};

void solve() {
  ll n, m;
  cin >> n >> m;
  vll a(n);
  rep(i, n) cin >> a[i];
  ll suma = 0;
  rep(i, n) suma += a[i];
  mint ans = 1;
  for (ll i = 0; i < suma + n; ++i) ans *= m + n - i;
  for (ll i = 1; i <= suma + n; ++i) ans /= i;
  cout << ans << endl;
  return;
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  cout << fixed << setprecision(15);
  solve();
}