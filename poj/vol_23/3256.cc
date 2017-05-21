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
#define maxn 1010
#define maxm 20200
using namespace std;
struct node {
    int u, next;
} e[maxm];
int p[maxn], idx;
void addedge(int u, int v) {
    e[idx].u = v;
    e[idx].next = p[u];
    p[u] = idx++;
}
void init() {
    idx = 0;
    memset(p, 0xff, sizeof p);
}

int cow[maxn];
int mark[maxn];
bool used[maxn];
void dfs(int u) {
    int v;
    mark[u]++;
    used[u] = true;
    for (int i = p[u]; ~i; i = e[i].next) {
        v = e[i].u;
        if (!used[v]) {
            dfs(v);
        }
    }
}
int main() {
    int k, n, m, a, b;
    while (~scanf("%d%d%d", &k, &n, &m)) {
        for (int i = 0; i < k; ++i) scanf("%d", &cow[i]);
        init();
        for (int i = 0; i < m; ++i) {
            scanf("%d%d", &a, &b);
            addedge(a, b);
        }
        memset(mark, 0, sizeof mark);
        for (int i = 0; i < k; ++i) {
            memset(used, false, sizeof used);
            dfs(cow[i]);
        }
        int ret = 0;
        for (int i = 1; i <= n; ++i) ret += mark[i] == k;
        printf("%d\n", ret);
    }
    return 0;
}
