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
double const eps = 1e-8;
double const pi = acos(-1.0);
double const tpi = 2.0 * pi;
int const maxn = 1010;
typedef long long ll;
int n; double r, h;
double len;

inline double conv(double x) {
  if (x < 0) x += tpi;
	if (x + eps > tpi) x -= tpi;
	return x * r;
}
inline double dis(double x, double y) {
	if (x > y) swap(x, y);
	double d = min(y - x, x + len - y);
	return sqrt(h * h + d * d);
}
struct node {
	double x; int id;
	friend bool operator < (node a, node b) {
		return a.x < b.x;
	}
} p1[maxn], p2[maxn], p3[maxn];

int mat1[maxn], mat2[maxn];

int main() {
	while (~scanf("%d%lf%lf", &n, &r, &h)) {
		h *= 0.5;
		len = tpi * r;
		for (int i = 0; i < n; ++i) {
			scanf("%lf", &p1[i].x);
			p1[i].x = conv(p1[i].x);
			p1[i].id = i + 1;
		}
		for (int i = 0; i < n; ++i) {
			scanf("%lf", &p2[i].x);
			p2[i].x = conv(p2[i].x);
			p2[i].id = i + 1;
		}
		for (int i = 0; i < n; ++i) {
			scanf("%lf", &p3[i].x);
			p3[i].x = conv(p3[i].x);
			p3[i].id = i + 1;
		}
		sort(p1, p1 + n); sort(p2, p2 + n); sort(p3, p3 + n);
		
		double r1 = 1e10, r2 = 1e10;
		for (int i = 0; i < n; ++i) {
			double tr = 0;
			for (int j = 0; j < n; ++j) {
				tr += dis(p1[j].x, p2[(j + i) % n].x);
			}
			if (tr < r1) {
				r1 = tr;
				for (int j = 0; j < n; ++j) {
					mat1[j] = (i + j) % n;
				}
			}
		}
		for (int i = 0; i < n; ++i) {
			double tr = 0;
			for (int j = 0; j < n; ++j) {
				tr += dis(p2[j].x, p3[(j + i) % n].x);
			}
			if (tr < r2) {
				r2 = tr;
				for (int j = 0; j < n; ++j) {
					mat2[j] = (i + j) % n;
				}
			}
		}
		printf("%.10lf\n", r1 + r2);
		for (int i = 0; i < n; ++i) {
			int id1 = p1[i].id;
			int id2 = p2[mat1[i]].id;
			int id3 = p3[mat2[mat1[i]]].id;
			printf("%d %d %d\n", id1, id2, id3);
		}
	}
    return 0;
}
