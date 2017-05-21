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
int dp[maxn][maxn];
int a[maxn];
int main(){
    int n;
    while(~scanf("%d", &n)){
        for(int i=1;i<=n;i++){
            scanf("%d", &a[i]);
            dp[i][i] = a[i] * n;
        }
        for(int len=1;len<n;len++){
            for(int i=1;i+len<=n;i++){
                dp[i][i+len] = max(dp[i+1][i+len] + a[i] * (n - len),
                                   dp[i][i+len-1] + a[i+len] * (n - len));
            }
        }
        printf("%d\n", dp[1][n]);
    }
    return 0;
}
