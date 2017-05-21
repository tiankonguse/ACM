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
int const maxn = 111;
typedef long long ll;
int g[maxn][maxn], d[maxn][maxn], f[maxn][maxn];
int ans[maxn], ant;
int s[maxn], top;

int main() {
  int n, m;
	int a, b, c;
	while (~scanf("%d%d", &n, &m)) {
		memset(g, 0x3f, sizeof g);
		memset(d, 0x3f, sizeof d);
		memset(f, 0xff, sizeof f);
		for (int i = 1; i <= n; ++i) g[i][i] = d[i][i] = 0;
		for (int i = 0; i < m; ++i) {
			scanf("%d%d%d", &a, &b, &c);
            d[a][b] = d[b][a] = g[a][b] = g[b][a] = min(d[a][b], c);
		}
		int ret = inf;
		for (int k = 1; k <= n; ++k) {
			for (int i = 1; i < k; ++i) {
				for (int j = i + 1; j < k; ++j) {
					if (g[i][k] == inf || g[k][j] == inf || d[i][j] == inf) continue;
					if (g[i][k] + g[k][j] + d[i][j] < ret) {
						ret = g[i][k] + g[k][j] + d[i][j];
						ant = 0; top = 0;
						s[++top] = j, s[++top] = i;
						while (top != 1) {
							int t = ans[ant++] = s[top];
							--top;
							while (f[t][s[top]] != -1) {
								s[top + 1] = f[t][s[top]];
								++top;
							}
						}
						ans[ant++] = j;
						ans[ant++] = k;
					}
				}
			}
			for (int i = 1; i <= n; ++i) {
				for (int j = 1; j <= n; ++j) {
					if (d[i][k] + d[k][j] < d[i][j]) {
						d[i][j] = d[i][k] + d[k][j];
						f[i][j] = f[j][i] = k;
					}
				}
			}
		}

		if (ret == inf) puts("No solution.");
		else {
			for (int i = 0; i < ant; ++i) {
				if (i == ant - 1) printf("%d\n", ans[i]);
				else printf("%d ", ans[i]);
			}
		}
	}
    return 0;
}
