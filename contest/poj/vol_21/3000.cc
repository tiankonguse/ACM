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
#define maxn 55
using namespace std;
int n, m, k;
char mp[maxn][maxn];
bool can[maxn][maxn][maxn];
inline bool check(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}
int const dir[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};

struct node {
    int x, y, t;
    node (int _x, int _y, int _t) { x = _x, y = _y, t = _t; }
    node () {}
} tmp;
queue <node> q;
int mark[maxn][maxn][maxn];

int bfs(int sx, int sy, int dx, int dy) {
    while (!q.empty()) q.pop();
    memset(mark, 0x3f, sizeof mark);
    q.push( node(sx, sy, 0) );
    mark[sx][sy][0] = 0;
    int tx, ty, tt;
    while (!q.empty()) {
        tmp = q.front(); q.pop();
        tt = (tmp.t + 1) % m;
        if (tmp.x == dx && tmp.y == dy) return tmp.t;
        if (can[tt][tmp.x][tmp.y] && tmp.t + 1 < mark[tmp.x][tmp.y][tt]) {
            mark[tmp.x][tmp.y][tt] = tmp.t + 1;
            q.push( node(tmp.x, tmp.y, tmp.t + 1) );
        }
        for (int i = 0; i < 4; ++i) {
            tx = tmp.x + dir[i][0];
            ty = tmp.y + dir[i][1];
            if (check(tx, ty) && can[tt][tx][ty] && tmp.t + 1 < mark[tx][ty][tt]) {
                mark[tx][ty][tt] = tmp.t + 1;
                q.push( node(tx, ty, tmp.t + 1) );
            }
        }
    }
    return inf;
}
int main() {
    int T;
    int sx, sy, dx, dy;
    for (scanf("%d", &T); T--; ) {
        scanf("%d%d%d", &k, &n, &m);
        n += 2;
        for(int i = 0; i < n; ++i) scanf(" %s", mp[i]);
        for (int i = 0; i < m; ++i) {
            if (mp[0][i] == 'G') { dx = 0, dy = i; }
            if (mp[n - 1][i] == 'F') { sx = n - 1, sy = i; }
        }
        for (int t = 0; t < m; ++t) {
            for(int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    if (n & 1) {
                        if (i & 1) {
                            can[t][i][j] = mp[i][(j - t + m) % m] != 'X';
                        }
                        else {
                            can[t][i][j] = mp[i][(j + t) % m] != 'X';
                        }
                    }
                    else {
                        if (i & 1) {
                            can[t][i][j] = mp[i][(j + t) % m] != 'X';
                        }
                        else {
                            can[t][i][j] = mp[i][(j - t + m) % m] != 'X';
                        }
                    }
                }
            }
        }
        int ret = bfs(sx, sy, dx, dy);
        if (ret > k) puts("The problem has no solution.");
        else printf("The minimum number of turns is %d.\n", ret);
    }
    return 0;
}
