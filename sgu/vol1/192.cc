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
int const maxn = 303;
typedef long long ll;
double const eps = 1e-8;
#define zero(x) (((x)>0?(x):-(x))<eps)

inline int sgn(double x) { return x < -eps ? -1 : x > eps ? 1 : 0; }
struct point {
  double x, y;
	friend bool operator < (point a, point b) {
		if (sgn(a.x - b.x) == 0) return a.y < b.y;
		else return a.x < b.x;
	}
} tmp;
struct line {
	point a, b;
	int c;
} l[maxn];

int parallel(point u1,point u2,point v1,point v2){
	return zero((u1.x-u2.x)*(v1.y-v2.y)-(v1.x-v2.x)*(u1.y-u2.y));
}

point intersection(point u1,point u2,point v1,point v2){
	point ret=u1;
	double t=((u1.x-v1.x)*(v1.y-v2.y)-(u1.y-v1.y)*(v1.x-v2.x))
			/((u1.x-u2.x)*(v1.y-v2.y)-(u1.y-u2.y)*(v1.x-v2.x));
	ret.x+=(u2.x-u1.x)*t;
	ret.y+=(u2.y-u1.y)*t;
	return ret;
}
double xpos[50000]; int cnt;
double ans[5];

int main() {
	int n;
	char ch[3];
	while (~scanf("%d", &n)) {
		for (int i = 0; i < n; ++i) {
			scanf("%lf %lf %lf %lf %s", &l[i].a.x, &l[i].a.y, &l[i].b.x, &l[i].b.y, ch);
			if (l[i].b < l[i].a) swap(l[i].a, l[i].b);
			if (ch[0] == 'R') l[i].c = 0;
			else if (ch[0] == 'G') l[i].c = 1;
			else l[i].c = 2;
		}
		cnt = 0;
		for (int i = 0; i < n; ++i) {
			xpos[cnt++] = l[i].a.x;
			xpos[cnt++] = l[i].b.x;
			for (int j = i + 1; j < n; ++j) {
				if (!parallel(l[i].a, l[i].b, l[j].a, l[j].b)) {
					tmp = intersection(l[i].a, l[i].b, l[j].a, l[j].b);
					xpos[cnt++] = tmp.x;
				}
			}
		}
		sort(xpos, xpos + cnt);
		ans[0] = ans[1] = ans[2] = 0;
		double y01, y02, y1, y2;
		for (int i = 0; i < cnt - 1; ++i) {
			y01 = y02 = 1e10; int rc = -1;
			for (int j = 0; j < n; ++j) {
				if (sgn(xpos[i] - l[j].a.x) >= 0 && sgn(l[j].b.x - xpos[i + 1]) >= 0) {
					y1 = l[j].a.y + (l[j].b.y - l[j].a.y) * (xpos[i] - l[j].a.x) / 
						(l[j].b.x - l[j].a.x);
					y2 = l[j].a.y + (l[j].b.y - l[j].a.y) * (xpos[i + 1] - l[j].a.x) / 
						(l[j].b.x - l[j].a.x);
					if (sgn(y1 - y01) <= 0 && sgn(y2 - y02) <= 0) {
						y01 = y1, y02 = y2;
						rc = l[j].c;
					}
				}
			}
			if (rc != -1) ans[rc] += xpos[i + 1] - xpos[i];
		}
		printf("R %.2lf\nG %.2lf\nB %.2lf\n", ans[0], ans[1], ans[2]);
	}
    return 0;
}
