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
char str[22][22];
int pos[22];
bool used[22];
int main() {
  int T, n, m;
	for (scanf("%d", &T); T--; ) {
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; ++i) scanf(" %s", str[i]);
		memset(pos, 0, sizeof pos);
		memset(used, 0, sizeof used);
		int a, b;
		while (m--) {
			scanf("%d%d", &a, &b);
			pos[b] = a;
			used[a] = true;
		}
		int now = 1;
		for (int i = 1; i <= n; ++i) {
			if (pos[i] == 0) {
				while (used[now]) ++now;
				pos[i] = now;
				used[now] = true;
			}
		}
		for (int i = 1; i <= n; ++i) {
			if (i == n) printf("%s\n", str[pos[i] - 1]);
			else printf("%s ", str[pos[i] - 1]);
		}
	}
    return 0;
}
