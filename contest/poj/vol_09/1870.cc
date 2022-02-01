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
#define maxn 300
using namespace std;
int mp[maxn][maxn];
int cor[20020][2];

int const _base = 150;

void init() {
    int id = 0;
    mp[_base][_base] = ++id;
    cor[id][0] = _base, cor[id][1] = _base;

    mp[_base][_base + 1] = ++id;
    cor[id][0] = _base, cor[id][1] = _base + 1;

    mp[_base + 1][_base + 1] = ++id;
    cor[id][0] = _base + 1, cor[id][1] = _base + 1;

    mp[_base + 1][_base] = ++id;
    cor[id][0] = _base + 1, cor[id][1] = _base;

    mp[_base][_base - 1] = ++id;
    cor[id][0] = _base, cor[id][1] = _base - 1;

    mp[_base - 1][_base - 1] = ++id;
    cor[id][0] = _base - 1, cor[id][1] = _base - 1;

    int dx = 0, dy = 1, tx = _base - 1, ty = _base - 1;
    while (id < 20000) {
        if (dx == 0 && dy == -1) {
            if (mp[tx - 1][ty - 1] != 0) {
                tx += dx, ty += dy;
                mp[tx][ty] = ++id; cor[id][0] = tx, cor[id][1] = ty;
            }
            else {
                dx = -1, dy = -1;
                tx += dx, ty += dy;
                mp[tx][ty] = ++id; cor[id][0] = tx, cor[id][1] = ty;
            }
        }
        else if (dx == -1 && dy == -1) {
            if (mp[tx - 1][ty] != 0) {
                tx += dx, ty += dy;
                mp[tx][ty] = ++id; cor[id][0] = tx, cor[id][1] = ty;
            }
            else {
                dx = -1, dy = 0;
                tx += dx, ty += dy;
                mp[tx][ty] = ++id; cor[id][0] = tx, cor[id][1] = ty;
            }
        }
        else if (dx == -1 && dy == 0) {

            if (mp[tx - 1][ty + 1] != 0) {
                tx += dx, ty += dy;
                mp[tx][ty] = ++id; cor[id][0] = tx, cor[id][1] = ty;
            }
            else {

                tx += dx, ty += dy;
                mp[tx][ty] = ++id; cor[id][0] = tx, cor[id][1] = ty;
                dx = 0, dy = 1;
            }
        }
        else if (dx == 0 && dy == 1) {
            if (mp[tx + 1][ty + 1] != 0) {
                tx += dx, ty += dy;
                mp[tx][ty] = ++id; cor[id][0] = tx, cor[id][1] = ty;
            }
            else {
                dx = 1, dy = 1;
                tx += dx, ty += dy;
                mp[tx][ty] = ++id; cor[id][0] = tx, cor[id][1] = ty;
            }
        }
        else if (dx == 1 && dy == 1) {
            if (mp[tx + 1][ty] != 0) {
                tx += dx, ty += dy;
                mp[tx][ty] = ++id; cor[id][0] = tx, cor[id][1] = ty;
            }
            else {
                dx = 1, dy = 0;
                tx += dx, ty += dy;
                mp[tx][ty] = ++id; cor[id][0] = tx, cor[id][1] = ty;
            }
        }
        else if (dx == 1 && dy == 0) {
            if (mp[tx + 1][ty - 1] != 0) {
                tx += dx, ty += dy;
                mp[tx][ty] = ++id; cor[id][0] = tx, cor[id][1] = ty;
            }
            else {
                tx += dx, ty += dy;
                mp[tx][ty] = ++id; cor[id][0] = tx, cor[id][1] = ty;
                dx = 0, dy = -1;
            }
        }
    }

}


int main() {
    init();
    int a, b;
    while (~scanf("%d%d", &a, &b)) {
        if (a == 0 && b == 0) break;
        int x1 = cor[a][0], y1 = cor[a][1];
        int x2 = cor[b][0], y2 = cor[b][1];
        if (x1 > x2) { swap(x1, x2), swap(y1, y2); }
        int d = x2 - x1;
        int l = y1, r = y1 + d;
        int ret;
        if (y2 < l) ret = d + l - y2;
        else if (y2 >= l && y2 <= r) ret = d;
        else ret = d + y2 - r;
        printf("The distance between cells %d and %d is %d.\n", a, b, ret);
    }
    return 0;
}
