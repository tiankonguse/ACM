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
char a[1111], b[1111];
int ca[128], cb[128];
int main() {
  while (gets(a)) {
		gets(b);
		memset(ca, 0, sizeof ca);
		memset(cb, 0, sizeof cb);
		for (int i = 0; a[i]; ++i) ++ca[a[i]];
		for (int i = 0; b[i]; ++i) ++cb[b[i]];
		for (int i = 'a'; i <= 'z'; ++i) {
			for (int j = min(ca[i], cb[i]); j > 0; --j) {
				putchar(i);
			}
		}
		puts("");
	}
    return 0;
}
