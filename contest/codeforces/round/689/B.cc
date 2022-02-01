
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

char str[555][555];
int sum[555][555][2];  //这个坐标向前连续多少个
int n, m;

enum {
  ROW = 0,
  COL = 1,
};

void init() {
  memset(sum, 0, sizeof(sum));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (str[i][j] == '.') {
        sum[i][j][ROW] = 0;
      } else {
        sum[i][j][ROW] = 1 + sum[i][j - 1][ROW];
      }
    }
  }

  for (int j = 1; j <= m; j++) {
    for (int i = 1; i <= n; i++) {
      if (str[i][j] == '.') {
        sum[i][j][COL] = 0;
      } else {
        sum[i][j][COL] = 1 + sum[i - 1][j][COL];
      }
    }
  }
}

int dir[4][2] = {{1, -1}, {1, 1}, {1, 1}, {-1, 1}};
int check(int x, int y, int k) {
  int ans = 0;
  int len = 1;
  // printf("x=%d y = %d k=%d \n", x, y, k);
  while (sum[x][y][k % 2] >= len) {
    ans++;
    len += 2;
    x += dir[k][0];
    y += dir[k][1];
  }
  // printf("x=%d y = %d ans=%d len=%d\n", x, y, ans, len);

  return ans - 1;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
      scanf("%s", str[i] + 1);
    }
    // for(int i=1;i<=n;i++){
    //   printf("%d:%s\n",i, str[i] + 1);
    // }
    init();
    int ans = 0;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        if (str[i][j] == '.') continue;
        ans++;
        ans += check(i, j, 2);
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}