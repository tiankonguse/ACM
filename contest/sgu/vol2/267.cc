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
double const eps = 1e-7;
struct Node {
	double s; int c;
	Node(double s = 0., int c = 0) : s(s), c(c) {}
	friend bool operator < (Node a, Node b) {
		if (fabs(a.s - b.s) < eps) {
			return a.c < b.c;
		} else {
			return a.s < b.s;
		}
	}
};
vector<Node> v1, v2;

double l[6];
double x[6], y[6];
double dmul(double x1, double y1, double x2, double y2) {
	return x1 * x2 + y1 * y2;
}
double xmul(double x1, double y1, double x2, double y2) {
	return x1 * y2 - x2 * y1;	
}

int main() {
	int n, k; scanf("%d%d", &n, &k);
	rep(z, n) {
		rep(i, 6) scanf("%lf %lf", &x[i], &y[i]);
		int t = 0;
		rep(i, 4) rep(j, 4) if (i < j) {
			l[t++] = sqrt((x[i]-x[j]) * (x[i]-x[j]) + (y[i]-y[j]) * (y[i]-y[j]));
		}
		sort(l, l + t);
		double ox = 0, oy = 0;
		rep(i, 4) ox += x[i], oy += y[i];
		ox /= 4.0, oy /= 4.0;
		double x1 = x[4] - ox, y1 = y[4] - oy;
		double x2 = x[5] - ox, y2 = y[5] - oy;
		double s = l[0] * l[2] * 0.5;
		if (dmul(x1, y1, x2, y2) > -eps && fabs(xmul(x1, y1, x2, y2)) < eps) {
			v1.push_back(Node(s, 0));
			v2.push_back(Node(s, 1));
		} else {
			v1.push_back(Node(s, 1));
			v2.push_back(Node(s, 0));
		}
	}
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	double ans1 = 0, ans2 = 0;
	for (int i = v1.size() - 1; i >= 0; --i) {
		if (v1[i].c == 1) ans1 += v1[i].s;
		if (v2[i].c == 0) ans2 += v2[i].s;
		if (--k == 0) break;
	}
	printf("%.3lf %.3lf\n", ans2, ans1);
	return 0;
}

