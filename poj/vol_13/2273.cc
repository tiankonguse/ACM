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
char s[1111];
int num[1111];
int func(int n) {
	int cnt = 0;
	while (n--) {
		num[cnt++] = n % 26;
		n /= 26;
	}	
	return cnt;
}

int main() {
	int n, m;
	while (~scanf(" R%dC%d", &n, &m)) {
		if (n == 0 && m == 0) break;
		int r = func(m);
		for (int i = r - 1; ~i; --i) {
			putchar('A' + num[i]);
		}
		printf("%d\n", n);
	}	
	return 0;
}

