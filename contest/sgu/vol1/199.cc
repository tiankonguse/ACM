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
typedef long long ll;
struct node {
	int x, y, id;
	friend bool operator < (node a, node b) {
		if (a.x == b.x) return a.y > b.y;
		else return a.x < b.x;
	}
} p[maxn];
int n;
int dp[maxn], pre[maxn];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d%d", &p[i].x, &p[i].y);
		p[i].id = i;
	}
	sort(p, p + n);
	int ret = 0, rb, low, high, mid;
	for (int i = 0; i < n; ++i) {
		low = 1, high = ret;
		while (low <= high) {
			mid = (low + high) >> 1;
			if (p[i].y > p[dp[mid]].y) low = mid + 1;
			else high = mid - 1;
		}
		pre[i] = dp[low - 1];
		dp[low] = i;
		if (low > ret) {
			ret = low;
			rb = i;
		}
	}
	printf("%d\n", ret);
	for (int i = 0; i < ret; ++i) {
		if (i == ret - 1) printf("%d\n", p[rb].id + 1);
		else printf("%d ", p[rb].id + 1);
		rb = pre[rb];
	}
	return 0;
}

