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
long long powMod(long long a, long long b, long long c) {
  long long ret = 1 % c;
  for (; b; a = a * a % c, b >>= 1)
    if(b & 1) ret = ret * a % c;
  return ret;
}
int main() {
	ll n, m, k, a;
	while (cin >> n >> m >> k) {
		int ret = 0;
		for (int i = 0; i < n; ++i) {
			cin >> a;
			ret += powMod(a, m, k) == 0;
		}
		cout << ret << endl;
	}
    return 0;
}
