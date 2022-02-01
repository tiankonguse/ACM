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
int const maxn = 100100;
typedef long long ll;
int idx;
int num[maxn];
map <int, int> mp;
map <int, int> :: iterator it;

int tree[maxn << 2]; 
void update(int l, int r, int a, int c, int p) {
	if (l == r) {
		tree[p] = c;
		return;
	}
	int mid = (l + r) >> 1, lp = p << 1, rp = p << 1 | 1;
	if (a <= mid) update(l, mid, a, c, lp);
	else update(mid + 1, r, a, c, rp);
	tree[p] = __gcd(tree[lp], tree[rp]);
}

int main() {
	int n, a, id; char op[2];
	idx = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf(" %s%d", op, &a);
		it = mp.find(a);
		if (it == mp.end()) {
			mp.insert( make_pair(a, ++idx) );
			id = idx;
		}
		else {
			id = it -> second;
		}
		if (op[0] == '+') {
			if (num[id] == 0) {
				update(1, n, id, a, 1);
			}
			++num[id];
			printf("%d\n", tree[1]);
		}
		else {
			--num[id];
			if (num[id] == 0) {
				update(1, n, id, 0, 1);
			}
			if (tree[1] == 0) puts("1");
			else printf("%d\n", tree[1]);
		}
	}
	return 0;
}

