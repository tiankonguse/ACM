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
#define maxn 7 + 2
#define maxm 70 + 2
using namespace std;
char mp[maxm][maxn];
int dp[maxm][2187 + 10];
int pr[8] = {1, 3, 9, 27, 81, 243, 729, 2187};
int num[2187 + 10][8];
int m, n;
void init(){
    for(int i=0;i<2187;i++){
        int t = i;
        for(int j=0;j<7;j++){
            num[i][j] = t % 3;
            t /= 3;
        }
    }
}
void dfs(int r, int d, int s, int mask, int c, bool flag){
    if(d == n){
        dp[r][s] = min(dp[r][s], dp[r - 1][mask] + c);
        return;
    }
    if(mp[r][d] == '*'){
        dfs(r, d + 1, s, mask, c, true);
    }
    if(num[mask][d] == 2){
        dfs(r, d + 1, s + pr[d], mask, c, true);
    }
    if(flag && (r == 1 || mp[r - 1][d] == '*' || num[mask][d] == 1) ){
        dfs(r, d + 1, s, mask, c, false);
    }
    if(r < m && mp[r + 1][d] != '*'){
        dfs(r, d + 1, s + pr[d] + pr[d], mask, c + 1, true);
    }
    if(d + 1 < n && mp[r][d + 1] != '*' && num[mask][d + 1] != 2){
        dfs(r, d + 2, s + pr[d] + pr[d + 1], mask, c + 1, true);
    }

}
int main(){
    init();
    while(scanf("%d%d", &m, &n) == 2){
        for(int i=1;i<=m;i++){
            scanf(" %s", mp[i]);
        }
        memset(dp, 0x3f, sizeof dp);
        dp[0][0] = 0;
        int mx = pr[n];
        for(int i=1;i<=m;i++){
            for(int j=0;j<mx;j++){
                if(dp[i - 1][j] != inf){
                    dfs(i, 0, 0, j, 0, 1);
                }
            }
        }
        int res = inf;
        for(int i=0;i<mx;i++){
            res = min(res, dp[m][i]);
        }
        printf("%d\n", res);
    }
    return 0;
}
