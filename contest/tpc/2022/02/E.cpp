#include <bits/stdc++.h>

#pragma GCC optimize("O3")

using namespace std;

typedef __int128_t int128;

typedef vector<int> vi;
typedef vector<vi> vvi;

typedef pair<int, int> pii;
typedef vector<pii> vpii;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<pll> vpll;

typedef long double ld;
typedef vector<ld> vld;

typedef vector<bool> vb;
typedef vector<string> vs;

// const int mod = 1e9 + 7;

#define rep(i, n) for (ll i = 0; i < (n); i++)
#define rep1(i, n) for (ll i = 1; i <= (n); i++)
#define rrep(i, n) for (ll i = (n)-1; i >= 0; i--)
#define rrep1(i, n) for (ll i = (n); i >= 1; i--)
#define all(v) (v).begin(), (v).end()
#define ALL(A) A.begin(), A.end()
#define LLA(A) A.rbegin(), A.rend()
#define sz(x) (int)(x).size()
#define SZ(A) int((A).size())
#define CPY(A, B) memcpy(A, B, sizeof(A))
#define CTN(T, x) (T.find(x) != T.end())
#define PB push_back
#define MP(A, B) make_pair(A, B)
#define fi first
#define se second

template <class T>
using min_queue = priority_queue<T, vector<T>, greater<T>>;
template <class T>
using max_queue = priority_queue<T>;

