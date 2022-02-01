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
int const maxn = 25;
int n, m;
int s[2];
int mp[maxn][maxn];
bool mark[maxn][maxn];

int const dir[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};
inline bool checkin(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < n;
}

bool killed;
inline bool check(int x, int y, int p) {
    int tx, ty;
    mark[x][y] = true;
    for (int i = 0; i < 4; ++i) {
        tx = x + dir[i][0], ty = y + dir[i][1];
        if (checkin(tx, ty) && !mark[tx][ty]) {
            if (mp[tx][ty] == -1) return true;
            else if (mp[tx][ty] == (p ^ 1)) killed = true;
            else if (mp[tx][ty] == p) {
                if (check(tx, ty, p)) return true;
            }
        }
    }
    return false;
}
inline int fill(int x, int y, int p) {
    int ret = 1, tx, ty;
    mp[x][y] = -1;
    for (int i = 0; i < 4; ++i) {
        tx = x + dir[i][0], ty = y + dir[i][1];
        if (checkin(tx, ty) &&  mp[tx][ty] == p) {
            ret += fill(tx, ty, p);
        }
    }
    return ret;
}
void insert(int x, int y, int p) {
    int op = p ^ 1;
    mp[x][y] = p;
    int tx, ty;
    memset(mark, 0, sizeof mark);
    for (int i = 0; i < 4; ++i) {
        tx = x + dir[i][0], ty = y + dir[i][1];
        if (checkin(tx, ty) && mp[tx][ty] == op && !mark[tx][ty] && !check(tx, ty, op)) {
            s[p] += fill(tx, ty, op);
        }
    }
    memset(mark, 0, sizeof mark);
    killed = false;
    if (!check(x, y, p) && killed) {
        s[op] += fill(x, y, p);
    }
}

int msk;
int dfs(int x, int y) {
    int ret = 1, tx, ty;
    mark[x][y] = true;
    for (int i = 0; i < 4; ++i) {
        tx = x + dir[i][0], ty = y + dir[i][1];
        if (checkin(tx, ty) && !mark[tx][ty]) {
            if (mp[tx][ty] != -1) msk |= (1 << mp[tx][ty]);
            else ret += dfs(tx, ty);
        }
    }
    return ret;
}
void print() {
    puts("------");
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (mp[i][j] == -1) putchar('.');
            else if (mp[i][j] == 0) putchar('x');
            else putchar('o');
        }
        puts("");
    }
    puts("------");
}
int main() {
    int add;
    char player; int x, y;

    while (~scanf("%d%d", &n, &m) && (n + m)) {
        add = (n - 1) >> 1;
        memset(mp, 0xff, sizeof mp);
        s[0] = s[1] = 0;
        while (m--) {
            scanf(" %c(%d,%d)", &player, &x, &y);
            x += add, y += add;
            insert(x, y, player == 'W');
//            print();
        }
        memset(mark, 0, sizeof mark);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mp[i][j] == -1 && !mark[i][j]) {
                    msk = 0;
                    int t = dfs(i, j);
                    if (msk == 1) s[0] += t;
                    else if (msk == 2) s[1] += t;
                }
            }
        }
        printf("%d %d\n", s[0], s[1]);
    }
    return 0;
}
