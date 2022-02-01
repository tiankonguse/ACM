#include <bits/stdc++.h>
using namespace std;
int const N = 210;
int mp[128];
bool ok[4][4][4];
char buf[10], str[N];
int dp[4][N][N];
char lst[] = "bryw";

bool dfs(int l, int r, int c) {
  if (~dp[c][l][r]) return dp[c][l][r];
  if (l == r) return dp[c][l][r] = (mp[str[l]] == c);
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) {
      if (ok[c][i][j]) {
        for (int k = l; k < r; ++k) {
          if (dfs(l, k, i) && dfs(k + 1, r, j)) {
            return dp[c][l][r] = 1;
          }
        }
      }
    }
  }
  return dp[c][l][r] = 0;
}

int main() {
  for (int i = 0; i < 4; ++i) mp[lst[i]] = i;
  int a[10]; for (int i = 0; i < 4; ++i) scanf("%d", &a[i]);
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < a[i]; ++j) {
      scanf(" %s", buf);
      ok[i][mp[buf[0]]][mp[buf[1]]] = 1;
    }
  }
  scanf(" %s", str);
  int n = strlen(str);
  bool noAnswer = 1;
  memset(dp, 0xff, sizeof dp);
  for (int i = 0; i < 4; ++i) {
    if (dfs(0, n - 1, i)) {
      noAnswer = 0;
      putchar(lst[i]);
    } 
  }  
  if (noAnswer) puts("Nobody");
  else puts("");
  return 0;
}
