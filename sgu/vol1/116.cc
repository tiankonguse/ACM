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
int const maxn = 10010;
int pri[maxn], mark[maxn], cnt;
void sieve() {
  cnt = 0, mark[0] = mark[1] = 1;
  for (int i = 2; i < maxn; ++i) {
		if (!mark[i]) pri[cnt++] = mark[i] = i;
		for (int j = 0; pri[j] * i < maxn; ++j) {
			mark[i * pri[j]] = pri[j];
			if (!(i % pri[j])) break;
		}
	}
}
int sup[maxn];
int dp[maxn], pre[maxn];
int ans[maxn];

int main() {
	sieve();
	int cc;
	for (cc = 0; pri[cc] <= cnt; ++cc) {
		sup[cc] = pri[pri[cc] - 1];
	}
	memset(dp, 0x3f, sizeof dp);
	dp[0] = 0; pre[0] = -1;
	for (int i = 0; i < cc; ++i) {
		for (int j = sup[i]; j <= 10000; ++j) {
			if (dp[j - sup[i]] + 1 < dp[j]) {
				dp[j] = dp[j - sup[i]] + 1;
				pre[j] = sup[i];
			}
		}
	}
	int n;
	while (~scanf("%d", &n)) {
		if (pre[n] == 0) {
			puts("0");
			continue;
		}
		int ant = 0;
		int pos = n;
		while (pos != 0) {
			ans[ant++] = pre[pos];
			pos -= pre[pos];
		}
		sort(ans, ans + ant);
		printf("%d\n", ant);
		for (int i = ant - 1; i >= 0; --i) {
			if (i == 0) printf("%d\n", ans[i]);
			else printf("%d ", ans[i]);
		}
	}
    return 0;
}
