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
typedef long long ll;
int const maxn = 30030;
char str[maxn], s0[2];
int st[maxn], top;
inline int turn(char ch) { return ch == 'A' ? 0 : 1; }
int main() {
  while (~scanf(" %s %s", s0, str)) {
		top = 0;
		st[++top] = turn(s0[0]);
		int pos = 0;
		int n = strlen(str);
		while (top > 0 && pos < n) {
			if (turn(str[pos]) != st[top]) {
				++pos;
				--top;
			}
			else {
				++pos;
				st[top + 1] = st[top] ^ 1;
				++top;
			}
		}
		if (top == 0 && pos == n) puts("YES");
		else puts("NO");
	}
    return 0;
}
