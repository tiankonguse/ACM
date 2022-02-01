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
int n;
char num[111];
char words[50050][55];
int leng[50050];
bool ok[10][128];
char chset[] = "oqz;ij;abc;def;gh;kl;mn;prs;tuv;wxy;";
int dp[50050];
int pre[50050];
int ans[50050];
int main() {
  for (int i = 0, j = 0; j < 10; ++i) {
		if (chset[i] == ';') ++j;
		else ok[j][chset[i]] = true;
	}
	while (~scanf(" %s", num)) {
		if (num[0] == '-') break;
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) {
			scanf(" %s", words[i]);
			leng[i] = strlen(words[i]);
		}
		pre[0] = -1;
		memset(dp, 0x3f, sizeof dp);
		dp[0] = 0;
		int len = strlen(num);
		for (int i = 0; i < len; ++i) {
			for (int j = 0; j < n; ++j) {
				if (i + leng[j] > len) continue;
				bool flag = true;
				for (int k = 0; k < leng[j]; ++k) {
					if (!ok[num[i + k] - '0'][words[j][k]]) {
						flag = false;
						break;
					}
				}
				if (flag) {
					if (dp[i] + 1 < dp[i + leng[j]]) {
						dp[i + leng[j]] = dp[i] + 1;
						pre[i + leng[j]] = j;
					}
				}
			}
		}
		if (dp[len] == inf) puts("No solution.");
		else {
			int ant = 0;
			int pos = len;
			while (pos != 0) {
				ans[ant++] = pre[pos];
				pos -= leng[pre[pos]];
			}
			for (int i = ant - 1; i >= 0; --i) {
				if (i == 0) printf("%s\n", words[ans[i]]);
				else printf("%s ", words[ans[i]]);
			}
		}
	}
    return 0;
}
