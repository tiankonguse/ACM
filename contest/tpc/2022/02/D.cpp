#include <bits/stdc++.h>

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
const int inf = 0x3f3f3f3f, ninf = 0xc0c0c0c0, mod = 998244353;
const int max3 = 2010, max4 = 20010, max5 = 200010, max6 = 2000010;
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

int n, k;

vector<int> nodes;
vector<vector<int>> g;  // {child, childTreeSize}

// DfsInit 计算出每条边子树的大小
int DfsInit(int u, int pre) {
  int& childNum = nodes[u];
  childNum = 1;

  for (auto v : g[u]) {
    if (v == pre) continue;
    childNum += DfsInit(v, u);
  }
  return childNum;
}

/*
A(n,r)=n(n-1)…(n-r+1)
A(n,r)=n!/(n-r)!
C(n,r)=A(n,r)/r!
*/

ll qpow(ll x, ll v, ll mod) {
  x = x % mod;
  ll y = 1;
  while (v) {
    if (v & 1) y = y * x % mod;
    x = x * x % mod;
    v >>= 1;
  }
  return y;
}
ll inv(ll x, ll mod) { return qpow(x, mod - 2, mod); }

vector<ll> A;
vector<ll> RA;

void InitA(int n, int mod) {
  A.resize(n + 1);
  A[0] = 1;

  for (int i = 1; i <= n; i++) {
    A[i] = (A[i - 1] * i) % mod;
  }

  RA.resize(n + 1);
  for (int i = 0; i <= n; i++) {
    RA[i] = inv(A[i], mod);
  }
}

ll C(ll n, ll r, ll mod) {
  ll Anr = A[n] * RA[n - r] % mod;
  return Anr * RA[r] % mod;
}
/*
定义：边删除时，儿子合并到父亲节点
目标：剩余的叶子的期望数量
公式：sum(所有方案: 一个方案叶子的个数)/方案总数
方案总数： C(n-1, k)
叶子个数：sum(所有顶点: 每个顶点是否是叶子)

  sum(所有方案: 一个方案叶子的个数)/方案总数
= sum(所有方案: sum(所有顶点: 每个顶点是否是叶子))/方案总数
= sum(所有顶点: sum(所有方案: 每个方案该顶点是否是叶子))/方案总数
= sum(所有顶点: 每个顶点作为叶子的方案数)/方案总数
*/

// delEdgeNum 确定需要删除的边数
ll DfsCal(int u, int pre, int delEdgeNum) {
  if (delEdgeNum > k) return 0;

  ll ans = 0;
  for (auto v : g[u]) {
    if (v == pre) continue;
    int otherChildNum = nodes[u] - nodes[v] - 1;
    int delChildNum = otherChildNum + delEdgeNum;
    if (delChildNum > k) continue;  // 不成立

    // 保留 u->v 这条边
    ans = (ans + C(n - 1 - delChildNum - 1, k - delChildNum, mod)) % mod;

    // 不保留 v，递归到儿子
    ans = (ans + DfsCal(v, u, delChildNum + 1)) % mod;
  }

  return ans;
}

// u 节点作为叶子的方案数
ll Cal(int u) {
  if (u == 0) {
    // 根节点比较特殊, 需要递归枚举计算保留的边
    return DfsCal(u, -1, 0);
  } else {
    //非根节点，想要作为叶子，需要所有儿子删除且父亲不删除
    int childEdge = nodes[u] - 1;
    if (childEdge > k) return 0;  // 无法称为叶子
    return C(n - 1 - childEdge - 1, k - childEdge, mod);
  }
}

void Solver() {  //
  scanf("%d", &n);
  scanf("%d", &k);

  InitA(n, mod);

  g.resize(n);
  nodes.resize(n);
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    u--, v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  DfsInit(0, -1);

  ll sum = 0;
  for (int i = 0; i < n; i++) {
    ll val = Cal(i);
    // printf("i=%d val=%lld\n", i + 1, val);
    sum = (sum + val) % mod;
  }
  ll all = C(n - 1, k, mod);
  // printf("sum=%lld\n", sum);
  // printf("all=%lld\n", all);
  // printf("mod=%d\n", mod);

  /*
  num/C(n-1, k)  % mod
  = num * inv(C(n-1, k), mod) % mod
  = num * qpow(C(n-1, k), mod - 2) % mod
  = num * qpow(C(n-1, k) % mod, mod - 2) % mod
  */

  ll ans = sum * inv(all, mod) % mod;
  printf("%lld\n", ans);
}

int main() {
  int t = 1;
  // scanf("%d", &t);

  while (t--) {
    Solver();
  }

  return 0;
}
