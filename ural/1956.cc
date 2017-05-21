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
int const maxn = 1010;
double const eps = 1e-10;
typedef long long ll;
struct point {
	double x, y, c;
	
	point (double x = 0.0, double y = 0.0) : x(x), y(y) { }
	
	friend bool operator < (point a, point b) {
		return a.x * b.y > a.y * b.x;
	}
	
	friend bool operator == (point a, point b) {
		return fabs(a.x - b.x) < eps && fabs(a.y - b.y) < eps;
	}
	
} p[maxn], q[maxn];

double ans[maxn];

int n, m;


int main() {
	while (~scanf("%d", &n)) {
		for (int i = 0; i < n; ++i) scanf("%lf %lf", &p[i].x, &p[i].y);
		
		double ret = 1e15;
		
		for (int i = 0; i < n; ++i) {
			m = 0;
			for (int j = 0; j < n; ++j) if (i != j && !(p[i] == p[j])) {
				q[m] = point(p[j].x - p[i].x, p[j].y - p[i].y);
				if (q[m].y < 0) q[m].y = -q[m].y, q[m].x = -q[m].x;
				q[m].c = hypot(q[m].x, q[m].y);
				++m;
			}
			if (m == 0) {
				ret = 0.0;
				break;
			}
			for (int j = 0; j < m; ++j) ans[j] = 0.0;
			
			sort(q, q + m);
			double xs = q[0].x, ys = q[0].y;
			double t;
			
			for (int j = 1; j < m; ++j) {
				t = (xs * q[j].y - ys * q[j].x) / q[j].c ;
				ans[j] += t ;
				xs += q[j].x;
				ys += q[j].y;
			}
			
			xs = -q[m - 1].x, ys = q[m - 1].y;
			for (int j = m - 2; j >= 0; --j) {
				t = (xs * q[j].y - ys * (-q[j].x)) / q[j].c;
				ans[j] += t;
		   		xs += -q[j].x;
				ys += q[j].y;	
			}
			
			for (int j = 0; j < m; ++j) ret = min(ret, ans[j]);
		}
		printf("%.10lf\n", ret);
	}	
	return 0;
}
