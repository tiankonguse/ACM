#include <bits/stdc++.h>

#include <atcoder/modint>

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

vector<int> ans;
int Solver0(ll x) {
  ll y = x * 1.0 / (1.0 + sqrt(5.0)) * 2;
  int flag = 0;

  ans.clear();
  while (x > 0 || y > 0) {
    if (x < y) {
      flag = 1 - flag;
      swap(x, y);
      continue;
    }

    if (y == 0) {
      ans.push_back(1 + flag);
      x--;
    } else {
      ans.push_back(3 + flag);
      x = x - y;
    }

    if (ans.size() > 130) {
      break;
    }
  }

  return ans.size();
}

int Solver(ll x, int op = 0) {
  ll y = x * 1.0 / (1.0 + sqrt(5.0)) * 2;
  int flag = 0;
  ans.clear();
  while (x > 0 || y > 0) {
    if (x < y) {
      flag = 1 - flag;
      swap(x, y);
      continue;
    }

    if (y == 0) {
      ans.push_back(1 + flag);
      x--;
    } else {
      ll tmp_y = x * 1.0 / (1.0 + sqrt(5.0)) * 2;
      if (tmp_y > y && op > 0) {  // y 有点大
        ans.push_back(1 + flag);
        x--;
        op--;
      } else if (tmp_y < y && op > 0) {  // x 有点大
        ans.push_back(2 - (1 - flag));
        y--;
        op--;
      } else {
        ans.push_back(3 + flag);
        x = x - y;
      }
    }

    if (ans.size() > 130) {
      break;
    }
  }
  return ans.size();
}

int Solver2(ll x, int op = 0) {
  ll y = x * 1.0 / (1.0 + sqrt(5.0)) * 2;
  int flag = 0;
  ans.clear();
  while (x > 0 || y > 0) {
    if (x < y) {
      flag = 1 - flag;
      swap(x, y);
      continue;
    }

    if (y == 0) {
      ans.push_back(1 + flag);
      x--;
    } else {
      ll tmp_y = x * 1.0 / (1.0 + sqrt(5.0)) * 2;
      if (tmp_y > y && op > 0) {  // y 有点大
        ans.push_back(1 + flag);
        x--;
        op--;
      } else if (tmp_y < y && op > 0) {  // x 有点大
        ans.push_back(2 - (1 - flag));
        y--;
        op--;
      }

      ans.push_back(3 + flag);
      x = x - y;
    }

    if (ans.size() > 130) {
      break;
    }
  }
  return ans.size();
}

void MyTrySolver(const ll x) {
  if (Solver0(x) <= 130) {
    return;
  }
  for (int op = 1; op < 100; op++) {
    if (Solver(x, op) <= 130) {
      return;
    }
  }
}

void Test() {
  for (ll i = 1;; i++) {
    if (i % 1000000 == 0) {
      printf("i=%lld\n", i);
    }
    MyTrySolver(i);
    // scanf("%lld", &x);
    // printf("x=%lld y=%lld\n", x, y);

    if (ans.size() > 130) {
      int n = ans.size();
      double rate = (1.0 + sqrt(5.0)) / 2;
      printf("x=%lld y=%lld ans=%d\n", i, i * rate, n);
      printf("%d\n", n);
      ll x = 0, y = 0;
      for (int i = n - 1; i >= 0; i--) {
        // printf("%d\n", ans[i]);
        switch (ans[i]) {
          case 1:
            x++;
            break;
          case 2:
            y++;
            break;
          case 3:
            x = x + y;
            break;
          case 4:
            y = x + y;
            break;
        }
        printf("o=%d x=%d y=%d\n", ans[i], x, y);
      }
      break;
    }
  }
}

int main() {
  // #ifndef ONLINE_JUDGE
  //   freopen("in.txt", "r", stdin);
  //   freopen("out.txt", "w", stdout);
  //   // freopen("out_std.txt", "w", stdout);
  // #endif
  // Test();

  ll x;
  scanf("%lld", &x);

  MyTrySolver(x);

  int n = ans.size();
  if (n > 130) {
    n = 0;
    x /= n;
  }
  printf("%d\n", n);
  for (int i = n - 1; i >= 0; i--) {
    printf("%d\n", ans[i]);
  }

  return 0;
}
