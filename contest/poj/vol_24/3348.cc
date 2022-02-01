#include <iostream>
#include <iomanip>
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
using namespace std;
int const N = 10101;
// const {{{
typedef long long ll;
typedef double db;
db const pi = 3.141592653589793;
db const eps = 1e-10;
db const dnf = 1e+10;
// }}}

// basic {{{
inline ll sqr(ll x) { return x * x; }
// }}}
struct Point {
	ll x, y;
	Point (int x = 0., int y = 0.): x(x), y(y) {}
	void in() { 
		scanf("%I64d %I64d", &x, &y); 
	}
	void out() { 
		printf("%I64d %I64d\n", x, y); 
	}
	friend Point operator+ (Point const &a, Point const &b) { 
		return Point(a.x + b.x, a.y + b.y); 
	}
	friend Point operator- (Point const &a, Point const &b) { 
		return Point(a.x - b.x, a.y - b.y); 
	}
	friend Point operator* (Point const &a, int const &b) { 
		return Point(a.x * b, a.y * b); 
	}
	friend ll operator^ (Point const &a, Point const &b) { 
		return a.x * b.y - a.y * b.x; 
	}
	friend ll operator* (Point const &a, Point const &b) { 
		return a.x * b.x + a.y * b.y; 
	}
	friend bool operator< (Point const &a, Point const &b) { 
		return a.y == b.y ? a.x < b.x : a.y < b.y;
	}
	ll lens() { 
		return sqr(x) + sqr(y); 
	}
};
ll xmult(Point a, Point b, Point c) { return (b - a) ^ (c - a); }
int n;
Point p[N], ans[N];

int Graham() {
	int now = 1, top; sort(p, p + n); p[n] = p[0];
	rep(i, 3) {
		if (n == i) return i;
		ans[i] = p[i];
	}
	for (int i = 2; i < n; ++i) {
		while (now && xmult(ans[now - 1], ans[now], p[i]) <= 0) --now;
		ans[++now] = p[i];
	}
	top = now, ans[++now] = p[n - 2];
	for (int i = n - 3; ~i; --i) {
		while (now != top && xmult(ans[now - 1], ans[now], p[i]) <= 0) --now;
		ans[++now] = p[i];
	}
	ans[now] = ans[0];
	return now;
};

int main() {
	scanf("%d", &n);
	rep(i, n) p[i].in();
	int g = Graham();
	ll s = 0;
	rep(i, g) s += ans[i] ^ ans[i + 1];
	s = s < 0 ? -s : s;
	printf("%I64d\n", s / 100);
	return 0;
}

