#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <set>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bitset>
using namespace std;
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define foreach(it,v) for (__typeof((v).end()) it = (v).begin(); it != (v).end(); it++)
typedef int ll;

const int mem[2][2] = {0, 0, 0, 1};

ll nim_mul_power(ll x, ll y) {
	if (x < 2) return mem[x][y];
	ll p, s, t, m, d1, d2;
	for (p = 1; p < 64 && (1LL << p) <= x; p <<= 1);
	p >>= 1;
	m = 1LL << p;
	s = y >> p;
	p = x >> p;
	t = y & (m - 1);
	d1 = nim_mul_power(p, s);
	d2 = nim_mul_power(p, t);
	return m * (d1 ^ d2) ^ nim_mul_power(m >> 1, d1);
}

ll nim_mul(ll x, ll y) {
	if (x < y) swap(x, y);
	if (x < 2) return mem[x][y];
	ll p, q, s, t, m, c1, c2, c3;
	for (p = 1; p < 64 && (1LL << p) <= x; p <<= 1);
	p >>= 1;
	m = 1LL << p;
	s = y >> p; t = y & (m - 1);
	p = x >> p; q = x & (m - 1);
	c1 = nim_mul(p, s);
	c2 = nim_mul(p, t) ^ nim_mul(q, s);
	c3 = nim_mul(q, t);
	return (c1 ^ c2) * m ^ c3 ^ nim_mul_power(m >> 1, c1);
}
