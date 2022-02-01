#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <bitset>

#define inf 0x3f3f3f3f
#define INF 0x3FFFFFFFFFFFFFFFLL
#define maxn 1001001
using namespace std;
typedef __int64 ll;
ll a[maxn][2], b[maxn];
ll dp[maxn][2];
ll getint()
{
    ll ret=0;
  char tmp;
    while(!isdigit(tmp=getchar()));
    do{
		ret=(ret<<3)+(ret<<1)+tmp-'0';
    }while(isdigit(tmp=getchar()));
    return ret;
}
int main(){
    ll n, sx, sy, dx, dy;
    while (n = getint()) {
        if (!n) break;
        sy = getint(), sx = getint(), dy = getint(), dx = getint();
        if (sx > dx) {swap(sy, dy); swap(sx, dx);}
        for (int i = 0; i < n; ++i) {
            a[i][0] = getint();
        }
        for (int i = 0; i <= n; ++i) {
            b[i] = getint();
        }
        for (int i = 0; i < n; ++i) {
            a[i][1] = getint();
        }
        ll ta = 0;
        for (int i = sx - 1; i >= 0; --i) {
            ta += a[i][0] + a[i][1];
            b[sx] = min(b[sx], ta + b[i]);
        }
        ta = 0;
        for (int i = dx; i < n; ++i) {
            ta += a[i][0] + a[i][1];
            b[dx] = min(b[dx], ta + b[i + 1]);
        }
        if (sy == 0) {
            dp[sx][0] = 0;
            dp[sx][1] = b[sx];
        }
        else {
            dp[sx][1] = 0;
            dp[sx][0] = b[sx];
        }
        for (int i = sx + 1; i <= dx; ++i) {
            dp[i][0] = min(dp[i - 1][0] + a[i - 1][0], dp[i - 1][1] + a[i - 1][1] + b[i]);
            dp[i][1] = min(dp[i - 1][1] + a[i - 1][1], dp[i - 1][0] + a[i - 1][0] + b[i]);
//            printf("dp[%d][0] = %I64d, dp[%d][1] = %I64d\n", i, dp[i][0], i, dp[i][1]);
        }
        printf("%I64d\n", dp[dx][dy]);
    }
    return 0;
}
