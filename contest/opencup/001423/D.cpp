#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

int main() {
	int T;
	cin >> T;
	while (T--) {
		LL xa, ya, xc, yc, xp, yp;
		cin >> xa >> ya >> xc >> yc >> xp >> yp;
		LL d = xa * yc - xc * ya;
		if (d < 0) d = -d, swap(xa, xc), swap(ya, yc);
		LL x = xp * yc - xc * yp;
		LL y = xa * yp - xp * ya;
		if (x % d == 0 || y % d == 0) {
			cout << -1 << '\n';
		} else {
			x = abs(x / d - (x < 0));
			y = abs(y / d - (y < 0));
			cout << 4 * (x + y) << '\n';
		}
	}
}
