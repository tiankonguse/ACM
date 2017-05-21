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
ll a[44] = {0, 1, 1};
ll s[44] = {0, 1, 2};
int main() {
	for (int i = 2; i <= 40; ++i) {
		a[i] = a[i - 1] + a[i - 2];
		s[i] = s[i - 1] + a[i];
	}
	int n;
	cin >> n;
	cout << s[n] << endl;
	return 0;
}

