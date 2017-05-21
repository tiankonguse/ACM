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
int const maxn = 10101;
double const eps = 1e-9;
struct Point {
	double x, y;
} p[maxn];
double x[maxn], y[maxn];
inline int sgn(double x) {
	return x < -eps ? -1 : x > eps ? 1 : 0;
}
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) scanf("%lf %lf", &p[i].x, &p[i].y);

	if (n & 1) {
		x[0] = y[0] = 0.0; int sig = 1;
		for (int i = n - 1; i >= 0; --i) {
			if (sig == 1) {
				x[0] += p[i].x;
				y[0] += p[i].y;
			}
			else {
				x[0] -= p[i].x;
				y[0] -= p[i].y;
			}
			sig ^= 1;
		}
		for (int i = 1; i < n; ++i) {
			x[i] = 2.0 * p[i - 1].x - x[i - 1];
			y[i] = 2.0 * p[i - 1].y - y[i - 1];
		}
	}	
	else {
		x[0] = 0.0;
		y[0] = 0.0;
		for (int i = 1; i <= n; ++i) {
			x[i] = 2.0 * p[i - 1].x - x[i - 1];
			y[i] = 2.0 * p[i - 1].y - y[i - 1];
		}
		if (!(sgn(x[0] - x[n]) == 0 && sgn(y[0] - y[n]) == 0)) {
			puts("NO");
			return 0;
		}
	}
	puts("YES");
	for (int i = 0; i < n; ++i) {
		printf("%.3lf %.3lf\n", x[i], y[i]);
	}
	return 0;
}
