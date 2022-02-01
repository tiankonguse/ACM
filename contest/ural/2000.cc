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
int const N = 100010;
int a[N];
int main() {
	int n, x, y;
	scanf("%d", &n); Rep(i, n) scanf("%d", &a[i]);
	scanf("%d%d", &x, &y);
	if (x == y) {
		int r1 = 0, r2 = 0;
		for (int i = x; i <= n; ++i) r1 += a[i];
		for (int i = x; i >= 1; --i) r2 += a[i];
		if (r1 > r2) printf("%d %d\n", r1, r2 - a[x]);
		else printf("%d %d\n", r2, r1 - a[x]);
	}
	else if (x < y) {
		int s = (x + y) / 2; int r1 = 0, r2 = 0;
		for (int i = 1; i <= s; ++i) r1 += a[i];
		for (int i = s + 1; i <= n; ++i) r2 += a[i];
		printf("%d %d\n", r1, r2);
	}
	else {
		int s = (x + y + 1) / 2; int r1 = 0, r2 = 0;
		for (int i = s; i <= n; ++i) r1 += a[i];
		for (int i = 1; i < s; ++i) r2 += a[i];
		printf("%d %d\n", r1, r2);
	}
	return 0;
}

