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
#define maxn 15
#define maxm 32768
using namespace std;
int n, m, cnt, mx;

struct node {
    bool mp[maxn][maxn];
} p[maxm];

char ori[maxn + 5][maxn + 5];
int ids[maxn + 5][maxn + 5];
int dist[maxn][maxn][maxm];

int const dir0[8][2] = {
    -1, -2, -2, -1, -2, 1, -1, 2,
     1, -2,  2, -1,  2, 1,  1, 2
};
int const dir1[4][2] = {
    -1, -1, -1, 1, 1, 1, 1, -1
};
int const dir2[4][2] = {
    -1, 0, 1, 0, 0, 1, 0, -1
};
int const dir3[8][2] = {
    -1, -1, -1, 1, 1, 1, 1, -1, -1, 0, 1, 0, 0, 1, 0, -1
};

inline bool check(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

struct bfs_node {
    int mask, x, y, t;
    bfs_node (int _mask, int _x, int _y, int _t) {mask = _mask, x = _x, y = _y, t = _t; }
    bfs_node () {}
} tmp;
int mark[maxn][maxn][maxm];
queue <bfs_node> q;
int bfs(int sx, int sy) {
    int ret = inf;
    while (!q.empty()) q.pop();
    memset(mark, 0x3f, sizeof mark);
    mark[sx][sy][0] = true;
    q.push(bfs_node(0, sx, sy, 0));
    int tid, tx, ty, tmsk;
    while (!q.empty()) {
        tmp = q.front();
        q.pop();
      //  printf("%d %d \n", tmp.mask, tmp.t); system("pause");
        if (tmp.mask == mx - 1) {
            ret = min(ret, tmp.t);
            continue;
        }
        for (int i = 0; i < 8; ++i) {
            tx = tmp.x + dir3[i][0];
            ty = tmp.y + dir3[i][1];
            if (check(tx, ty) && !p[tmp.mask].mp[tx][ty] && tmp.t + 1 < mark[tx][ty][tmp.mask]) {
                mark[tx][ty][tmp.mask] = tmp.t + 1;
                tid = ids[tx][ty];
                if (tid == -1 || (tmp.mask & (1 << tid))) {
                    q.push( bfs_node(tmp.mask, tx, ty, tmp.t + 1) );

                }
                else {
                    tmsk = tmp.mask | (1 << tid);
                    if (!p[tmsk].mp[tx][ty] && tmp.t + 1 < mark[tx][ty][tmsk]) {
                        mark[tx][ty][tmsk] = tmp.t + 1;
                        q.push( bfs_node(tmsk, tx, ty, tmp.t + 1) );
                    }
                }
            }
        }
    }
    return ret == inf ? -1 :ret;
}
void gen(int id) {
    int rid = (~id) & (mx - 1);
    memset(p[rid].mp, 0, sizeof p[rid].mp);
    int tid, tx, ty;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            tid = ids[i][j];
            if (tid != -1 && (id & (1 << tid))) {
                if (ori[i][j] == 'K') {
                    for (int d = 0; d < 8; ++d) {
                        tx = i + dir0[d][0];
                        ty = j + dir0[d][1];
                        if (check(tx, ty) && (ids[tx][ty] == -1 || !(id & (1 << ids[tx][ty])))) {
                            p[rid].mp[tx][ty] = true;
                        }
                    }
                }
                else if (ori[i][j] == 'B') {
                    for (int d = 0; d < 4; ++d) {
                        tx = i + dir1[d][0];
                        ty = j + dir1[d][1];
                        while (check(tx, ty) && (ids[tx][ty] == -1 || !(id & (1 << ids[tx][ty])))) {
                            p[rid].mp[tx][ty] = true;
                            tx += dir1[d][0];
                            ty += dir1[d][1];
                        }
                    }
                }
                else if (ori[i][j] == 'R') {
                    for (int d = 0; d < 4; ++d) {
                        tx = i + dir2[d][0];
                        ty = j + dir2[d][1];
                        while (check(tx, ty) && (ids[tx][ty] == -1 || !(id & (1 << ids[tx][ty])))) {
                            p[rid].mp[tx][ty] = true;
                            tx += dir2[d][0];
                            ty += dir2[d][1];
                        }
                    }
                }
            }
        }
    }

}
void print(int id) {
    puts("");
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            printf("%2d", p[id].mp[i][j]);
        }
        puts("");
    }
}

int main() {
    int sx, sy;
    while (~scanf("%d%d", &n, &m)) {
        for (int i = 0; i < n; ++i) {
            scanf(" %s", ori[i]);
        }
        memset(ids, 0xff, sizeof ids);
        cnt = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (ori[i][j] == '*') {
                    sx = i;
                    sy = j;
                }
                else if (ori[i][j] != '.') {
                    ids[i][j] = cnt++;
                }
            }
        }
        if (cnt == 0) { puts("0"); continue; }

        mx = (1 << cnt);
        for (int i = 0; i < mx; ++i) {
            gen(i);
        }
        printf("%d\n", bfs(sx, sy));

    }
    return 0;
}
