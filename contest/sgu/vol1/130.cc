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
ll a[111] = {1, 1};

int main() {
	for (int i = 2; i <= 33; ++i) {
		a[i] = a[i - 1] * (4 * i - 2) / (i + 1);
	}	
	int k;
	scanf("%d", &k);
	printf("%I64d %d\n", a[k], k + 1);
	return 0;
}

