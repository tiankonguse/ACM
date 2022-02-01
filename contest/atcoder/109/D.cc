
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

struct Point {
  int x, y;
};
struct St {
  int type;
  Point point;
  St(int type) : type(type) { point.x = point.y = 0; }
};

St decode(int h) {
  St st;
  st.type = h % 10;
  h /= 10;
  st.point.x = h / 100;
  st.point.x = h % 100;
  return st;
}

int encode(St st) {
  int h = 0;
  h = st.point.x * 100 + st.point.y;
  return h * 10 + st.type;
}

map<int, struct St> m;

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  // freopen("out_std.txt", "w", stdout);
#endif

  queue<St> que;
  m[0] = St(0);
  que.push(St(0));
  while (!que.empty()) {
    auto st = que.front();
    que.pop();
    if (st.type == 0) {
      // 0 =>

    } else if (st.type == 1) {
    } else if (st.type == 2) {
    } else if (st.type == 3) {
    }
  }

  int t;
  while (~scanf("%t", &t)) {
  }

  return 0;
}
