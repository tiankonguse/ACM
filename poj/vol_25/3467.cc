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
#define maxn 105
using namespace std;
int mp[maxn][maxn];
int num[maxn];
int n, m, c, q;

inline bool check(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}
int const dir[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};
int ext[maxn][maxn][4];



int main(){
    char op; int x, y, z;
    while (~scanf("%d%d%d%d", &n, &m, &c, &q)) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                scanf("%d", &mp[i][j]);
            }
        }
        memset(num, 0, sizeof num);
        int tx, ty, tt;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                tt = inf;
                for (int k = 0; k < 4; ++k) {
                    ext[i][j][k] = 0;
                    tx = i + dir[k][0];
                    ty = j + dir[k][1];
                    while (check(tx, ty) && mp[tx][ty] == mp[i][j]) {
                        ++ext[i][j][k];
                        tx += dir[k][0];
                        ty += dir[k][1];
                    }
                    tt = min(tt, ext[i][j][k]);
                }
                num[ mp[i][j] ] += tt;
            }
        }
        while (q--) {
            scanf(" %c", &op);
            if (op == 'Q') {
                scanf("%d", &x);
                printf("%d\n", num[x]);
            }
            else {
                scanf("%d%d%d", &x, &y, &z);
                --x, --y;
                num[ mp[x][y] ] -= min(ext[x][y][0], min(ext[x][y][1], min(ext[x][y][2], ext[x][y][3])));
                mp[x][y] = z;
                tt = inf;
                for (int i = 0; i < 4; ++i) {
                    ext[x][y][i] = 0;
                    tx = x + dir[i][0];
                    ty = y + dir[i][1];
                    while (check(tx, ty) && mp[tx][ty] == z) {
                        ++ext[x][y][i];
                        tx += dir[i][0];
                        ty += dir[i][1];
                    }
                    tt = min(tt, ext[x][y][i]);
                }

                num[z] += tt;
                int pre, now, xp, yp;
                for (int i = 0; i < 4; ++i) {
                    tx = x + dir[i][0];
                    ty = y + dir[i][1];
                    while (check(tx, ty)) {
                        pre = min(ext[tx][ty][0], min(ext[tx][ty][1], min(ext[tx][ty][2], ext[tx][ty][3])));
                        xp = tx - dir[i][0];
                        yp = ty - dir[i][1];
                        if (mp[tx][ty] == mp[xp][yp]) {
                            ext[tx][ty][(i + 2) % 4] = ext[xp][yp][(i + 2) % 4] + 1;
                        }
                        else ext[tx][ty][(i + 2) % 4] = 0;

                        now = min(ext[tx][ty][0], min(ext[tx][ty][1], min(ext[tx][ty][2], ext[tx][ty][3])));
                        num[ mp[tx][ty] ] -= pre;
                        num[ mp[tx][ty] ] += now;
                        tx += dir[i][0];
                        ty += dir[i][1];
                    }
                }
            }
        }
    }
    return 0;
}
