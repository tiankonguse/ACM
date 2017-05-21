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
#define maxn 105
using namespace std;
bool mp[maxn][maxn];
vector<int> group[maxn][2];
int num[maxn][2];
int n, a, m, gnt, tot;
bool used[maxn];
bool dp[maxn][maxn];
int pre[maxn][maxn];
int dep[maxn];
int ans[2][maxn], ant[2];
bool dfs(int d, int u, int p){
    //printf("dfs(%d, %d, %d)\n", d, u, p);
    used[u] = true;
    dep[u] = d % 2;
    group[gnt][d % 2].push_back(u);
    num[gnt][d % 2]++;
    for(int i=1;i<=n;i++){
        if(i != p && (!mp[u][i] || !mp[i][u])){
            if(used[i]){
                if(dep[i] == dep[u]) return false;
            }
            else if(!dfs(d + 1, i, u)) return false;
        }
    }
    return true;
}
int main(){
    while(~scanf("%d", &n)){
        memset(mp, false, sizeof(mp));
        for(int i=1;i<=n;i++){
            mp[i][i] = true;
            while(scanf("%d", &a) && a){
                mp[i][a] = true;
            }
        }

        m = gnt = 0;
        memset(used, false, sizeof(used));
        memset(num, 0, sizeof(num));
        bool flag = true;
        for(int i=1;i<=n && flag;i++){
            if(used[i]) continue;
            for(int j=1;j<=n && flag;j++){
                if(!mp[i][j] || !mp[j][i]){
                    group[gnt][0].clear();
                    group[gnt][1].clear();
                    flag &= dfs(0, i, -1);
                    gnt++;
                    break;
                }
            }
        }
        if(!flag) puts("No solution");
        else{
            tot = 0;
            for(int i=0;i<gnt;i++) tot += num[i][0] + num[i][1];
            tot >>= 1;
            memset(dp, false, sizeof(dp));
            dp[0][0] = true;
            for(int i=0;i<gnt;i++){
                for(int j=0;j<2;j++){
                    for(int k=tot;k>=num[i][j];k--){
                        if(dp[i][k - num[i][j]]){
                            dp[i + 1][k] = true;
                            pre[i + 1][k] = j;
                        }
                    }
                }
            }
            int res, pos, ps;
            for(pos=tot;pos && !dp[gnt][pos];pos--);
            ant[0] = ant[1] = 0;
            for(int i=gnt;i>=1;i--){
                ps = pre[i][pos];
                for(int j=0;j<num[i-1][ps];j++){
                    ans[0][ant[0]++] = group[i-1][ps][j];
                }
                for(int j=0;j<num[i-1][ps^1];j++){
                    ans[1][ant[1]++] = group[i-1][ps^1][j];
                }
                pos -= num[i-1][ps];
            }
            for(int i=1;i<=n;i++){
                if(!used[i]){
                    if(ant[0] <= ant[1]){
                        ans[0][ant[0]++] = i;
                    }
                    else{
                        ans[1][ant[1]++] = i;
                    }
                }
            }
            for(int i=0;i<2;i++){
                printf("%d", ant[i]);
                for(int j=0;j<ant[i];j++){
                    printf(" %d", ans[i][j]);
                }
                puts("");
            }
        }
    }
    return 0;
}
