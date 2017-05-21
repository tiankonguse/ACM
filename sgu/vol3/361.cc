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
#define maxn 404
using namespace std;
char mp[maxn][maxn];
inline bool check(int x, int y) {
    return x >= 1 && y >= 1;
}
void init() {
    for (int i = 1; i <= 200; ++i) {
        for (int j = 1; j <= 200; ++j) {
            mp[i][j] = '0';
        }
    }
    int tx, ty;
    for (int i = 3; i <= 400; i += 3) {
        tx = 1, ty = i;
        while (check(tx, ty)) {
            mp[tx][ty] = '#';
            ++tx, --ty;
        }
    }
}
int main() {
    init();
    int n, m;
    while (~scanf("%d%d", &n, &m)) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                putchar(mp[i][j]);
            }
            puts("");
        }
    }
    return 0;
}
