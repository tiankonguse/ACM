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

#define inf 0x7fffffff
#define Inf 0x3FFFFFFFFFFFFFFFLL
using namespace std;
int const maxn = 20000;
typedef long long ll;
struct node {
	int a, b;
	friend bool operator < (node A, node B) {
		return A.b > B.b;
	}
} p[maxn];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d%d", &p[i].a, &p[i].b);
	}
	sort(p, p + n);
	int ret = 0;
	int mx = inf;
	for (int i = 0; i < n; ++i) {
		if (mx < p[i].a) ++ret;
		mx = min(mx, p[i].a);
	}
	printf("%d\n", ret);
	return 0;
}
