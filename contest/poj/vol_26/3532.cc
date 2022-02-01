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
#define maxn 55
using namespace std;
double const eps = 1e-8;
double mat[maxn][maxn];
double x[maxn];
int n, m;
inline int sgn(double x) { return x < -eps ? -1 : x < eps ? 0 : 1; } 
void print() {
    puts("----------------------------");
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= m; ++j) {
            printf("%.2lf ", mat[i][j]);
        }
        puts("");
    }
}
void gauss() {
    int r, c, mr;
    double mx, t;
    for (r = c = 0; r < n && c < m; ++r, ++c) {
        mr = -1, mx = eps;
        for (int i = r; i < n; ++i) {
            if (fabs(mat[i][c]) > mx) {
                mx = fabs(mat[i][c]);
                mr = i;
            }
        }
        if (!~mr) {
            --r;
            continue;
        }
        else if (mr != r) {
            for (int i = c; i <= m; ++i) {
                swap(mat[r][i], mat[mr][i]);
            }
        }
        for (int i = r + 1; i < n; ++i) {
            if (sgn(mat[i][c]) == 0) continue;
            t = mat[i][c] / mat[r][c];
            for (int j = c; j <= m; ++j) {
                mat[i][j] -= mat[r][j] * t;
            }
        }
     //   print();
    }
    x[m - 1] = 0;
    for (int i = m - 2; i >= 0; --i) {
        t = mat[i][m];
        for (int j = i + 1; j < m; ++j) {
            t -= x[j] * mat[i][j];
        }
        x[i] = t / mat[i][i];
    }
}

int main() {
   
    int T, k;
    int a, b; double r;
    while (~scanf("%d%d", &n, &k)) {
        m = n;
        memset(mat, 0, sizeof mat);
        for (int i = 0; i < k; ++i) {
            scanf("%d%d%lf", &a, &b, &r);
            --a, --b;
            mat[a][a] += 1.0 / r;
            mat[a][b] -= 1.0 / r;
            mat[b][b] += 1.0 / r;
            mat[b][a] -= 1.0 / r;
        }
        mat[0][m] = 1, mat[n - 1][m] = -1;
        gauss();
        printf("%.2f\n", x[0]);
        //print();
      
    }
    //system("pause");
    return 0;
}
