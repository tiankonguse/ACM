#include <bits/stdc++.h>
using namespace std;
int const M = 110;
int a[M], mp[25][25];
bool vis[M];
set <int> s;

int main() {
  int n, m;
  scanf("%d", &m);
  for (int i = 0; i < m; ++i) {
    scanf("%d", &a[i]);
    s.insert(a[i]);
  }
  n = 0;
  while (n * (n - 1) / 2 != m) ++n;
  mp[0][0] = a[0], vis[0] = 1;
  for (int col = 1; col < n; ++col) {
    for (int i = 0; i < m; ++i) if (!vis[i]) {
      bool flag = 1;
      for (int j = 0; j < col; ++j) {
        int t = a[i] ^ mp[0][j];
        if (s.find(t) == s.end()) flag = 0;
        if (!flag) break;
      }
      if (flag) {
        mp[0][col] = a[i], vis[i] = 1;
        for (int j = 0; j < m; ++j) if (!vis[j]) {
          for (int k = 0; k < col; ++k) {
            if ((a[j] ^ a[i]) == mp[0][k]) {
              mp[k + 1][col] = a[j], vis[j] = 1;
              break;
            }
          }
        }
        break;
      }
    }
  }
  printf("0");
  for (int i = 1; i < n; ++i) {
    printf(" %d", mp[0][i - 1]);
  }
  puts("");
  return 0;
}

