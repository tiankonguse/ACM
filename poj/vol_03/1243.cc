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
#define maxn 31
using namespace std;
int dp[maxn][maxn];
int main(){
    for(int i=1;i<=30;i++){
        dp[i][0] = i;
        for(int j=1;j<=30;j++){
            if(i < j) dp[i][j] = dp[i][j-1];
            else dp[i][j] = dp[i-1][j] + dp[i-1][j-1] + 1;
        }
    }
    int g, l, _case = 1;
    while(scanf("%d%d", &g, &l) && g + l){
        printf("Case %d: %d\n", _case++, dp[g][l]);
    }
    return 0;
}
