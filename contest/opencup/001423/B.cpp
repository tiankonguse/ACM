#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
const double PI = atan2(0, -1);
const double TAU = 2 * PI;
const double EPS = 1e-6;
const double INF = 1e50;
const double G = (sqrt(5) - 1) / 2;

inline double fix(double x) {
	return fmod(x + TAU, TAU);
}

inline bool eq(double a, double b) {
	return fabs(a - b) < EPS;
}

int n, x[N], y[N];
double l[N], a[N];
double ans = INF;

double length(double b0) {
	double b = fix(b0), ret = 0;
	for (int i = 1; i < n; ++i) {
		double c = fabs(a[i] - b);
		if (eq(c, PI)) return INF;
		if (c > PI) c = TAU - c;
		if (eq(c, 0)) ret += l[i];
		else ret += l[i] * c / sin(c);
		b = fix(fix(2 * a[i] - b));
	}
	return ret;
}

int main() {
	scanf("%d%d%d", &n, x, y);
	vector<double> ban;
	for (int i = 1; i < n; ++i) {
		scanf("%d%d", x+i, y+i);
		double dx = x[i] - x[i - 1];
		double dy = y[i] - y[i - 1];
		a[i] = fix(atan2(dy, dx));
		l[i] = sqrt(dx * dx + dy * dy);
		double b = fix(atan2(-dy, -dx));
		for (int j = i - 1; j; --j) {
			b = fix(fix(2 * a[j] - b));
		}
		ban.push_back(b);
	}
	sort(ban.begin(), ban.end());
	ban.resize(unique(ban.begin(), ban.end()) - ban.begin());
	ban.push_back(ban[0] + TAU);
	for (size_t i = 0; i + 1 < ban.size(); ++i) {
		double l = ban[i], r = ban[i + 1];
		if (eq(l, r)) continue;
		double ml = l * G + r * (1 - G);
		double mr = l * (1 - G) + r * G;
		double fl = length(ml);
		double fr = length(mr);
		for (int t = 0; t < 20; ++t) {
			if (fl > fr) {
				l = ml;
				ml = mr;
				fl = fr;
				mr = l * (1 - G) + r * G;
				fr = length(mr);
			} else {
				r = mr;
				mr = ml;
				fr = fl;
				ml = l * G + r * (1 - G);
				fl = length(ml);
			}
			ans = min(ans, min(fl, fr));
		}
	}
	printf("%.15f\n", ans);
}
