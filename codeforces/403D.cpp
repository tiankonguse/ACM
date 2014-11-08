/*
 * 403D.cpp
 * 
 * Copyright edward_mj
 * 
 */

#include <cstdio>
#include <cstring>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <string>
using namespace std;
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define foreach(it,v) for (__typeof((v).end()) it = (v).begin(); it != (v).end(); it++)
typedef long long ll;
typedef pair <int, int> PII;
const int Mod =  1000000007;
const int N = 1005;
int Tc;
int fac[N];
int g[N][N][2];
int w[N][N];
int C[N][N];
//int ans[N][N];

int main() {
    fac[0] = 1;
    rep (i, 1000) {
        fac[i + 1] = fac[i] * (ll)(i + 1) % Mod;
    }
    //cout << fac[1] << endl;
    g[0][1][1] = 1;
    for (int i = 0; i <= 1000; i++) {
        for (int j = 1; j <= 1000; j++) {
            if (i >= j) g[i][j][0] = (g[i - j][j][0] + (ll)g[i - j][j][1]) % Mod;
            if (g[i][j][1]) continue;
            g[i][j][1] = g[i][j - 1][0];
        }
    }
    for (int i = 0; i <= 1000; i++) {
        for (int j = 1; j <= 1000; j++) {
            w[i][j] = (g[i][j][0] + g[i][j][1]) % Mod * (ll)(fac[j]) % Mod;
        }
    }
    C[0][0] = 1;
    for (int i = 1; i <= 1000; i++)
        for (int j = 0; j <= i; j++) {
            C[i][j] = C[i - 1][j];
            if (j) C[i][j] = (C[i][j] + C[i - 1][j - 1]) % Mod;
        }
    //cout << w[0][1] << endl;
    //cout << C[2][1] << endl;
    scanf("%d", &Tc);
    int k, n;
    while (Tc--) {
        scanf("%d%d", &n, &k);
        n--;
        int ans = 0;
        //cout << n << k << endl;
        for (int i = 0; i <= n; i++) {
            int lhs = i;
            int rhs = n - i;
            ans += C[lhs + 1][k] * (ll)w[rhs][k] % Mod;
            //cout << C[lhs + 1][k] << ",  " << w[rhs][k] << endl;
            if (ans >= Mod) ans -= Mod;
        }
        printf("%d\n", ans);
    }
}

