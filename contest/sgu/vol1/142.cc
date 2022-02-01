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
int const maxn = 530000;
typedef long long ll;
char str[maxn];
bool mark[maxn];

int main() {
	int n;
	scanf("%d %s", &n, str);

	for (int len = 1; len <= n; ++len) {
		memset(mark, 0, sizeof mark);
		int cc = 0, mx = 1 << len;
		int msk = mx - 1;
		int t = 0;
		for (int j = 0; j < len; ++j) {
			t <<= 1;
			if (str[j] == 'b') t |= 1;
		}	
		mark[t] = true; ++cc;
		bool flag = true;
		for (int j = len; j < n; ++j) {
			t = ((t << 1) | (str[j] == 'b')) & msk;
			if (!mark[t]) {
				mark[t] = true;
				++cc;
				if (cc == mx) {
					flag = false;
					break;
				}
			}
		}
		if (flag) {
			printf("%d\n", len);
			for (int j = 0; j < mx; ++j) {
				if (!mark[j]) {
					for (int k = len - 1; k >= 0; --k) {
						if (j >> k & 1) putchar('b');
						else putchar('a');
					}
					puts("");
					break;
				}
			}
			break;
		}
	}
	return 0;
}
