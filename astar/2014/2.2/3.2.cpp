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

struct T {
    int start, finish, rate;
    bool operator<(const T &t2)const {
        return this->start < t2.start;// < : 大堆;< : 小堆
    }

} str[N];
int n,m, maxTime;
LL ans;


int dp[M];

void read() {
    scanf("%d%d", &n, &m);
    maxTime = 0;
    for(int i = 0; i < n; ++i) {
        scanf("%d%lld", &dates[i], &earning[i]);
        maxTime = max(maxTime, dates[i]);
    }

    for(int i = 0; i < m; ++i) {
        scanf("%d%d%d", &str[i].start, &str[i].finish, &str[i].rate);
        maxTime = max(maxTime, str[i].finish);
    }

}



void DP() {
    memset(dp, 0,  sizeof(dp));
    m--;
    for(int u = maxTime; u >= 0; --u) {
        dp[u] = dp[u+1];
        while(m >= 0 && u == str[m].start){
        	dp[u] = max(dp[u], dp[str[m].finish] + str[m].rate);
        	m--;
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

        sort(str,str+m);

        DP();

        ans = 0;
        for(int i = 0; i < n; ++i) {
            ans += earning[i] * dp[dates[i]];
        }

        output(tt);
    }

    return 0;
}
