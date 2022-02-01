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
int const N = 111;
int s[N], ans[N][2];
int main() {
	int a, b, n; scanf("%d%d%d", &a, &b, &n);
	rep(i, n) scanf("%d", &s[i]);
	int x = 0, y = b, px, py;
	rep(i, n) {
		px = x, py = y;
		if (x + y < s[i]) {
			x += s[i] - x - y;
			if (x > a) {
				puts("ERROR");
				return 0;
			}
		}
		else {
			y -= x + y - s[i];
			if (y < 0) {
				puts("ERROR");
				return 0;
			}
		}
		ans[i][0] = x - px, ans[i][1] = py - y;
	}
	rep(i, n) printf("%d %d\n", ans[i][0], ans[i][1]);
	return 0;
}

