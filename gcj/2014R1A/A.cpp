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
const int INF = 1e9;
int Tc, n, m;
vector <string> plug, need;

void revBit(char &c) {
	if (c == '0')
		c = '1';
	else
		c = '0';
} 

bool ok(vector <bool> rev) {
	vector <string> newPlug = plug;
	rep (i, n) {
		rep (j, m) {
			if (rev[j]) {
				revBit(newPlug[i][j]);
			}
		}
	}
	sort(newPlug.begin(), newPlug.end());
	return newPlug == need;
}

int main() {
	scanf("%d", &Tc);
	rep (ri, Tc) {
		printf("Case #%d: ", ri + 1);
		scanf("%d%d", &n, &m);
		string s;
		plug.clear();
		need.clear();
		rep (i, n) {
			cin >> s;
			plug.push_back(s);
		}
		rep (i, n) {
			cin >> s;
			need.push_back(s);
		}
		sort(need.begin(), need.end());
		int ans = INF;
		rep (matchIdx, n) {
			vector <bool> rev(m);
			rep (i, m) rev[i] = plug[0][i] != need[matchIdx][i];
			if (ok(rev)) {
				int cnt = 0;
				rep (i, m) cnt += rev[i];
				if (cnt < ans) ans = cnt;
			}
		}
		if (ans == INF) {
			cout << "NOT POSSIBLE" << endl;
		} else {
			cout << ans << endl;
		}
	}
}
