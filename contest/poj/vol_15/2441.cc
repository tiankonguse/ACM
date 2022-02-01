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
#define maxn 21
#define maxm (1 << 20)
using namespace std;
int dp[maxm];
int list[maxn][maxn];
int p[maxn];
int main(){
    int n, m;
    while(~scanf("%d%d", &n, &m)){
        for(int i=1;i<=n;i++){
            scanf("%d", &p[i]);
            for(int j=0;j<p[i];j++){
                scanf("%d", &list[i][j]);
                list[i][j]--;
            }
        }
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        int mx = (1 << m);
        for(int i=1;i<=n;i++){
            for(int j=0;j<mx;j++){
                if(dp[j] != -1 && __builtin_popcount(j) == i - 1){
                    for(int k=0;k<p[i];k++){
                        if(!(j & (1 << list[i][k]))){
                            dp[j | (1 << list[i][k])] += dp[j];
                        }
                    }
                }
            }
        }
        int res = 0;
        for(int i=0;i<mx;i++) if(__builtin_popcount(i) == n) res += dp[i];
        printf("%d\n", res);
    }
    return 0;
}
