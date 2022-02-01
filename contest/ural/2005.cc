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
int const N = 10;
int mp[N][N];

int main() {
	Rep(i, 5) Rep(j, 5) cin >> mp[i][j];
	int a[3]; rep(i, 3) a[i] = i + 2;
	int ans[3];
	int ret = inf;
	do {
		if (a[2] == 3) continue;
		int t = mp[1][a[0]] + mp[5][a[2]];
		t += mp[a[0]][a[1]] + mp[a[1]][a[2]];
		if (t < ret) {
			ret = t;
			rep(i, 3) ans[i] = a[i];
		}
	} while (next_permutation(a, a + 3));
	cout << ret << endl;
	cout << 1 << " ";
	rep(i, 3) cout << ans[i] << " ";
	cout << 5 << endl;
	return 0;
}

