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

int main() {
	int n;
	cin >> n;
	if (n == 1) cout << 14 ;
	if (n == 2) cout << 155 ;
	if (n >= 3) cout << 1575 ;
	for (int i = 4; i <= n; ++i) cout << 0;
	cout << endl;
	return 0;
}
