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
int const N = 22;
ll dp[N][10];
ll g[N][10];

int main() {
	int n; cin >> n;
	dp[0][0] = 1;
	Rep(i, n) rep(digit, 10) {
		rep(j, digit + 1) {
			dp[i][digit] += dp[i - 1][j];
		}
	}
	Rep(i, n) rep(digit, 10) {
		rep(j, digit) {
			g[i][digit] += dp[i - 1][j];
		}
	}
	ll ret = 0;
	Rep(i, n) Rep(j, n) if (i <= j) {
		rep(digit, 10) {
			ret += g[i][digit] * g[n - j + 1][digit];
		}
	}
	cout << ret + 1 << endl;

    return 0;
}

