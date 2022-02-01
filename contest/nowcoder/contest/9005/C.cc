
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
   * 返回1-n的所有k*m的和
   * @param num long长整型 正整数 n
   * @return long长整型
   */
  long long cowModCount(long long num) {
    if (num <= 2) {
      return 0;
    }
    ll mid = sqrt(num * 1.0);
    ll ans = 0;

    ll p = num;
    for (ll i = 1; i <= mid; i++) {
      // a, a+i, a+2i, ..., a+(b-1)i
      ll next = num / (i + 1);
      ll a = num % p;
      ll b = num % (next + 1);
      ll tmp = (a + b) * (p - next) / 2 % mod;
      tmp = tmp * i % mod;
      ans = (ans + tmp) % mod;
      p = next;
    }
    while (p) {
      ll k = num / p;
      ll m = num % p;
      ll tmp = k * m % mod;
      ans = (ans + tmp) % mod;
      p--;
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
  TEST_SMP1(Solution, cowModCount, 0, 1);
  TEST_SMP1(Solution, cowModCount, 0, 2);
  TEST_SMP1(Solution, cowModCount, 1, 3);
  TEST_SMP1(Solution, cowModCount, 1, 4);
  TEST_SMP1(Solution, cowModCount, 5, 5);
  TEST_SMP1(Solution, cowModCount, 3, 6);
  TEST_SMP1(Solution, cowModCount, 11, 7);
  TEST_SMP1(Solution, cowModCount, 10, 8);
  TEST_SMP1(Solution, cowModCount, 16, 9);
  TEST_SMP1(Solution, cowModCount, 17, 10);
  TEST_SMP1(Solution, cowModCount, 34, 11);
  return 0;
}
