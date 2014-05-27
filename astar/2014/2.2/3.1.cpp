#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<string>
#include<queue>
#include<cmath>
#include<stack>
#include<algorithm>
#include<functional>
#include<stdarg.h>
using namespace std;
#ifdef __int64
typedef __int64 LL;
#else
typedef long long LL;
#endif

const int N = 100010;
const int M = N;

int dates[N];
LL earning[N];
int start[N], finish[N], rates[N];
int n,m;
LL ans;

int map[N];
int mapCount;

int dp[M];

int head[N],to[M],cost[M],next[M],cnt;
void addedge(int u, int v, int w) {
    to[cnt] = v;
    cost[cnt] = w;
    next[cnt] = head[u];
    head[u] = cnt++;
}
void init() {
    memset(head, -1, sizeof(head));
    cnt=0;
}



void read() {
    scanf("%d%d", &n, &m);

    for(int i = 0; i < n; ++i) {
        scanf("%d%lld", &dates[i], &earning[i]);
    }

    for(int i = 0; i < m; ++i) {
        scanf("%d%d%d", &start[i], &finish[i], &rates[i]);
    }
}

void bulid() {
    init();
    for(int i = 0; i < m; ++i) {
        addedge(start[i], finish[i], rates[i]);
    }
}


void DP() {
    memset(dp, 0,  sizeof(dp));
    for(int u = N-2; u >= 0; --u) {
    	dp[u] = dp[u+1];
        for(int p = head[u]; p != -1; p = next[p]) {
            dp[u] = max(dp[u], dp[to[p]] + cost[p]);
        }
    }
}

void output(int tt) {
    printf("Case #%d:\n", tt);
#if (defined _UNIX) || (defined linux)
    printf("%lld.%02lld\n", ans / 100, ans % 100);
#else
    printf("%I64d.%02lld\n", ans / 100, ans % 100);
#endif

}

int main() {
    int t;
    scanf("%d",&t);
    for(int tt=1; tt<=t; tt++) {
        read();

        bulid();

        DP();

        ans = 0;
        for(int i = 0; i < n; ++i) {
            ans += earning[i] * dp[dates[i]];
        }

        output(tt);
    }

    return 0;
}
