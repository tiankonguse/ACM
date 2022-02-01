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
#define maxn 410
using namespace std;
char res[maxn][maxn];
char unit[22][22];

int main() {
    int n, k;
    while (~scanf("%d%d", &n, &k)) {
        int t = k;
        int la = n;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (t) {
                    unit[i][j] = '*';
                    --t;
                    la = i;
                }
                else {
                    unit[i][j] = '.';
                }
            }
        }
        int si, sj;
        for (int k = 0; k < n; ++k) {
            for (int l = 0; l < n; ++l) {
                si = k * n;
                sj = l * n;
                for (int i = 0; i < n; ++i) {
                    for (int j = 0; j < n; ++j) {
                        res[si + i][sj + j] = unit[(i - l + n) % n][(j - k + n) % n];
                    }
                }
            }
        }
        int len = n * n;
        for (int i = 0; i < len; ++i) {
            for (int j = 0; j < len; ++j) {
                putchar(res[i][j]);
            }
            puts("");
        }
    }
    return 0;
}
