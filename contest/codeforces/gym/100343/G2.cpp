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
int a, b, m, sum;
int p[N], dfn[N], low[N], ans[N], need[N], rest[N], depth[N];
int fa[N][17], faback[N][17];
int need2[N], rest2[N];

struct Edge {
    int id, u, v;
    Edge() {
        id = u = v = -1;
    }
    Edge(int id, int u, int v) : id(id), u(u), v(v) {}
} path[N];

vector <Edge> E[N], treeEdge[N], backEdge[N];

void fix(int &t) {
    if (t < 0) {
        t = -t - 1;
    } else {
        t = t - 1 + a;
    }
}

void dfs(int u) {
    static int cnt = 0;
    need[u] = max(0, -p[u]);
    dfn[u] = ++cnt;
    low[u] = dfn[u];
    rep (i, E[u].size()) {
        int v = E[u][i].v;
        if (dfn[v] == -1) {
            fa[v][0] = u;
            depth[v] = depth[u] + 1;
            dfs(v);
            need[u] += need[v];
            if (low[v] < low[u]) {
                low[u] = low[v];
                faback[u][0] = v;
                path[u] = E[u][i];
            }
            treeEdge[u].push_back(E[u][i]);
        } else if (dfn[v] < low[u]) {
            low[u] = dfn[v];
            faback[u][0] = v;
            path[u] = E[u][i];
        }
    }
}

int getLca(int u, int v) {
    if (depth[u] > depth[v]) swap(u, v);
    for (int k = 16; depth[v] != depth[u] && k >= 0; k--)
        if (depth[fa[v][k]] >= depth[u]) 
            v = fa[v][k];
    if (u == v) return u;
    for (int k = 16; k >= 0; k--) {
        if (fa[u][k] != fa[v][k]) {
            u = fa[u][k];
            v = fa[v][k];
        }
    }
    return fa[u][0];
}

void gao() {
    int i = 0, j = a;
    while (i < a && j < a + b) {
        int value = min(p[i], -p[j]);
        int lca = getLca(i, j);
        int u = i, v = j;
        if (dfn[u] > dfn[v]) swap(u, v);
        
        if (!p[i]) i++;
        if (!p[j]) j++;
    }
}

int main() {
    freopen("transport.in", "r", stdin);
    freopen("transport.out", "w", stdout);
    puts("YES");
    scanf("%d%d%d", &a, &b, &m);
    sum = 0;
    rep (i, a + b) {
        scanf("%d", &p[i]);
        if (i >= a) {
            p[i] = -p[i];
        } else {
            sum += p[i];
        }
    }
    rep (i, m) {
        int u, v;
        scanf("%d%d", &u, &v);
        fix(u);
        fix(v);
        E[u].push_back(Edge(i, u, v));
    }
    fill_n(dfn, a + b, -1);
    fa[0][0] = 0;
    faback[0][0] = 0;
    depth[0] = 0;
    dfs(0);
    gao();
    rep (i, m) printf("%d ", ans[i]);
    return 0;
}

