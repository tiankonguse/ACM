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
int const maxn = 18;
int const maxm = 1 << 18;
typedef long long ll;
bool dp[maxm][maxn];
int pre[maxm][maxn][3];
int ans[maxn + maxn + 5];
char str[maxn + 5];
int a[maxn];
int n, mx;

int main() {
	scanf(" %s", str);
	n = strlen(str);
	for (int i = 0; i < n; ++i) a[i] = str[i] - '0';
	mx = 1 << n;
	dp[0][0] = true;
	int tj, tk;
	for (int j = 0; j < mx; ++j) {
		for (int k = 0; k < 17; ++k) {
			if (dp[j][k]) {
				for (int l = 0; l < n; ++l) {
					if (!(j >> l & 1)) {
						tj = j | (1 << l);
						tk = (k * 10 + a[l]) % 17;
						dp[tj][tk] = true;
						pre[tj][tk][0] = j;
						pre[tj][tk][1] = k;
						pre[tj][tk][2] = a[l];
					}				
				}
			}
		}
	}
	if (!dp[mx - 1][0]) puts("-1");
	else {
		int nMsk = mx - 1, nK = 0;
		for (int i = 0; i < n; ++i) {
			ans[n - i - 1] = pre[nMsk][nK][2];
			tj = pre[nMsk][nK][0];
			tk = pre[nMsk][nK][1];
			nMsk = tj;
			nK = tk;
		}
		for (int i = 0; i < n; ++i) {
			if (ans[i] != 0) {
				for (int j = i; j < n; ++j) printf("%d", ans[j]);
				puts("");
				break;
			}
			else ans[n++] = 0;
		}
	}
	return 0;
}

