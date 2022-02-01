
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

char str[max5];

ll baseLen = 10000000000;

bool checkBegin(char* p, int n) {  //检查 是否是 110
  while (n) {
    if (n == 1) {
      return p[0] == '1';
    } else if (n == 2) {
      return p[0] == '1' && p[1] == '1';
    } else {
      if (p[0] == '1' && p[1] == '1' && p[2] == '0') {
        n -= 3;
        p += 3;
      } else {
        return false;
      }
    }
  }
  return true;
}

bool check(char* p, int n) {  //检查是否是任意的 110 子串
  if (n == 1) {
    return true;
  } else if (n == 2) {
    if (p[0] == '0' && p[1] == '0') {
      return false;  // 00
    } else {
      return true;  // 01 10 11
    }
  } else if (p[0] == '1' && p[1] == '1') {  // 110
    return checkBegin(str, n);
  } else if (p[0] == '0' && p[1] == '1') {  // 011
    return checkBegin(str + 1, n - 1);
  } else if (p[0] == '1' && p[1] == '0') {  // 101
    return checkBegin(p + 2, n - 2);
  } else {
    return false;
  }
}

ll solver(char* p, int n) {
  if (n == 1) {
    if (p[0] == '0') {
      return baseLen;
    } else {
      return baseLen * 2;
    }
  } else if (n == 2) {
    if (p[0] == '1' && p[1] == '1') {
      return baseLen;
    } else if (p[0] == '1' && p[1] == '0') {
      return baseLen;
    } else {
      return baseLen - 1;
    }
  } else {
    if (p[0] == '1' && p[1] == '1') {  // 11
      return 1 + (3 * baseLen - n) / 3;
    } else if (p[0] == '1' && p[1] == '0') {  // 10
      return 1 + (3 * baseLen - 1 - n) / 3;
    } else {  // 01
      return 1 + (3 * baseLen - 2 - n) / 3;
    }
  }

  return 0;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  // freopen("out_std.txt", "w", stdout);
#endif
  int n;
  while (~scanf("%d%s", &n, str)) {
    if (!check(str, n)) {
      printf("0\n");
    } else {
      printf("%lld\n", solver(str, n));
    }
  }
  return 0;
}
