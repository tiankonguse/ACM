nclude <iostream>
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
int const N = 33;
int a[N];
int main() {
	int n, x;
	scanf("%d", &n);
	rep(i, n) {
		scanf("%d", &x);
		++a[x];
	}
	int ret = 0;
	Rep(i, 30) {
		int t = min(a[i], a[i + 1]);
		ret += t;
		a[i] -= t;
		a[i + 1] -= t;
	}
	printf("%d\n", n - ret);
	return 0;
}


