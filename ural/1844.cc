#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
#include <sstream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <ctime>

#define inf 0x3f3f3f3f
#define Inf 0x3FFFFFFFFFFFFFFFLL
using namespace std;
typedef long long ll;
int const maxn = 1010;
int a[maxn], b[maxn];
int n, m, k;
bool dp[maxn][maxn];
int num[maxn];
bool has[maxn][maxn];

int main() {
	int T;
	char op[2]; 
	for (scanf("%d", &T); T--; ) {
		scanf("%d%d%d", &n, &m, &k);
		for (int i = 1; i <= n; ++i) {
			scanf(" %s %d", op, &a[i]);
			if (op[0] == '-') a[i] = -a[i];
		}
		for (int i = 1; i <= m; ++i) {
			scanf(" %s %d", op, &b[i]);
			if (op[0] == '-') b[i] = -b[i];
		}
	
		memset(num, 0, sizeof num);
		for (int i = 1; i <= n; ++i) {
			int x = a[i];
			if (x > 0) ++num[x];
			else --num[-x];
			for (int j = 1; j <= k; ++j) {
				if (num[j] > 0) has[i][j] = true;
				else has[i][j] = false;
			}
		}
		
		memset(dp, 0, sizeof dp);
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j) {
				if (!dp[i - 1][j] || !dp[i][j - 1]) {
					if (b[j] > 0 && has[i][b[j]]) {
						int t = b[j];
						for (int p = i; p <= n && a[p] + t != 0; ++p) {
							for (int q = j; q <= m && b[q] + t != 0; ++q) {
								dp[p][q] = true;
							}
						}
					}
				}
			}
		}

		
		bool flag = true;
		for (int i = 0; i <= n; ++i) {
			for (int j = 0; j <= m; ++j) {
				if (i == n && j == m) continue;
				if (!dp[i][j] && (i + 1 > n || dp[i + 1][j]) && (j + 1 > m || dp[i][j + 1])) {
					flag = false;
				}
			}
		}
		puts(flag ? ":-)" : ":-(");
	}
	return 0;
}

