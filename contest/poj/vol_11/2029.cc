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
#define maxn 110
using namespace std;
bool mp[maxn][maxn];
int dp[maxn][maxn];
int main(){
    int n, w, h, s, t, d, res;
    while(scanf("%d", &n) && n){
        scanf("%d%d", &w, &h);
        memset(mp, false, sizeof(mp));
        for(int i=0;i<n;i++){
            scanf("%d%d", &s, &t);
            mp[s][t] = true;
        }
        memset(dp, 0, sizeof(dp));
        for(int i=1;i<=w;i++){
            d = 0;
            for(int j=1;j<=h;j++){
                d += mp[i][j];
                dp[i][j] = dp[i-1][j] + d;
            }
        }
        scanf("%d%d", &s, &t);
        res = 0;
        for(int i=s;i<=w;i++){
            for(int j=t;j<=h;j++){
                res = max(res, dp[i][j] - dp[i-s][j] - dp[i][j-t] + dp[i-s][j-t]);
            }
        }
        printf("%d\n", res);
    }
    return 0;
}
