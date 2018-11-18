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
const int N = 300005;
int n, m;
vector <int> cc;
vector <int> cell[N];
int a[N], b[N];

int main() {
	scanf("%d%d", &n, &m);
	if (n == 1) {
		if (m) {
			puts("-1");
		} else {
			puts("0");
		}
		return 0;
	}
	cc.push_back(1);
	cc.push_back(n);
	rep (i, m) {
		scanf("%d%d", &a[i], &b[i]);
		cc.push_back(b[i]);
		if (b[i] > 1) cc.push_back(b[i] - 1);
		if (b[i] < n) cc.push_back(b[i] + 1);
	}
	sort(cc.begin(), cc.end());
	cc.resize(unique(cc.begin(), cc.end()) - cc.begin());
	rep (i, m) {
		int idx = lower_bound(cc.begin(), cc.end(), b[i]) - cc.begin();
		cell[idx].push_back(a[i]);
	}
	rep (i, cc.size()) sort(cell[i].begin(), cell[i].end());
	set <PII> s[2];
	if (cell[0].empty()) {
		s[0].insert(PII(1, n));
	} else if (cell[0][0] > 1) {
		s[0].insert(PII(1, cell[0][0] - 1));
	}
	int o = 0;
	rep (i, cc.size() - 1) {
		if (s[o].empty()) {
			puts("-1");
			return 0;
		}
		o ^= 1;
		s[o].clear();
		if (cell[i + 1].empty()) {
			s[o].insert(PII(s[o ^ 1].begin()->first, n));
		} else {
			int prev = 0;
			cell[i + 1].push_back(n + 1);
			foreach (j, cell[i + 1]) {
				if (prev + 1 < *j) {
					int res = n + 1;
					set <PII>::iterator it = s[o ^ 1].lower_bound(PII(prev + 1, -1));
					if (it != s[o ^ 1].end()) {
						if (it->first < *j) {
							res = min(res, it->first);
						}
					}
					if (it != s[o ^ 1].begin()) {
						--it;
						if (it->second > prev) {
							res = min(res, max(it->first, prev + 1));
						}
					}
					if (res < *j) {
						s[o].insert(PII(res, *j - 1));
					}
				}
				prev = *j;
			}
		}
	}
	if (s[o].empty() || (--s[o].end())->second != n) {
		puts("-1");
	} else {
		printf("%d\n", n + n - 2);
	}
}
