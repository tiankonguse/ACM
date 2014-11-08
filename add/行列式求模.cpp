// @author Navi
// 高斯消元法行列式求模。复杂度O(n^3logn)。
// n为行列式大小，计算|mat| % m
const int MAXN = 200;
typedef long long LL;
int detMod(int n, int m, int mat[][MAXN]) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            mat[i][j] %= m;
    LL ret = 1;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++)
            while (mat[j][i] != 0) {
                LL t = mat[i][i] / mat[j][i];
                for (int k = i; k < n; k++) {
                    mat[i][k] = (mat[i][k] - mat[j][k] * t) % m;
                    int s = mat[i][k];
                    mat[i][k] = mat[j][k];
                    mat[j][k] = s;
                }
                ret = -ret;
            }
        if (mat[i][i] == 0)
            return 0;
        ret = ret * mat[i][i] % m;
    }
    if (ret < 0)
        ret += m;
    return (int)ret;
}

// @author Navi
// 高斯消元法行列式求模。复杂度O(n^3 + n^2logn)。
// n为行列式大小，计算|mat| % m
// 速度只比O(n^3logn)的快一些，推荐用另外那个。
const int MAXN = 200;
typedef long long LL;
int detMod(int n, int m, int mat[][MAXN]) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            mat[i][j] %= m;
    LL ret = 1;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            LL x1 = 1, y1 = 0, x2 = 0, y2 = 1, p = i, q = j;
            if (mat[i][i] < 0) {
                x1 = -1;
                mat[i][i] = -mat[i][i];
                ret = -ret;
            }
            if (mat[j][i] < 0) {
                y2 = -1;
                mat[j][i] = -mat[j][i];
                ret = -ret;
            }
            while (mat[i][i] != 0 && mat[j][i] != 0) {
                if (mat[i][i] <= mat[j][i]) {
                    int t = mat[j][i] / mat[i][i];
                    mat[j][i] -= mat[i][i] * t;
                    x2 -= x1 * t;
                    y2 -= y1 * t;
                } else {
                    int t = mat[i][i] / mat[j][i];
                    mat[i][i] -= mat[j][i] * t;
                    x1 -= x2 * t;
                    y1 -= y2 * t;
                }
            }
            x1 %= m; y1 %= m;
            x2 %= m; y2 %= m;
            if (mat[i][i] == 0 && mat[j][i] != 0) {
                ret = -ret;
                p = j; q = i;
                mat[i][i] = mat[j][i];
                mat[j][i] = 0;
            }
            for (int k = i + 1; k < n; k++) {
                int s = mat[i][k], t = mat[j][k];
                mat[p][k] = (s * x1 + t * y1) % m;
                mat[q][k] = (s * x2 + t * y2) % m;
            }
        }
        if (mat[i][i] == 0)
            return 0;
        ret = ret * mat[i][i] % m;
    }
    if (ret < 0)
        ret += m;
    return (int)ret;
}
 