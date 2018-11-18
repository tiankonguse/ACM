/*
 * 406C.cpp
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
const int N = 100005;
int n, m, inS[N], vis[N];
int order[N];
vector <int> E[N];
vector <int> extra[N];

void dfs(int u) {
    vis[u] = 1;
    inS[u] = 1;
    order[m++] = u;
    rep (i, E[u].size()) {
        int v = E[u][i];
        if (!vis[v])
            dfs(v);
        else if (inS[v])
            extra[u].push_back(v);
    }
    inS[u] = 0;
}

int main() {
    scanf("%d%d", &n, &m);
    rep (i, m) {
        int u, v;
        scanf("%d%d", &u, &v);
        u--;
        v--;
        E[u].push_back(v);
        E[v].push_back(u);
    }
    if (m & 1) {
        puts("No solution");
        return 0;
    }
    m = 0;
    dfs(0);
    for (int k = m - 1; k >= 0; k--) {
        int u = order[k];
        while (extra[u].size() >= 2) {
            int x = extra[u].back();
            extra[u].pop_back();
            int y = extra[u].back();
            extra[u].pop_back();
            printf("%d %d %d\n", x + 1, u + 1, y + 1);
        }
        if (!extra[u].empty()) {
            int x = extra[u].back();
            extra[x].push_back(u);
        }
    }
}

