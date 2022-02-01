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
#define maxn 33
using namespace std;
int mat[maxn][maxn];
int const dir[5][2] = {0, 0, 0, 1, 1, 0, 0, -1, -1, 0};

struct gauss {
    int n, m;
    int a[maxn][maxn];
    void print() {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j <= m; ++j) {
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
    }
    inline bool check(int x, int y) {
        return x >= 0 && x < 5 && y >= 0 && y < 6;
    }
    void init() {
        n = m = 30;
        memset(a, 0, sizeof a);
        int id, tx, ty;
        for (int i = 0; i < 5; ++i) {
            for (int j = 0; j < 6; ++j) {
                id = i * 6 + j;
                a[id][m] = mat[i][j];
                for (int k = 0; k < 5; ++k) {
                    tx = i + dir[k][0];
                    ty = j + dir[k][1];
                    if (check(tx, ty)) {
                       //printf("%d (%d, %d)\n", id, tx, ty);
                        a[id][tx * 6 + ty] = 1;
                    }
                }
            }
        }
    }
    void solve() {
        for (int i = 0, j = 0; i < n && j < m; ++j) {
            int id = i;
            for (int k = i + 1; k < n; ++k) {
               if (abs(a[k][j]) > abs(a[id][j])) id = k;
            }
            if (a[id][j]) {
                if (id != i) {
                    for (int k = j; k <= m; ++k) {
                        swap(a[i][k], a[id][k]);
                    }
                }
                for (int k = i + 1; k < n; ++k) {
                    if (a[k][j]) {
                        for (int it = j; it <= m; ++it) {
                            a[k][it] ^= a[i][it];
                        }
                    }
                }
                ++i;
            }
        }
        for (int i = n - 2; i >= 0; --i) {
            for (int j = i + 1; j < n; ++j) {
                a[i][m] ^= (a[i][j] & a[j][m]);
            }
        }
    }
} g;


int main() {
    int T, _ca = 1;
    for (scanf("%d", &T); T--; ) {
        for (int i = 0; i < 5; ++i) {
            for (int j = 0; j < 6; ++j) {
                scanf("%d", &mat[i][j]);
            }
        }
        g.init();
       // g.print();
        g.solve();
       // g.print();
        printf("PUZZLE #%d\n", _ca++);
        for (int i = 0; i < 30; ++i) {
            if (i % 6 == 5) {
                printf("%d\n", g.a[i][30]);
            }
            else printf("%d ", g.a[i][30]);
        }
    }
    return 0;
}
