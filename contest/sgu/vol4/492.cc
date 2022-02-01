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
#define maxn 25
using namespace std;
typedef __int64 ll;
int num[maxn], m;
ll dp[maxn][3];


ll dfs(int pos, int state, bool flag){
    if (pos == -1) return state != 2;
    if(!flag && dp[pos][state] != -1) return dp[pos][state];

    ll ret = 0;
    int end = flag ? num[pos] : 9;
    for (int i = 0; i <= end; ++i) {
        if(state == 2) ret += dfs(pos - 1, 2, flag && i == num[pos]);
        else if(state == 1 && i == 3) ret += dfs(pos - 1, 2, flag && i == num[pos]);
        else if(i == 1) ret += dfs(pos - 1, 1, flag && i == num[pos]);
        else ret += dfs(pos - 1, 0, flag && i == num[pos]);
    }
    if(!flag) dp[pos][state] = ret;
    return ret;
}

void init(ll a) {
    memset(dp, 0xff, sizeof dp);
    m = 0; for (;a ;a /= 10LL) num[m++] = a % 10;
}

ll ans;

void find(int pos, int state, ll now, ll k, bool flag) {
    if(pos == -1) {
        if(state != 2){
            if(k == 1) ans = now;
        }
        return;
    }
    int end = flag ? num[pos] : 9;
    int p; ll t;
    int ns;
    for (p = 0; p <= end; ++p) {
        if(state == 2) {
            ns = 2;
            t = dfs(pos - 1, 2, flag && p == num[pos]);
        }
        else if(state == 1 && p == 3) {
            ns = 2;
            t = dfs(pos - 1, 2, flag && p == num[pos]);
        }
        else if(p == 1) {
            ns = 1;
            t = dfs(pos - 1, 1, flag && p == num[pos]);
        }
        else {
            ns = 0;
            t = dfs(pos - 1, 0, flag && p == num[pos]);
        }
        if(t < k) k -= t;
        else break;
    }
    find(pos - 1, ns, now * 10LL + p, k, flag && p == end);
}

int main() {
    int T;
    ll a;
    init(9000000000000000000LL);
    for (scanf("%d", &T); T--; ) {
        scanf(" %I64d", &a);
        find(m, 0, 0, a + 1, true);
        printf("%I64d\n", ans);
    }
    return 0;
}
