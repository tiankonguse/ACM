#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

const LL mod = 10e9 + 7;
LL dp[1111][1111][3];

LL dfs(int n, int m, int c){
    if(dp[n][m][c] != -1){
        return dp[n][m][c];
    }
    LL ans = 0;

    if(n == 0 && m == 0){
        return dp[n][m] = 1;
    }

    if(n > 0){
        ans += dfs(n-1, m);
    }

    if(m > 0){
        ans += dfs(n, m-1);
    }

    return dp[n][m] = ans % mod;
}

int main() {
    int n,m;
    memset(dp, -1, sizeof(dp));
    while(scanf("%d %d",&n, &n) != EOF){
        printf("%lld\n", dfs(n, m, 0));
    }
    return 0;
}
