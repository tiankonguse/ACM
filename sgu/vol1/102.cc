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
using namespace std;
typedef long long ll;

int main() {
	int n, ret;
	scanf("%d", &n);
	ret = n;
	for (int i = 2; i * i <= n; i += i == 2 ? 1 : 2) {
		if (!(n % i)) {
			ret = ret * (i - 1) / i;
			while (!(n % i)) n /= i;
		}
	}	
	if (n > 1) ret = ret * (n - 1) / n;
	printf("%d\n", ret);
	return 0;
}

