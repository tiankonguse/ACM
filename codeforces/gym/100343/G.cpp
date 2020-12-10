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
int p[N], dfn[N], low[N], ans[N], need[N], rest[N], Tr[N];

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
            dfs(v);
            need[u] += need[v];
            if (low[v] < low[u]) {
                low[u] = low[v];
                path[u] = E[u][i];
            }
            treeEdge[u].push_back(E[u][i]);
        } else if (dfn[v] < low[u]) {
            low[u] = dfn[v];
            path[u] = E[u][i];
        }
    }
}

void give(int u) {
    rest[u] = max(0, p[u]);
    rep (i, backEdge[u].size()) {
        int v = backEdge[u][i].u;
        give(v);
        int x = min(rest[v], sum - need[v]);
        rest[u] += x;
        rest[v] -= x;
        ans[backEdge[u][i].id] += x;
    }
}

void push(int u) {
    need[u] = max(0, -p[u]) - rest[u];
    rep (i, treeEdge[u].size()) {
        int v = treeEdge[u][i].v;
        push(v);
        need[u] += need[v];
        ans[treeEdge[u][i].id] += need[v];
    }
}

void gao() {
    for (int i = 1; i < a + b; i++) {
        backEdge[path[i].v].push_back(path[i]);
        //printf("treeEdge %d %d\n", path[i].u, path[i].v);
    }
    give(0);
    push(0);
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
    dfs(0);
    gao();
    rep (i, m) printf("%d ", ans[i]);
    return 0;
}

