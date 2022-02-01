
#include "base.h"

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

ll dp[max3][max3];

class Solution {
  int k;
  ll dfs(int n, int m) {
    if (n < 0 || m < 0) {
      return 0;
    }
    if (dp[n][m] != -1) {
      return dp[n][m];
    }
    if (n < m) {
      return dp[n][m] = 0;
    }
    if (m == 1) {
      return dp[n][m] = n;
    }

    ll sum = dfs(n - 1, m) + dfs(n - 1 - k, m - 1);
    return dp[n][m] = sum % mod;
  }

 public:
  /**
   *
   * @param n int整型 乐谱总音符数
   * @param m int整型 重音符数
   * @param k int整型 重音符之间至少的间隔
   * @return long长整型
   */
  long long solve_bangbang(int n, int m, int k_) {
    if(m == 0){
      return 1;
    }
    memset(dp, -1, sizeof(dp));
    k = k_;
    return dfs(n, m);
  }
};

/*
    TEST_SMP1(ClassName, FunNAme, expectAns, firstData)
    TEST_SMP2(ClassName, FunNAme, expectAns, firstData, secondData)

    int first;
    int expectAns;


    first = 1;
    expectAns = 1;
    TEST_SMP1(Solution, smallestRepunitDivByK, expectAns, first);
*/
int main() {
  TEST_SMP3(Solution, solve_bangbang, 1, 3, 2, 1);
  TEST_SMP3(Solution, solve_bangbang, 3, 3, 2, 0);
  TEST_SMP3(Solution, solve_bangbang, 6, 4, 2, 0);
  TEST_SMP3(Solution, solve_bangbang, 1, 4, 0, 0);
  TEST_SMP3(Solution, solve_bangbang, 100, 100, 1, 0);
  return 0;
}
