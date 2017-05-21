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
using namespace std;
char mp[maxn][maxn];
char cal(int x, int y) {
    int s = (mp[x][y] - '0') + (mp[x + 1][y] - '0') + (mp[x][y + 1] - '0') + (mp[x + 1][y + 1] - '0');
    s /= 4;
    return s + '0';
}
char str[20];

int main() {
    int n, m;
    while (~scanf(" %s", str)) {
        if (strcmp(str, "ENDOFINPUT") == 0) break;
        scanf(" %d%d", &n, &m);
        for (int i = 0; i < n; ++i) scanf(" %s", mp[i]);
        scanf(" %*s");
        for (int i = 0; i + 1 < n; ++i) {
            for (int j = 0; j + 1 < m; ++j) {
                putchar(cal(i, j));
            }
            puts("");
        }
    }
    return 0;
}
