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
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define Rep(i, n) for (int i = 1; i <= (n); ++i)
#define clr(x, a) memset(x, (a), sizeof x)
using namespace std;
typedef long long ll;
int const N = 300100;
char s[N], t[N];
int cc[26];
int r[N], l[N], v[N];

int main() {
	int n = strlen(gets(s)), m = strlen(gets(t));
	rep(i, m) cc[t[i] - 'a'] ++;
	Rep(i, n) r[i] = i + 1, l[i] = i - 1, v[i] = s[i - 1] - 'a';
	r[0] = 1, l[n + 1] = n; v[0] = v[n + 1] = -1;
	int idx = n + 2;
	for (int i = 25; ~i; --i) if (cc[i]) {
		int now = 0;
		while (now != n + 1) {
			now = r[now];
			if (v[now] == i) {
				int tn = now;
				while (v[tn] == i) tn = r[tn];
				if (v[tn] > i) {
					while (cc[i] > 0) {
						--cc[i];
						r[l[tn]] = idx;
						l[idx] = l[tn];
						r[idx] = tn;
						l[tn] = idx;
						v[idx] = i;
						++idx;
					}
					goto next;
				}
				else {
					while (cc[i] > 0 && now != tn) {
						--cc[i];
						int pre = l[now];
						now = r[now];
						l[now] = pre;
						r[pre] = now;
					}
					if (cc[i] == 0) goto next;
				}
			}
			else if (v[now] > i) {
				while (cc[i] > 0) {
					--cc[i];
					r[l[now]] = idx;
					l[idx] = l[now];
					r[idx] = now;
					l[now] = idx;
					v[idx] = i;
					++idx;
				}
				goto next;
			}
		}
		if (cc[i] & 1) {
			now = n + 1;
			r[l[now]] = idx;
			l[idx] = l[now];
			r[idx] = now;
			l[now] = idx;
			v[idx] = i;
			++idx;
		}
next:;
	}
	int now = 0;
	while (r[now] != n + 1) {
		now = r[now];
		putchar(v[now] + 'a');
	}
	puts("");
	return 0;
}

