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
int knight[8][2] = { -1, -2, -2, -1, -2, 1, -1, 2, 1, -2, 2, -1, 2, 1, 1, 2 };
int king[8][2] = { -1, -1, -1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1 };
inline bool check(int n, int x, int y) {
	return x >= 1 && y >= 1 && x <= n && y <= n;
}
int main() {
	int n, x, y;
	cin >> n >> x >> y;
	int kn = 0, ki = 0;
	rep(i, 8) {
		int tx = x + knight[i][0], ty = y + knight[i][1];
		if (check(n, tx, ty)) ++kn;
		tx = x + king[i][0], ty = y + king[i][1];
		if (check(n, tx, ty)) ++ki;
	}
	int ro = n + n - 2;
	x = min(x, n - x + 1);
	y = min(y, n - y + 1);
	int bi = x + y - 2 + min(n - x + 1 + y - 2, n - y + 1 + x - 2);
	printf("King: %d\n", ki);
	printf("Knight: %d\n", kn);
	printf("Bishop: %d\n", bi);
	printf("Rook: %d\n", ro);
	printf("Queen: %d\n", ro + bi);
	return 0;
}

