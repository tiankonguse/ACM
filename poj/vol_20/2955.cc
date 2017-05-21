#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>

#define inf 0x3f3f3f3f
#define Inf 0x3FFFFFFFFFFFFFFFLL
#define maxn 111
using namespace std;
char str[maxn];
int dp[maxn][maxn];
int dfs(int l, int r) {
    if (l >= r) return 0;
    if (dp[l][r] != -1) return dp[l][r];
    int ret = 0;
    for (int i = l; i < r; ++i) {
        ret = max(ret, dfs(l, i) + dfs(i + 1, r));
    }
    if ((str[l] == '[' && str[r] == ']') || (str[l] == '(' && str[r] == ')')) {
        ret = max(ret, dfs(l + 1, r - 1) + 1);
    }
    return dp[l][r] = ret;
}
int main() {
    int n;
    while (~scanf(" %s", str)) {
        if (str[0] == 'e') break;
        n = strlen(str);
        memset(dp, 0xff, sizeof dp);
        printf("%d\n", dfs(0, n - 1) * 2);
    }
    return 0;
}
