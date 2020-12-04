
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
  int dis(char a, char b) {
    if (a > b) {
      return a - b;
    } else {
      return b - a;
    }
  }

 public:
  /**
   *
   * @param k int整型 表示最多的操作次数
   * @param s string字符串 表示一个仅包含小写字母的字符串
   * @return int整型
   */
  int string2(int k, const string& s) {
    int n = s.size();
    vector<int> nums;
    nums.resize(n, 0);
    int ans = 0;
    for (char c = 'a'; c <= 'z'; c++) {
      for (int i = 0; i < n; i++) {
        nums[i] = dis(c, s[i]);
      }
      sort(nums.begin(), nums.end());
      int sum = 0;
      for (int i = 0; i < n; i++) {
        sum += nums[i];
        if (sum > k) {
          break;
        }
        ans = max(ans, i + 1);
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
  TEST_SMP2(Solution, string2, 3, 2, string("abcde"));
  TEST_SMP2(Solution, string2, 4, 10, string("acesxd"));
  return 0;
}
