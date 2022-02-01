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
int num[maxn][30];
int cnt[30];
char str[11];
int main() {
  int n;
	while (scanf("%d", &n) && n) {
		memset(num, 0, sizeof num);
		memset(cnt, 0, sizeof cnt);
		for (int i = 0; i < n; ++i) {
			scanf(" %s", str);
			for (int j = 0; str[j]; ++j) {
				num[i][str[j] - 'A']++;
			}
		}
		scanf(" %s", str);
		int v = 0;
		for (int i = 0; str[i]; ++i) {
			if (str[i] == '_') ++v;
			else ++cnt[str[i] - 'A'];
		}
		int ret = 0;
		for (int i = 0; i < n; ++i) {
			int need = 0;
			for (int j = 0; j < 26; ++j) {
				need += max(0, num[i][j] - cnt[j]);
			}
			if (need <= v) ++ret;
		}
		printf("%d\n", ret);
	}
    return 0;
}
