
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
     * 返回将这个数n拆成两个自然数之和一共有多少种拆法（符合规则）。
     * @param n int整型 代表题意中的n
     * @return int整型
     */
    int solve(int n) {
        if(n == 1 || n == 2) {
            return 0;
        }
        if(n % 2 == 0){
            return n/2 - 1;
        }else{
            return n/2;
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
  TEST_SMP1(Solution, solve, 0, 1);
  TEST_SMP1(Solution, solve, 0, 2);
  TEST_SMP1(Solution, solve, 1, 3);
  TEST_SMP1(Solution, solve, 1, 4);
  TEST_SMP1(Solution, solve, 2, 5);
  return 0;
}
