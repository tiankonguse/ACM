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
#define maxn 12
using namespace std;
typedef __int64 ll;
int num[maxn], m;
ll dp[maxn][4];

int dfs(int pos, int state, bool flag) {
    if(pos == -1) return state == 3;
    if(!flag && dp[pos][state] != -1) return dp[pos][state];
    int end = flag ? num[pos] : 9;
    ll ret = 0;
    for (int i = 0; i <= end; ++i) {
        if(state == 3) ret += dfs(pos - 1, 3, flag && i == end);
        else ret += dfs(pos - 1, (i == 6)? state + 1 : 0, flag && i == end);
    }
    if(!flag) dp[pos][state] = ret;
    return ret;
}

void init(ll n) {
    m = 0;
    for (; n; n /= 10) num[m++] = n % 10;
    num[m] = 0;
    memset(dp, 0xff, sizeof dp);
    dfs(m - 1, 0, true);
}

ll ans;

void find(int pos, int state, ll now, int k, bool flag) {
    if(pos == -1) {
        if(state == 3) ans = now;
        return;
    }
    int end = flag ? num[pos] : 9;
    int p, t;
    for (p = 0; p <= end; ++p) {
        if(state == 3) t = dfs(pos - 1, 3, flag && p == end);
        else t = dfs(pos - 1, (p == 6) ? state + 1 : 0, flag && p == end);
        if(t < k) k -= t;
        else break;
    }
    if(state == 3) find(pos - 1, 3, now * 10 + p, k, flag && p == end);
    else find(pos - 1, (p == 6) ? state + 1 : 0, now * 10 + p, k, flag && p == end);
}

int main(){
    init(10000000000LL);
    int T, k;
    for (scanf("%d", &T); T--; ) {
        scanf("%d", &k);
        find(m, 0, 0, k, true);
        printf("%I64d\n", ans);
    }
    return 0;
}
