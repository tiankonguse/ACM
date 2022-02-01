
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

namespace KMP {
int next[max6];
//`next[i]的意义`
// s 为匹配串,t 为 s 的前 i 个字符组成的子串`
//`t = s[0]s[1]...s[i-1]`
//`设串 s[0]s[1]...s[k]和串 s[i-1-k]s[i-1-(k-1)]...s[i-1]相等，`
//`next[i]就是这样的 k 的最大值`
//
void get_next(const char* pat) {
  memset(next, -1, sizeof(next));
  for (int i = 1, k; pat[i]; ++i) {
    for (k = next[i - 1]; k >= 0 && pat[i] != pat[k + 1]; k = next[k])
      ;
    if (pat[k + 1] == pat[i]) next[i] = k + 1;
  }
} 

//`返回匹配的第一个位置`
//`返回匹配的个数 ans`
int kmp(char* str, char* pat) {
  get_next(pat);
  int i = 0, j = 0, ans = 0;
  while (str[i] && pat[j]) {
    if (pat[j] == str[i]) {
      ++i;
      if (!pat[++j]) ans++;
    } else if (j == 0)
      ++i;
    else
      j = next[j - 1] + 1;
  }
  // return ans;
  if (pat[j])
    return -1;
  else
    return i - j;
}

};  // namespace KMP

class Solution {
 public:
  /**
   * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
   * 给定一个字符串s，返回具有相同前缀后缀的子串的第二大长度，反之，返回-1即可。
   * @param s string字符串 代表题意中的字符串s
   * @return int整型
   */
  int solve(string& str) {
    if (str.length() == 1) {
      return -1;
    }
    // str.push_back('$');
    KMP::get_next(str.c_str());
    // printf("next: \n");
    // for (int i = 0; i <= str.length(); i++) {
    //   printf("%c: %d\n", str[i], KMP::next[i]);
    // }
    // printf("\n");
    int ans = KMP::next[str.length() - 1];
    if (ans >= 0) {
      return ans + 1;
    } else {
      return -1;
    }
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
  TEST_SMP1(Solution, solve, 1, string("ABA"));
    TEST_SMP1(Solution, solve, -1, string("ABC"));
    TEST_SMP1(Solution, solve, -1, string("A"));
    TEST_SMP1(Solution, solve, 5, string("AAAAAA"));
  return 0;
}
