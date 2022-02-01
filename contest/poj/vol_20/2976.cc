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
int const maxn = 1010;
double const eps = 1e-6;
double a[maxn], b[maxn], c[maxn];

int main() {
  int n, k;
	while (~scanf("%d%d", &n, &k)) {
		if (n == 0 && k == 0) break;
		for (int i = 0; i < n; ++i) scanf("%lf", &a[i]);
		for (int i = 0; i < n; ++i) scanf("%lf", &b[i]);
		double low = 0.0, high = 1.0, mid;
		while (low + eps < high) {
			mid = 0.5 * (low + high);
			for (int i = 0; i < n; ++i) {
				c[i] = a[i] - mid * b[i];
			}
			sort(c, c + n);
			double t = 0;
			for (int i = k; i < n; ++i) {
				t += c[i];
			}
			if (t > 0) {
				low = mid;
			}
			else {
				high = mid;
			}
		}
		printf("%.0lf\n", 100.0 * low);
	}
    return 0;
}
