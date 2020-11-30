#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define foreach(it,v) for (__typeof((v).end()) it = (v).begin(); it != (v).end(); it++)
typedef long long ll;
typedef pair <int, int> PII;
const int N = 1000005;
int n;
int a[N], cnt[N];

int main() {
	scanf("%d", &n);
	rep (i, n) scanf("%d", &a[i]);
	cnt[n] = 0;
	for (int i = n - 1; i >= 0; i--)
		cnt[i] = cnt[i + 1] + (a[i] == 0);
	long long ans = 0;
	rep (i, n) {
		if (a[i] == 1) {
			ans += cnt[i + 1];
		}
	}
	cout << ans << endl;
}
