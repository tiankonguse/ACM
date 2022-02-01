/*
 * 392E.cpp
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
const int N = 405;
const int INF = 1 << 26;
int n;
int v[N], a[N];
int f[N][N][2];
bool done[N][N][2];

int solve(int l, int r, bool o) {
    if (l > r) return 0;
    int &res = f[l][r][o];
    if (done[l][r][o]) return res;
    done[l][r][o] = 1;
    res = -INF;
    if (o) {
        if (l == r) {
            res = 0;
        } else if (a[l] != a[r]) {
            if (abs(a[l] - a[r]) == 1) {
                res = solve(l + 1, r - 1, 0);
            } else {
                int d = a[l] < a[r] ? 1 : -1;
                for (int i = l + 1; i < r; i++) {
                    if (a[i] == a[l] + d) {
                        res = max(res, solve(l + 1, i - 1, 0) + solve(i, r, 1));
                    }
                }
            }
        }
    } else {
        if (abs(a[l] - a[r]) + 1 <= r - l + 1) {
            res = max(res, solve(l, r, 1) + v[abs(a[l] - a[r]) + 1]);
        }
        for (int i = l; i < r; i++) {
            res = max(res, solve(l, i, 0) + solve(i + 1, r, 0));
        }
        for (int i = l + 1; i < r; i++) {
            if (a[i] > a[l] && a[i] > a[r]) {
                int len = a[i] - a[l] + a[i] - a[r] + 1;
                if (len <= r - l + 1) {
                    res = max(res, solve(l, i, 1) + solve(i, r, 1) + v[len]);
                }
            }
        }
    }
    return res;
}

int main() {
    scanf("%d", &n);
    rep (i, n) scanf("%d", &v[i + 1]);
    rep (i, n) scanf("%d", &a[i]);
    static int g[N];
    g[0] = 0;
    rep (i, n) {
        g[i + 1] = g[i];
        rep (j, i + 1) {
            g[i + 1] = max(g[i + 1], g[j] + solve(j, i, 0));
        }
    }
    printf("%d\n", g[n]);
    return 0;
}

