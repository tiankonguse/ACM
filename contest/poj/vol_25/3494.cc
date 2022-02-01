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
#define maxn 2020
using namespace std;

int n, m;
bool mp[maxn][maxn];

int h[maxn][maxn];
int l[maxn], r[maxn];

int cal() {
    for (int i = 1; i <= n; ++i) {
        h[i][m + 1] = 0;
        for (int j = m; j >= 1; --j) {
            if (!mp[i][j]) h[i][j] = 0;
            else h[i][j] = h[i][j + 1] + 1;
        }
    }

    int ret = 0;
    int x1, y1, x2, y2;
    for (int j = 1; j <= m; ++j) {
        h[0][j] = h[n + 1][j] = -1;
        for (int i = 1; i <= n; ++i) {
            l[i] = i;
            while (h[l[i] - 1][j] >= h[i][j]) {
                l[i] = l[l[i] - 1];
            }
        }
        for (int i = n; i >= 1; --i) {
            r[i] = i;
            while (h[r[i] + 1][j] >= h[i][j]) {
                r[i] = r[r[i] + 1];
            }
        }
        for (int i = 1; i <= n; ++i) {
            x1 = l[i], x2 = r[i], y1 = j, y2 = j + h[i][j] - 1;
            ret = max(ret, (x2 - x1 + 1) * (y2 - y1 + 1));
        }
    }
    return ret;
}
int main() {
    char ch;
    while (~scanf("%d%d", &n, &m)) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                while (!isdigit(ch = getchar()));
                mp[i][j] = ch == '1';
            }
        }
        printf("%d\n", cal());
    }
    return 0;
}
