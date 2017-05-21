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
int const maxn = 1010;
int a[maxn];
int dp[maxn][2][2];
int main() {
	int n;
	while (~scanf("%d", &n)) {
		for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
		memset(dp, 0, sizeof dp);
		dp[0][0][0] = 1;
		if (a[0] > 0) dp[0][0][1] = 1;
		
		for (int i = 0; i < n - 1; ++i) {
			for (int j = 0; j < 2; ++j) {
				for (int k = 0; k < 2; ++k) {
					if (a[i] - j - k >= 0 && a[i] - j - k <= 1) {
						dp[i + 1][k][a[i] - j - k] += dp[i][j][k];
					}
				}
			}	
		}
		
		int ret = 0;
		for (int i = 0; i < 2; ++i) {
			for (int j = 0; j < 2; ++j) {
				if (i + j == a[n - 1]) {
					ret += dp[n - 1][i][j];
				}
			}
		}
		printf("%d\n", ret);
	}	
    return 0;
}

