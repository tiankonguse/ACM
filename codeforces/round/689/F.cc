
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

int str[max5];
char op[5] = {'+', '-', '*', '\0'};

int main() {
  int n;
  while (scanf("%d", &n) != EOF) {
    for (int i = 1; i <= n; i++) {
      scanf("%d", &str[i]);
    }
    scanf("%s", op);
    int len = strlen(op);
    sort(op, op + len);
    //*+-
    if (len == 1) {
      for (int i = 1; i <= n; i++) {
        printf("%d%c", str[i], i < n ? op[0] : '\n');
      }
    } else if (len == 2) {
      if (op[0] == '*' && op[1] == '+') {
        // 0 不能乘
        printf("%d", str[1]);
        for (int i = 2; i <= n; i++) {
          if (str[i - 1] == 0 || str[i] == 0) {
            printf("+");
          } else {
            printf("*");
          }
          printf("%d", str[i]);
        }
        printf("\n");
      } else if (op[0] == '*' && op[1] == '-') {
        // 中间有0：0 前是减号，0后是乘号，这样前半段就是正数
        // 首个字母是 0，全部乘号
        printf("%d", str[1]);
        bool haveZero = false;
        if (str[1] == 0) {
          haveZero = true;
        }
        for (int i = 2; i <= n; i++) {
          if (haveZero) {
            printf("*%d", str[i]);
            continue;
          }
          if (str[i] == 0) {
            printf("-%d", str[i]);
            haveZero = true;
          } else {
            printf("*%d", str[i]);
          }
        }
        printf("\n");
      } else if (op[0] == '+' && op[1] == '-') {
        //全部加号
        for (int i = 1; i <= n; i++) {
          printf("%d%c", str[i], i < n ? op[0] : '\n');
        }
      }
    } else if (len == 3) {
      //等价与 *+
      printf("%d", str[1]);
      for (int i = 2; i <= n; i++) {
        if (str[i - 1] == 0 || str[i] == 0) {
          printf("+");
        } else {
          printf("*");
        }
        printf("%d", str[i]);
      }
      printf("\n");
    }
  }
  return 0;
}