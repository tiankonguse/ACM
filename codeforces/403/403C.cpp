/*
 * 403C.cpp
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
const int N = 2005;
int n;
int low[N], dfn[N], id[N], stack[N], inS[N];
int stop, ts, idn;
vector <int> E[N];
int a[N][N];

void dfs(int u) {
    stack[stop++] = u;
    dfn[u] = ts++;
    low[u] = dfn[u];
    inS[u] = 1;
    rep (v, n) if (a[u][v]) {
        if (dfn[v] == -1) {
            dfs(v);
            low[u] = min(low[u], low[v]);
        } else if (inS[v]) {
            low[u] = min(low[u], dfn[v]);
        }
    }
    if (low[u] == dfn[u]) {
        while (stack[--stop] != u) {
            id[stack[stop]] = idn;
            inS[stack[stop]] = 0;
        }
        id[u] = idn++;
        inS[u] = 0;
    }
}

void SCC(int n) {
    idn = ts = stop = 0;
    rep (i, n) dfn[i] = -1, inS[i] = 0;
    rep (i, n)
        if (dfn[i] == -1) 
            dfs(i);
}

int main() {
    scanf("%d", &n);
    rep (i, n) rep (j, n) scanf("%d", &a[i][j]);
    SCC(n);
    if (idn == 1) {
        puts("YES");
    } else {
        puts("NO");
    }
}

