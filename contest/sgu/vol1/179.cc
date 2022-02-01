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
int const maxn = 10010;
char s[maxn];
int n, a[maxn];

int main() {
	scanf(" %s", s + 1);
	n = strlen(s + 1);
	a[0] = 0;
	for (int i = 1; i <= n; ++i) {
		if (s[i] == '(') a[i] = a[i - 1] + 1;
		else a[i] = a[i - 1] - 1;
	}
	bool flag = false;
	for (int i = n; i >= 1; --i) {
		if (s[i] == '(' && a[i - 1] > 0) {
			int top = a[i - 1] - 1;
			s[i] = ')';
			int m = (n - i + 1);
			int k = (m - top) / 2;
			for (int l = 1; l <= k; ++l) s[i + l] = '(';
			for (int l = k + 1; l <= m; ++l) s[i + l] = ')';
			for (int l = 1; l <= n; ++l) putchar(s[l]); puts("");
			flag = true;
			break;
		}
	}
	if (!flag) puts("No solution");
	return 0;
}

