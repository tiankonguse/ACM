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
char _mp[10][10];
int mp[10][10];
int n, n2;
int best_x, best_y;
int bc, wc, s;
bool used[10][10];
int const dir[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};
inline bool check(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < n;
}
void dfsb(int x, int y, int p) {
    int tx, ty;
    used[x][y] = true;
    ++bc;
    for (int i = 0; i < 4; ++i) {
        tx = x + dir[i][0];
        ty = y + dir[i][1];
        if (check(tx, ty) && mp[tx][ty] == p && !used[tx][ty]) {
            dfsb(tx, ty, p);
        }
    }
}
void dfsw(int x, int y, int p) {
    int tx, ty;
    used[x][y] = true;
    ++wc;
    for (int i = 0; i < 4; ++i) {
        tx = x + dir[i][0];
        ty = y + dir[i][1];
        if (check(tx, ty) && mp[tx][ty] == p && !used[tx][ty]) {
            dfsw(tx, ty, p);
        }
    }
}
void print() {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%d", mp[i][j]);
        }
        puts("");
    }
}
int coor[12][2], cz;
int dp[1024][1024], mx;

int dfs(int d, int p, int sa, int sb) {
    if (dp[sa][sb] != -1) return dp[sa][sb];

    if (d == n2) {
        int bt = 0, wt = 0;
        memset(used, 0, sizeof used);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (!used[i][j]) {
                    if (mp[i][j] == 0) {
                        bc = 0;
                        dfsb(i, j, 0);
                        bt = max(bt, bc);
                    }
                    else {
                        wc = 0;
                        dfsw(i, j, 1);
                        wt = max(wt, wc);
                    }
                }
            }
        }
        if (d & 1) return dp[sa][sb] = wt - bt;
        else return dp[sa][sb] = bt - wt;
    }
    int ret = -inf;
    int x, y;
    for (int i = 0; i < cz; ++i) {
        x = coor[i][0];
        y = coor[i][1];
        if (mp[x][y] == -1) {
            mp[x][y] = p;
            int tc ;
            if (d & 1) tc = dfs(d + 1, p ^ 1, sa, sb | (1 << i));
            else tc = dfs(d + 1, p ^ 1, sa | (1 << i), sb);

            if (-tc > ret) {
                ret = -tc;
                if (d == s) {
                    best_x = x;
                    best_y = y;
                }
            }
            mp[x][y] = -1;
        }

    }
//    printf("dfs(%d, %d) = %d\n", d, p, ret);
    return dp[sa][sb] = ret;
}

int main() {
    while (scanf("%d", &n) && n) {
        for (int i = 0; i < n; ++i) {
            scanf(" %s", _mp[i]);
        }
        n2 = n * n;
        int b = 0, w = 0; s = 0;
        cz = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (_mp[i][j] == '.') {
                    mp[i][j] = -1;
                    coor[cz][0] = i;
                    coor[cz][1] = j;
                    ++cz;
                }
                if (_mp[i][j] == '0') {
                    ++b;
                    mp[i][j] = 0;
                }
                if (_mp[i][j] == '1') {
                    ++w;
                    mp[i][j] = 1;
                }
            }
        }
        s = b + w;
        memset(dp, 0xff, sizeof dp);
        int ret;
        if (b == w) {
            ret = dfs(s, 0, 0, 0);
        }
        else {
            ret = dfs(s, 1, 0, 0);
        }
        printf("(%d,%d) %d\n", best_x, best_y, ret);
    }
    return 0;
}
