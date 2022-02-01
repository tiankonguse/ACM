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

using namespace std;
int const maxn = 22;
int const maxm = 111;
int dp[maxm][maxn][maxm];

int main()
{
    int n, e, d;
    for (; ~scanf("%d %d %d", &n, &e, &d); )
    {
        memset(dp, 0x3f, sizeof dp);
        dp[0][0][0] = 0;
        for (int i = 0; i < d; ++i)
        {
            for (int j = 0; j <= n; ++j)
            {
                for (int k = 0; k <= e; ++k)
                {
                    if (dp[i][j][k] != inf)
                    {
                        for (int l = 1; l * l <= k && i + l <= d; ++l)
                        {
                            dp[i + l][j][k - l * l] = min(dp[i + l][j][k - l * l], dp[i][j][k] + 1);
                        }
                        int em = e - i;
                        for (int l = 1; l * l <= em && i + l <= d; ++l)
                        {
                            dp[i + l][j + 1][em - l * l] = min(dp[i + l][j + 1][em - l * l], dp[i][j][k] + 1);
                        }
                    }
                }
            }
        }
        int ret = inf;
        for (int i = 0; i <= n; ++i)
        {
            for (int j = 0; j <= e; ++j)
            {
                ret = min(ret, dp[d][i][j]);
            }
        }
        if (ret == inf) puts("0");
        else printf("%d\n", ret);
    }
    return 0;
}
