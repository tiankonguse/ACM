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

using namespace std;
typedef __int64 ll;

int cliq[30][30] = {
    {1, 2, -1},
    {3, 4, 5, 6, 7, -1},
    {8, 9, 10, 11, 12, 13, -1}, 
    {14, 15, 16, 17, 18, -1},
    {19, 20, 21, 22, 23, 24, -1},
    {25, 26, 27, 28, 29, -1},
    {30, 31, -1},
    {3, 8, -1},
    {1, 4, 9, 14, 19, -1},
    {2, 5, 10, 15, 20, 25, -1},
    {6, 11, 16, 21, 26, -1},
    {7, 12, 17, 22, 27, 30, -1},
    {13, 18, 23, 28, 31, -1},
    {24, 29, -1},
    {7, 13, -1},
    {2, 6, 12, 18, 24, -1},
    {1, 5, 11, 17, 23, 29, -1},
    {4, 10, 16, 22, 28, -1},
    {3, 9, 15, 21, 27, 31, -1},
    {8, 14, 20, 26, 30, -1},
    {19, 25, -1},
    {1, 2, 4, 5, 6, 10, 11, -1},
    {3, 4, 8, 9, 10, 14, 15, -1},
    {6, 7, 11, 12, 13, 17, 18, -1},
    {10, 11, 15, 16, 17, 21, 22, -1},
    {14, 15, 19, 20, 21, 25, 26, -1},
    {17, 18, 22, 23, 24, 28, 29, -1},
    {21, 22, 26, 27, 28, 30, 31, -1},
    {-1}
};

int belong[35][35], bnt[35];
bool mark[35][35];

void init() {
    for (int i = 1; i <= 31; ++i) {
        for (int j = 0; cliq[j][0] != -1; ++j) {
            for (int k = 0; cliq[j][k] != -1; ++k) {
                if (i == cliq[j][k]) {
                    belong[i][ bnt[i]++ ] = j;
                    break;
                }
            }
        }
    }
}
int res[35];
int cnt;
int k, n;
inline bool check(int pos, int id) {
    for (int i = 0; i < bnt[pos]; ++i) {
        if (mark[ belong[pos][i] ][id]) return false;
    }
    return true;
}
bool dfs(int dep) {
    if (dep > 31) {
        if (++cnt == n) return true;
        else return false;
    }
    if (res[dep] != 0) {
        return dfs(dep + 1);
    }
    else {
        for (int i = 1; i <= k; ++i) {
            if (check(dep, i)) {
                for (int j = 0; j < bnt[dep]; ++j) {
                    mark[ belong[dep][j] ][i] = true;
                }
                res[dep] = i;
                if (dfs(dep + 1)) return true;
                res[dep] = 0;
                for (int j = 0; j < bnt[dep]; ++j) {
                    mark[ belong[dep][j] ][i] = false;
                }
            }
        }
    }
    return false;
}
int main() {
    init();
    while (~scanf("%d%d", &k, &n)) {
        memset(mark, false, sizeof mark);
        bool flag = true;
        for (int i = 1; i <= 31; ++i) {
            scanf("%d", &res[i]);
            if (!flag) continue;
            if (res[i] != 0) {
                for (int j = 0; j < bnt[i]; ++j) {
                    if (mark[ belong[i][j] ][ res[i] ]) {
                        flag = false;
                        break;
                    }
                    mark[ belong[i][j] ][ res[i] ] = true;
                }
            }
        }
        flag = dfs(1);
        if (!flag) puts("No way");
        else {
            cnt = 0;
            puts("Found");
            for (int i = 1; i <= 31; ++i) {
                if (i == 31) printf("%d\n", res[i]);
                else printf("%d ", res[i]);
            }
        }
    }
    return 0;
}
