
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

char str[max3];

char maxC;
char TryMin(char c) {
  if (c == 'a') {
    return 'a';  // NONE
  }
  if (c == maxC) {
    return 'a';  // UP
  }
  return c - 1;  // DWON
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  // freopen("out_std.txt", "w", stdout);
#endif

#ifndef ONLINE_JUDGE
  // diff out.txt out_std.txt
#endif
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, k;
    scanf("%d%d", &n, &k);
    scanf("%s", str);

    maxC = 'a' + k - 1;
    str[n] = 'z';
    for (int i = 0; i < n; i++) {
      // SWAP PRE & SWAP NEXT
      if (i > 0 && i + 1 < n) {
        if (str[i + 1] < str[i] && str[i + 1] < str[i - 1]) {
          swap(str[i], str[i + 1]);
          swap(str[i], str[i - 1]);
          i += 1;
          continue;
        }
      }

      // SWAP PRE
      if (i > 0) {
        if (str[i] < str[i - 1]) {
          swap(str[i], str[i - 1]);
          continue;
        }
      }

      // NOW 
      if (TryMin(str[i]) == 'a') {
        str[i] = 'a';
        continue;  // O
      }

      // (NONE | UP | DOWN) & SWAP NEXT & SWAP PRE
      if (i + 2 < n && TryMin(str[i + 1]) > str[i + 2] &&
          TryMin(str[i]) > str[i + 2]) {
        str[i] = TryMin(str[i]);
        swap(str[i + 1], str[i + 2]);
        swap(str[i + 1], str[i]);
        i += 2;
        continue;
      }

      // SWAP NEXT
      // SWAP NEXT & DOWN
      // SWAP NEXT & UP
      if (i + 1 < n && TryMin(str[i]) > TryMin(str[i + 1])) {
        if (str[i + 1] == 'a') {
          str[i] = TryMin(str[i]);  //已经是最小了，修改当前值
        } else {
          str[i + 1] = TryMin(str[i + 1]);
        }
        swap(str[i], str[i + 1]);  // SWAP
        i += 1;
        continue;
      }

      str[i]--;  // DOWN
    }

    str[n] = '\0';
    printf("%s\n", str);
  }
  return 0;
}