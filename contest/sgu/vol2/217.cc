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
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define Rep(i, n) for (int i = 1; i <= (n); ++i)
#define clr(x, a) memset(x, (a), sizeof x)
using namespace std;
typedef long long ll;
double r1, r2, rr1, rr2;

double f(double x) {
	return sqrt((rr1 - x * x) * (rr2 - x * x));
}
double simpson(double a, double b) {
	return (b - a) * (f(a) + 4.0 * f((a + b) * 0.5) + f(b)) / 6.0;
}
double rsimpson(double a, double b, double e, double s) {
	double mid = (a + b) * 0.5;
	double l = simpson(a, mid), r = simpson(mid, b);
	if (fabs(l + r - s) <= 15.0 * e) return l + r + (l + r - s) / 15.0;
	return rsimpson(a, mid, e * 0.5, l) + rsimpson(mid, b, e * 0.5, r);
}

int main() {
	double r1, r2;
	scanf("%lf %lf", &r1, &r2);
	if (r1 > r2) swap(r1, r2);
	rr1 = r1 * r1;
	rr2 = r2 * r2;
	printf("%.4lf\n", 8.0 * rsimpson(0, r1, 1e-4, simpson(0, r1)));
	return 0;
}

