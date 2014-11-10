#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <iostream>
#include <string.h>

using namespace std;

const int MOD =  1000000007;

int N, K;
int dp[1000+5][1000+5][8], c[1000+5][1000+5];
int a[1000+5];
int main() {


#ifndef ONLINE_JUDGE;
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif

    scanf("%d %d", &N, &K);
    for(int i = 0; i < 1000+5; i++) {
        c[i][0] = c[i][i] = 1;
        for(int j = 1; j < i; j++) {
            c[i][j] = (c[i-1][j-1] + c[i-1][j]) % MOD;
        }
    }
    dp[0][0][6] = 1;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j <= i; j++) {
            for(int k = 0; k < 8; k++) {
                int t = (k + k) % 8;
                if(dp[i][j][k] == 0) continue;
                cout << i << " " << j << " " << k << " " << dp[i][j][k] << endl;
                dp[i+1][j][t] += dp[i][j][k];
                dp[i+1][j][t] %= MOD;
                if((k & 2) == 0) {
                    int _t = (t | 4);
                    dp[i+1][j+1][_t] += dp[i][j][k];
                    dp[i+1][j+1][_t] %= MOD;
                }
                if(i + 1 < N) {
                    t |= 1;
                    dp[i+1][j+1][t] += dp[i][j][k];
                    dp[i+1][j+1][t] %= MOD;
                }
            }
        }
    }
    cout << dp[3][0][0] << endl;



    for(int i = 0; i <= N; i++)  {
        for(int j = 0; j < 8; j++) {
            a[i] += dp[N][i][j];
            a[i] %= MOD;
        }
        //cout << i << " " << a[i] << endl;
        for(int k = 1; k <= N - i; k++)   a[i] = 1LL * k * a[i] % MOD;
      //  cout << i << " " << a[i] << endl;
    }
    for(int i = N; i >= 0; i--) {
        for(int j = i+1; j <= N; j++) {
            int tt = 1LL * a[j] * c[j][i] % MOD;
            a[i] -= tt;
            if(a[i] < 0)  a[i] += MOD;
        }
    }
    cout << a[K] << endl;
    return 0;
}
