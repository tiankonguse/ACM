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
#define maxn 202
using namespace std;

int n;
int mp[maxn][maxn];
void floyd() {
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            if (k == i) continue;
            for (int j = 1; j <= n; ++j) {
                mp[i][j] |= mp[i][k] & mp[k][j];
            }
        }
    }
}
char str[30];
int main() {
    int a, b, len;
    while (scanf("%d", &n) && n) {
        memset(mp, 0, sizeof mp);
        while (~scanf("%d%d", &a, &b) && a + b) {
            scanf("%s", str);
            len = strlen(str);
            for (int i = 0; i < len; ++i) {
                mp[a][b] |= 1 << (str[i] - 'a');
            }
        }
        floyd();
        while (~scanf("%d%d", &a, &b) && a + b) {
            bool flag = false;
            for (int i = 0; i < 26; ++i) {
                if ((mp[a][b] >> i) & 1) {
                    flag = true;
                    putchar('a' + i);
                }
            }
            if (!flag) putchar('-');
            puts("");
        }
        puts("");
    }
    return 0;
}
