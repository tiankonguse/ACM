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
int const maxn = 222;
double const eps = 1e-8;
inline int sgn(double x) { return x < -eps ? -1 : x > eps ? 1 : 0; }
struct node {
  int t;
	double x;
	friend bool operator < (node a, node b) {
		if (sgn(a.x - b.x) == 0) return a.t > b.t;
		else return a.x < b.x;
	}
} p[maxn];

int main() {
	double x0, y0, x1, y1, x2, y2, xp1, xp2;
	int T, n;	
	for (scanf("%d", &T); T--; ) {
		scanf("%d %lf %lf", &n, &x0, &y0);
		for (int i = 0; i < n; ++i) {
			scanf("%lf %lf %lf %lf", &x1, &y1, &x2, &y2);
			xp1 = (x0 * y1 - x1 * y0) / (y1 - y0);
			xp2 = (x0 * y2 - x2 * y0) / (y2 - y0);
			if (xp1 > xp2) swap(xp1, xp2);
			p[i * 2].t = 1, p[i * 2].x = xp1;
			p[i * 2 + 1].t = -1, p[i * 2 + 1].x = xp2;
		}
		n <<= 1;
		sort(p, p + n);
		int top = 0, ret = 0;
		for (int i = 0; i < n; ++i) {
			top += p[i].t;
			if (top == 0) ++ret;
		}
		printf("%d\n", ret + 1);
	}
    return 0;
}
