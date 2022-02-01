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
#define maxn 22
#define maxm 1024
using namespace std;
typedef __int64 ll;
int num[maxn];
int m;
ll dp[2][maxn][maxm];
ll dfs(int pos, int state, bool prefix_zero, bool flag) {
    if (pos == -1) return state != 0;
    if (!flag && dp[prefix_zero][pos][state] != -1) return dp[prefix_zero][pos][state];
    int end = flag ? num[pos] : 9;
    ll ret = 0; int ns;
    for (int i = 0; i <= end; ++i) {
        if (prefix_zero && i == 0) {
            ret += dfs(pos - 1, 0, true, flag && i == end);
        }
        else {
            ns = state | (1 << i);
            if (ns != state) {
                ret += dfs(pos - 1, ns, false, flag && i == end);
            }
        }
    }
    if (!flag) dp[prefix_zero][pos][state] = ret;
    return ret;
}
ll cal(int n) {
    m = 0;
    for (; n; n /= 10) num[m++] = n % 10;
    return dfs(m - 1, 0, true, true);
}

ll ans;

void find(int pos, int state, int prefix_zero, ll now, ll k, bool flag) {
    if(pos == -1) {
        ans = now;
        return;
    }
    int end = flag ? num[pos] : 9;
    int p, ns, ts = 0; ll t;
    for (p = 0; p <= end; ++p) {
        if (prefix_zero && p == 0) t = dfs(pos - 1, 0, true, flag && p == end);
        else {
            ns = state | (1 << p);
            if (ns != state) {
                t = dfs(pos - 1, ns, false, flag && p == end);
                ts = ns;
            }
            else t = 0;
        }
        if(t < k) k -= t;
        else break;
    }
    find(pos - 1, ts, prefix_zero && p == 0, now * 10 + p, k, flag && p == end);
}

int main() {
    memset(dp, 0xff, sizeof dp);
    cal(100000000);
    int n;
    while (~scanf("%d", &n) && n) {
        find(m - 1, 0, true, 0, n, true);
        printf("%I64d\n", ans);
    }
    return 0;
}
