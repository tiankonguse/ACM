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
#define maxn 5050
#define maxm 70070
using namespace std;
bool mark[maxm];
int dp[maxn];
int cnt[maxn];
int a[maxn];

int main(){
    int n, t, mx, mm, res, tl, last;
    while(~scanf("%d", &n)){
        for(int i=1;i<=n;i++){
            scanf("%d", &a[i]);
        }
        memset(dp, 0, sizeof(dp));
        cnt[0] = 1;
        a[0] = 70000, a[n+1] = -1;
        mm = 0;
        for(int i=1;i<=n+1;i++){
            mx = 0, t = -1;
            memset(mark, false, sizeof(mark));
            for(int j=i-1;j>=0;j--){
                if(a[j] > a[i]){
                    if(dp[j] + 1 > mx){
                        mark[ a[j] ] = true;
                        mx = dp[j] + 1;
                        t = cnt[j];
                        tl = a[j];
                      //  printf("%d +1 ", j);
                    }
                    else if(dp[j] + 1 == mx && !mark[ a[j] ]){
                        t += cnt[j];
                      //  printf("%d ++ ", j);
                        mark[ a[j] ] = true;
                    }
                }
            }
            dp[i] = mx;
            cnt[i] = t;
           // puts("");
           // printf("dp[%d] = %d, cnt[%d] = %d\n", i, mx, i, t); system("pause");
        }
        printf("%d %d\n", dp[n+1] - 1, cnt[n+1]);
    }
    return 0;
}
