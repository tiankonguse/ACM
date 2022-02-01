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
int a[maxn];
int dp[maxn][33][2];
int main(){
    int n, w, res;
    while(~scanf("%d%d", &n, &w)){
        for(int i=1;i<=n;i++){
            scanf("%d", &a[i]);
        }
        memset(dp, 0xe0, sizeof(dp));
        dp[0][0][0] = 0;
        for(int i=1;i<=n;i++){
            dp[i][0][0] = dp[i-1][0][0] + (a[i] == 1);
            dp[i][0][1] = dp[i-1][0][1] + (a[i] == 2);
            for(int j=1;j<=i&&j<=w;j++){
                dp[i][j][0] = max(dp[i-1][j][0], dp[i-1][j-1][1]) + (a[i] == 1);
                dp[i][j][1] = max(dp[i-1][j][1], dp[i-1][j-1][0]) + (a[i] == 2);
            }
        }
        res = 0;
        for(int i=0;i<=w;i++) res = max(res, max(dp[n][i][0], dp[n][i][1]));
        printf("%d\n", res);
    }
    return 0;
}
