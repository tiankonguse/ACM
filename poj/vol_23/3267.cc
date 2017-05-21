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
#include <ctime>

#define inf 0x3f3f3f3f
#define Inf 0x3FFFFFFFFFFFFFFFLL
#define maxn 666
#define maxl 333
#define maxs 33
using namespace std;
int dp[maxl];
char str[maxl];
char dir[maxn][maxs];
int nxt[maxl][26];
int pos[26];

int main() {
    int n, l;
    while (~scanf("%d%d", &n, &l)) {
        scanf(" %s", str + 1);
        for (int i = 0; i < n; ++i) {
            scanf(" %s", dir[i]);
        }
        memset(pos, 0xff, sizeof pos);
        for (int i = l; i >= 0; --i) {
            for (int j = 0; j < 26; ++j) {
                nxt[i][j] = pos[j];
            }
            pos[ str[i] - 'a' ] = i;
        }

        for (int i = 0; i <= l; ++i) dp[i] = i;
        for (int i = 0; i <= l; ++i) {
            if (i > 0) dp[i] = min(dp[i], dp[i - 1] + 1);
            for (int j = 0; j < n; ++j) {
                int t = i, k, c = 0;
                for (k = 0; dir[j][k] && t != -1; ++k) {
                    t = nxt[t][ dir[j][k] - 'a' ];
                }
                if (t != -1) {
                    c = t - i - k;
                    dp[t] = min(dp[t], dp[i] + c);
                }
            }


        }
        printf("%d\n", dp[l]);
    }
    return 0;
}
