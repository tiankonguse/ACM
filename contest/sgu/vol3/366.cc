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

#define Inf 0x3FFFFFFFFFFFFFFFLL
#define maxn 202
#define maxs 4040
#define pb push_back
#define mp make_pair
using namespace std;
int const inf = 1061109568;
typedef pair<int, int> pii;
vector <pii> v[maxn];
bool cmp(pii a, pii b) {
    return a > b;
}

int dp[maxn][maxs];
int pre[maxn][maxs];

int dat[60060][2];
int rlist[maxn], rnt;
int main() {
    int n, k;
    int a, b;
    while (~scanf("%d%d", &n, &k)) {
        for (int i = 0; i <= 100; ++i) v[i].clear();
        for (int i = 1; i <= n; ++i) {
            scanf("%d%d", &a, &b);
            v[a - b + 50].pb(mp(a + b, i));
            dat[i][0] = a;
            dat[i][1] = b;
        }
        for (int i = 0; i <= 100; ++i) sort(v[i].begin(), v[i].end(), cmp);

        memset(dp, 0xc0, sizeof dp);
        dp[0][0] = 0;
        memset(pre, 0xff, sizeof pre);

        int mid = k * 50, len = mid << 1;
        for (int _k = 0; _k < k; ++_k) {
            for (int i = 0; i <= 100; ++i) {
                int sz = v[i].size();
                sz = min(sz, k);
                for (int j = 0; j < sz; ++j) {
                    for (int l = i; l <= len; ++l) {

                            if (dp[_k][l - i] != -inf) {
                                if (dp[_k][l - i] + v[i][j].first > dp[_k + 1][l]) {

                                    bool flag = true;
                                    int tx=_k,ty=l-i;

                                    while(pre[tx][ty]!=-1){
                                        if (pre[tx][ty] == v[i][j].second) {
                                            flag = false;
                                            break;
                                        }
                                        ty-= dat[ pre[tx][ty] ][0]-dat[ pre[tx][ty] ][1]+50;
                                        --tx;
                                    }

                                    if (flag) {
                                        dp[_k + 1][l] = dp[_k][l - i] + v[i][j].first;
                                        pre[_k + 1][l] = v[i][j].second;
                                    }
                            }
                        }
                    }
                }
            }
        }

        int sel = -1, mi = inf, mx = 0;
        for (int i = 0; i <= len; ++i) {
            if (dp[k][i] >= 0) {
                if (abs(i - mid) < mi) {
                    mi = abs(i - mid);
                    sel = i;
                    mx = dp[k][i];
                }
                else if (abs(i - mid) == mi) {
                    if (dp[k][i] > mx) {
                        mx = dp[k][i];
                        sel = i;
                    }
                }
            }
        }
        int tx = k, ty = sel;
        rnt = 0;
        int s1 = 0, s2 = 0;
        while (pre[tx][ty] != -1) {
            rlist[rnt++] = pre[tx][ty];
            int a = dat[ pre[tx][ty] ][0];
            int b = dat[ pre[tx][ty] ][1];
            s1 += a, s2 += b;
            ty -= a - b + 50;
            --tx;
        }
        printf("%d %d\n", s1, s2);
        sort(rlist, rlist + rnt);
        for (int i = 0; i < rnt; ++i) {
            if (i == rnt - 1) printf("%d\n", rlist[i]);
            else printf("%d ", rlist[i]);
        }
    }
    return 0;
}

