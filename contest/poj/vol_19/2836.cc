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
int const maxn = 16;
typedef long long ll;
struct point {
  int x, y;
} p[maxn];
struct rec {
	int msk, area;
} r[2222];
int dp[65536];
int main() {
	int n, m;
	while (~scanf("%d", &n) && n != 0) {
		for (int i = 0; i < n; ++i) {
			scanf("%d%d", &p[i].x, &p[i].y);
		}
		m = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = i + 1; j < n; ++j) {
				int x1 = min(p[i].x, p[j].x);
				int x2 = max(p[i].x, p[j].x);
				int y1 = min(p[i].y, p[j].y);
				int y2 = max(p[i].y, p[j].y);
				if (x1 != x2 && y1 != y2) {
					r[m].msk = 0;
					r[m].area = (x2 - x1) * (y2 - y1);
					for (int k = 0; k < n; ++k) {
						if (p[k].x >= x1 && p[k].x <= x2 && 
							p[k].y >= y1 && p[k].y <= y2) {
								r[m].msk |= 1 << k;
						}
					}
					++m;
				}
				else if (x1 == x2) {
					r[m].msk = 0;
					r[m].area = (y2 - y1);
					for (int k = 0; k < n; ++k) {
						if (p[k].x >= x1 - 1 && p[k].x <= x2 && 
							p[k].y >= y1 && p[k].y <= y2) {
								r[m].msk |= 1 << k;
						}
					}
					++m;
					r[m].msk = 0;
					r[m].area = (y2 - y1);
					for (int k = 0; k < n; ++k) {
						if (p[k].x >= x1 && p[k].x <= x2 + 1 && 
							p[k].y >= y1 && p[k].y <= y2) {
								r[m].msk |= 1 << k;
						}
					}
					++m;
				}
				else if (y1 == y2) {
					r[m].msk = 0;
					r[m].area = x2 - x1;
					for (int k = 0; k < n; ++k) {
						if (p[k].x >= x1 && p[k].x <= x2 && 
							p[k].y >= y1 - 1 && p[k].y <= y2) {
								r[m].msk |= 1 << k;
						}
					}
					++m;
					r[m].msk = 0;
					r[m].area = x2 - x1;
					for (int k = 0; k < n; ++k) {
						if (p[k].x >= x1 && p[k].x <= x2 && 
							p[k].y >= y1 && p[k].y <= y2 + 1) {
								r[m].msk |= 1 << k;
						}
					}
					++m;
				}
			}
		}
	
		memset(dp, 0x3f, sizeof dp);
		dp[0] = 0;
		int mx = 1 << n;
		for (int i = 0; i < mx; ++i) {
			if (dp[i] != inf) {
				for (int j = 0; j < m; ++j) {
					dp[i | r[j].msk] = min(dp[i | r[j].msk], dp[i] + r[j].area);
				}
			}
		}
		printf("%d\n", dp[mx - 1]);
	}	
    return 0;
}
