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
int const maxn = 1010;
typedef long long ll;
int num[maxn][maxn];
int mm[maxn][maxn];
int n, m;

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			scanf("%d", &num[i][j]);
		}
	}	
	for (int j = 0; j < m; ++j) {
		mm[n][j] = inf;
		for (int i = n - 1; i >= 0; --i) {
			mm[i][j] = min(num[i][j], mm[i + 1][j]);
		}
	}
	for (int j = m - 1; j >= 0; --j) {
		for (int i = n - 1; i >= 0; --i) {
			if (j == m - 1) num[i][j] = mm[i][j];
			else {
				if (i == 0) num[i][j] = min(mm[i][j], num[i][j + 1]);
				else num[i][j] = min(mm[i][j], num[i - 1][j + 1]);
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (j == m - 1) printf("%d\n", num[i][j]);
			else printf("%d ", num[i][j]);
		}
	}
	return 0;
}

