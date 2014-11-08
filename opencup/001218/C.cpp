#include <cassert>
#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

typedef long long LL;
typedef LL NUM;

struct VEC {NUM x,y;};

inline VEC operator -(const VEC& a, const VEC& b){
	return (VEC){a.x-b.x,a.y-b.y};
}
inline NUM operator *(const VEC& a, const VEC& b){
	return a.x*b.y-a.y*b.x;
}

LL exgcd(LL a, LL b, LL& x, LL& y){
    if(!b) return x=1,y=0,a;
    LL u=exgcd(b,a%b,y,x);
    return y-=a/b*x,u;
}

bool equation(LL a, LL b, LL c, LL &x, LL &y){
    LL r=exgcd(a,b,x,y);
    if(c%r) return false;
    x*=c/r; y*=c/r;
    return true;
}

const int N = 100005;
const int INF = 1000000;

int n;
NUM s;
VEC p[N];

int main() {
	int tmp;
	scanf("%d%lld%*c%d", &n, &s, &tmp); --n;
	s = s * 2 + !!tmp;
	for (int i = 0; i < n; ++i) {
		scanf("%lld%lld", &p[i].x, &p[i].y);
	}
	for (int i = 0; i < n; ++i) {
		s -= p[i] * p[(i+1)%n];
	}
	for (int i = 0; i < n; ++i) {
		VEC p0 = p[(i-1+n)%n];
		VEC p1 = p[i];
		VEC p2 = p[(i+1)%n];
		VEC p3 = p[(i+2)%n];
		NUM c = s + p1 * p2;
		NUM a = p2.y - p1.y;
		NUM b = p2.x - p1.x;
		NUM dx2 = p3.x - p2.x;
		NUM dy2 = p3.y - p2.y;
		VEC ans;
		// l0: a * x - b * y = c
		if (!b) {
			// a * x = c, a != 0
			if (c % a || abs(c / a) > INF) continue;
			ans.x = c / a;
			NUM A = dx2;
			NUM B = dy2 * ans.x - (p2.x * dy2 - p2.y * dx2);
			// A * y > B, A != 0
			if (A > 0) {
				ans.y = B / A - 5;
				while (A * ans.y <= B) ++ans.y;
				if (ans.y < -INF) ans.y = -INF;
			} else {
				A = -A, B = -B;
				// A * y < B
				ans.y = B / A + 5;
				while (A * ans.y >= B) --ans.y;
				if (ans.y > INF) ans.y = INF;
			}
		} else {
			NUM x0, y0;
			if (!equation(a, -b, c, x0, y0)) continue;
			NUM g = __gcd(a, b);
			a /= g, b /= g, c /= g;
			if (b < 0) a = -a, b = -b, c = -c;
			// b * y = a * x - c, b > 0
			NUM A = a * dx2 - b * dy2;
			NUM B = c * dx2 - b * (p2.x * dy2 - p2.y * dx2);
			NUM k;
			// A * x > B, A != 0
			if (A > 0) {
				NUM xmin = B / A - 5;
				while (A * xmin <= B) ++xmin;
				if (xmin < -INF) xmin = -INF;
				// x0 + k * b >= xmin
				k = (xmin - x0) / b - 5;
				while (x0 + k * b < xmin) ++k;
				NUM x = x0 + k * b;
				NUM y = (a * x - c) / b;
				if (y > INF) {
					if (a >= 0) continue;
					xmin = (b * INF + c) / a - 5;
					while (a * xmin - c > b * INF) ++xmin;
				} else if (y < -INF) {
					if (a <= 0) continue;
					xmin = (b * INF - c) / -a - 5;
					while (a * xmin - c < b * -INF) ++xmin;
				}
				k = (xmin - x0) / b - 5;
				while (x0 + k * b < xmin) ++k;
			} else {
				A = -A, B = -B;
				// A * x < B
				NUM xmax = B / A + 5;
				while (A * xmax >= B) --xmax;
				if (xmax > INF) xmax = INF;
				// x0 + k * b <= xmax
				k = (xmax - x0) / b + 5;
				while (x0 + k * b > xmax) --k;
				NUM x = x0 + k * b;
				NUM y = (a * x - c) / b;
				if (y > INF) {
					if (a <= 0) continue;
					xmax = (b * INF + c) / a + 5;
					while (a * xmax - c > b * INF) --xmax;
				} else if (y < -INF) {
					if (a >= 0) continue;
					xmax = (b * INF - c) / -a + 5;
					while (a * xmax - c < b * -INF) --xmax;
				}
				k = (xmax - x0) / b + 5;
				while (x0 + k * b > xmax) --k;
			}
			ans.x = x0 + k * b;
			assert((a * ans.x - c) % b == 0);
			ans.y = (a * ans.x - c) / b;	
		}
		assert((p2 - ans) * (p3 - p2) > 0);
		assert((ans - p1) * (p2 - p1) == s);
		if (abs(ans.x) <= INF && abs(ans.y) <= INF &&
			(p1 - p0) * (ans - p1) > 0) {
			printf("%lld %lld\n", ans.x, ans.y);
			return 0;
		}
	}
}
