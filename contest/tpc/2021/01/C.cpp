#include <bits/stdc++.h>
#include <stdio.h>

using namespace std;

typedef long long ll;
typedef long long LL;
typedef unsigned long long ull;
typedef unsigned long long ULL;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
// const int mod = 1e9 + 7;

template <class T>
using min_queue = priority_queue<T, vector<T>, greater<T>>;
template <class T>
using max_queue = priority_queue<T>;

// lower_bound 大于等于
// upper_bound 大于
// reserve vector预先分配内存
// reverse(v.begin(), v.end()) 反转
// sum = accumulate(a.begin(), a.end(), 0);

const LL INF = 0x3f3f3f3f3f3f3f3fll;
const double PI = acos(-1.0), eps = 1e-7;
const int inf = 0x3f3f3f3f, ninf = 0xc0c0c0c0, mod = 1000000007;
const int max3 = 2100, max4 = 11100, max5 = 200100, max6 = 2000100;

vector<int> str;
bool check(int n, int k) {
  int maxNum = n * (n - 1) / 2;
  if (k > maxNum) {
    printf("No\n");
    return false;
  }

  for (int a = 0; a <= n; a++) {              // 2
    for (int b = 0; b + a <= n; b++) {        // 98
      for (int c = 0; c + a + b <= n; c++) {  // 7
        int ans = a * (a - 1) / 2 + a * b + b * (b - 1)/2 + a * c;
        if (ans == k) {
          printf("Yes\n");
          int one = n - a - b - c;
          str.clear();
          while (one--) {
            str.push_back(1);
          }
          while (a--) {
            str.push_back(2);
          }
          while (b--) {
            str.push_back(98);
          }
          while (c--) {
            str.push_back(7);
          }
          for (int i = 0; i < n; i++) {
            printf("%d%c", str[i], i + 1 == n ? '\n' : ' ');
          }

          return true;
        }
      }
    }
  }
  printf("No\n");
  return false;
}



int main() {
#ifndef ONLINE_JUDGE
  // freopen("./in.txt", "r", stdin);
  // freopen("./out.txt", "w", stdout);
#endif
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, k;
    scanf("%d%d", &n, &k);
    check(n, k);
  }

  // #ifndef ONLINE_JUDGE
  //   freopen("./diff.txt", "w", stdout);
  //   system("diff ./out_std.txt ./out.txt | wc -l");
  //   system("diff ./out_std.txt ./out.txt");
  // #endif

  return 0;
}

/*
input:
3
1
0
20

output:
You are the future of Tencent!
Good luck and Enjoy TPC!
You are the future of Tencent!
*/