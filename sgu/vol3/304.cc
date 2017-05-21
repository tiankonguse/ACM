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
#define maxn 606
#define mp make_pair
#define pb push_back

using namespace std;
int dp[maxn][maxn];
vector <pair<int, int> > v[maxn];
int cost[maxn];

int pre[maxn][maxn];
int res[maxn];

int main() {
    int n, k, p;
    int a, c;
    while (~scanf("%d%d%d", &n, &k, &p)) {
        for (int i = 1; i <= k; ++i) scanf("%d", &cost[i]);
        for (int i = 1; i <= n; ++i) {
            scanf("%d%d", &a, &c);
            v[c].pb(mp(a, i));
        }
        memset(dp, 0x3f, sizeof dp);
        memset(pre, 0xff, sizeof pre);
        dp[0][0] = 0;
        for (int i = 1; i <= k; ++i) {
            sort(v[i].begin(), v[i].end());
            int sz = v[i].size();
            int t = 0;
            for (int j = 0; j <= n; ++j) {
                if (dp[i - 1][j] < dp[i][j]) {
                    dp[i][j] = dp[i - 1][j];
                    pre[i][j] = 0;
                }
            }

            for (int j = 0; j < sz; ++j) {
                t += v[i][j].first;
                for (int s = n; s >= (j + 1); --s) {
                    if (dp[i - 1][s - (j + 1)] + t + cost[i] < dp[i][s]) {
                        dp[i][s] = dp[i - 1][s - (j + 1)] + t + cost[i];
                        pre[i][s] = j + 1;
                    }
                }
            }
        }
        int ret = 0;
        for (int i = n; i >= 1; --i) {
            if (dp[k][i] <= p) {
                ret = i;
                break;
            }
        }
        int rnt = 0;
        printf("%d\n", ret);

        int p = ret, q = k;
        while (q) {
            for (int i = 0; i < pre[q][p]; ++i) {
                res[rnt++] = v[q][i].second;
            }
            p -= pre[q][p];
            --q;
        }

        for (int i = 0; i < rnt; ++i) {
            if (i == rnt - 1) printf("%d\n", res[i]);
            else printf("%d ", res[i]);
        }

    }
    return 0;
}

