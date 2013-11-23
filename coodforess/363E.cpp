#include <cstdio>
#include <algorithm>
using namespace std;

int sc[555][555], cum[555][555], w[555], cp[9999], csc[555][555], mcsc[555][555];
long long nm[555][555];
int main() {
    int n, m, r, msc = 0;
    long long ngm = 0;

    scanf("%d %d %d", &n, &m, &r);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", sc[i]+j);
            cum[i][j+1] = cum[i][j]+sc[i][j];
        }
    }

    w[0] = r;
    for (int i = 1; i <= r; i++) {
        for (w[i] = w[i-1]; i*i+w[i]*w[i] > r*r; w[i]--);
    }

    cp[0] = 2*r+1;
    for (int i = 1; i <= 2*r; i++) {
        for (int h = 1; h <= r; h++) {
            if (h >= i-r && h <= i) {
                cp[i] = max(cp[i], w[h]+w[i-h]+1);
            }
        }
    }
    for (int i = r; i < n-r; i++) {
        for (int j = r; j < m-r; j++) {
            csc[i][j] = cum[i][j+w[0]+1] - cum[i][j-w[0]];
            for (int h = 1; h <= r; h++) {
                csc[i][j] += cum[i+h][j+w[h]+1] - cum[i+h][j-w[h]];
                csc[i][j] += cum[i-h][j+w[h]+1] - cum[i-h][j-w[h]];
            }
        }
    }

    for (int i = r; i < n-r; i++) {
        mcsc[i][m-r-1] = csc[i][m-r-1];
        nm[i][m-r-1] = 1;
        for (int j = m-r-2; j >= r; j--) {
            if (csc[i][j] <= mcsc[i][j+1]) {
                mcsc[i][j] = mcsc[i][j+1];
                nm[i][j] = nm[i][j+1];
                if (csc[i][j] == mcsc[i][j+1]) nm[i][j]++;
            } else {
                mcsc[i][j] = csc[i][j];
                nm[i][j] = 1;
            }
        }
    }
    for (int i = r; i < n-r; i++) {
        for (int j = i+2*r+1; j < n-r; j++) {
            if (mcsc[i][r]+mcsc[j][r] == msc) ngm += nm[i][r]*nm[j][r];
            else if (mcsc[i][r]+mcsc[j][r] > msc) {
                msc = mcsc[i][r]+mcsc[j][r];
                ngm = nm[i][r]*nm[j][r];
            }
        }
    }
    for (int i = r; i < n-r; i++) {
        for (int j = r; j < m-r; j++) {
            for (int h = 0; h <= 2*r; h++) {
                if (j + cp[h]+r >= m) continue;
                if (i+h < n-r) {
                    int score = csc[i][j] + mcsc[i+h][j+cp[h]];
                    if (score == msc) {
                        ngm += nm[i+h][j+cp[h]];
                    } else if (score > msc) {
                        msc = score;
                        ngm = nm[i+h][j+cp[h]];
                    }
                }
                if (h && i-h >= r) {
                    int score = csc[i][j] + mcsc[i-h][j+cp[h]];
                    if (score == msc) {
                        ngm += nm[i-h][j+cp[h]];
                    } else if (score > msc) {
                        msc = score;
                        ngm = nm[i-h][j+cp[h]];
                    }
                }
            }
        }
    }
    printf("%d %lld\n", msc, ngm);

    return 0;
}
