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
int const N = 10001000;
int a[N];
int pri[664777]; bool mark[N]; int cnt;
void sieve() {
  cnt = 0, mark[0] = mark[1] = 1;
  for (int i = 2; i < N; ++i) {
		if (!mark[i]) pri[cnt++] = i, mark[i] = 1;
		for (int j = 0; pri[j] * i < N; ++j) {
			mark[i * pri[j]] = 1;
			if (!(i % pri[j])) break;
		}
	}
}

int main() {
	sieve();
	int n, x;
	scanf("%d", &n);
	rep(i, n) {
		scanf("%d", &x);
		a[x] += 1;
	}
	int ret = 0;
	for (int i = 0; i < cnt; ++i) {
		int t = 0;
		for (int j = pri[i]; j <= 10000000; j += pri[i]) {
			t += a[j];
		}
		ret = max(ret, t);
		if (ret >= 3) break;
	}
	if (ret >= 3) puts("infinity");
	else printf("%d\n", ret);
	return 0;
}

