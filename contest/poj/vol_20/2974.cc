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
#define PI 3.14159265358979323846;
using namespace std;
int const maxn = 33;
double const eps = 1e-8;
inline int sgn(double x) { return x < -eps ? -1 : x > eps ? 1 : 0; }
inline double Sqr(double x) { return x * x; }
inline double Sqrt(double x) { return x < 0 ? 0 : sqrt(x); }  
class Point_3 {
public:
	double x, y, z;
	Point_3 () { }
	Point_3 (double x, double y, double z) : x(x), y(y), z(z) { }
	Point_3 Unit() const;
	friend bool operator<(Point_3 a, Point_3 b) {
		if (sgn(a.x - b.x) != 0) return a.x < b.x;
		if (sgn(a.y - b.y) != 0) return a.y < b.y;
		return a.z < b.z;
	}
	 bool operator==(const Point_3 &b) const {
		return sgn(x - b.x) == 0 && sgn(y - b.y) == 0 && sgn(z - b.z) == 0;
	}
	double length() const {
		return Sqrt(Sqr(x) + Sqr(y) + Sqr(z));
	}
};
Point_3 operator- (const Point_3 &a, const Point_3 &b) {
	return Point_3(a.x - b.x, a.y - b.y, a.z - b.z);
}
double dot(const Point_3 &a, const Point_3 &b) {
	return a.x * b.x + a.y * b.y + a.z * b.z;
}
Point_3 det(const Point_3 &a, const Point_3 &b) {
	return Point_3(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x);
}

int mark[maxn][maxn];
Point_3 info[maxn];
int n, cnt;
double mix(const Point_3 &a, const Point_3 &b, const Point_3 &c) {
	return dot(a, det(b, c));
}
double area(int a, int b, int c) {
	return det(info[b] - info[a], info[c] - info[a]).length();
}
double volume(int a, int b, int c, int d) {
	return mix(info[b] - info[a], info[c] - info[a], info[d] - info[a]);
}
struct Face {
	int a, b, c;
	Face () {}
	Face(int a, int b, int c) : a(a), b(b), c(c) { }
	int &operator [](int k) {
		if (k == 0) return a;
		if (k == 1) return b;
		return c;
	}
};

vector <Face> face;
inline void insert(int a, int b, int c) {
	face.push_back(Face(a, b, c));
}
void add(int v) {
	vector <Face> tmp;
	int a, b, c;
	++cnt;
	for (int i = 0; i < face.size(); ++i) {
		a = face[i][0];
		b = face[i][1];
		c = face[i][2];
		if (sgn(volume(v, a, b, c)) < 0) {
			mark[a][b] = mark[b][a] = mark[b][c] = mark[c][b] = mark[c][a] =
				mark[a][c] = cnt;
		}
		else tmp.push_back(face[i]);
	}
	face = tmp;
	for (int i = 0; i < tmp.size(); ++i) {
		a = face[i][0];
		b = face[i][1];
		c = face[i][2];
		if (mark[a][b] == cnt) insert(b, a, v);
		if (mark[b][c] == cnt) insert(c, b, v);
		if (mark[c][a] == cnt) insert(a, c, v);
	}
}

int Find() {
	for (int i = 2; i < n; ++i) {
		Point_3 ndir = det(info[0] - info[i], info[1] - info[i]);
		if (ndir == Point_3()) continue;
		swap(info[i], info[2]);
		for (int j = i + 1; j < n; ++j) {
			if (sgn(volume(0, 1, 2, j)) != 0) {
				swap(info[j], info[3]);
				insert(0, 1, 2);
				insert(0, 2, 1);
				return 1;
			}
		}
	}
	return 0;
}
double convex3() {
	sort(info, info + n);
	n = unique(info, info + n) - info;
	face.clear();
	random_shuffle(info, info + n);
	if (Find()) {
		memset(mark, 0, sizeof mark);
		cnt = 0;
		for (int i = 3; i < n; ++i) add(i);
		double ans = 0;
		for (int i = 0; i < face.size(); ++i) {
			Point_3 p = det(info[face[i][0]] - info[face[i][1]], 
						    info[face[i][2]] - info[face[i][1]]);
			ans += p.length();
		}
		return 0.5 * ans;
	}
	return -1;
}


int main() {
	while (~scanf("%d", &n) && n) {
		for (int i = 0; i < n; ++i) {
			scanf("%lf %lf %lf", &info[i].x, &info[i].y, &info[i].z);
		}
		printf("%.0lf\n", convex3());
	}
    return 0;
}
