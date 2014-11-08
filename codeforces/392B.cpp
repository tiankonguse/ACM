/*
 * 392B.cpp
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
const int N = 45;
const ll INF = 1LL << 62;
int n;
ll W[3][3];
ll f[3][3][N];

ll rec(int u, int v, int n) {
    if (n == 0) return 0;
    if (f[u][v][n] != -1) {
        return f[u][v][n];
    }
    int w = 3 - u - v;
    if (n == 1) {
        return min(W[u][v], W[u][w] + W[w][v]);
    }
    ll &res = f[u][v][n];
    res = min(rec(u, w, n - 1) + W[u][v] + rec(w, v, n - 1), rec(u, v, n - 1) + W[u][w] + rec(v, u, n - 1) + W[w][v] + rec(u, v, n - 1));
    return res;
}

int main() {
    memset(f, 0xff, sizeof(f));
    rep (i, 3) rep (j, 3) cin >> W[i][j];
    cin >> n;
    cout << rec(0, 2, n) << endl;
}

