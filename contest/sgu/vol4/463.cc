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
#define maxn 222
using namespace std;
int mp[maxn][maxn];
bool mark[maxn][maxn];
char buf[maxn];
char str[555];
int const dir[4][2] = {
    0, 1, 1, 0, 0, -1, -1, 0 // R D L U
};
int n, m;
inline bool check(int x, int y) {
    return x >= 0 && x <= 2 * n && y >= 0 && y <= 2 * m;
}
int main() {
    while (~scanf("%d%d", &n, &m)) {
        memset(mp, 0, sizeof mp);
        for (int i = 0; i < n; ++i) {
            scanf(" %s", buf);
            for (int j = 0; j < m; ++j) {
                mp[i * 2 + 1][j * 2 + 1] = buf[j] - '0';
            }
        }
        memset(mark, false, sizeof mark);
        int ret = 0;
        int x = 0, y = 0, d = 0;
        int tx, ty;
        scanf(" %s", str);
        int len = strlen(str);
        for (int i = 0; i < len; ++i) {
            if (str[i] == 'M') {
                x += dir[d][0];
                y += dir[d][1];
                tx = x + dir[(d + 3) % 4][0];
                ty = y + dir[(d + 3) % 4][1];
                if (check(tx, ty)) {
                    if (!mark[tx][ty]) {
                        mark[tx][ty] = true;
                        ret += mp[tx][ty];
                    }
                    else ret += mp[tx][ty] / 2;
                }
                tx = x + dir[(d + 1) % 4][0];
                ty = y + dir[(d + 1) % 4][1];
                if (check(tx, ty)) {
                    if (!mark[tx][ty]) {
                        mark[tx][ty] = true;
                        ret += mp[tx][ty];
                    }
                    else ret += mp[tx][ty] / 2;
                }
                x += dir[d][0];
                y += dir[d][1];
            }
            else if (str[i] == 'R') {
                d = (d + 1) % 4;
            }
            else {
                d = (d + 3) % 4;
            }
        }
        printf("%d\n", ret);
    }
    return 0;
}
