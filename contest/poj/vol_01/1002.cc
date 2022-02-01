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
int const maxn = 100100;
int const mp[26] = {2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, -1, 7, 7, 8, 8, 8, 9, 9, 9};
map <int, int> s;
int main() {
	int n, t; char str[111];
	for (scanf("%d", &n); n--; ) {
		scanf(" %s", str);
		t = 0;
		for (int i = 0; str[i]; ++i) {
			if (isdigit(str[i])) {
				t = t * 10 + str[i] - '0';
			}
			else if (isupper(str[i])) {
				t = t * 10 + mp[str[i] - 'A'];
			}
		}
		s[t]++;
	}
	bool dup = false;
	for (map <int, int> :: iterator it = s.begin(); it != s.end(); ++it) {
		if (it -> second > 1) {
			dup = true;
			printf("%03d-%04d %d\n", it -> first / 10000, it -> first % 10000, it -> second);
		}
	}
	if (!dup) puts("No duplicates.");
	return 0;
}
