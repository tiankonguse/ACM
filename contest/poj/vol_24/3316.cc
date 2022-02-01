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
#define maxn 40404
#define maxl 222
using namespace std;

int mark[maxl][maxl];
char mp[maxl][maxl];
int n, m;
int const dir[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};
inline bool check(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}
bool used[maxl][maxl];

void dfs_fill(int x, int y, int c) {
    used[x][y] = true;
    mark[x][y] = c;
    int tx, ty;
    for (int i = 0; i < 4; ++i) {
        tx = x + dir[i][0];
        ty = y + dir[i][1];
        if (check(tx, ty) && mp[tx][ty] == '1' && !used[tx][ty]) {
            dfs_fill(tx, ty, c);
        }
    }
}
void print() {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            printf("%2d", mark[i][j]);
        }
        puts("");
    }
    puts("");
}
bool ok[maxn];
int deg[maxl][maxl];

int main() {
    while (~scanf("%d%d", &n, &m)) {
        if (n == 0 && m == 0) break;
        for (int i = 0; i < n; ++i) scanf(" %s", mp[i]);
        memset(mark, 0xff, sizeof mark);
        memset(used, 0, sizeof used);
        memset(deg, 0, sizeof deg);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (mp[i][j] == '1') {
                    int cc = 0;
                    for (int k = 0; k < 4; ++k) {
                        int ti = i + dir[k][0];
                        int tj = j + dir[k][1];
                        if (check(ti, tj) && mp[ti][tj] == '1') {
                            ++cc;
                        }
                    }
                    deg[i][j] = cc;
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (mp[i][j] == '1' && mark[i][j] != 0) {
                    if (deg[i][j] > 2) {
                        dfs_fill(i, j, 0);
                    }
                }
            }
        }
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (mp[i][j] == '1' && mark[i][j] == -1) {
                    dfs_fill(i, j, ++cnt);
                }
            }
        }
        memset(ok, 0, sizeof ok);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (mp[i][j] == '0') {
                    int cc = 0;
                    int z = -1, x, y;
                    for (int k = 0; k < 4; ++k) {
                        int ti = i + dir[k][0];
                        int tj = j + dir[k][1];
                        if (check(ti, tj) && mark[ti][tj] != -1) {
                            ++cc;
                            z = mark[ti][tj];
                            x = ti;
                            y = tj;
                        }
                    }
                    if (cc == 1 && deg[x][y] <= 1) {
                        ok[z] = true;
//                        cout<<x<<","<<y<<endl;
                    }
                }
            }
        }
        int ret = 0;
        for (int i = 1; i <= cnt; ++i) ret += !ok[i];
        printf("%d\n", ret);
//        print();
    }
    return 0;
}
