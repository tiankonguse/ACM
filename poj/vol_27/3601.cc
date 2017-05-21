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
#define maxn 111
using namespace std;
typedef __int64 ll;
ll arr[maxn];
ll mod;
ll powMod(ll a, int b) {
    ll ret = 1LL;
    while (b) {
        if (b & 1) ret = ret * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ret;
}
ll f[maxn], g[maxn];
ll dp[maxn];
int main() {
    int n, m;
    while (~scanf("%d%I64d", &n, &mod)) {
        mod <<= 1LL; 
        for (int i = 0; i < n; ++i) scanf("%I64d", &arr[n - i - 1]);
        for (int i = 0; i < n; ++i) {
          //  f[i] = powMod(2LL, i + 1) - 1;
          //  f[i] = (f[i] + mod) % mod;
            g[i] = powMod(2LL, i);
        }
        dp[0] = g[0];
        for (int i = 0; i < n - 1; ++i) {
            if (arr[i] > 1 && dp[i] % 2 == 1) {
                dp[i + 1] = dp[i] * 2 + 1;
                dp[i + 1] %= mod;
            }
            else {
                dp[i + 1] = dp[i] * 2;
                dp[i + 1] %= mod;
            }
        }
       // for (int i = 0; i < n; ++i) cout << dp[i] << " "; cout << endl;
        
        ll ret = 0;
        for (int i = 0; i < n; ++i) {
            ret += dp[i] * arr[i];
            if (dp[i] % 2 == 1 && arr[i] > 1) ret += arr[i];
            ret %= mod;
        }
        
        if (dp[n - 1] % 2 == 1 && arr[n - 1] > 1) ret = (ret - 1 + mod) % mod;
        ret %= (mod >> 1LL);
        printf("%I64d\n", ret);
    }
    return 0;
}
