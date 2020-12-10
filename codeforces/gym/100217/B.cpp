#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

const double eps = 1e-8;
const double pi = atan2(0, -1);

double cmp(double a, double b = 0) {
	return fabs(a - b) < eps ? 0 : a - b;
}

struct Point {
	double x, y;
	Point() {}
	Point(double x, double y) : x(x), y(y) {}
	Point operator-(const Point& rhs) const {
		return Point(x - rhs.x, y - rhs.y);
	}
	double operator*(const Point& rhs) const {
		return x * rhs.y - y * rhs.x;
	}
	bool operator==(const Point& rhs) const {
		return !cmp(x, rhs.x) && !cmp(y, rhs.y);
	}
	bool operator<(const Point& rhs) const {
		return cmp(x, rhs.x) ? cmp(x, rhs.x) < 0 : cmp(y, rhs.y) < 0;
	}
};

typedef vector<Point> VP;

void convex_hull(VP& p) {
	sort(p.begin(), p.end());
	p.resize(unique(p.begin(), p.end()) - p.begin());
	if (p.size() < 3) return ;
	int i, j, k, n = p.size();
	VP v(n+1);
	v[0] = p[0], v[1] = p[1];
	for (i = j = 2; i < n; v[j++] = p[i++]) 
		while (j > 1 && (v[j - 2] - v[j - 1]) * (p[i] - v[j - 1]) > -eps)
			--j;
	v[k = j++] = p[n - 2];
	for (i = n - 3; i > 0; v[j++] = p[i--])
		while (j > k && (v[j - 2] - v[j - 1]) * (p[i] - v[j - 1]) > -eps)
			--j;
	while (j > k && (v[j - 2] - v[j - 1]) * (v[0] - v[j - 1]) > -eps)
		--j;
	v.resize(j);
	p = v;
}
double area(const VP& p) {
	int n = p.size();
	double s = 0;
	for (int i = 0; i < n; ++i) {
		s += p[i] * p[(i + 1) % n];
	}
	return fabs(s) / 2;
}
double xarea(const VP& p) {
	int n = p.size();
	double s = 0;
	for (int i = 0; i < n; ++i) {
		s += p[i] * p[(i + 1) % n] * (p[i].x + p[(i + 1) % n].x);
	}
	return fabs(s) / 6;
}
double yarea(const VP& p) {
	int n = p.size();
	double s = 0;
	for (int i = 0; i < n; ++i) {
		s += p[i] * p[(i + 1) % n] * (p[i].y + p[(i + 1) % n].y);
	}
	return fabs(s) / 6;
}

inline void add(VP& p, double x, double y) {
	p.push_back(Point(x, y));
}

void cut(double a, double b, double c, VP& p) {
	p.clear();
	if (c >= 0) add(p, 0, 0);
	if (a + c >= 0) add(p, 1, 0);
	if (b + c >= 0) add(p, 0, 1);
	if (a + b + c >= 0) add(p, 1, 1);
	if (cmp(b)) {
		double x = 0, y = -c / b;
		if (y > 0 && y < 1) add(p, x, y);
		x = 1, y = -(a + c) / b;
		if (y > 0 && y < 1) add(p, x, y);
	}
	if (cmp(a)) {
		double x = -c / a, y = 0;
		if (x > 0 && x < 1) add(p, x, y);
		x = -(b + c) / a, y = 1;
		if (x > 0 && x < 1) add(p, x, y);
	}
	convex_hull(p);
}

double alpha, beta, gama, delta;

double calc_c(double a, double b) {
	double l = 0, r = 0;
	VP p;
	for (int x = 0; x <= 1; ++x) {
		for (int y = 0; y <= 1; ++y) {
			double ci = -a * x - b * y;
			cut(a, b, ci, p);
			double s = area(p);
			if (cmp(s, 0) <= 0) l = ci;
			if (cmp(s, 1) >= 1) r = ci;
		}
	}
	double vt = alpha / 2 + beta;
	for (int t = 0; t < 100; ++t) {
		double m = (l + r) / 2;
		cut(a, b, m, p);
		double v = xarea(p) * alpha + area(p) * beta;
		(v < vt / 2) ? (l = m) : (r = m);
	}
	return l;
}

int main() {
	freopen("bacteria.in", "r", stdin);
	freopen("bacteria.out","w", stdout);
	scanf("%lf%lf%lf%lf", &alpha, &beta, &gama, &delta);
	double vt = gama / 2 + delta;
	double l = 0, r = pi;
	double a, b, c;
	VP p;
	for (int t = 0; t < 100; ++t) {
		double m = (l + r) / 2;
		a = sin(m);
		b = cos(m);
		c = calc_c(a, b);
		cut(a, b, c, p);
		double v = yarea(p) * gama + area(p) * delta;
		(v > vt / 2) ? (l = m) : (r = m);
	}
	printf("%.15f %.15f %.15f\n", a, b, c);
}
