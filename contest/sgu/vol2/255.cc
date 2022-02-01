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
typedef __int64 ll;
set <ll> s;

int main() {
  ll a = 2, b = 2;
	s.insert(a);
	while (1) {
		a += b;
		++b;
		s.insert(a);
		if (a > 2147483647LL) break;
	}
	int T; 
	ll m;
	for (scanf("%d", &T); T--; ) {
		scanf("%I64d", &m);
		if (s.find(m) != s.end()) puts("YES");
		else puts("NO");
	}
    return 0;
}
