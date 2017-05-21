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
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define Rep(i, n) for (int i = 1; i <= (n); ++i)
#define clr(x, a) memset(x, (a), sizeof x)
using namespace std;
typedef long long ll;
string op, s1, s2;
map <string, string> mp;
map <string, int> lg;

int main() {
	int n;
	cin >> n;
	while (n--) {
		cin >> op;
		if (op == "register") {
			cin >> s1 >> s2;
			if (mp.find(s1) != mp.end()) {
				cout << "fail: user already exists" << endl;
			}
			else {
				mp[s1] = s2;
				cout << "success: new user added" << endl;
			}
		}
		else if (op == "login") {
			cin >> s1 >> s2;
			if (mp.find(s1) == mp.end()) {
				cout << "fail: no such user" << endl;
			}
			else {
				if (s2 != mp[s1]) {
					cout << "fail: incorrect password" << endl;
				}
				else if (lg[s1] == 1) {
					cout << "fail: already logged in" << endl;
				}
				else {
					cout << "success: user logged in" << endl;
					lg[s1] = 1;
				}
			}
		}
		else {
			cin >> s1;
			if (mp.find(s1) == mp.end()) {
				cout << "fail: no such user" << endl;
			}
			else if (lg[s1] == 0) {
				cout << "fail: already logged out" << endl;
			}
			else {
				lg[s1] = 0;
				cout << "success: user logged out" << endl;
			}
		}
	}
	return 0;
}

