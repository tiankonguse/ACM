#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
#include <sstream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <ctime>

#define inf 0x3f3f3f3f
#define Inf 0x3FFFFFFFFFFFFFFFLL
using namespace std;
typedef long long ll;
int const maxn = 10010;
int const maxm = 100100;
struct edges{ int u, w, next; } e[maxm];
int p[maxn], idx;
void addedge(int u, int v, int w) {
	e[idx].u = v, e[idx].w = w, e[idx].next = p[u], p[u] = idx++;
}
void init() { idx = 0; memset(p, 0xff, sizeof p); }

int dp[maxn][2];
int dfs(int u, int pre) {
    int v;
    int mx1 = 0, mx2 = 0;
    for (int i = p[u]; ~i; i = e[i].next) {
        v = e[i].u;
        if (v != pre) {
            int t = dfs(v, u) + e[i].w;
            if (t > mx1) {
                mx2 = mx1;
                mx1 = t;
            }
            else if (t > mx2) {
                mx2 = t;
            }
        }
    }
    dp[u][0] = mx1, dp[u][1] = mx2;
    return dp[u][0];
}

void dfs2(int u, int pre, int pc) {
    int v, r;
    if (pre != -1) {
        if (dp[pre][0] - dp[u][0] == pc) r = dp[pre][1] + pc;
        else r = dp[pre][0] + pc;
        if (r > dp[u][0]) {
            dp[u][1] = dp[u][0];
            dp[u][0] = r;
        }
        else if (r > dp[u][1]) {
            dp[u][1] = r;
        }
    }
    for (int i = p[u]; ~i; i = e[i].next) {
        v = e[i].u;
        if (v != pre) {
            dfs2(v, u, e[i].w);
        }
    }
}

int main() {
	int n, a, c;
	scanf("%d", &n);
	init();
	for (int i = 2; i <= n; ++i) {
		scanf("%d%d", &a, &c);
		addedge(i, a, c);
		addedge(a, i, c);
	}
	dfs(1, -1);
	dfs2(1, -1, 0);
	for (int i = 1; i <= n; ++i) printf("%d\n", dp[i][0]);
	return 0;
}

