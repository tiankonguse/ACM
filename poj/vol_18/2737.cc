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
int const maxn(1111);
struct point {
  int x, y;
	friend bool operator < (point a, point b) {
		if (a.y == b.y) return a.x < b.x;
		else return a.y < b.y;
	}
} p[maxn];
struct node {
	int x, y;
	node (int x, int y) : x(x), y(y) { }
	node () { }
	friend bool operator < (node a, node b) {
		return a.x * b.y - a.y * b.x < 0;
	}
	friend bool operator == (node a, node b) {
		return a.x * b.y == a.y * b.x;
	}
} v[maxn];

int main() {
	int n, m, ca = 1;
	while (~scanf("%d", &n) && n) {
		for (int i = 0; i < n; ++i) scanf("%d%d", &p[i].x, &p[i].y);
		sort(p, p + n);
		int ret = 0;
		for (int i = 0; i < n; ++i) {
			m = 0;
			for (int j = i + 1; j < n; ++j) {
				v[m++] = node(p[j].x - p[i].x, p[j].y - p[i].y);
			}
			sort(v, v + m);
			int rr = 1;
			for (int j = 1; j < m; ++j) {
				if (v[j] == v[j - 1]) {
					++rr;
					ret = max(ret, rr);
				}
				else {
					rr = 1;
				}
			}
		}
		++ret;
		if (ret < 4) ret = 0;
		printf("Photo %d: %d points eliminated\n", ca++, ret);
	}
    return 0;
}
