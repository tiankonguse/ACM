
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

class Solution {
  vector<int> v;
  vector<int> g;
  vector<int> s;
  map<pair<int, int>, int> dp;
  int dfs(int n, int V) {
    pair<int, int> p = {n, V};
    if (dp.count(p)) {
      return dp[p];
    }

    if (V == 0) {
      return dp[p] = 0;
    }

    if (s[n] < V) {
      return dp[p] = -1;
    }

    if (n == 0) {
      if (v[0] == V) {
        return dp[p] = g[n];
      } else {
        return dp[p] = -1;
      }
    }
    int ans = dfs(n - 1, V);

    if (V >= v[n]) {
      int tmp = dfs(n - 1, V - v[n]);
      if (tmp >= 0) {
        ans = max(ans, tmp + g[n]);
      }
    }
    return dp[p] = ans;
  }

 public:
  /**
   * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
   * 返回总体积为V若干物品的最大总重量，如果g存在选择若干物品总体积为V的情况，返回-1
   * @param v int整型vector
   * @param g int整型vector
   * @param V int整型
   * @return int整型
   */
  int Maximumweight(vector<int>& v_, vector<int>& g_, int V) {
    v.swap(v_);
    g.swap(g_);

    int sum = 0;
    s.reserve(v.size());
    for (auto a : v) {
      sum += a;
      s.push_back(sum);
    }

    return dfs(v.size() - 1, V);
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
  TEST_SMP3(Solution, Maximumweight, 5, vector<int>({1, 2, 3}),
            vector<int>({2, 3, 4}), 3);
  TEST_SMP3(Solution, Maximumweight, -1, vector<int>({1, 3}),
            vector<int>({100, 300}), 2);
  return 0;
}
