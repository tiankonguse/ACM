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
double const eps = 1e-11;
double const pi = atan2(0., -1.);
inline double dist(double x1, double y1, double x2, double y2) {
  return sqrt( (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) );
}
double ans[155][2];

int main() {
	int n, n1, n2;
	double x1, y1, x2, y2;
	while (~scanf("%d%d%d", &n, &n1, &n2)) {
		scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
		if (n1 > n2) {
			swap(n1, n2);
			swap(x1, x2);
			swap(y1, y2);
		}
		int d = n2 - n1;
		double ox = 0.5 * (x1 + x2);
		double oy = 0.5 * (y1 + y2);
		double dx = x2 - x1, dy = y2 - y1;
		swap(dx, dy), dy = -dy;
		double nom = sqrt(dx * dx + dy * dy);
		dx /= nom, dy /= nom;
		double theta = pi * d / n;
	
		
		double dis = 0.5 * dist(x1, y1, x2, y2);
		double dd = dis / tan(theta);
		dx *= dd, dy *= dd;
		double rx = ox + dx, ry = oy + dy;
		
		
		int num = n1;
		double ua = 2.0 * pi / n;
		double ca = cos(ua), sa = sin(ua);
		dx = x1 - rx, dy = y1 - ry;
		
		for (int i = 0; i < n; ++i) {
			ans[num][0] = rx + dx;
			ans[num][1] = ry + dy;
			--num; if (num == 0) num = n;
			double nx = dx * ca - dy * sa;
			double ny = dx * sa + dy * ca;
			dx = nx, dy = ny;
		}
		for (int i = 1; i <= n; ++i) {
			printf("%.6lf %.6lf\n", ans[i][0] + eps, ans[i][1] + eps);
		}
	}
    return 0;
}
