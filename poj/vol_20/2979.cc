#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

#define inf 0x3f3f3f3f
#define Inf 0x3FFFFFFFFFFFFFFFLL
#define maxn 111
using namespace std;
int dp[maxn][12][12];
bool rt[12][12];
int dist[12][12];
int mp[4][4] = {7, 8, 9, 0,
                4, 5, 6, 0,
                1, 2, 3, 0,
                10,11,0, 0};
char str[111];
int arr[111];
int _mp[12];

int pre[maxn][12][12][2];
int path[maxn][2];
int main(){
    for(int i=1;i<=9;i++) _mp[i] = i;
    _mp[10] = _mp[11] = 0;

    memset(rt, false, sizeof(rt));
    memset(dist, 0, sizeof(dist));
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            for(int k=0;k<j;k++){
                for(int l=0;l<4;l++){
                    rt[ mp[i][j] ][ mp[l][k] ] = true;
                }
            }
            for(int k=0;k<4;k++){
                for(int l=0;l<4;l++){
                    dist[ mp[i][j] ][ mp[k][l] ] = abs(i - k) + abs(j - l);
                }
            }
        }
    }
   // int x,y;while(cin>>x>>y)cout<<dist[x][y]<<endl;
    int n;
    while(~scanf(" %s", str)){
        if(str[0] == 'e') break;
        n = strlen(str);
        for(int i=0;i<n;i++) arr[i + 1] = str[i] - '0';
        memset(dp, 0x3f, sizeof(dp));
        dp[0][4][5] = 0;
        for(int i=1;i<=n;i++){
            for(int it=1;it<=11;it++){
                for(int jt=1;jt<=11;jt++){
                    if(!rt[jt][it]) continue;
                    if(_mp[it] == arr[i]){
                        for(int iq=1;iq<=11;iq++){
                            for(int jq=1;jq<=11;jq++){
                                if(!rt[jq][iq]) continue;
                                if((jq == 11 && iq == 1 && it == 2) || (jq == 11 && iq == 10 && it == 11)
                                    || (jq == 11 && iq == 7 && it == 8) || (jq == 11 && iq == 4 && it == 5)) {
                                    dp[i][it][jt] = min(dp[i][it][jt], dp[i-1][iq][jq] + max(dist[it][iq] + 2, dist[jt][jq]));
                                }
                                else{
                                    dp[i][it][jt] = min(dp[i][it][jt], dp[i-1][iq][jq] + max(dist[it][iq] + 1, dist[jt][jq]));
                                }
                               // printf("dp[%d][%d][%d] = %d\n",i,it,jt,dp[i][it][jt]);system("pause");
                            }
                        }
                    }
                    if(_mp[jt] == arr[i]){
                        for(int iq=1;iq<=11;iq++){
                            for(int jq=1;jq<=11;jq++){
                                if(!rt[jq][iq]) continue;
                                if((jq == 11 && iq == 1 && it == 2) || (jq == 11 && iq == 10 && it == 11)
                                    || (jq == 11 && iq == 7 && it == 8) || (jq == 11 && iq == 4 && it == 5)) {
                                    dp[i][it][jt] = min(dp[i][it][jt], dp[i-1][iq][jq] + max(dist[it][iq] + 1, dist[jt][jq] + 1));
                                }
                                else{
                                    dp[i][it][jt] = min(dp[i][it][jt], dp[i-1][iq][jq] + max(dist[it][iq] , dist[jt][jq] + 1));
                                }
                            }
                        }
                    }

                 //   if(dp[i][it][jt]!=inf)printf("dp[%d][%d][%d] = %d\n",i,it,jt,dp[i][it][jt]);
                }
            }
           // system("pause");
        }
        int res = inf;
        for(int i=1;i<=11;i++){
            for(int j=1;j<=11;j++){
                if(!rt[j][i]) continue;
                res = min(res, dp[n][i][j]);
            }
        }
        printf("%d\n", res);
    }
    return 0;
}
