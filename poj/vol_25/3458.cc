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
int const maxn = 111;
char s[maxn], s1[maxn], s2[maxn];
int main() {
  int T;
	for (scanf("%d", &T); T--; ) {
		scanf(" %s %s %s", s, s1, s2);
		int n = strlen(s), m = strlen(s1);
		int pos = 0;
		for (int i = 0; i < m; ++i) {
			if (s1[i] == '*' || s2[i] == '*' || s1[i] == s[pos] || s2[i] == s[pos]) {
				++pos;
				if (pos == n) break;
			}
		}
		puts(pos == n ? "win" : "lose");
	}
    return 0;
}
