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
int const maxn = 2020;
typedef long long ll;
typedef unsigned long long ull;
class BigNum {
	ull static const digit = 1000000000;
	int static const digit_len = 9;
	int static const maxl = 1000;
	ull data[maxl];
	int len;
	
	void shrink() {
		while (len > 1 && !data[len - 1]) --len;	
	}
	
	public:
	BigNum(ull i = 0) {
		data[0] = i % digit;
		len = 1;
		i /= digit;
		while (i) {
			data[len++] = i % digit;
			i /= digit;
		}
	}
	explicit BigNum(char const *s) {
		int t; len = 0;
		for (int i = strlen(s) - 1; i >= 0; i -= digit_len) {
			t = 0;
			for (int j = digit_len - 1; ~j; --j) {
				if (i - j >= 0) {
					t = (t << 3) + (t << 1) + (s[i - j] - '0');
				}		
			}
			data[len++] = t;
		}
		shrink();
	}
	
	bool zero() const {
		return len == 1 && !data[0];
	}
	
	BigNum &operator--() {
		int i;
		for (i = 0; !data[i]; ++i) {
			data[i] = digit - 1;
		}
		--data[i];
		return *this;
	}
	
	BigNum &operator+=(BigNum const &a) {
		ull p = 0;
		for (int i = 0; p || i < len || i < a.len; ++i) {
			if (i < len) p += data[i];
			if (i < a.len) p += a.data[i];
			if (i >= len) ++len;
			if (p >= digit) data[i] = p - digit, p = 1;
			else data[i] = p, p = 0;
		}
		return *this;
	}
	
	BigNum &operator-=(BigNum const &a) {
		ull p = 0;
		for (int i = 0; i < len || p; ++i) {
			if (i < a.len) p += a.data[i];
			if (p <= data[i]) data[i] -= p, p = 0;
			else data[i] += digit - p, p = 1;
		}
		shrink();
		return *this;
	}
	
	BigNum operator+(BigNum a) {
		BigNum r = *this;
		return r += a;
	}
	
	BigNum operator-(BigNum a) {
		BigNum r = *this;
		return r -= a;
	}
	
	ull operator%(ull d) {
		ull p = 0;
		for (int i = len - 1; ~i; --i)
			p = (p * digit + data[i]) % d;
		return p;
	}
	
	BigNum &operator*=(ull a) {
		ull p = 0;
		for (int i = 0; p || i < len; ++i) {
			if (i < len) p += a * data[i];
			if (i >= len) ++len;
			data[i] = p % digit;
			p /= digit;
		}
		return *this;
	}
	BigNum operator*(BigNum const &a) {
		BigNum r = 0, t; ull p = 0;
		for (int i = 0; i <= a.len + a.len + 1; ++i) r.data[i] = 0;
		if (zero() || a.zero()) return r;
		for (int i = 0; i < len; ++i) {
			t = a;
			t *= data[i];
			t.len += i;
			r.len = max(r.len, t.len + 1);
			p = 0;
			for (int j = 0; j < t.len - i || p; ++j) {
				if (j + i < r.len) p += r.data[j + i];
				if (j < t.len) p += t.data[j];
				if (j >= r.len) ++r.len;
				if (p >= digit) r.data[j + i] = p - digit, p = 1;
				else r.data[j + i] = p, p = 0;
			}
		}
		r.shrink();
		return r;
	}
	
	BigNum &operator/=(ull a) {
		ull p = 0;
		for (int i = len - 1; ~i; --i) {
			p = p * digit + data[i];
			data[i] = p / a;
			p %= a;
		}
		shrink();
		return *this;
	}
	
	BigNum operator/(BigNum const &a) {
		BigNum ret, t = *this, p = 1, ta = a;
		while (ta < t) p *= 10, ta *= 10;
		while (!p.zero()) {
			while (ta < t || ta == t) ret += p, t -= ta;
			p /= 10, ta /= 10;
		}
		return ret;
	}
	
	BigNum operator%(BigNum const &a) {
		return *this - (*this / a) * a;
	}
	
	BigNum operator^(ull a) {
		BigNum ret = 1, t = *this, u;
		while (a > 0) {
			if (a & 1) ret = ret * t;
			t = t * t;
			a >>= 1;
		}
		return ret;
	}
	
	bool operator==(BigNum const &x) const {
		if (len != x.len) return false;
		for (int i = 0; i < len; ++i) {
			if (data[i] != x.data[i]) return false;
		}
		return true;
	}
	bool operator<(BigNum const &x) const {
		if (len != x.len) return len < x.len;
		for (int i = len - 1; ~i; --i) {
			if (data[i] != x.data[i]) return data[i] < x.data[i];
		}
		return false;
	}
	
	#define format0 "%I64u"
	#define format1 "%0*I64u"
	#ifdef __unix__
		#define format0 "%llu"
		#define format1 "%0*llu"
	#endif
	
	void print() {
		printf(format0, data[len - 1]);
		for (int i = len - 2; ~i; --i) printf(format1, digit_len, data[i]);
		puts("");
	}
} A, B, C;

BigNum gcd(BigNum a, BigNum b) {
	while (!b.zero()) {
		a = a % b;
		swap(a, b);
	}
	return a;
}


char str[maxn];
int main() {
	scanf(" %s", str);
	A = BigNum(str);
	B = A / 2;
	while (!(gcd(A, B) == 1)) B = B - 1;
	B.print();
	return 0;
}



