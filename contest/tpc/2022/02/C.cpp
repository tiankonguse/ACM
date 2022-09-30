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

// 1.bulid(); 2.query(a,b) 3.update(a,b)
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
const int maxn = 1e5 + 10;
const int kMaxVal = 10e8;

int maxNM;

typedef long long ll;

vector<ll> nums, cost;
int n, m;
int ans = 0;
vector<pair<ll, ll>> dp;
vector<vector<ll>> nextk;
vector<ll> flag;
int flagNum;

unordered_map<int, int> numsMap;  // 对数据离散化重新编号

int maxVal = 0;

void Update(int i, ll tmp, ll num) {
  if (tmp < dp[i].first) {
    dp[i] = {tmp, num};
  } else if (tmp == dp[i].first) {
    dp[i].second = (dp[i].second + num) % mod;
  }
}

void RealSolver() {
  // 第一步：对病毒库离散化， 下标从 0 开始，共 maxVal 种病毒
  numsMap.clear();
  for (int i = 1; i <= n; i++) {
    numsMap[nums[i]];
  }
  maxVal = 0;
  for (auto& [k, v] : numsMap) {
    v = maxVal++;
  }
  for (int i = 1; i <= n; i++) {
    nums[i] = numsMap[nums[i]];
    // printf("i=%d v=%lld\n", i, nums[i]);
  }

  // 第二步：预处理每个文件的 nextk
  nextk.clear();
  nextk.resize(m + 1, vector<ll>(n + 1, n + 1));

  for (int k = 1; k <= m; k++) {
    flag.clear();
    flag.resize(maxVal, 0);
    flagNum = 0;

    int l = 1, r = 1;
    while (l <= n && r <= n) {
      while (r <= n && flagNum <= k) {
        int v = nums[r];
        if (flag[v] == 0) {
          if (flagNum == k) {
            break;
          } else {
            flagNum++;
          }
        }
        r++;
        flag[v]++;
      }

      while (l < r && flagNum == k) {
        nextk[k][l] = r;  // 开区间
        int v = nums[l];
        l++;
        flag[v]--;
        if (flag[v] == 0) {
          flagNum--;
        }
      }
    }
  }

  // 第三步：dp 计算
  dp.clear();
  dp.resize(n + 2, {LONG_MAX, 0});

  dp[0] = {0, 1};
  for (int i = 1; i <= n; i++) {
    // 选择万能杀毒
    Update(i, cost[0] + dp[i - 1].first, dp[i - 1].second);
    for (int k = 1; k <= m; k++) {
      Update(nextk[k][i] - 1, cost[k] + dp[i - 1].first, dp[i - 1].second);
    }
  }
}

void Solver() {  //
  scanf("%d", &n);
  nums.resize(n + 1);

  for (int i = 1; i <= n; i++) {
    scanf("%lld", &nums[i]);
  }

  scanf("%d", &m);
  cost.resize(m + 1);
  for (int i = 0; i <= m; i++) {
    scanf("%lld", &cost[i]);
  }

  RealSolver();

  printf("%lld %lld\n", dp[n].first, dp[n].second);
}

int main() {
  int t;
  scanf("%d", &t);

  while (t--) {
    Solver();
  }

  return 0;
}
