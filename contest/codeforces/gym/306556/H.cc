
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
using min_queue = priority_queue<T, vector<T>, greater<T>>;
template <class T>
using max_queue = priority_queue<T>;

const LL INF = 0x3f3f3f3f3f3f3f3fll;
const double PI = acos(-1.0), eps = 1e-7;
const int inf = 0x3f3f3f3f, ninf = 0xc0c0c0c0, mod = 1000000007;
const int max3 = 2100, max4 = 11100, max5 = 200100, max6 = 2000100;

int str[max3][max3];
int dir[100][2];

int main() {
// #ifndef ONLINE_JUDGE
//   freopen("in.txt", "r", stdin);
//   freopen("out.txt", "w", stdout);
//   // freopen("out_std.txt", "w", stdout);
// #endif
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, m, k, q;
    scanf("%d%d%d%d", &n, &m, &k, &q);
    int x, y;
    while (k--) {
      scanf("%d%d", &x, &y);
    }
    for (int i = 0; i < q; i++) {
      scanf("%d%d", &dir[i][0], &dir[i][1]);
    }
    int x1, y1, x2, y2;
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);

    memset(str, -1, sizeof(str));
    str[x1][y1] = 0;
    queue<pair<int, int>> que;
    que.push({x1, y1});
    int ans = -1;
    while (!que.empty()) {
      auto p = que.front();
      que.pop();
      int x = p.first, y = p.second;
      for (int i = 0; i < q; i++) {
        int xx = x + dir[i][0];
        int yy = y + dir[i][1];
        if (xx < 1 || xx > n || yy < 1 || yy > m) {
          continue;
        }
        if (str[xx][yy] > 0) continue;
        str[xx][yy] = str[x][y] + 1;
        if(xx == x2 && yy == y2){
            ans = str[xx][yy];
            break;
        }
        que.push({xx, yy});
      }
      if(ans > 0){
          break;
      }
    }
    if(ans == -1){
        printf("hao zi wei zhi!\n");
    }else{
        printf("%d\n", ans);
    }


  }
  return 0;
}