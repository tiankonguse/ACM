/*
 * A.cpp
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
#include <queue>
#include <cmath>
using namespace std;
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define foreach(it,v) for (__typeof((v).end()) it = (v).begin(); it != (v).end(); it++)
typedef long long ll;
typedef pair <int, int> PII;
const int N = 10;
const double eps = 1e-6;
int n, m;
int id[N][N], a[N][N], c[N][N], fa[N];
vector < vector <double> > vec;

void maxflow() {
    while (1) {
        queue <int> Q;
        static int v[N];
        memset(v, 0, sizeof(v));
        v[0] = 1;
        Q.push(0);
        while (!Q.empty()) {
            int u = Q.front();
            Q.pop();
            rep (i, n) if (!v[i] && c[u][i]) {
                v[i] = 1;
                fa[i] = u;
                Q.push(i);
            }
        }
        if (v[n - 1]) {
            int minv = 0x7FFFFFFF;
            for (int i = n - 1; i; i = fa[i])
                minv = min(minv, c[fa[i]][i]);
            for (int i = n - 1; i; i = fa[i]) {
                c[fa[i]][i] -= minv;
                c[i][fa[i]] += minv;
            }
        } else {
            break;
        }
    }
}

int v[N];

void dfs(int st, int i, int mask = 0) {
    rep (j, n) if (!v[j] && c[i][j]) {
        v[j] = 1;
        dfs(st, j, mask | 1 << id[i][j]);
        v[j] = 0;
    }
    if (i != st && c[i][st]) {
        mask |= 1 << id[i][st];
        vector <double> cur(m);
        rep (j, m) {
            if (mask & 1 << j) cur[j]++;
            if (mask & 1 << (j + m)) cur[j]--;
        }
        vec.push_back(cur);
    }
}

void gauss() {
    int ans = 0, st = 0;
    rep (k, m) {
        for (int i = st; i < vec.size(); i++) {
            if (fabs(vec[i][k]) > eps) {
                ans++;
                swap(vec[i], vec[st]);
                st++;
                for (i = st; i < vec.size(); i++) {
                    if (fabs(vec[i][k]) > eps) {
                        double mul = vec[i][k] / vec[st - 1][k];
                        for (int j = k; j < m; j++) {
                            vec[i][j] -= mul * vec[st - 1][j];
                        }
                    }
                }
                break;
            }
        }
    }
    printf("%d\n", ans);
}

int main() {
    freopen("dimension.in", "r", stdin);
    freopen("dimension.out", "w", stdout);
    scanf("%d%d", &n, &m);
    rep (i, m) {
        int u, v, c;
        scanf("%d%d%d", &u, &v, &c);
        u--; v--;
        id[u][v] = i;
        id[v][u] = i + m;
        a[u][v] = c;
    }
    rep (i, n) rep (j, n) c[i][j] = a[i][j];
    maxflow();
    memset(v, 0, sizeof(v));
    rep (i, n) {
        v[i] = 1;
        dfs(i, i);
        v[i] = 0;
    }
    gauss();
}