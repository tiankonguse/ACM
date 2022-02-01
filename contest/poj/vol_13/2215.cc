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
#define maxn 1010
using namespace std;
int mp[maxn][maxn];
int dp[maxn][maxn];

int main(){
    int T, n, m, q, x1, y1, x2, y2, t;
    for(scanf("%d", &T);T--;){
        scanf("%d%d", &n, &m);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                scanf("%d", &mp[i][j]);
            }
        }
        for(int i=1;i<=n;i++){
            t = 0;
            for(int j=1;j<=m;j++){
                t += mp[i][j];
                dp[i][j] = dp[i-1][j] + t;
            }
        }
        for(scanf("%d", &q);q--;){
            scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
            printf("Absolutni hodnota pohodlnosti je %d bodu.\n",
                   dp[x2][y2] - dp[x1-1][y2] - dp[x2][y1-1] + dp[x1-1][y1-1]);
        }
        puts("");
    }
    return 0;
}
