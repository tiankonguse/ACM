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

int gard[5][5];
char base[30][5][5];
int num;

void dfs_check() {
  int count = 0;
  memset(base[num], '-', sizeof(base[num]));
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      if (gard[i][j]) {
        count++;
        base[num][i][j] = '#';
      }
    }
  }
  if (count == 9) {
    num++;
  }
}

void dfs_column() {
  for (int i = 0; i < 4; i++) {
    //选择第 i 条竖线
    for (int j = 0; j < 4; j++) {
      gard[j][i]++;
    }

    dfs_check();

    for (int j = 0; j < 4; j++) {
      gard[j][i]--;
    }
  }
}

void dfs_row() {
  for (int i = 0; i < 4; i++) {
    //选择第 i 条线
    for (int j = 0; j < 4; j++) {
      gard[i][j]++;
    }
    dfs_column();
    for (int j = 0; j < 4; j++) {
      gard[i][j]--;
    }
  }
}

void dfs_diagonal() {
  //选择主对角线
  for (int i = 0; i < 4; i++) {
    gard[i][i]++;
  }
  dfs_row();
  for (int i = 0; i < 4; i++) {
    gard[i][i]--;
  }

  // 副对角线
  for (int i = 0; i < 4; i++) {
    gard[i][3 - i]++;
  }
  dfs_row();
  for (int i = 0; i < 4; i++) {
    gard[i][3 - i]--;
  }
}

void init() {
  num = 0;
  memset(gard, 0, sizeof(gard));
  dfs_diagonal();
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("./in.txt", "r", stdin);
  freopen("./out.txt", "w", stdout);
#endif
  init();
  // printf("num=%d\n", num);

  int t;
  scanf("%d", &t);
  while (t--) {
    char str[5][5];
    for (int i = 0; i < 4; i++) {
      scanf("%s", str[i]);
    }

    int ans = 9;
    for (int k = 0; k < num; k++) {
      int tmpAns = 9;
      for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
          if (base[k][i][j] == str[i][j]) {
            tmpAns--;
          }
        }
      }
      ans = min(ans, tmpAns);
    }

    printf("%d\n", ans);
  }
#ifndef ONLINE_JUDGE
  freopen("./diff.txt", "w", stdout);
  system("diff ./out_std.txt ./out.txt | wc -l");
  system("diff ./out_std.txt ./out.txt");
#endif
  return 0;
}

/*
input:
2
####
####
#...
....
.#.#
####
.#..
##..

output:
2
0
*/