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
#define maxn 11 + 1
using namespace std;
int n, m;
__int64 dp[maxn][1 << maxn];
void dfs(int r, int s, int d, int mask){
    if(d == m){
        dp[r][s] += dp[r - 1][mask];
        return;
    }
    if((mask & (1 << d))) dfs(r, s, d + 1, mask);
    if((mask & (1 << d)) == 0) dfs(r, s | (1 << d), d + 1, mask);
    if(d + 1 < m && (mask & (1 << d)) == 0 && (mask & (1 << (d + 1))) == 0){
        dfs(r, s, d + 2, mask);
    //    dfs(r, s | (1 << d) | (1 << (d + 1)), d + 2, mask);
    }
}
int main(){

    while(~scanf("%d %d", &n, &m) && n + m){
        if(n * m % 2 != 0) puts("0");
        else{
            int mx = 1 << m;
            memset(dp, 0, sizeof dp);
            dp[0][0] = 1;
            for(int i=1;i<=n;i++){
                for(int j=0;j<mx;j++){
                    if(dp[i - 1][j]){
                        dfs(i, 0, 0, j);
                    }
                }
            }
       //     int x, y; while(cin >> x >> y) cout << dp[x][y] << endl;
            printf("%I64d\n", dp[n][0]);
        }
    }
    return 0;
}
