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
ll ans[70000] = { 1 };
int main() {
	ll t = 1;
	for (int i = 1; i <= 65535; ++i) {
		ans[i] = ans[i - 1] + t;
		++t;
	}
	int n;
	cin >> n;
	cout << ans[n] << endl;
	return 0;
}