int dir4[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int dir8[8][2] = {{0, 1},  {1, 1},   {1, 0},  {1, -1},
                  {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}};

template <class T>
inline void RST(T& A) {
  memset(A, 0, sizeof(A));
}
template <class T>
inline void FLC(T& A, int x) {
  memset(A, x, sizeof(A));
}
template <class T>
inline void CLR(T& A) {
  A.clear();
}
template <class T>
T& chmin(T& a, T b) {
  if (a == -1) {
    a = b;
  } else {
    a = min(a, b);
  }
  return a;
}
template <class T>
T& chmax(T& a, T b) {
  if (a == -1) {
    a = b;
  } else {
    a = max(a, b);
  }
  return a;
}

constexpr int INF = 1 << 30;
constexpr ll INFL = 1LL << 60;
constexpr ll MOD = 1000000007;
constexpr ld EPS = 1e-12;
ld PI = acos(-1.0);

const double pi = acos(-1.0), eps = 1e-7;
const int inf = 0x3f3f3f3f, ninf = 0xc0c0c0c0, mod = 1000000007;
const int max3 = 2010, max4 = 20010, max5 = 200010, max6 = 5000110;
// LONG_MIN(10进制 10位), LONG_MAX(10进制 19位)

/*
unordered_map / unordered_set

lower_bound 大于等于
upper_bound 大于
reserve 预先分配内存
reverse(all(vec)) 反转
sum = accumulate(a.begin(), a.end(), 0ll);
__builtin_popcount 一的个数
vector / array : upper_bound(all(vec), v)
map: m.upper_bound(v)

区间个数： std::distance(v.begin(), it)
map/set distance 复杂度 O(N)
vector/数组 distance 复杂度 O(1)

vector 去重
sort(nums.begin(), nums.end());
nums.erase(unique(nums.begin(), nums.end()), nums.end());

size_t found=str.find(string/char/char*);
std::string::npos

排序，小于是升序：[](auto&a, auto&b){ return a < b; })
优先队列 priority_queue<Node>：top/pop/push/empty
struct Node {
  Node(int t = 0) : t(t) {}
  int t;
  // 小于是最大堆，大于是最小堆
  bool operator<(const Node& that) const { return this->t < that.t; }
};

srand((unsigned)time(NULL));
rand();

mt19937 gen{random_device{}()};
uniform_real_distribution<double> dis(min, max);
function<double(void)> Rand = [that = this]() { return that->dis(that->gen); };

*/

// 朴素 GCD/gcd 算法，复杂度 Log(n))
ll Gcd(ll x, ll y) {
  if (!x || !y) return x ? x : y;
  for (ll t; (t = x % y); x = y, y = t)
    ;
  return y;
}

int n, q;
char str[max6];
char val[5];

const ll mod1e7 = 1000000007, mod1e9 = 1000000009;
const ll BASE = 29;
ll qpowCache[max6];
ll prehash[max6];
int facts[max6];
int factNum;

ll t1[max6], t2[max6];

class TreeArrayEx {
 public:
  void Init(int n_, ll mod_) {
    mod = mod_;
    n = n_;
    memset(t1, 0, sizeof(t1[0]) * (n + 100));
    memset(t2, 0, sizeof(t2[0]) * (n + 100));
  }

  void Add(int l, int r, ll v) {
    AddEx(l, v);
    AddEx(r + 1, mod - v);  // 将区间加差分为两个前缀加
  }

  ll Query(ll l, ll r) {
    ll ret = (r + 1ll) * QueryEx(t1, r) - 1ll * l * QueryEx(t1, l - 1) -
             (QueryEx(t2, r) - QueryEx(t2, l - 1));
    return (ret % mod + mod) % mod;
  }

 private:
  void AddEx(int k, ll v) {
    ll v1 = k * v % mod;
    while (k <= n) {
      t1[k] = (t1[k] + v + mod) % mod;
      t2[k] = (t2[k] + v1 + mod) % mod;
      k += Lowbit(k);
    }
  }
  ll QueryEx(ll* t, int k) {
    ll ret = 0;
    while (k) {
      ret = (ret + t[k]) % mod;
      k -= Lowbit(k);
    }
    return ret;
  }
  int Lowbit(int x) { return x & -x; }
  ll mod;
  int n;
};
TreeArrayEx treeArrayEx;

bool Check(int x, const ll h) {  //
  x = gcd(x, n);
  if (x == n) return true;

  // ll preX = prehash[x]; // 每个因子前缀的hash 值
  int p = lower_bound(facts, facts + factNum, x) - facts + 1;
  ll pre = treeArrayEx.Query(p, p);
  // printf("x=%d preX=%lld pre=%lld\n", x, preX, pre);
  ll preHalf = (h - pre * qpowCache[n - x] % mod1e7 + mod1e7) % mod1e7;

  return (preHalf * qpowCache[x] % mod1e7 + pre) % mod1e7 == h;
}

void Solver() {  //
  scanf("%d%d", &n, &q);
  scanf("%s", str);

  qpowCache[0] = 1;
  for (int i = 1; i <= n; i++) {
    qpowCache[i] = (qpowCache[i - 1] * BASE) % mod1e7;
  }

  ll h = 0;
  factNum = 0;
  for (int i = 1; i <= n; i++) {
    ll v = str[i - 1] - 'a' + 1;
    h = (h + v * qpowCache[i - 1]) % mod1e7;
    if (n % i == 0) {
      prehash[i] = h;
      facts[factNum] = i;
      factNum++;
    }
  }

  treeArrayEx.Init(factNum, mod1e7);
  for (int i = 1; i <= factNum; i++) {
    treeArrayEx.Add(i, i, prehash[facts[i - 1]]);
  }

  while (q--) {
    int op, x;
    scanf("%d", &op);
    if (op == 1) {
      scanf("%d%s", &x, val);
      ll oldVal = str[x - 1];
      ll newVal = val[0];
      str[x - 1] = val[0];

      ll dis = (newVal - oldVal + mod1e7) * qpowCache[x - 1] % mod1e7;

      int p = lower_bound(facts, facts + factNum, x) - facts + 1;
      treeArrayEx.Add(p, factNum, dis);

      // for (auto i : facts) {  // 维护所有因子前缀的 hash 值
      //   if (x > i) continue;
      //   prehash[i] = (prehash[i] + dis) % mod1e7;
      // }
      // for (int i = 1; i <= facts.size(); i++) {
      //   ll v = facts[i - 1];
      //   printf("i=%d v=%lld pre=%lld tree=%lld\n", i, v, prehash[v],
      //          treeArrayEx.Query(v, v));
      // }

      h = (h + dis) % mod1e7;
    } else {
      scanf("%d", &x);

      if (Check(x, h)) {
        printf("1\n");
      } else {
        printf("0\n");
      }
    }
  }
}

int main() {
  int t = 1;
  // scanf("%d", &t);

  while (t--) {
    Solver();
  }

  return 0;
}
