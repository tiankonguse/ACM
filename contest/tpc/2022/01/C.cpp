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

vector<int> nums, nums1, nums2;
char str[max6];
unsigned h[max6];
int n;

bool SameChar() {
  char pre = str[0];
  for (int i = 0; i < n; i++) {
    if (str[i] != pre) return false;
  }
  return true;
}

bool IsFirstMin() {
  char minVal = str[0];
  for (int i = 0; i < n; i++) {
    minVal = min(minVal, str[i]);
  }
  return minVal == str[0];
}

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
unsigned H(int l, int r) {
  if (l == 0) return h[r];
  unsigned pre = h[l - 1] * qpow(26, r - l + 1, mod) % mod;
  return(h[r] - pre + mod) % mod;
}

bool CheckLess(int len) {
  int l = 1, r = len;  // 二分长度，判断是否相等

  while (l < r) {
    int mid = (l + r) / 2;
    unsigned prefixHash = H(0, mid - 1);  //
    unsigned suffixHash = H(len - mid, len - 1);
    if (prefixHash == suffixHash) {
      l = mid + 1;
    } else {
      r = mid;
    }
  }
  char prefixVal = str[l - 1];
  char suffixVal = str[len - l];
  if (prefixVal > suffixVal) {
    return true;
  } else {
    return false;
  }
}

bool IsOneStep() {
  int nn = n * 2;

  // 填充逆序串
  for (int i = n, j = n - 1; i < nn; i++, j--) {
    str[i] = str[j];
  }
  str[nn] = '\0';

  unsigned pre = 0;
  for (int i = 0; i < nn; i++) {
    pre = (pre * 26 + (str[i] - 'a')) % mod;
    h[i] = pre;
  }

  for (int i = n + 1; i < nn; i++) {
    if (CheckLess(i)) {
      return true;
    }
  }

  return false;
}

bool IsOK() {
  for (int i = 0; i < n; i++) {
    if (str[i] > str[n - 1 - i]) return true;
    if (str[i] < str[n - 1 - i]) return false;
  }
  return false;
}

int Check() {
  n = strlen(str);

  // 无答案
  char pre = str[0];
  if (SameChar()) {
    return -1;
  }

  if (IsOK()) {
    return 0;
  }

  if (!IsFirstMin()) {
    return 1;
  }
  if (IsOneStep()) {
    return 1;
  }

  return 2;
}

void Solver() {  //
  scanf("%s", str);

  int ans = Check();
  if (ans == -1) {
    printf("Impossible\n");
  } else {
    printf("%d\n", ans);
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
