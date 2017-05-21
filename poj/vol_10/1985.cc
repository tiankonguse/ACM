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
#include <ctime>

#define inf 0x3f3f3f3f
#define Inf 0x3FFFFFFFFFFFFFFFLL

using namespace std;
int const maxn = 40404;
int const maxm = 80808;
struct edges {
    int u, c, next;
} e[maxm];
int p[maxn], idx;
void init() {
    idx = 0;
    memset(p, 0xff, sizeof p);
}
void addedge(int u, int v, int c) {
    e[idx].u = v;
    e[idx].c = c;
    e[idx].next = p[u];
    p[u] = idx++;
}
int rm, rc;
void dfs(int u, int pre, int s) {
    int v;
    if (s > rm) {
        rm = s;
        rc = u;
    }
    for (int i = p[u]; ~i; i = e[i].next) {
        v = e[i].u;
        if (v != pre) {
            dfs(v, u, s + e[i].c);
        }
    }
}

int main() {
    int n, m;
    int a, b, c;
    while (~scanf("%d%d", &n, &m)) {
        init();
        for (int i = 0; i < m; ++i) {
            scanf("%d %d %d %*c", &a, &b, &c);
            addedge(a, b, c);
            addedge(b, a, c);
        }
        rm = 0;
        dfs(1, -1, 0);
        rm = 0;
        dfs(rc, -1, 0);
        printf("%d\n", rm);
    }
    return 0;
}
