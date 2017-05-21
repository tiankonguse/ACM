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
typedef __int64 ll;
int const maxn = 110;
int const maxm = 510;
int const dx[3] = {1, 0, 0};
int const dy[3] = {0, -1, 1};

ll mp[maxn][maxm];
int q[maxn * maxm][2];
int pre[maxn][maxm][2];

ll D[maxn][maxm];
int ans[maxn + maxm];

int main() {
    int n, m;
    while (~scanf("%d%d", &n, &m)) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                scanf("%I64d", &mp[i][j]);
            }
        }
        for (int i = 0; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                D[i][j] = Inf;
            }
        }
        ll ret = Inf; int rx, ry;
        int l = 0, h = 0;
        q[h][0] = 0, q[h][1] = 1, ++h;
        D[0][1] = 0;

        for (; l != h; ++l) {
            if (l == 50000) l = 0;
            int x = q[l][0];
            int y = q[l][1];
            if (x == n) {
                if (D[x][y] < ret) {
                    ret = D[x][y];
                    rx = x;
                    ry = y;
                }
                continue;
            }
            for (int j = 0; j < 3; ++j) {
                int tx = x + dx[j];
                int ty = y + dy[j];
                if (tx >= 0 && tx <= n && ty >= 1 && ty <= m && D[x][y] + mp[tx][ty] < D[tx][ty]) {
                    D[tx][ty] = D[x][y] + mp[tx][ty];
                    pre[tx][ty][0] = x;
                    pre[tx][ty][1] = y;
                    q[h][0] = tx;
                    q[h][1] = ty;
                    ++h;
                    if (h == 50000) h = 0;
                }
            }
        }
        int top = 0;

        for (int tx = rx, ty = ry; rx != 0; ) {
            ans[top++] = ry;
            tx = pre[rx][ry][0];
            ty = pre[rx][ry][1];
            rx = tx;
            ry = ty;
        }

        for (int i = top - 1; i >= 0; --i) {
            printf("%d\n", ans[i]);
        }
    }
    return 0;
}
