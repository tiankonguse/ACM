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
int const maxn = 2001000;
bool mark[maxn];
int p[10];
int main() {
  int a, b, c, d;
	int T;
	for (scanf("%d", &T); T--; ) {
		scanf("%d%d%d%d", &p[0], &p[1], &p[2], &p[3]);
		sort(p, p + 4);
		memset(mark, 0, sizeof mark);
		mark[0] = true;
		int tr = 0;
		for (int i = 0; i < 1100000 ; ++i) {
			if (mark[i]) {
				for (int j = 0; j < 4; ++j) {
					if (i + p[j] <= 1100000) {
						mark[i + p[j]] = true;
					}
				}
			}
			else {
				tr = i;	
				if (i > 1000000) break;
			}
		}
		int mx = -1, ret = 0;
		for (int i = 1000000; i >= 1; --i) {
			if (!mark[i]) {
				if (tr <= 1000000 && mx == -1) mx = i;
				++ret;
			}
		}
		printf("%d\n%d\n", ret, mx);
	}
    return 0;
}
