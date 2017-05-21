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
int a[1 << 22];

int main() {
  a[0] = 0, a[1] = 1;
	int t = 2;
	for (int i = 2; i < 22; ++i) {
		for (int j = 0; j < t; ++j) {
			a[t + j] = a[t - j - 1] + t;
		}
		t <<= 1;
	}	
	int n, m;
	while (~scanf("%d%d", &n, &m)) {
		int nn = 1 << n, mm = 1 << m;
		for (int i = 0; i < nn; ++i) {
			for (int j = 0; j < mm; ++j) {
				int ret = (a[i] << m) + a[j];
				if (j == mm - 1) printf("%d\n", ret);
				else printf("%d ", ret);
			}
		}
	}
    return 0;
}
