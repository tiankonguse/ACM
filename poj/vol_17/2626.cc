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
#define maxm 16
using namespace std;
int a[maxn], b[maxn];
int dp[maxn][maxm][maxm];
int main(){
    int n = 1;
    while(~scanf("%d%d", &a[n], &b[n])) ++n;
    --n;
    memset(dp, 0xff, sizeof(dp));
    dp[0][0][0] = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<=15;j++){
            for(int k=0;k<=15;k++){
                if(dp[i][j][k] == -1) continue;
                dp[i + 1][j][k] = max(dp[i + 1][j][k], dp[i][j][k]);
                if(j < 15){
                    dp[i + 1][j + 1][k] = max(dp[i + 1][j + 1][k], dp[i][j][k] + a[i + 1]);
                }
                if(k < 15){
                    dp[i + 1][j][k + 1] = max(dp[i + 1][j][k + 1], dp[i][j][k] + b[i + 1]);
                }
            }
        }
    }
    printf("%d\n", dp[n][15][15]);
    return 0;
}
