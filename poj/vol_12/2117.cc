#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>

#define inf 0x3f3f3f3f
#define Inf 0x3FFFFFFFFFFFFFFFLL
#define maxn 10010
#define maxm 2002000
using namespace std;
struct edges {
    int u, next;
} e[maxm];
int p[maxn], idx;
void addedge(int u, int v) {
    e[idx].u = v;
    e[idx].next = p[u];
    p[u] = idx++;
}

int dfn[maxn], low[maxn], cnt[maxn], cont;
void dfs(int u, int pre) {
    int v;
    dfn[u] = low[u] = ++cont;
    for (int i = p[u]; ~i; i = e[i].next) {
        v = e[i].u;
        if (!dfn[v]) {
            dfs(v, pre);
            low[u] = min(low[u], low[v]);
            if (low[v] >= dfn[u]) ++cnt[u];
        }
        else {
            low[u] = min(low[u], dfn[v]);
        }
    }
    if (u != pre) ++cnt[u];
}
void init() {
    idx = cont = 0;
    memset(p, 0xff, sizeof p);
    memset(dfn, 0, sizeof dfn);
    memset(cnt, 0, sizeof cnt);
}

int main() {
    int n, m;
    int a, b;
    while (scanf("%d%d", &n, &m) && n + m) {
        init();
        for (int i = 0; i < m; ++i) {
            scanf("%d%d", &a, &b);
            addedge(a, b);
            addedge(b, a);
        }
        int s = 0;
        for (int i = 0; i < n; ++i) {
            if (!dfn[i]) {
                dfs(i, i);
                ++s;
            }
        }
        int ret = 0;
        for (int i = 0; i < n; ++i) {
            ret = max(ret, s - 1 + cnt[i]);
        }
        printf("%d\n", ret);
    }
    return 0;
}
