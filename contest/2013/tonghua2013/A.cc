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

char ans[100];
int main() {
  int T;
	double x, ret;
	for (scanf("%d", &T); T--; ) {
		ret = 0;
		for (int i = 0; i < 12; ++i) {
			scanf("%lf", &x);
			ret += x;
		}
		ret /= 12.0;
		sprintf(ans, "%.2lf", ret);
		int len = strlen(ans);
		int tl = len;
		for (int i = 1; i <= 3; ++i) {
			if (ans[len - i] == '.' || ans[len - i] == '0') --tl;
			else break;
		}
		ans[tl] = 0;
		printf("$%s\n", ans);
	}
	return 0;
}

