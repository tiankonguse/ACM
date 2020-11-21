
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

ll d, k;

bool dis(ll x, ll y) { return y * y + x * x > d * d; }

int m[5005][5005];
bool forceCheck() {
  int Y = d / k + 1;
  for (int j = Y; j >= 0; j--) {
    ll y = j * k;
    for (int i = Y; i >= 0; i--) {
      ll x = i * k;
      if (dis(x, y)) {
        m[i][j] = -2;  //不可到达
        continue;
      }

      if (dis(x + k, y) && dis(x, y + k)) {
        m[i][j] = 1;  //上右都是边界，必败
        continue;
      }

      if (m[i + 1][j] == 1 || m[i][j + 1] == 1) {
        m[i][j] = 2;  //上右有必败，则必胜
        continue;
      }

      //没有必胜，则是必败
      m[i][j] = 1;
    }
  }
  return m[0][0] == 2;
}

int flag[max5][2];

bool dfs(ll Y, ll nextY) {
  for (ll x = Y; x >= 0; x -= k) {
    int i = x / k;
    if (dis(x, Y)) {
      flag[i][1] = -2;  //不可到达
      continue;
    }

    if (flag[i + 1][1] == 1) {
      flag[i][1] = 2;  //上右有必败，则必胜
      continue;
    } else {
      flag[i][1] = 1;  //没有必胜，则是必败
    }
  }

  for (ll x = Y; x >= 0; x -= k) {
    int i = x / k;
    if (dis(x, nextY)) {
      flag[i][0] = -2;  //不可到达
      continue;
    }

    if (flag[i][1] == 1 || flag[i + 1][0] == 1) {
      flag[i][0] = 2;  //上右有必败，则必胜
    } else {
      flag[i][1] = 1;  //没有必胜，则是必败
    }
  }
  return flag[0][0] == 2;
}

bool check() {
  if (d <= 5000 * k) {  // 5000 以内的暴力计算
    return forceCheck();
  }

  // 5000 之外的贪心计算
  bool ans = true;
  int x = 0, y = 0;
  while (1) {
    if (dis(x, y)) break;
    if (x <= y) {
      x += k;
    } else {
      y += k;
    }
    ans = !ans;
  }
  //   int Y = d / k + 1;
  //   int nextY = Y - 1;

  //   bool res = dfs(Y, nextY);
  //   if (nextY % 2 == 0) {
  //     return res;
  //   } else {
  //     return !res;
  //   }
  return ans;
}

// void test() {
//   d = 100000;
//   k = 1;
//   for (int y = d; y >= 0; y--) {
//     int num = 0;
//     for (int x = d; x >= 0; x--) {
//       if (dis(x, y)) continue;
//       num++;
//     }
//     printf("y=%d num=%d\n", y, num);
//     if (y + 110 < d) {
//       break;
//     }
//   }
// }

int main() {
  int t;

  scanf("%d", &t);
  while (t--) {
    scanf("%lld%lld", &d, &k);
    printf("%s\n", check() ? "Ashish" : "Utkarsh");
  }
  return 0;
}