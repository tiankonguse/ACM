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
int const maxn = 55;
typedef long long ll;
ll dat[maxn];
int main() {
	for (int i = 1; i < maxn; ++i) {
		dat[i] = i;
		for (int j = 1; j <= i + 1; ++j) {
			dat[i] = dat[i] * 2 + 1;
		}
	}
	ll n;
	scanf("%I64d", &n);
	if (n == 1) puts("0");
	else {
		int ret = lower_bound(dat, dat + maxn, n) - dat;
		printf("%d\n", ret);
	}
	return 0;
}

