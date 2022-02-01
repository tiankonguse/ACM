
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
   *
   * @param a long长整型 木棒的长度
   * @return int整型
   */
  int stick(long long n) {
    long long a = 1, b = 1, c = 2;
    long long sum = 2;
    int ans = 2;

    while (sum + c <= n) {
      ans++;
      sum += c;
      a = b, b = c, c = a + b;
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
  TEST_SMP1(Solution, stick, 2, 3);
  TEST_SMP1(Solution, stick, 3, 4);
  TEST_SMP1(Solution, stick, 3, 5);
  TEST_SMP1(Solution, stick, 3, 6);
  TEST_SMP1(Solution, stick, 4, 7);
  TEST_SMP1(Solution, stick, 4, 8);
  return 0;
}
