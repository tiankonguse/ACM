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
const int N = 10005;
int n;
int m1[26];
int m2[32 * 32];
int m3[32 * 32 * 32];
int f[1 << 24];
char s[N][10];
ll ans;

int main() {
	scanf("%d", &n);
	rep (i, n) scanf("%s", s[i]);
	rep (i, n) {
		vector <int> a;
		a.push_back(s[i][0] - 'a');
		a.push_back(s[i][1] - 'a');
		a.push_back(s[i][2] - 'a');
		sort(a.begin(), a.end());
		a.resize(unique(a.begin(), a.end()) - a.begin());
		if (a.size() == 1) {
			m1[a[0]]++;
		} else if (a.size() == 2) {
			m1[a[0]]++;
			m1[a[1]]++;
			m2[a[0] << 5 | a[1]]++;
		} else if (a.size() == 3) {
			m1[a[0]]++;
			m1[a[1]]++;
			m1[a[2]]++;
			m2[a[0] << 5 | a[1]]++;
			m2[a[0] << 5 | a[2]]++;
			m2[a[1] << 5 | a[2]]++;
			m3[a[0] << 10 | a[1] << 5 | a[2]]++;
		}
	}
	ans = 0;
	int e;
	static int a[30];
	f[0] = 0;
	rep (mask, 1 << 24) {
		if (!mask) continue;
		int cur = 0;
		e = 0;
		rep (i, 24) {
			if (mask & 1 << i) a[e++] = i;
		}
		cur = f[mask ^ (1 << a[e - 1])] + m1[a[e - 1]];
		rep (i, e - 1) cur -= m2[a[i] << 5 | a[e - 1]];
		rep (i, e) rep (j, i)
			cur += m3[a[j] << 10 | a[i] << 5 | a[e - 1]];
		f[mask] = cur;
		ans ^= 1LL * cur * cur;
	}
	cout << ans << endl;
}
