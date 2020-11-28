
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

/*
 树状数组：解决单点更新，区间和查询问题
 
 */

class TreeArray {
 public:
  void init(int n_) {
    n = n_;
    memset(c, 0, sizeof(ll) * (n + 2));
  }

  ll query(int x) {
    ll s = 0;
    while (x > 0) {
      s += c[x];
      x -= Lowbit(x);
    }
    return s;
  }

  ll query(int l, int r) { return query(r) - query(l - 1); }

  void add(int x, ll v) {
    while (x <= n) {
      c[x] += v;
      x += Lowbit(x);
    }
  }

 private:
  int Lowbit(int x) { return x & -x; }
  ll c[max4];
  int n;
};

int main() {
  TreeArray treeArray;

  treeArray.init(11);
  treeArray.add(1, 2);
  treeArray.add(3, 5);
  printf("%lld\n", treeArray.query(5));

  return 0;
}