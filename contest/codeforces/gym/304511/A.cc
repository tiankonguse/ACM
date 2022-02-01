
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

void chkmax1(int& x, int y) {
  if (x < y) x = y;
}
void chkmax2(int& x, int y) {
  if (x > y) x = y;
}
void chkmax3(int x, int y) { x = std::max(x, y); }
void chkmin1(int& x, int y) {
  if (x > y) x = y;
}
void chkmin2(int& x, int y) {
  if (x < y) x = y;
}
void chkmin3(int x, int y) { x = std::min(x, y); }

typedef function<int(int, int, int)> MaxFun;

int main() {
  vector<MaxFun> vec;
  vec.push_back([](int a, int b, int c) -> int { return std::max({a, b, c}); });
  vec.push_back([](int a, int b, int c) -> int { return std::min({a, b, c}); });
  vec.push_back(
      [](int a, int b, int c) -> int { return std::max(a, std::max(b, c)); });
  vec.push_back([](int a, int b, int c) -> int {
    chkmax1(a, b);
    chkmax1(a, c);
    return a;
  });
  vec.push_back([](int a, int b, int c) -> int {
    chkmax2(a, b);
    chkmax2(a, c);
    return a;
  });
  vec.push_back([](int a, int b, int c) -> int {
    chkmax3(a, b);
    chkmax3(a, c);
    return a;
  });
  vec.push_back([](int a, int b, int c) -> int {
    chkmin1(a, b);
    chkmin1(a, c);
    return a;
  });
  vec.push_back([](int a, int b, int c) -> int {
    chkmin2(a, b);
    chkmin2(a, c);
    return a;
  });

  vec.push_back([](int a, int b, int c) -> int {
    chkmin3(a, b);
    chkmin3(a, c);
    return a;
  });
  vec.push_back([](int a, int b, int c) -> int {
    int d, e;
    if (a > b)
      d = a;
    else
      d = b;
    if (c > d)
      e = c;
    else
      e = d;
    return e;
  });

  char str[100];
  scanf("%s", str);

  int a, b, c;
  a = 123, b = 456, c = 789;
  vector<int> ans;
  for (int i = 0; i < vec.size(); i++) {
    if (vec[i](a, b, c) == c &&  //
        vec[i](a, c, b) == c &&  //
        vec[i](b, a, c) == c &&  //
        vec[i](b, a, c) == c &&  //
        vec[i](c, a, b) == c &&  //
        vec[i](c, b, a) == c &&  //
        true) {
      ans.push_back(i + 1);
    }
  }

  printf("%d\n", ans.size());
  for (int i = 0; i < ans.size(); i++) {
    printf("%d%c", ans[i], i == ans.size() - 1 ? '\n' : ' ');
  }

  return 0;
}