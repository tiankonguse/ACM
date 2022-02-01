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
#define maxm 10101
using namespace std;
bool mpa[maxn][maxn], mpb[maxn][maxn];


struct edges {
    int u, next;
} e[maxm];
int p[maxn], idx;
void addedge(int u, int v) {
    e[idx].u = v;
    e[idx].next = p[u];
    p[u] = idx++;
}
void init() {
    idx = 0;
    memset(p, 0xff, sizeof p);
}
int res[maxn][4], rnt;

int di, dj;
bool dfs(int u, int des, int pre) {
    if (u == des) return true;
    int v;
    bool flag = false;
    for (int i = p[u]; ~i; i = e[i].next) {
        v = e[i].u;
        if (v != pre && mpa[u][v]) {
            flag |= dfs(v, des, u);
            if (flag) {
                if (mpa[u][v] && !mpb[u][v]) {
                    di = u;
                    dj = v;
                }
                return true;
            }

        }
    }
    return flag;
}


int main() {
    int n;
    int a, b;
    while (~scanf("%d", &n)) {
        init();
        for (int i = 0; i < n - 1; ++i) {
            scanf("%d%d", &a, &b);
            addedge(a, b);
            addedge(b, a);
            mpa[a][b] = mpa[b][a] = true;
        }
        for (int i = 0; i < n - 1; ++i) {
            scanf("%d%d", &a, &b);
            mpb[a][b] = mpb[b][a] = true;
        }
        rnt = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = i + 1; j <= n; ++j) {
                if (mpb[i][j] && !mpa[i][j]) {
                    dfs(i, j, -1);
                    res[rnt][0] = i, res[rnt][1] = j;
                    res[rnt][2] = di, res[rnt][3] = dj;
                    ++rnt;
                    mpa[di][dj] = mpa[dj][di] = false;
                    mpa[i][j] = mpa[j][i] = true;
                    addedge(i, j);
                    addedge(j, i);
                }
            }
        }
        printf("%d\n", rnt);
        for (int i = 0; i < rnt; ++i) {
            printf("1 %d %d %d %d\n", res[i][0], res[i][1], res[i][2], res[i][3]);
        }
    }
    return 0;
}
