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
int const maxm = 5010;
struct rec {
	int x1, y1, x2, y2;
	char c;
} r[maxm];
int n, m;
int ret;

void dfs(int x1, int y1, int x2, int y2, int k) {
	if (k == m) {
		ret += (x2 - x1 + 1) * (y2 - y1 + 1);
		return;
	}
	int t;
	if (x1 < r[k].x1) {
		t = min(r[k].x1 - 1, x2);
		dfs(x1, y1, t, y2, k + 1);
		x1 = t + 1;
		if (x1 > x2) return;
	}
	if (x2 > r[k].x2) {
		t = max(r[k].x2 + 1, x1);
		dfs(t, y1, x2, y2, k + 1);
		x2 = t - 1;
		if (x1 > x2) return;
	}
	if (y1 < r[k].y1) {
		t = min(r[k].y1 - 1, y2);
		dfs(x1, y1, x2, t, k + 1);
		y1 = t + 1;
		if (y1 > y2) return;
	}
	if (y2 > r[k].y2) {
		t = max(r[k].y2 + 1, y1);
		dfs(x1, t, x2, y2, k + 1);
		y2 = t - 1;
		if (y1 > y2) return;
	}
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i) {
		scanf("%d%d%d%d %c", &r[i].x1, &r[i].y1, &r[i].x2, &r[i].y2, &r[i].c);
		if (r[i].x1 > r[i].x2) swap(r[i].x1, r[i].x2);
		if (r[i].y1 > r[i].y2) swap(r[i].y1, r[i].y2);
	}	
	for (int i = m - 1; i >= 0; --i) {
		if (r[i].c == 'b') dfs(r[i].x1, r[i].y1, r[i].x2, r[i].y2, i + 1);
	}	
	printf("%d\n", n * n - ret);
	return 0;
}

