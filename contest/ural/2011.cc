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
int C[N][N];

int main() {
	C[0][0] = 1;
	for (int i = 1; i <= 100; ++i) {
		C[i][0] = 1;
		for (int j = 1; j <= i; ++j) {
			C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
			if (C[i][j] >= 100) C[i][j] = 100;
		}
	}	
	int c1 = 0, c2 = 0, c3 = 0, n;
	scanf("%d", &n); int x;
	rep(i, n) {
		scanf("%d", &x);
		if (x == 1) ++c1;
		if (x == 2) ++c2;
		if (x == 3) ++c3;
	}
	int ret = C[n][c1] * C[n - c1][c2];
	if (ret >= 6) puts("Yes"); else puts("No");
	return 0;
}

