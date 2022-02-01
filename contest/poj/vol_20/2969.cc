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
char str[1010];
int c[10], r[10];
vector <int> v[3];
int num[22], m;
int main() {
  while (~scanf(" %s", str)) {
		memset(c, 0, sizeof c);
		memset(r, 0, sizeof r);
		int len = strlen(str);
		for (int i = 0; i < 3; ++i) v[i].clear();
		for (int i = 0; i < len; ++i) c[str[i] - '0']++;
		if (c[0] == 0 && c[5] == 0) { puts("impossible"); continue; }
		for (int i = 0; i < 10; ++i) {
			if (i % 3 == 0) r[i] = c[i];
			else {
				for (int j = 0; j < c[i]; ++j) {
					v[i % 3].push_back(i);
				}
			}
		}
		m = 0;
		bool need = r[0] == 0;
		int mod = 0;
		for (int t = 1; t <= 2; ++t) {
			sort(v[t].begin(), v[t].end());
			if (need && t == 2) {
				for (int i = 0; i < v[t].size(); ++i) {
					if (v[t][i] == 5) {
						r[5]++;
						for (int j = i; j < v[t].size() - 1; ++j) {
							v[t][j] = v[t][j + 1];
						}
						v[t].pop_back();
						mod = (mod + (3 - t)) % 3;
						break;
					}
				}
			}
			for (int i = v[t].size() - 1; i >= 0; --i) {
				if (i < 4) {
					num[m++] = v[t][i];
				}
				else {
					r[v[t][i]]++;
					mod = (mod + (3 - t)) % 3;
				}
			}
		}
		sort(num, num + m);
		reverse(num, num + m);
		int mx = 1 << m;
		ll ret = 0;
		for (int i = 0; i < mx; ++i) {
			ll t = 0;
			for (int j = 0; j < m; ++j) {
				if (i >> j & 1) t = t * 10LL + num[j];
			}
			if (t % 3 == mod && t > ret) {
				ret = t;
			}
		}
		if (need && ret == 0) {
			puts("impossible");
			continue;
		}
		while (ret) {
			r[ret % 10]++;
			ret /= 10;
		}
		int end = -1;
		if (r[0] > 0) {
			end = 0; --r[0];
		}	
		else if (r[5] > 0) {
			end = 5; --r[5];
		}
		else {
			puts("impossible");
			continue;
		}
		string res = "";
		for (int i = 9; i >= 0; --i) {
			for (int j = 0; j < r[i]; ++j) {
				res += (i + '0');
			}
		}
		res += (end + '0');
		for (int i = 0; i < res.length(); ++i) {
			if (i == res.length() - 1 || res[i] != '0') {
				for (int j = i; j < res.length(); ++j) {
					putchar(res[j]);
				}
				break;
			}
		}
		puts("");
		
	}		
    return 0;
}
