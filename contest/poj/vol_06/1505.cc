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
#define maxn 505
using namespace std;
int num[maxn], sum[maxn];
int dp[maxn][maxn];
bool mark[maxn];
int main(){
//    freopen("1505out.txt", "w", stdout);
    int T, n, k, lim, t, res;
    for(scanf("%d", &T);T--;){
        scanf("%d%d", &n, &k);
        sum[0] = 0;
        for(int i=1;i<=n;i++){
            scanf("%d", &num[i]);
            sum[i] = sum[i - 1] + num[i];
        }
        memset(dp, 0x3f, sizeof(dp));
        for(int i=1;i<=n;i++){
            dp[i][1] = sum[i];
            lim = min(i, k);
            for(int j=2;j<=lim;j++){
                for(int l=j-1;l<i;l++){
                    t = max(dp[l][j-1], sum[i] - sum[l]);
                    if(dp[i][j] > t){
                        dp[i][j] = t;
                    }
                  //  printf("dp[%d][%d] = %d\n", i, j, dp[i][j]);
                }
            }
        }

    //    cout<<dp[n][k]<<endl;
        res = dp[n][k];
        memset(mark, false, sizeof(mark));
        int s = 0, pos = k - 1;
        for(int i=n;i>=1;i--){
            if(s + num[i] > res){
                mark[i] = true;
                pos--;
                s = 0;
            }
            s += num[i];
        }
        for(int i=1;i<=n && pos;i++){
            if(!mark[i]){
                mark[i] = true;
                pos--;
            }
        }
        for(int i=1;i<=n;i++){
            printf("%d", num[i]);
            if(i == n) puts("");
            else printf(" ");
            if(mark[i]){
                printf("/ ");
            }
        }
    }
    return 0;
}
