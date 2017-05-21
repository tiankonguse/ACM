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
int s[4][4] = {
	0, 1, 2, 3,
	2, 1, 3, 0,
	1, 3, 2, 0,
	3, 2, 1, 0
};
char a[5], b[5];

int main() {
	scanf(" %s %s", a, b);
	rep(i, 4) if (a[s[i][0]] == b[0]) {
		rep(j, 3) {
			bool ok = 1;
			rep(k, 3) {
				if (b[k + 1] != a[s[i][(j + k) % 3 + 1]]) {
					ok = 0;
					break;
				}
			}
			if (ok) {
				puts("equal");
				return 0;
			}
		}
	}	
	puts("different");
	return 0;
}


