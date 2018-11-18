#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair <int, int> PII;
const int N = 1005;
int m, n;
int a[N][N];
int f[4][N][N];

bool inRange(int x, int y) {
    return 0 <= x && x < m && 0 <= y && y < n;
}

void checkmax(int &t, int x) {
    if (x > t) t = x;
}

void calcf(int (&f)[N][N], int sx, int sy, int dx, int dy) {
    for (int i = sx; 0 <= i && i < m; i += dx) {
        for (int j = sy; 0 <= j && j < n; j += dy) {
            f[i][j] += a[i][j];
            if (inRange(i + dx, j)) {
                checkmax(f[i + dx][j], f[i][j]);
            }
            if (inRange(i, j + dy)) {
                checkmax(f[i][j + dy], f[i][j]);
            }
        }
    }
}

int main() {
    scanf("%d%d", &m, &n);
    rep (i, m) rep (j, n) scanf("%d", &a[i][j]);
    memset(f, 0, sizeof(f));
    calcf(f[0], 0, 0, 1, 1);
    calcf(f[1], m - 1, 0, -1, 1);
    calcf(f[2], 0, n - 1, 1, -1);
    calcf(f[3], m - 1, n - 1, -1, -1);
    int ans = 0;
    rep (i, m) rep (j, n) {
        if (0 < i && i + 1 < m && 0 < j && j + 1 < n) {
            checkmax(ans, f[0][i - 1][j] + f[1][i][j - 1] + f[2][i][j + 1] + f[3][i + 1][j]);
            checkmax(ans, f[0][i][j - 1] + f[1][i + 1][j] + f[2][i - 1][j] + f[3][i][j + 1]);
        }
    }
    printf("%d\n", ans);
}

