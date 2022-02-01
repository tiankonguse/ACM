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
bool mark[11];
bool check(int n, int r) {
	int ret = 0;
	for (int i = 0; i < n - 1; ++i) {
		ret = (ret * 10 + 1) % r;
	}
	ret = (ret * 10 + r) % r;
	return ret == 0;
}
int main() {
	int k, ret = 0;
	scanf("%d", &k);
	for (int i = 1; i <= 9; ++i) {
		mark[i] = check(k, i);
		if (i > 1 && mark[i] && mark[i - 1]) ++ret;
	}
	printf("%d\n", ret);
	return 0;
}

