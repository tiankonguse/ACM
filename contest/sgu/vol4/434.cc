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
#define maxn 30
#define maxm 2097152
using namespace std;
int s[maxm], dp[maxm];
int a[maxn];

int main() {
    int n;
    while (~scanf("%d", &n)) {
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
        }
        int x, t = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%d", &x);
            a[i] -= x;
            t += a[i];
        }
        if (t != 0) puts("-1");
        else {
            memset(s, 0, sizeof s);
            memset(dp, 0, sizeof dp);
            int mx = 1 << n;
            for (int i = 0; i < mx; ++i) {
                for (int j = 0; j < n; ++j)  {
                    if (i & (1 << j)) s[i] += a[j];
                }
            }
            for (int i = 0; i < mx; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (!(i & (1 << j))) {
                        t = i ^ (1 << j);
                        dp[t] = max(dp[t], dp[i] + (s[i] == 0));
                    }
                }
            }
            printf("%d\n", n - dp[mx - 1]);
        }
    }
    return 0;
}

