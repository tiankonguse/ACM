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
#define MAXN 404
using namespace std;
int N,n,m;
int mp[MAXN][MAXN];
void floyd(){
    for(int k=1;k<=N;k++)for(int i=1;i<=N;i++){
        if(mp[i][k]){
            for(int j=1;j<=N;j++){
                if(mp[k][j])mp[i][j] = 1;
            }
        }
    }
}
int cliq[MAXN][2];
bool used[MAXN];
bool dp[MAXN][MAXN];
int main(){
    int t,a,b;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        N = n<<1;
        memset(mp,0,sizeof(mp));
        for(int i=1;i<=N;i++)mp[i][i] = 1;
        for(int i=0;i<m;i++){
            scanf("%d%d",&a,&b);
            mp[a][b+n] = mp[b+n][a] = 1;
        }
        floyd();
//        for(int i=1;i<=N;i++){
//            for(int j=1;j<=N;j++){
//                printf("%d ",mp[i][j]);
//            }
//            printf("\n");
//        }
        memset(cliq,0,sizeof(cliq));
        memset(used,0,sizeof(used));
        int cnt=0;
        for(int i=1;i<=N;i++){
            if(!used[i]){
                for(int j=1;j<=n;j++){
                    if(mp[i][j]){
                        cliq[cnt][0]++;
                        used[j] = true;
                    }
                }
                for(int j=n+1;j<=N;j++){
                    if(mp[i][j]){
                        cliq[cnt][1]++;
                        used[j] = true;
                    }
                }
                cnt++;
            }
        }
        memset(dp,0,sizeof(dp));
        dp[n][n] = 1;
        for(int k=0;k<cnt;k++){
            for(int i=cliq[k][0];i<=n;i++){
                for(int j=cliq[k][1];j<=n;j++){
                    if(dp[i][j]) dp[i-cliq[k][0]][j-cliq[k][1]] = 1;
                }
            }
        }
        for(int i=n - n/2;i<=n;i++){
            if(dp[i][i]){
                printf("%d\n",n-i);
                break;
            }
        }
    }
    return 0;
}
