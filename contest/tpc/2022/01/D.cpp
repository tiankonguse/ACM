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
const int inf = 0x3f3f3f3f, ninf = 0xc0c0c0c0, mod = 1000000007;
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

class Solution {
 public:
  int smallestRepunitDivByK(int K) { return -1; }
};

int n, r;
vector<int> as;
vector<vector<int>> g;
vector<vector<tuple<int, int, int>>> childs;
ll ans;

pair<int, int> Dfs(int u, int p) {
  int ret_one = 0;
  int ret_zero = 0;
  if (as[u] == 1) {
    ret_one++;
  } else {
    ret_zero++;
  }

  auto& child = childs[u];
  child.reserve(g[u].size());
  for (auto& v : g[u]) {
    if (v == p) continue;
    auto [one, zero] = Dfs(v, u);
    child.push_back({zero, one, v});
  }

  sort(child.begin(), child.end(), [](auto& a, auto& b) {
    auto [a0, a1, ap] = a;
    auto [b0, b1, bp] = b;
    return a1 * b0 > b1 * a0;
  });

  for (auto [zero, one, v] : child) {
    ans += ret_one * zero;
    ret_one += one;
    ret_zero += zero;
  }
  return {ret_one, ret_zero};
}

vector<int> ansNums;
void DfsPrintf(int u, int p) {
  ansNums.push_back(u);
  for (auto& [zero, one, v] : childs[u]) {
    if (v == p) continue;
    DfsPrintf(v, u);
  }
}

void Solver() {  //
  scanf("%d%d", &n, &r);
  r--;

  as.resize(n);
  g.clear();
  g.resize(n);
  childs.clear();
  childs.resize(n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &as[i]);
  }
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    u--, v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  ans = 0;
  Dfs(r, -1);
  printf("%lld\n", ans);

  ansNums.clear();
  ansNums.reserve(n);
  DfsPrintf(r, -1);
  for (int i = 0; i < n; i++) {
    printf("%d%c", ansNums[i]+1, i + 1 == n ? '\n' : ' ');
  }
}

int main() {
  int t;
  scanf("%d", &t);

  while (t--) {
    Solver();
  }

  return 0;
}
