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
double const eps = 1e-10;
double xx[5];
int main() {
	double _c, _b, _m;
	while (~scanf("%lf %lf %lf", &_b, &_c, &_m)) {
		double a = _m + _m, b = _b, c = _c;
		xx[0] = a, xx[1] = b, xx[2] = c;
		sort(xx, xx + 3);
		if (xx[0] + xx[1] + eps < xx[2]) puts("Mission impossible");
		else {
			double cs = 0.5 * (a * a + b * b - c * c) / a / b;
			double bx = b * cs;
			double by = sqrt(b * b - bx * bx + eps);
			double cx = a - bx;
			double cy = -by;
			puts("0.00000 0.00000");
			printf("%.5lf %.5lf\n%.5lf %.5lf\n", bx, by, cx, cy);
		}
	}
	return 0;
}

