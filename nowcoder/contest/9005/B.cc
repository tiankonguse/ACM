
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
  void Add(string& x, char c, int k) {
    int sum = c - '0';
    for (int i = k; i < x.size(); i++) {
      sum += x[i] - '0';
      x[i] = '0' + (sum % 10);
      sum /= 10;
      if (sum == 0) {
        break;
      }
    }
    if (sum > 0) {
      x.push_back('0' + sum);
    }
  }

 public:
  /**
   * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
   * 返回最大和的字符串
   * @param x string字符串 即题目描述中所给字符串
   * @param k int整型 即题目描述中所给的k
   * @return string字符串
   */
  string Maxsumforknumers(string& x, int k) {
    sort(x.begin(), x.end());

    for (int i = 0; i < k - 1; i++) {
      Add(x, x[i], k - 1);
    }
    x = x.substr(k - 1);
    std::reverse(x.begin(), x.end());
    return x;
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
  TEST_SMP2(Solution, Maxsumforknumers, string("57"), string("345"), 2);
  TEST_SMP2(Solution, Maxsumforknumers, string("3338"), string("233333"), 3);
  TEST_SMP2(Solution, Maxsumforknumers, string("999888777666555444333222111"),
            string("111222333444555666777888999"), 1);
  return 0;
}
