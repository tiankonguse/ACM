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
#define maxn 2020
using namespace std;
int num[maxn];
bool dp[maxn];
int pre[maxn];
int res[maxn];
int main(){
    int n, m, l, s;
    while(scanf("%d%d", &m, &l) && m + l){
        scanf("%d", &n);
        s = 0;
        for(int i=1;i<=n;i++){
            scanf("%d", &num[i]);
            s += num[i];
        }
        memset(dp, false, sizeof(dp));
        dp[0] = true;
        pre[0] = -1;
        for(int i=1;i<=n;i++){
            for(int j=m;j>=num[i];j--){
                if(!dp[j] && dp[j - num[i]]){
                    dp[j] = true;
                    pre[j] = i;
                }
            }
        }
        int r = 0, cnt = 0;
        for(int j=m;j>=1;j--){
            if(dp[j]){
                r = j;
                break;
            }
        }
        if(s - r > l) puts("Impossible to distribute");
        else{
            while(pre[r] != -1){
                res[cnt++] = pre[r];
                r = r - num[ pre[r] ];
            }
            sort(res, res + cnt);
            printf("%d", cnt);
            for(int i=0;i<cnt;i++){
                printf(" %d", res[i]);
            }
            puts("");
        }
    }
    return 0;
}
