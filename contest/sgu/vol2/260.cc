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
#include <ctime>

#define inf 0x3f3f3f3f
#define Inf 0x3FFFFFFFFFFFFFFFLL
#define maxn 212
using namespace std;
int mat[maxn][maxn];
int n, m;
void print(int mat[maxn][maxn]) {
    putchar(10);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= m; ++j) {
            printf("%d ", mat[i][j]);
        }
        putchar(10);
    }
}
int x[maxn];


bool fre[maxn]; int fs[maxn], fnt;

int solve(int r) {
    memset(x, 0, sizeof x);
    for (int i = r - 1, j = m - 1; i >= 0 && j >= 0; --i) {
        while (j >= 0 && fre[j]) --j;
        if (j >= 0) {
            x[j] = mat[i][m];
            for (int k = j + 1; k < m; ++k) {
                x[j] ^= (mat[i][k] && x[k]);
            }
            --j;
        }
    }
    return r;
}
int gauss() {
    memset(fre, 0, sizeof fre); fnt = 0;
    int r, c, mr, mx;
    for (r = c = 0; r < n && c < m; ++r, ++c) {
        mx = 0, mr = -1;
        for (int i = r; i < n; ++i) {
            if (abs(mat[i][c]) > mx) {
                mx = abs(mat[i][c]);
                mr = i;
            }
        }
        if (!~mr) {
            fre[c] = true;
            fs[fnt++] = c;
            --r;
            continue;
        }
        else if (mr != r) {
            for (int j = c; j <= m; ++j) {
                swap(mat[r][j], mat[mr][j]);
            }
        }
        for (int i = r + 1; i < n; ++i) {
            if (!mat[i][c]) continue;
            for (int j = c; j <= m; ++j) {
                mat[i][j] ^= mat[r][j];
            }
        }
    }
    for (int i = r; i < n; ++i) if (mat[i][m] != 0) return -1;

    return solve(r);
}
int _mat[maxn][maxn];
int main() {
    int k, a;
    while (~scanf("%d", &n)) {
        m = n;
        memset(_mat, 0, sizeof _mat);
        for (int i = 0; i < n; ++i) {
            for (scanf("%d", &k); k--; ) {
                scanf("%d", &a); --a;
                _mat[a][i] = true;
            }
        }
        for (int i = 0; i < n; ++i) {
            scanf("%d", &_mat[i][m]);
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j <= m; ++j) {
                mat[i][j] = _mat[i][j];
            }
        }
//        print(mat);
        int ret = gauss();
//print(mat);
//cout<<ret<<endl;
        if (ret != -1) {
            int s = 0;
            for (int i = 0; i < n; ++i) if (x[i]) ++s;
            printf("%d\n", s);
            for (int i = 0, j = 0; i < n; ++i) {
                if (x[i]) {
                    if (j == s - 1) {
                        printf("%d\n", i + 1);
                        break;
                    }
                    else {
                        printf("%d ", i + 1);
                    }
                    ++j;
                }
            }
        }
        else {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j <= m; ++j) {
                    mat[i][j] = _mat[i][j];
                }
                mat[i][m] ^= 1;
            }
            ret = gauss();
//            print(mat);
//            cout<<ret<<endl;
            if (ret != -1) {
                int s = 0;
                for (int i = 0; i < n; ++i) if (x[i]) ++s;
                printf("%d\n", s);
                for (int i = 0, j = 0; i < n; ++i) {
                    if (x[i]) {
                        if (j == s - 1) {
                            printf("%d\n", i + 1);
                            break;
                        }
                        else {
                            printf("%d ", i + 1);
                        }
                        ++j;
                    }
                }
            }
            else puts("-1");
        }
    }
    return 0;
}
