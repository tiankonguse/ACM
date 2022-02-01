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
int c[111];
int main() {
	int k, n, a;
	scanf("%d%d", &k, &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a);
		c[a / 1000]++;
	}
	int ret = 2;
	for (int i = 1; i <= 9; ++i) {
		ret += (c[i] + k - 1) / k;
	}
	printf("%d\n", ret);
	return 0;
}

