/*
 * 392C.cpp
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

const int Mod = 1000000007;

struct Matrix_t {
    static const int N = 83;
    int d[N][N];
    Matrix_t() {
        memset(d, 0, sizeof(d));
    }

    static Matrix_t ONE() {
        Matrix_t res;
        rep (i, N) res.d[i][i] = 1;
        return res;
    }

    Matrix_t operator * (const Matrix_t &oth) const {
        Matrix_t ret;
        for (int k = 0; k < N; k++) {
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    ret.d[i][j] += (ll)(d[i][k]) * oth.d[k][j] % Mod;
                    if (ret.d[i][j] >= Mod) {
                        ret.d[i][j] -= Mod;
                    }
                }
            }
        }
        return ret;
    }
};

ll Pow(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a;
        a = a * a % Mod;
        b >>= 1;
    }
    return res;
}

Matrix_t Pow(Matrix_t a, ll b) {
    Matrix_t res = Matrix_t::ONE();
    while (b) {
        if (b & 1) res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

int main() {
    ll n, k, C[50][50];
    cin >> n >> k;
    Matrix_t a, b;
    rep (i, k + 1) a.d[0][i] = 1;
    rep (i, k + 1) a.d[0][k + 1 + i] = 2 * Pow(2, i) % Mod;
    C[0][0] = 1;
    for (int i = 1; i < 50; i++) {
        for (int j = 0; j <= i; j++) {
            C[i][j] = 0;
            if (j < i) C[i][j] = (C[i][j] + C[i - 1][j]) % Mod;
            if (j > 0) C[i][j] = (C[i][j] + C[i - 1][j - 1]) % Mod;
        }
    }
    rep (j, k + 1) {
        b.d[j + k + 1][j] = 1;
    }
    rep (j, k + 1) rep (i, j + 1) {
        b.d[i][j + k + 1] = C[j][i] * Pow(2, j - i) % Mod;
        b.d[i + k + 1][j + k + 1] = C[j][i];
    }
    b.d[k * 2 + 2][k * 2 + 2] = 1;
    b.d[k        ][k * 2 + 2] = 1;
    b = Pow(b, n);
    a = a * b;
    cout << a.d[0][k * 2 + 2] << endl;
}