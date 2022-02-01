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
#define maxn 25
using namespace std;
char mp[maxn][maxn];

int main() {
    int T;
    int n, m, c;
    for (scanf("%d", &T); T--; ) {
        scanf("%d%d%d", &n, &m, &c);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                mp[i][j] = '.';
            }
            mp[i][m] = 0;
        }
        for (int i = 1; i + 1 < n; i += 2) {
            for (int j = 1; j + 1 < m; j += 2) {
                if (c) {
                    --c;
                    mp[i][j] = '#';
                }
            }
        }
        for (int i = 2; i + 1 < n; i += 2) {
            for (int j = 2; j + 1 < m; j += 2) {
                if (c) {
                    --c;
                    mp[i][j] = '#';
                }
            }
        }
        if (c) puts("Impossible");
        else {
            for (int i = 0; i < n; ++i) puts(mp[i]);
        }
        if (T) puts("");
    }
    return 0;
}
