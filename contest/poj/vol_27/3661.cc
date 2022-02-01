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
#define maxn 10010
#define maxm 505
using namespace std;
int dp[maxn][maxm];
int a[maxn];
int main(){
    int n, m;
    while(~scanf("%d%d", &n, &m)){
        for(int i=0;i<n;i++){
            scanf("%d", &a[i]);
        }
        memset(dp, 0, sizeof(dp));
        dp[0][1] = dp[1][0] = a[0];
        for(int i=1;i<n;i++){
            dp[i][0] = max(dp[i][0], dp[i - 1][0]);
            for(int j=1;j<=m;j++){
                dp[i][j] = dp[i - 1][j - 1] + a[i];
                if(i + j < n) dp[i + j][0] = max(dp[i + j][0], dp[i][j]);
            }
        }
        printf("%d\n", dp[n - 1][0]);
    }
    return 0;
}
