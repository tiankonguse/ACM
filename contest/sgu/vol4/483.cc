#include <cstdio>
#include <algorithm>
using namespace std;
int a[100100];
int main() {
	int c(0), n, h, x, v, t; scanf("%d %d", &n, &h); ++h;
	x = h * h, t = x + h, a[c++] = x; if (t <= n) a[c++] = t;
	for (v = h + h + 1; t + v <= n; v += 2) a[c++] = t += v;
	reverse(a, a + c); 
	for (v = h + h, t = x; t + v <= n; v += 2) a[c++] = t += v;
	for (int i = 0; i < c; ++i) printf("%d%c", a[i], i == c - 1 ? '\n' : ' ');
	return 0;
}

