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
int const maxn = 11111;
ll mark[maxn];

int main() {
	ll A, a, b, c, mod, k;
	scanf("%I64d%I64d%I64d%I64d%I64d%I64d", &A, &a, &b, &c, &mod, &k);
	memset(mark, 0xff, sizeof mark);
	mark[A] = 0;
	ll x = A;
	for (int i = 1; i <= k; ++i) {
		x = (a * x * x + b * x + c) % mod;
		if (mark[x] != -1) {
			ll rc = i - mark[x];
			i += (k - i) / rc * rc;
			for (; i < k; ++i) {
				x = (a * x * x + b * x + c) % mod;
			}
			break;
		}
		mark[x] = i;
	}
	printf("%I64d\n", x);
	return 0;
}

