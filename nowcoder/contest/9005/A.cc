
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

// lower_bound 大于等于
// upper_bound 大于

const LL INF = 0x3f3f3f3f3f3f3f3fll;
const double PI = acos(-1.0), eps = 1e-7;
const int inf = 0x3f3f3f3f, ninf = 0xc0c0c0c0, mod = 1000000007;
const int max3 = 2100, max4 = 11100, max5 = 200100, max6 = 2000100;

const ll MOD = 998244353;

class Solution {
 public:
  /**
   * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
   *
   * @param n long长整型 表示标准完全二叉树的结点个数
   * @return long长整型
   */
  long long tree4(long long n) {
    ll lev = 1;
    ll dep = 1;
    ll ans = 0;
    ll now = 1;
    while (now <= n) {
      ll num = min(n - now + 1, lev); //不是满的一行时，个数
      ll tmp = (now + now + num - 1) * num / 2 % MOD;
      ans = (ans + tmp * dep) % MOD;
      now += num;
      lev = lev * 2;
      dep++;
    }

    return ans;
  }
};