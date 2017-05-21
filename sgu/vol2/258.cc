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
#define maxn 22
#define maxs 50
using namespace std;
typedef __int64 ll;
int num[maxn], m;
ll dp[maxn][maxs][11][11][11];

ll dfs(int pos, int limit, int s1, int s2, int mx1, int mx2, int tx1, int tx2, bool flag, bool beg) {
    if (pos == -1) {
        if (s1 == s2) return false;
        else if (s1 > s2) {
            return s2 + tx2 >= s1 || s1 - mx1 <= s2;
        }
        else if (s1 < s2) {
            return s1 + mx2 >= s2 || s2 - tx1 <= s1;
        }
        else return false;
    }
    if (!flag && pos >= limit && dp[pos][s1][mx1][mx2][tx1] != -1) return dp[pos][s1][mx1][mx2][tx1];
    int end = flag ? num[pos] : 9;
    int begin = beg ? 1 : 0;
    ll ret = 0;
    int t1, t2;
    for (int i = begin; i <= end; ++i) {
        if (beg) {
            t1 = i - 1;
        }
        else t1 = i;
        t2 = 9 - i;

        if (pos > limit) {

            ret += dfs(pos - 1, limit, s1 + i, s2, max(mx1, t1), max(mx2, t2), tx1, tx2, flag && i == end, 0);
        }
        else {
            if (s1 + mx2 >= s2 + i  || s1 - mx1 <= s2 + i + 9 * pos)
                ret += dfs(pos - 1, limit, s1, s2 + i, mx1, mx2, max(tx1, t1), max(tx2, t2), flag && i == end, 0);
        }
    }
    if (!flag) dp[pos][s1][mx1][mx2][tx1] = ret;
    return ret;
}
ll cal(ll n) {
    m = 0;
    for (; n; n /= 10) num[m++] = n % 10;
    num[m] = 0;
    ll ret = 0;
    int k = m;
    if (m & 1) --k;
    for (int i = k - 1; i > 0; i -= 2) {
        memset(dp, 0xff, sizeof dp);
        ret += dfs(i, i >> 1, 0, 0, 0, 0, 0, 0, i == m - 1, 1);
    }
    return ret;
}
int main() {
    ll a, b;

    while (~scanf("%I64d %I64d", &a, &b)) {
        printf("%I64d\n", cal(b) - cal(a - 1));
    }
    return 0;
}
