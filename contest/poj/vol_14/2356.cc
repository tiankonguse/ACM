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
int const maxn = 10010;
int s[maxn], a[maxn];
int mark[maxn];
int main() {
  int n;
	while (~scanf("%d", &n)) {
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &a[i]);
			s[i] = s[i - 1] + a[i];
			s[i] %= n;
		}
		memset(mark, 0xff, sizeof mark);
		for (int i = 0; i <= n; ++i) {
			if (mark[s[i]] != -1) {
				int l = mark[s[i]];
				printf("%d\n", i - l);
				for (int j = l + 1; j <= i; ++j) printf("%d\n", a[j]);
				break;
			}
			else mark[s[i]] = i;
		}
	}	
    return 0;
}
