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
int const maxn = 1111;
int a[maxn];
int main() {
  int n;
	while (~scanf("%d", &n) && n) {
		int t = 0;
		for (int i = 0; i < n; ++i) {
			scanf("%d", &a[i]);
			t ^= a[i];
		}
		if (t == 0) {
			puts("0");
			continue;
		}
		int ret = 0, r;
		for (int i = 0; i < n; ++i) {
			r = t ^ a[i];
			if (a[i] >= r) ++ret;
		}
		printf("%d\n", ret);
	}
    return 0;
}
