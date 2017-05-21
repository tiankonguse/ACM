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
using namespace std;
typedef long long ll;
double const eps = 1e-8;
int const maxn = 10101;
int a[maxn], b[maxn], c[maxn], d[maxn];

int main() {
	int n;
	while (~scanf("%d", &n)) {
		int s = 0;
		for (int i = 0; i < n; ++i) {
			scanf("%d", &a[i]);
			s += a[i];
		}
		int z = 0;
		for (int i = 0; i < n; ++i) {
			double t = 100.0 * a[i] / s + 1e-10;
			if (t - floor(t) < eps) {
				c[i] = 0;
			}
			else c[i] = 1;
			d[i] = (int)(floor(t));
			z += d[i];
		}
		for (int i = 0; i < n && z < 100; ++i) {
			if (c[i]) {
				++z;
				++d[i];
			}
		}
		if (z == 100) {
			for (int i = 0; i < n; ++i) {
				if (i == n - 1) printf("%d\n", d[i]);
				else printf("%d ", d[i]);
			}
		}
		else puts("No solution");
	}	
	return 0;
}

