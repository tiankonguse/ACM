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
#define maxs 210000
#define maxn 110
using namespace std;
int hz, hs = 1000;
int dp[maxs];
int s[maxn], f[maxn];
int main(){
    int n;
    while(~scanf("%d", &n)){
        hz = hs * n;
        for(int i=0;i<n;i++){
            scanf("%d%d", &s[i], &f[i]);
        }
        memset(dp, 0xc0, sizeof(dp));
        dp[hz] = 0;
        for(int i=0;i<n;i++){
           // int limit = max(0, s[i]);
            if(s[i] < 0){
                for(int v = 0; v <= (hz << 1) + s[i]; v++){
                    dp[v] = max(dp[v], dp[v - s[i]] + f[i]);
                }
            }
            else{
                for(int v = (hz << 1); v >= s[i]; v--){
                    dp[v] = max(dp[v], dp[v - s[i]] + f[i]);
                 //   if(dp[v] >= 0) {printf("dp[%d] = %d\n", v, dp[v]); system("pause");}
                }
            }
        }
        int res = 0;
        for(int i=hz;i<=(hz<<1);i++){
            if(dp[i] >= 0){
              //  printf("dp[%d] = %d\n", i, dp[i]);
                res = max(res, i + dp[i]);
            }
        }
        if(res - hz < 0) puts("0");
        else printf("%d\n", res - hz);
    }
    return 0;
}
