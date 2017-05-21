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
int const maxn = 1000100;
int pri[maxn / 10], cnt;
bool mark[maxn];
int ans[maxn / 10], ant;

int main() {
	cnt = 0, mark[0] = mark[1] = true;
	for (int i = 2; i < maxn; ++i) {
		if (!mark[i]) pri[cnt++] = i;
		for (int j = 0; i * pri[j] < maxn; ++j) {
			mark[i * pri[j]] = true;
			if (!(i % pri[j])) break;
		}
	}
	int n;
	scanf("%d", &n);
	ant = 0;
	for (int i = 0; pri[i] + 2 <= n; ++i) {
		if (!mark[pri[i] + 2]) ans[ant++] = pri[i];
	}
	printf("%d\n", ant);
	for (int i = 0; i < ant; ++i) {
		printf("%d %d\n", 2, ans[i]);
	}
	return 0;
}

