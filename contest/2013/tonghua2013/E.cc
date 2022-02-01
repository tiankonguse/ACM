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
using namespace std;
typedef long long ll;
int const maxn = 100100;
ll pri[maxn], mark[maxn];
int cnt;
void sieve() {
  cnt = 0, mark[0] = mark[1] = 1;
  for (int i = 2; i < maxn; ++i) {
  	if (!mark[i]) pri[cnt++] = mark[i] = i;
		for (int j = 0; pri[j] * i < maxn; ++j) {
			mark[i * pri[j]] = pri[j];
			if (!(i % pri[j])) break;
		}
	}
}

ll cal(ll G, ll L) {
	ll ret = 1LL; int c1, c2;
	for (int i = 0; pri[i] * pri[i] <= L; ++i) {
		if (L % pri[i] == 0) {
			c1 = 0, c2 = 0;
			while (G % pri[i] == 0) G /= pri[i], ++c1;
			while (L % pri[i] == 0) L /= pri[i], ++c2;
			if (c1 == c2) continue;
			else if (c1 + 1 == c2) ret *= 6LL;
			else ret *= 6LL + 6LL * (c2 - c1 - 1);
		}
	}
	if (L > 1 && G == 1) {
		ret *= 6LL;
	}
	return ret;
}
int main() {
	sieve();
	int T; ll G, L, ret;
	for (scanf("%d", &T); T--; ) {
		scanf("%lld %lld", &G, &L);
		if (L % G != 0) {
			puts("0");
			continue;
		}
		ret = cal(G, L);
		printf("%lld\n", ret);
	}
	return 0;
}

