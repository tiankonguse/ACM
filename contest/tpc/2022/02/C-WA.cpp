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
struct SegTree {
  vector<ll> sign;
  vector<pair<ll, int>> minVal;
  vector<pair<ll, int>> maxVal;
  vector<ll> sumVal;
  vector<ll> nums;
  vector<ll> str;

  void Init(int n) {
    n++;
    maxNM = n;
    sign.resize(maxNM << 2, 0);
    minVal.resize(maxNM << 2);
    maxVal.resize(maxNM << 2);
    sumVal.resize(maxNM << 2, 0);
    nums.resize(maxNM << 2, 0);
    str.clear();
    str.resize(maxNM + 1, 0);
  }

  void PushUp(int rt) {
    minVal[rt] = min(minVal[rt << 1], minVal[rt << 1 | 1]);
    maxVal[rt] = max(maxVal[rt << 1], maxVal[rt << 1 | 1]);
    sumVal[rt] = sumVal[rt << 1] + sumVal[rt << 1 | 1];
  }
  void PushDown(int rt) {
    if (sign[rt]) {
      sign[rt << 1] += sign[rt];
      sign[rt << 1 | 1] += sign[rt];

      minVal[rt << 1].first += sign[rt];
      minVal[rt << 1 | 1].first += sign[rt];

      maxVal[rt << 1].first += sign[rt];
      maxVal[rt << 1 | 1].first += sign[rt];

      sumVal[rt << 1] += sign[rt] * nums[rt << 1];
      sumVal[rt << 1 | 1] += sign[rt] * nums[rt << 1 | 1];

      sign[rt] = 0;
    }
  }
  void Bulid(int l = 1, int r = maxNM, int rt = 1) {
    sign[rt] = 0;
    nums[rt] = r - l + 1;
    if (l == r) {
      sumVal[rt] = str[l];
      minVal[rt] = maxVal[rt] = {str[l], l};
      return;
    }
    int m = (l + r) >> 1;
    Bulid(lson);
    Bulid(rson);
    PushUp(rt);
  }
  void Update(int L, int R, int add, int l = 1, int r = maxNM, int rt = 1) {
    if (L <= l && r <= R) {
      sign[rt] += add;
      minVal[rt].first += add;
      maxVal[rt].first += add;
      sumVal[rt] += add * nums[rt];
      return;
    }
    PushDown(rt);
    int m = (l + r) >> 1;
    if (L <= m) Update(L, R, add, lson);
    if (R > m) Update(L, R, add, rson);
    PushUp(rt);
  }
  pair<ll, int> QueryMax(int L, int R, int l = 1, int r = maxNM, int rt = 1) {
    if (L <= l && r <= R) {
      return maxVal[rt];
    }
    PushDown(rt);
    int m = (l + r) >> 1;
    pair<ll, int> ret = {-1, 0};
    if (L <= m) {
      ret = max(ret, QueryMax(L, R, lson));
    }
    if (m < R) {
      ret = max(ret, QueryMax(L, R, rson));
    }
    return ret;
  }
  pair<ll, int> QueryMin(int L, int R, int l = 1, int r = maxNM, int rt = 1) {
    if (L <= l && r <= R) {
      return minVal[rt];
    }
    PushDown(rt);
    int m = (l + r) >> 1;
    pair<ll, int> ret = {__LONG_LONG_MAX__, 0};
    if (L <= m) {
      ret = min(ret, QueryMin(L, R, lson));
    }
    if (m < R) {
      ret = min(ret, QueryMin(L, R, rson));
    }
    return ret;
  }
  ll QuerySum(int L, int R, int l = 1, int r = maxNM, int rt = 1) {
    if (L <= l && r <= R) {
      return sumVal[rt];
    }
    PushDown(rt);
    int m = (l + r) >> 1;
    ll ret = 0;
    if (L <= m) {
      ret += QuerySum(L, R, lson);
    }
    if (m < R) {
      ret += QuerySum(L, R, rson);
    }
    return ret;
  }
};

SegTree segTree;
vector<ll> nums, cost;
int n, m;
int ans = 0;
vector<ll> dp;
vector<ll> counts;
vector<int> preDiff;
vector<ll> dpLeft, dpRight;

void Solver() {  //
  scanf("%d", &n);
  nums.resize(n + 1);
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &nums[i]);
  }
  scanf("%d", &m);
  for (int i = 0; i = m; i++) {
    scanf("%lld", &cost[i]);
  }

  // 计算上一个不同的位置
  preDiff.resize(n + 1, 0);
  for (int i = 2; i <= n; i++) {
    if (nums[i] == nums[i - 1]) {
      preDiff[i] = preDiff[i - 1];
    } else {
      preDiff[i] = i - 1;
    }
  }

  dp.clear();
  dp.resize(n + 1, 0);
  segTree.Init(n + 1);
  segTree.Bulid();

  dp[1] = min(cost[0], cost[1]);
  segTree.Update(1, 1, dp[1]);

  for (int i = 2; i <= n; i++) {
    dp[i] = dp[i - 1] + cost[0];  // 选择万能

    int now = i;
    int pre = preDiff[i];
    for (int k = 1; k <= m; k++) {  // 选择 k 个相同的
      // [pre+1, i] ~ [i,i]
      if (pre == 0) {   // 前缀都相等
        if (now > 1) {  // 至少预留一个
          auto [minVal, pos] = segTree.QueryMin(1, now - 1);
          dp[i] = min(dp[i], minVal + cost[k]);
        }
        dp[i] = min(dp[i], cost[k]);  // 全选择
        break;
      } else {
        auto [minVal, pos] = segTree.QueryMin(pre, now - 1);
        dp[i] = min(dp[i], minVal + cost[k]);
      }

      now = pre;
    }
    segTree.Update(i, i, dp[i]);
  }

  dpLeft.resize(n + 1, 0);
  dpRight.resize(n + 1, n + 1);

  for (int i = 2; i <= n; i++) {
    if (dp[i] == dp[i - 1]) {
      dpLeft[i] = dpLeft[i - 1];
    } else {
      dpLeft[i] = i - 1;
    }
  }
  for (int i = n - 2; i >= 1; i--) {
    if (dp[i] == dp[i + 1]) {
      dpLeft[i] = dpLeft[i + 1];
    } else {
      dpLeft[i] = i + 1;
    }
  }

  counts.resize(n+1, 0);
  if(cost[0] == cost[1]){
    counts[1] = 2;
  }else{
    counts[1] = 1;
  }


  for (int i = 2; i <= n; i++) {
    if(dp[i - 1] + cost[0] == dp[i]){
      counts[i]++; // 选择万能
    }

    int now = i;
    int pre = preDiff[i];
    for (int k = 1; k <= m; k++) {  // 选择 k 个相同的
      // [pre+1, i] ~ [i,i]
      if (pre == 0) {   // 前缀都相等
        if (now > 1) {  // 至少预留一个
          auto [minVal, pos] = segTree.QueryMin(1, now - 1);

          int l = dpLeft[pos] + 1;
          int l = dpRight[pos] - 1;

          dp[i] = min(dp[i], minVal + cost[k]);
        }
        if(dp[i] == cost[k]){

        }
        if(cost[k] == dp[i]){
          dp[i]++;
        }
        break;
      } else {
        auto [minVal, pos] = segTree.QueryMin(pre, now - 1);
        dp[i] = min(dp[i], minVal + cost[k]);
      }

      now = pre;
    }
  }

  ans = dp[n];
  printf("%lld %lld\n", ans, counts[n]);
}

int main() {
  int t;
  scanf("%d", &t);

  while (t--) {
    Solver();
  }

  return 0;
}
