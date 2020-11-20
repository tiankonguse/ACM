
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
 public:
  /**
   * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
   *
   * @param k int整型 表示完全k叉树的叉数k
   * @param a int整型vector 表示这棵完全k叉树的Bfs遍历序列的结点编号
   * @return long长整型
   */
  long long tree2(int k, vector<int>& a) {
    long long ans = 0;

    for (int i = 0; i < a.size(); i++) {
      int j = i * k + 1;
      for (int index = 0; index < k && j < a.size(); index++, j++) {
        ans += a[i] ^ a[j];
      }
    }

    return ans;
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
  TEST_SMP2(Solution, tree2, 18, 2, vector<int>({1, 2, 3, 4, 5}));
  TEST_SMP2(Solution, tree2, 18, 2, vector<int>({1, 2, 3, 4, 5}));
  return 0;
}
