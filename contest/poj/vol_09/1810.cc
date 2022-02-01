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
#define maxn 1010
using namespace std;
double const eps = 1e-6;
int k, n, m;
int mp[maxn][maxn];
int sum[maxn][maxn];

inline int cal(int x1, int y1, int x2, int y2) {
    return sum[x2][y2] - sum[x1 - 1][y2] - sum[x2][y1 - 1] + sum[x1 - 1][y1 - 1];
}
int main() {
    int T;
    double x, y;
    int tx, ty;
    for (scanf("%d", &T); T--; ) {
        scanf("%d%d%d", &k, &n, &m);
        memset(mp, 0, sizeof mp);
        for (int i = 0; i < k; ++i) {
            scanf("%lf %lf", &x, &y);
            tx = (int)(x - eps) + 1, ty = (int)(y - eps) + 1;
            if (tx >= 1 && tx <= n && ty >= 1 && ty <= n) {
                mp[tx][ty]++;
            }
        }
        memset(sum, 0, sizeof sum);
        int t;
        for (int i = 1; i <= n; ++i) {
            t = 0;
            for (int j = 1; j <= n; ++j) {
                t += mp[i][j];
                sum[i][j] = sum[i - 1][j] + t;
            }
        }


        int i2, j2, s;
        int rx, ry, ret = -1;
        for (int i = 1; i + m - 1 <= n; ++i) {
            for (int j = 1; j + m - 1 <= n; ++j) {
                i2 = i + m - 1;
                j2 = j + m - 1;
                s = cal(i, j, i2, j2);
                if (s > ret) {
                    ret = s;
                    rx = i, ry = j;
                }
                else if (s == ret) {
                    if (j > ry) {
                        rx = i, ry = j;
                    }
                    else if (j == ry && i > rx) {
                        rx = i;
                    }
                }
            }
        }
        printf("%d %d\n", rx - 1, ry - 1);
    }
    return 0;
}
