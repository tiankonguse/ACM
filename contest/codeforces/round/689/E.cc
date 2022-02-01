
#include <bits/stdc++.h>

using namespace std;

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

const LL INF = 0x3f3f3f3f3f3f3f3fll;
const double PI = acos(-1.0), eps = 1e-7;
const int inf = 0x3f3f3f3f, ninf = 0xc0c0c0c0, mod = 1000000007;
const int max3 = 2100, max4 = 11100, max5 = 200100, max6 = 2000100;

int main() {
  ll k, l, r, t, x, y;
  while (scanf("%lld%lld%lld%lld%lld%lld", &k, &l, &r, &t, &x, &y) != EOF) {
    k -= l;
    r -= l;
    //此时将水位转换到 [0, r-l]

    if (k + y > r && k - x < 0) {
      printf("No\n");  //加水超了，不加水不够
      continue;
    }

    // 此时要么可以先加水，要么先可以喝水

    if (x > y) {  //水越来越少
      ll use = x - y;

      //可以先喝水
      if (k - x >= 0) {
        //在 x-1 水位之上，可以先喝水再加水
        // 可以和 (k - x) / use + 1次
        ll day = (k - x) / use + 1;
        if (day >= t) {
          printf("Yes\n");
          continue;
        }

        t -= day;
        k -= day * use;
      }

      //此时需要先加水，再喝水
      ll day = (k + y - x) / use + 1;
      if (day >= t) {
        printf("Yes\n");
        continue;
      } else {
        printf("No\n");
        continue;
      }

    } else if (x == y) {  //每天水位不变
      printf("Yes\n");
    } else if (x < y) {  //水约加越多，不能加的时候需要等几天
      //可以先喝水到临街之间
      int day = k / x;
      if (day >= t) {
        printf("Yes\n");  //不加水就到时间了
        continue;
      }

      t -= day;
      k -= day * x;

      // 此时必须加水了
      if (k + y > r) {
        printf("No\n");  //只能喝水，无法加水
        continue;
      }

      if(x - 1 + y <= r){
        printf("Yes\n");  //不能喝水的时候，加水都不会越界，那就可以一直喝水
        continue;
      }

      ll use = y - x;
      //一种极端情况是，水位越喝越高，但是又小于 x，但是 k + y > r 的情况
      // 需要判断，前 t 天，这个公式是否恒成立
      // (k + t * use) % x > r - y

    }
  }
  return 0;
}