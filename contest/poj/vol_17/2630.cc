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
using namespace std;
typedef long long ll;
int const maxn = 33;
int mp[maxn][maxn];
int pat[maxn][maxn];
int r, c;
bool check(int x, int y) { return x >= 0 && x < r && y >= 0 && y < c; }
int mat[maxn][maxn];
int n, m;
int rr;
bool fre[maxn]; int fs[maxn], fnt;
int x[maxn], y[maxn];
void print() {
  for (int i = 0; i < n; ++i) {
		for (int j = 0; j <= m; ++j) {
			printf("%d ", mat[i][j]);
		}
		puts("");
	}
}
int cal(int r) {
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
    int ret = 0;
    for (int i = 0; i < m; ++i) ret += x[i];
	if (ret < rr) {
		for (int i = 0; i < m; ++i) y[i] = x[i];
	}
    return ret;
}
int solve(int r) {
    int mx = 1 << fnt;
    rr = inf;
    for (int i = 0; i < mx; ++i) {
        if (__builtin_popcount(i) >= rr) continue;
        for (int j = 0; j < fnt; ++j) {
            if (i & (1 << j)) x[fs[j]] = 1;
            else x[fs[j]] = 0;
        }
        rr = min(rr, cal(r));
    }
    return rr;
}
int gauss() {
    memset(fre, false, sizeof fre); fnt = 0;
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
	for (int i = r; i < n; ++i) {
		if (mat[i][m] != 0) return -1;
	}

    return solve(r);
}

int main() {
	int ca = 1;
	char buf[maxn];
	while (~scanf("%d%d", &r, &c)) {
		if (r == 0 && c == 0) break;
		for (int i = 0; i < 3; ++i) {
			scanf(" %s", buf);
			for (int j = 0; j < 3; ++j) {
				pat[i][j] = buf[j] == '*';
			}
		}
		memset(mat, 0, sizeof mat);
		n = m = r * c;
		for (int i = 0; i < r; ++i) {
			for (int j = 0; j < c; ++j) {
				int id = i * c + j;
				for (int di = -1; di <= 1; ++di) {
					for (int dj = -1; dj <= 1; ++dj) {
						int ti = i + di, tj = j + dj;
						if (check(ti, tj) && pat[di + 1][dj + 1]) {
							mat[ti * c + tj][id] = 1;
						}
					}
				}
				mat[id][m] = 1;
			}
		}
		int ret = gauss();
		printf("Case #%d\n", ca++);
		if (ret == -1) puts("Impossible.");
		else {
			for (int i = 0, j = 0; i < n; ++i) {
				if (y[i]) {
					++j;
					if (j == ret) {
						printf("%d\n", i + 1);
						break;
					}
					else printf("%d ", i + 1);
				}
			}
		}
	}
    return 0;
}
