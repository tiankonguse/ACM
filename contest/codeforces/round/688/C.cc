
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

char str[max3][max3];

int rows[max3][10][2];     //每一行每个数字的最左边界与最右边界
int columns[max3][10][2];  //每一列每个数字的最下边界与最上边界
int rowMax[10][2];         // 每个数字的最上边界与最下边界
int columnMax[10][2];      // 每个数字的最左边界与最右边界

int n;

int myMin(int a, int b) {
  if (a == -1) {
    return b;
  } else if (b == -1) {
    return a;
  } else {
    return min(a, b);
  }
}
int myMax(int a, int b) {
  if (a == -1) {
    return b;
  } else if (b == -1) {
    return a;
  } else {
    return max(a, b);
  }
}

void init() {
  memset(rows, -1, sizeof(rows));
  memset(columns, -1, sizeof(columns));
  memset(rowMax, -1, sizeof(rowMax));
  memset(columnMax, -1, sizeof(columnMax));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int v = str[i][j] - '0';
      rows[i][v][0] = myMin(rows[i][v][0], j);  //左边界
      rows[i][v][1] = myMax(rows[i][v][1], j);  //右边界

      columns[j][v][0] = myMin(columns[j][v][0], i);  //下边界
      columns[j][v][1] = myMax(columns[j][v][1], i);  //上边界

      rowMax[v][0] = myMin(rowMax[v][0], i);        //下边界
      rowMax[v][1] = myMax(rowMax[v][1], i);        //上边界
      columnMax[v][0] = myMin(columnMax[v][0], j);  //左边界
      columnMax[v][1] = myMax(columnMax[v][1], j);  //右边界
    }
  }

//   for (int v = 0; v < 10; v++) {
//     printf("v=%d up[%d] down[%d] left[%d] right[%d]\n", v, rowMax[v][1],
//            rowMax[v][0], columnMax[v][0], columnMax[v][1]);
//   }
}

int Cal(int k) {
  // 枚举每一行为底
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (rows[i][k][1] == -1) {
      continue;
    }

    int l = rows[i][k][1] - rows[i][k][0];
    ans = max(ans, l * (rowMax[k][1] - i));  //向上的三角
    ans = max(ans, l * (i - rowMax[k][0]));  //向上的三角

    ans = max(ans, l * (n - 1 - i));  //向上的三角(修改上)
    ans = max(ans, l * (i - 0));      //向上的三角(修改下)

    l = rows[i][k][1] - 0;                   //修改行的左边界
    ans = max(ans, l * (rowMax[k][1] - i));  //向上的三角
    ans = max(ans, l * (i - rowMax[k][0]));  //向上的三角

    l = n - 1 - rows[i][k][0];               //修改行的有边界
    ans = max(ans, l * (rowMax[k][1] - i));  //向上的三角
    ans = max(ans, l * (i - rowMax[k][0]));  //向上的三角
  }

  // 枚举每一列为底
  for (int i = 0; i < n; i++) {
    if (columns[i][k][1] == -1) {
      continue;
    }

    int l = columns[i][k][1] - columns[i][k][0];
    ans = max(ans, l * (columnMax[k][1] - i));  //向上的三角
    ans = max(ans, l * (i - columnMax[k][0]));  //向上的三角

    ans = max(ans, l * (n - 1 - i));  //向上的三角(修改上)
    ans = max(ans, l * (i - 0));      //向上的三角(修改下)

    l = columns[i][k][1] - 0;                   //修改列的最下边界
    ans = max(ans, l * (columnMax[k][1] - i));  //向上的三角
    ans = max(ans, l * (i - columnMax[k][0]));  //向上的三角

    l = n - 1 - columns[i][k][0];               //修改列的最上边界
    ans = max(ans, l * (columnMax[k][1] - i));  //向上的三角
    ans = max(ans, l * (i - columnMax[k][0]));  //向上的三角
  }

  return ans;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  // freopen("out_std.txt", "w", stdout);
#endif
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      scanf("%s", str[i]);
    }
    init();
    int ans[10];
    memset(ans, 0, sizeof(ans));
    for (int k = 0; k < 10; k++) {
      ans[k] = Cal(k);
    }

    for (int i = 0; i < 10; i++) {
      printf("%d%c", ans[i], i == 9 ? '\n' : ' ');
    }
  }
  return 0;
}