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
#define maxn 11
#define maxm 2020
using namespace std;
long long dp[maxn][maxm];

int main(){
    int T, n, m;
    scanf("%d", &T);
    for(int _t=1;_t<=T;_t++){
        scanf("%d%d", &n, &m);
        memset(dp, 0, sizeof(dp));
        for(int i=1;i<=m;i++) dp[1][i] = i;
        for(int i=2;i<=n;i++){
            for(int j=1;j<=m;j++){
                dp[i][j] = dp[i][j-1] + dp[i-1][j/2];
            }
        }
        printf("Case %d: n = %d, m = %d, # lists = %I64d\n", _t, n, m, dp[n][m]);
    }
    return 0;
}
