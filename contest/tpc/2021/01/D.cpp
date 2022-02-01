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

int str[max5];
double dp[max5];  // 最近两个报团的最优解 VS 最近三个报团的最优解
int d;

double solve2(int x, int y) { return max(y - x - d, 0) / 2.0; }

double solve3(int x, int y, int z) {
  return (max(y - x - d, 0) + max(z - y - d, 0)) / 2.0;
}

double dfs2(int i) { return max(dp[i - 2], solve2(str[i - 1], str[i])); }
double dfs3(int i) {
  return max(dp[i - 3], solve3(str[i - 2], str[i - 1], str[i]));
}

double dfs(int i) {
  if (i == 2) {
    return dfs2(i);
  }
  if (i == 3) {
    return dfs3(i);
  }
  if (i == 4) {
    return dfs2(i);
  }
  return min(dfs2(i), dfs3(i));
}

int main() {
#ifndef ONLINE_JUDGE
  // freopen("./in.txt", "r", stdin);
  // freopen("./out.txt", "w", stdout);
#endif
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d%d", &n, &d);
    for (int i = 1; i <= n; i++) {
      scanf("%d", &str[i]);
    }
    sort(str + 1, str + n + 1);

    dp[0] = 0;
    dp[1] = 0;  // 一个无解，设置为最大值

    for (int i = 2; i <= n; i++) {
      dp[i] = dfs(i);
    }
    printf("%.6f\n", dp[n]);
  }

#ifndef ONLINE_JUDGE
  // freopen("./diff.txt", "w", stdout);
  // system("diff ./out_std.txt ./out.txt | wc -l");
  // system("diff ./out_std.txt ./out.txt");
#endif

  return 0;
}

/*
input:
3
1
0
20

output:
You are the future of Tencent!
Good luck and Enjoy TPC!
You are the future of Tencent!
*/