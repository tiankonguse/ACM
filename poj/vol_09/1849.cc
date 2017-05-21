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
#define maxn 100010
#define maxm 200020
#define maxk 3
using namespace std;
int n, s;
int const k = 2;
struct edges {
    int u, c, next;
} e[maxm];
int p[maxn], idx;
void addedge(int u, int v, int c) {
    e[idx].u = v;
    e[idx].c = c;
    e[idx].next = p[u];
    p[u] = idx++;
}
void init() {
    idx = 0;
    memset(p, 0xff, sizeof p);
}
int dp[maxn][maxk];

void dfs(int u, int pre) {
    int v, c;
    for (int i = p[u]; ~i; i = e[i].next) {
        v = e[i].u;
        c = e[i].c;
        if (v != pre) {
            dfs(v, u);
            for (int j = k; j >= 0; --j) {
                dp[u][j] += dp[v][0] + c + c;
                for (int t = j; t >= 1; --t) {
                    dp[u][j] = min(dp[u][j], dp[u][j - t] + dp[v][t] + c * t);
                }
            }
        }
    }
//    for (int i = 0; i <= k; ++i) {
//        printf("dp[%d][%d] = %d\n", u, i, dp[u][i]);
//    }

}

int main() {
    int a, b, c;
    while (~scanf("%d%d", &n, &s)) {
        init();
        for (int i = 1; i < n; ++i) {
            scanf("%d%d%d", &a, &b, &c);
            addedge(a, b, c);
            addedge(b, a, c);
        }
        memset(dp, 0, sizeof dp);
        dfs(s, -1);
        printf("%d\n", dp[s][k]);
    }
    return 0;
}
