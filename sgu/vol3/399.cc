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
#define maxn 20
using namespace std;
int n, m;
int const dir[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};
inline bool check(int x, int y) { return x >= 0 && x < n && y >= 0 && y < m; }

char mp[maxn][maxn];  int id[maxn][maxn];

bool used[maxn][maxn];
void dfsId(int x, int y, int idx) {

    used[x][y] = true;
    id[x][y] = idx;
    int tx, ty;
    for (int i = 0; i < 4; ++i) {
        tx = x + dir[i][0];
        ty = y + dir[i][1];
        if (check(tx, ty) && !used[tx][ty] && mp[tx][ty] == 'X') {
            dfsId(tx, ty, idx);
        }
    }
}

int minDis[maxn*maxn];
struct position {
    int x, y;
    position (int _x, int _y) { x = _x, y = _y; }
    position () {}
} minPos[maxn*maxn];

void print_init(int p) {
    int i, j;
    if (minPos[p].y == 1) {
        i = minPos[p].x;
        for (j = 0; !id[i][j]; ++j) mp[i][j] = '*';
    }
    else if (minPos[p].y == 2) {
        i = minPos[p].x;
        for (j = m - 1; !id[i][j]; --j) mp[i][j] = '*';
    }
    else if (minPos[p].y == 3) {
        j = minPos[p].x;
        for (i = 0; !id[i][j]; ++i) mp[i][j] = '*';
    }
    else {
        j = minPos[p].x;
        for (i = n - 1; !id[i][j]; --i) mp[i][j] = '*';
    }
}
void print1(int p1, int p2) {
    print_init(p1), print_init(p2);
    for (int i = 0; i < n; ++i) puts(mp[i]);
}
//-----------------------------------------------------------------------------

struct node {
    int x, y, t, p;
    node (int _x, int _y, int _t, int _p) {
        x = _x, y = _y, t = _t, p = _p;
    }
    node () {}
} tmp, rmp1, rmp2;

queue <node> q;
bool mark[maxn][maxn];
int pre[maxn][maxn][2];

void bfs(int sx, int sy) {
    while (!q.empty()) q.pop(); q.push(node(sx, sy, 0, -1));
    memset(mark, false, sizeof mark); mark[sx][sy] = true;
    pre[sx][sy][0] = pre[sx][sy][1] = -1;
    int tx, ty;
    int p1 = -1;
    rmp1.t = rmp2.t = inf;
    while (!q.empty()) {
        tmp = q.front(); q.pop();
        for (int i = 0; i < 4; ++i) {
            tx = tmp.x + dir[i][0], ty = tmp.y + dir[i][1];
            if (check(tx, ty)) {
                if (id[tx][ty]) {
                    if (p1 != -1 && id[tx][ty] != p1) {
                        rmp2 = node(tmp.x, tmp.y, tmp.t, id[tx][ty]);
                        return;
                    }
                    else if (p1 == -1) {
                        p1 = id[tx][ty];
                        rmp1 = node(tmp.x, tmp.y, tmp.t, id[tx][ty]);
                    }
                }
                else if (!mark[tx][ty]) {
                    mark[tx][ty] = true;
                    pre[tx][ty][0] = tmp.x;
                    pre[tx][ty][1] = tmp.y;
                    q.push(node(tx, ty, tmp.t + 1, tmp.p));
                }
            }
        }
    }
}

char trmp[maxn][maxn], rmp[maxn][maxn];
void print2() { for (int i = 0; i < n; ++i) puts(rmp[i]); }

void print2_init(node p) {
    int nx, ny, tx, ty;
    nx = p.x, ny = p.y;
    while (check(nx, ny) && pre[nx][ny][0] != -1) {
        trmp[nx][ny] = '*';
        tx = pre[nx][ny][0];
        ty = pre[nx][ny][1];
        nx = tx, ny = ty;
    }
}

int main() {
    while (~scanf("%d%d", &n, &m)) {
        for (int i = 0; i < n; ++i) {
            scanf(" %s", mp[i]);
        }
        memset(id, 0, sizeof id);
        memset(used, false, sizeof used);
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (mp[i][j] == 'X' && id[i][j] == 0) {
                    dfsId(i, j, ++cnt);
                }
            }
        }

        //plan1
        memset(minDis, 0x3f, sizeof minDis);
        for (int i = 0; i < n; ++i) {
            //dir 1
            for (int j = 0; j < m; ++j) {
                if (id[i][j]) {
                    if (j < minDis[ id[i][j] ]) {
                        minDis[ id[i][j] ] = j;
                        minPos[ id[i][j] ] = position(i, 1);
                    }
                    break;
                }
            }
            //dir 2
            for (int j = m - 1; j >= 0; --j) {
                if (id[i][j]) {
                    if (m - j - 1 < minDis[ id[i][j] ]) {
                        minDis[ id[i][j] ] = m - j - 1;
                        minPos[ id[i][j] ] = position(i, 2);

                    }
                    break;
                }
            }
        }
        for (int j = 0; j < m; ++j) {
            //dir 3
            for (int i = 0; i < n; ++i) {
                if (id[i][j]) {
                    if (i < minDis[ id[i][j] ]) {
                        minDis[ id[i][j] ] = i;
                        minPos[ id[i][j] ] = position(j, 3);

                    }
                    break;
                }
            }
            //dir 4
            for (int i = n - 1; i >= 0; --i) {
                if (id[i][j]) {
                    if (n - i - 1 < minDis[ id[i][j] ]) {
                        minDis[ id[i][j] ] = n - i - 1;
                        minPos[ id[i][j] ] = position(j, 4);

                    }
                    break;
                }
            }
        }
        int ret1 = inf, p1, p2;
        for (int i = 1; i <= cnt; ++i) {
            for (int j = i + 1; j <= cnt; ++j) {
                if (minDis[i] + minDis[j] < ret1) {
                    ret1 = minDis[i] + minDis[j];
                    p1 = i, p2 = j;
                }
            }
        }
        int ret2 = inf;
        int nx, ny, tx, ty, t0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (!id[i][j]) {
                    bfs(i, j);
                    t0 = rmp1.t + rmp2.t;
                    if (t0 > ret2) continue;
                    memcpy(trmp, mp, sizeof mp);
                    print2_init(rmp1);
                    print2_init(rmp2);
                    for (int d = 0; d < 4; ++d) {
                        bool flag = true;
                        nx = i, ny = j;
                        int t = 0;
                        while (check(nx, ny)) {
                            if (id[nx][ny]) {
                                flag = false;
                                break;
                            }
                            ++t;
                            tx = nx + dir[d][0];
                            ty = ny + dir[d][1];
                            nx = tx, ny = ty;
                        }
                        if (flag && t0 + t < ret2) {
                            ret2 = t0 + t;
                            nx = i, ny = j;
                            memcpy(rmp, trmp, sizeof trmp);
                            while (check(nx, ny)) {
                                rmp[nx][ny] = '*';
                                tx = nx + dir[d][0];
                                ty = ny + dir[d][1];
                                nx = tx, ny = ty;
                            }
                        }
                    }
                }
            }
        }
        if (ret1 < ret2) print1(p1, p2);
        else print2();
    }

    return 0;
}

