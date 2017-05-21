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
using namespace std;
typedef long long ll;

int main() {
	static int a[1000010];
	int n, x, y;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d%d", &x, &y);
		a[i] = x + y;
	}
	for (int i = n - 1; ~i; --i) {
		if (a[i] >= 10) {
			a[i - 1] += 1;
			a[i] -= 10;
		}
	}	
	for (int i = 0; i < n; ++i) {
		printf("%d", a[i]);
	}
	puts("");
	return 0;
}
