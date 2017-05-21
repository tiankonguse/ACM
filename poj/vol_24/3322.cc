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
#define maxn 505
using namespace std;
char mp[maxn][maxn];
int n, m;
int sx, sy, ss;
int const dir[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};
inline bool check(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m && mp[x][y] != '#';
}
void init() {
    for (int i = 1; i < n - 1; ++i) {
        for (int j = 1; j < m - 1; ++j) {
            if (mp[i][j] == 'X') {
                sx = i, sy = j;
                if (mp[i][j + 1] == 'X') ss = 1;
                else if (mp[i + 1][j] == 'X') ss = 2;
                else ss = 0;
                return;
            }
        }
    }
}

struct node {
    int x, y, s, t;
    node (int _x, int _y, int _s, int _t) { x = _x, y = _y, s = _s, t = _t; }
    node () {}
} tmp;

int mark[maxn][maxn][3];
int next_s[4] = {2, 1, 2, 1};
int next_p[4] = {1, 0, 0, 1};
queue<node> q;

inline void update(int _x, int _y, int _s, int _t) {
    if (_t < mark[_x][_y][_s]) {
        mark[_x][_y][_s] = _t;
        q.push(node(_x, _y, _s, _t));
    }
}
int bfs(int sx, int sy, int ss) {
    while (!q.empty()) q.pop();
    memset(mark, 0x3f, sizeof mark);
    mark[sx][sy][ss] = 0;
    q.push(node(sx, sy, ss, 0));

    int tx[2], ty[2], tx1, ty1, tx2, ty2;
    int _x, _y, _s;
    while (!q.empty()) {
        tmp = q.front(); q.pop();
//        for (int i = 0; i < n; ++i) {
//            for (int j = 0; j < m; ++j) {
//                if(i==tmp.x&&j==tmp.y) printf("%d", tmp.s);
//                else{
//                    if(mp[i][j]=='X')mp[i][j]='.';
//                    putchar(mp[i][j]);
//                }
//            }
//            puts("");
//        }system("pause");

        if (tmp.s == 0) {
            for (int i = 0; i < 4; ++i) {
                tx[0] = tmp.x + dir[i][0];
                ty[0] = tmp.y + dir[i][1];
                tx[1] = tx[0] + dir[i][0];
                ty[1] = ty[0] + dir[i][1];
                if (check(tx[0], ty[0]) && check(tx[1], ty[1])) {
                    _x = tx[ next_p[i] ];
                    _y = ty[ next_p[i] ];
                    _s = next_s[i];
                    update(_x, _y, _s, tmp.t + 1);
                }
            }
        }
        else if (tmp.s == 1) {
            tx1 = tmp.x - 1, ty1 = tmp.y, tx2 = tx1, ty2 = ty1 + 1;
            if (check(tx1, ty1) && check(tx2, ty2)) {
                _x = tx1, _y = ty1, _s = 1;
                update(_x, _y, _s, tmp.t + 1);
            }
            tx1 = tmp.x + 1, tx2 = tx1;
            if (check(tx1, ty1) && check(tx2, ty2)) {
                _x = tx1, _y = ty1, _s = 1;
                update(_x, _y, _s, tmp.t + 1);
            }
            tx1 = tmp.x, ty1 = tmp.y - 1;
            if (check(tx1, ty1) && mp[tx1][ty1] != 'E') {
                if (mp[tx1][ty1] == 'O') return tmp.t + 1;
                update(tx1, ty1, 0, tmp.t + 1);
            }
            tx1 = tmp.x, ty1 = tmp.y + 2;
            if (check(tx1, ty1) && mp[tx1][ty1] != 'E') {
                if (mp[tx1][ty1] == 'O') return tmp.t + 1;
                update(tx1, ty1, 0, tmp.t + 1);
            }
        }
        else {
            tx1 = tmp.x, ty1 = tmp.y - 1, tx2 = tmp.x + 1, ty2 = ty1;
            if (check(tx1, ty1) && check(tx2, ty2)) {
                _x = tx1, _y = ty1, _s = 2;
                update(_x, _y, _s, tmp.t + 1);
            }
            ty1 = tmp.y + 1, ty2 = ty1;
            if (check(tx1, ty1) && check(tx2, ty2)) {
                _x = tx1, _y = ty1, _s = 2;
                update(_x, _y, _s, tmp.t + 1);
            }
            tx1 = tmp.x - 1, ty1 = tmp.y;
            if (check(tx1, ty1) && mp[tx1][ty1] != 'E') {
                if (mp[tx1][ty1] == 'O') return tmp.t + 1;
                update(tx1, ty1, 0, tmp.t + 1);
            }
            tx1 = tmp.x + 2, ty1 = tmp.y;
            if (check(tx1, ty1) && mp[tx1][ty1] != 'E') {
                if (mp[tx1][ty1] == 'O') return tmp.t + 1;
                update(tx1, ty1, 0, tmp.t + 1);
            }
        }
    }
    return -1;
}

int main() {
    while (scanf("%d%d", &n, &m) && n + m) {
        for (int i = 0; i < n; ++i) scanf(" %s", mp[i]);
        init();
        int ret = bfs(sx, sy, ss);
        if (ret == -1) puts("Impossible");
        else printf("%d\n", ret);
    }
    return 0;
}
