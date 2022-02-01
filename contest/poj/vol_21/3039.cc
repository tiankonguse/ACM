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
typedef long long ll;
int gcd(int a, int b) {
  return b ? gcd(b, a % b) : a;
}
int main() {
	int n, d;
	while (~scanf("%d%d", &n, &d)) {
		double r = 1.0 * n / d;
		double ret = 1e10;
		int rn, rd;
		for (int i = 1; i <= 32767; ++i) {
			int b = r * i;
			int c = b + 1;
			if (b < i && !(b == n && i == d)) {
				double tr = fabs(1.0 * b / i - r);
				if (tr > 1e-10 && tr < ret) {
					ret = tr;
					rn = b, rd = i;
				}
			}
			if (c < i && !(c == n && i == d)) {
				double tr = fabs(1.0 * c / i - r);
				if (tr > 1e-10 && tr < ret) {
					ret = tr;
					rn = c, rd = i;
				}
			}
		}
		printf("%d %d\n", rn, rd);
	}
    return 0;
}
