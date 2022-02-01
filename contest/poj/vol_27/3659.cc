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
#define maxn 10100
#define maxm 20200
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
void init() {
    idx = 0;
    memset(p, 0xff, sizeof p);
}
int dp[maxn][3];
bool used[maxn];
void dfs(int u) {
    used[u] = true;
    int v;
    dp[u][0] = 1; // self
    dp[u][1] = 0; // down
    dp[u][2] = 0; // up
    bool flag = false; int mi = inf;
    for (int i = p[u]; ~i; i = e[i].next) {
        v = e[i].u;
        if (!used[v]) {
            dfs(v);
            dp[u][0] += min(dp[v][0], min(dp[v][1], dp[v][2]));
            dp[u][2] += min(dp[v][0], dp[v][1]);
            dp[u][1] += min(dp[v][0], dp[v][1]);
            if (dp[v][0] <= dp[v][1]) flag = true;
            else if(!flag) mi = min(mi, dp[v][0] - dp[v][1]);
        }
    }
    if (dp[u][1] == 0) dp[u][1] = 1;
    else if(!flag) dp[u][1] += mi;
//    for (int i = 0; i < 3; ++i) {
//        printf("dp[%d][%d] = %d\n", u, i, dp[u][i]);
//    }
}
int main() {
    int n, a, b;
    while (~scanf("%d", &n)) {
        init();
        for (int i = 1; i < n; ++i) {
            scanf("%d %d", &a, &b);
            addedge(a, b);
            addedge(b, a);
        }
        memset(dp, 0, sizeof dp);
        memset(used, false, sizeof used);
        dfs(1);
        printf("%d\n", min(dp[1][0], dp[1][1]));
    }
    return 0;
}
