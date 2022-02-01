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
int const maxn = 100100;
int const maxm = 1000100;
typedef long long ll;
int n, a[maxn];
bool mark[maxm];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", a + i);
		mark[a[i]] = true;
	}
	sort(a, a + n);
	int ret = 1;
	for (int i = a[n - 1]; i > 1; --i) {
		int cnt = 0;
		for (int j = i; j <= a[n - 1]; j += i) {
			if (mark[j]) {
				if (++cnt >= 2) break;
			}
		}
		if (cnt >= 2) {
			ret = i;
			break;
		}
	}	
	printf("%d\n", ret);
	return 0;
}

