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
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define Rep(i, n) for (int i = 1; i <= (n); ++i)
#define clr(x, a) memset(x, (a), sizeof x)
using namespace std;
typedef long long ll;
int a[1010];
int b[1010];

void func(int n, int a[]) {
	clr(a, 0);
	a[0] = 1;
	rep(i, n) {
		for (int j = 0; j < 1000; ++j) {
			a[j] <<= 1;
		}
		for (int j = 0; j < 1000; ++j) {
			a[j + 1] += a[j] / 10;
			a[j] %= 10;
		}
	}
}

int main() {
	int n, m; scanf("%d%d", &n, &m);
	func(n, a);
	func(m, b);
	for (int i = 0; i < 1000; ++i) {
		a[i] += b[i];
		a[i + 1] += a[i] / 10;
		a[i] %= 10;
	}
	a[0] -= 2;
	for (int i = 0; i < 1000; ++i) {
		while (a[i] < 0) {
			a[i] += 10;
			--a[i + 1];
		}
		while (a[i] >= 10) {
			a[i] -= 10;
			++a[i + 1];
		}
	}
	for (int i = 1000; i >= 0; --i) {
		if (a[i] != 0) {
			for (int j = i; j >= 0; --j) {
				printf("%d", a[j]);
			}
			puts("");
			return 0;
		}
	}
    return 0;
}
