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

#define inf 0x3f3f3f3f
#define Inf 0x3FFFFFFFFFFFFFFFLL
#define maxn 105
using namespace std;

//n个圆覆盖[1...n]次的面积 
double const eps = 1e-8;
double const pi = atan2(0, -1.0);
inline int sgn(double x) { return x < -eps ? -1 : x < eps ? 0 : 1; }
struct pt {
    double x, y;
    pt (double _x, double _y) { x = _x, y = _y; }
    pt () {}
    pt operator+ (const pt a) { return pt(x + a.x, y + a.y); }
    pt operator- (const pt a) { return pt(x - a.x, y - a.y); }
    pt operator* (const double r) { return pt(x * r, y * r); }
    pt operator/ (const double r) { return pt(x / r, y / r); }
    inline void print() { printf("%.2lf %.2lf\n", x, y); }
} p[maxn];
inline double xmul(const pt &a, const pt &b) { return a.x * b.y - a.y * b.x; }
inline double dist(const pt &a, const pt &b) { return sqrt( (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y) ); }


int n;
double r[maxn];


inline int rlt(int a, int b) {
  double d = dist(p[a], p[b]), d1 = sgn(d - r[a] + r[b]), d2 = sgn(d - r[b] + r[a]);
	if (d1 < 0 || !d1 && (d > eps || a > b))return 0;
	if (d2 < 0 || !d2 && (d > eps || a < b))return 1;
	return d < r[a] + r[b] - eps ? 2 : 3;
}

double areaArc(pt &o, double r, double ang1, double ang2) {
    pt a(o.x + r * cos(ang1), o.y + r * sin(ang1));
    pt b(o.x + r * cos(ang2), o.y + r * sin(ang2));
    double dif = ang2 - ang1;
    return (xmul(a, b) + (dif - sin(dif)) * r * r) * 0.5;
}

pair<double, int> e[maxn << 1];
double res[maxn];
int cnt;

void cal() {
    fill(res, res + n + 1, 0.0);
    double last;
    pt X, Y;
    for (int i = 0; i < n; ++i) if (r[i] > eps) {
        int acc = 0;
        cnt = 0;
        e[cnt++] = make_pair(-pi, 1);
        e[cnt++] = make_pair(pi, -1);
        for (int j = 0; j < n; ++j) if (i != j && r[j] > eps) {
            int rel = rlt(i, j);
            if (rel == 1) {
                e[cnt++] = make_pair(-pi, 1);
                e[cnt++] = make_pair(pi, -1);
            }
            else if (rel == 2)
			{
                double center = atan2(p[j].y - p[i].y, p[j].x - p[i].x);
				double d2 = (p[i].x - p[j].x) * (p[i].x - p[j].x) + (p[i].y - p[j].y) * (p[i].y - p[j].y);
				double ang = acos((r[i] * r[i] + d2 - r[j] * r[j]) / (2 * r[i] * sqrt(d2)));
				double angX = center + ang;
				double angY = center - ang;
				if (angX > pi)angX -= 2 * pi;
				if (angY < -pi)angY += 2 * pi;
				
                if (angX < angY) ++acc;
                e[cnt++] = make_pair(angX, -1);
                e[cnt++] = make_pair(angY, 1);
			}
        }
        sort(e, e + cnt);
        last = -pi;
        for (int j = 0; j < cnt; ++j) {
            double tmp = areaArc(p[i], r[i], last, e[j].first);
            res[acc] += tmp;
            res[acc - 1] -= tmp;
            acc += e[j].second;
            last = e[j].first;
        }
    }
}
int main() {
    
    while (~scanf("%d", &n)) {
        for (int i = 0; i < n; ++i) {
            scanf("%lf %lf %lf", &p[i].x, &p[i].y, &r[i]);
        }
        cal();
        double r1 = 0, r2 = 0;
        for (int i = 1; i <= n; ++i) {
            if (i & 1) r1 += res[i];
            else r2 += res[i];
        }
        printf("%.5lf %.5lf\n", r1, r2);
    }
    return 0;
}

