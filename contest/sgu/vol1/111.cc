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
int const N = 1010;
char buf[N];
int s[N];
struct BigInt {
	int a[N], len;
	void operator += (int const &t) {
		a[0] += t; int l = 0;
		while (a[l] >= 10) {
			a[l + 1] += a[l] / 10;
			a[l] %= 10;
			++l;
		}
		len = max(len, l + 1);
	}
	void operator -= (BigInt const &B) {
		rep(i, B.len) {
			a[i] -= B.a[i];
			if (a[i] < 0) a[i] += 10, a[i + 1] -= 1;
		}
		for (int i = len - 1; ~i; --i) {
			if (a[i]) {
				len = i + 1;
				break;
			}
		}
	}
	void operator *= (int const &t) {
		rep(i, len) a[i] *= t;
		rep(i, len) {
			a[i + 1] += a[i] / 10;
			a[i] %= 10;
		}
		while (a[len] >= 10) {
			a[len + 1] += a[len] / 10;
			a[len] %= 10;
			++len;
		}
		if (a[len] > 0) ++len;
	}
	bool operator <= (BigInt const &B) const {
		if (len != B.len) return len < B.len;
		for (int i = len - 1; ~i; --i) {
			if (a[i] != B.a[i]) return a[i] < B.a[i];
		}
		return 1;
	}
	BigInt(int x = 0) {
		len = 0; clr(a, 0);
		while (x) {
			a[len++] = x % 10;
			x /= 10;
		}
		len = max(len, 1);
	}
	void pr() { for (int i = len - 1; ~i; --i) printf("%d", a[i]); puts(""); }
} X, Y, Z;
int main() {
	int n = strlen(gets(buf));
	if (n & 1) { Rep(i, n) s[i] = buf[i - 1] - '0'; ++n; }
	else rep(i, n) s[i] = buf[i] - '0';
	for (int i = 0; i < n; i += 2) {
		X *= 10; Y *= 100; Y += (s[i] * 10 + s[i + 1]);
		for (int t = 9; ~t; --t) {
			Z = X; Z *= (2 * t); Z += (t * t);
			if (Z <= Y) {
				X += t;
				break;
			}
		}
		Y -= Z;
	}
	X.pr();
	return 0;
}

