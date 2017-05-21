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
typedef long double db;
db const g = 9.8;
db const eps = 1e-6;
db const hpi = 0.5 * acos(-1.0);
int sgn(db x) { return x < -eps ? -1 : x < eps ? 0 : 1; }
bool check(db v, db x1, db y1, db x2, db y2) {
	if (x1 > x2) { swap(x1, x2); }
	for (db d = 0.0; d <= hpi; d += 0.000002) {
		db s = y2 - y1;
		db vx = v * cos(d), vy = v * sin(d);
		db dt = vy * vy - 2.0 * g * s;
		if (sgn(dt) < 0) continue;
		if (dt < 0.0) dt = 0.0;
		db t = (vy + sqrt(dt)) / g;
		if (sgn(vx * t - (x2 - x1)) >= 0) return 1;
	}
	return 0;
}
int main() {
	db v, x1, y1, x2, y2, x3, y3;
	while (cin >> v >> x1 >> y1 >> x2 >> y2 >> x3 >> y3) {
		if (check(v, x2, y2, x3, y3) && check(v, x3, y3, x2, y2) &&
				(check(v, x2, y2, x1, y1) || check(v, x3, y3, x1, y1))) {
			puts("Yes");
		}
		else puts("No");
	}	
	return 0;
}

