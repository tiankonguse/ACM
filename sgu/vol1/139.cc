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
int a[16];

int main() {
	for (int i = 0; i < 16; ++i) scanf("%d", &a[i]);
	int ret = 0;
	for (int i = 0; i < 16; ++i) {
		if (a[i] == 0) {
			ret ^= (3 - i / 4) & 1;
			continue;
		}
		for (int j = i + 1; j < 16; ++j) {
			if (a[j] != 0) ret ^= a[i] > a[j];
		}
	}	
	if (ret) puts("NO"); else puts("YES");
	return 0;
}

