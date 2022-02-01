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
#define maxn 6060
#define maxm 12120
using namespace std;
int val[maxn];
struct edges {
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

int dp[maxn][2];
bool used[maxn];

void dfs(int u) {
    used[u] = true;
    int v;
    dp[u][0] = 0, dp[u][1] = val[u];
    for (int i = p[u]; ~i; i = e[i].next) {
        v = e[i].u;
        if (!used[v]) {
            dfs(v);
            dp[u][0] += max(dp[v][0], dp[v][1]);
            dp[u][1] += dp[v][0];
        }
    }
}
int main() {
    int n, a, b;
    while (~scanf("%d", &n)) {
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &val[i]);
        }
        init();
        while (scanf("%d%d", &a, &b)) {
            if (a == 0 && b == 0) break;
            addedge(a, b);
            addedge(b, a);
        }
        memset(dp, 0, sizeof dp);
        memset(used, false, sizeof used);
        int ret = 0;
        for (int i = 1; i <= n; ++i) {
            if (!used[i]) {
                dfs(i);
                ret += max(dp[i][0], dp[i][1]);
            }
        }
        printf("%d\n", ret);
    }
    return 0;
}
