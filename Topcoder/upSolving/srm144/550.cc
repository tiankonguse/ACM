// BEGIN CUT HERE
/*
   
 */
// END CUT HERE
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
using namespace std;

#define inf 0x3f3f3f3f
#define Inf 0x3FFFFFFFFFFFFFFFLL

#define PB push_back
#define MP make_pair

#define rep(i, n) for(int i = 0; i < (n); ++i)
#define repi(i, l, h) for (int i = (l); i <= (h); ++i)
#define repd(i, h, l) for (int i = (h); i >= (l); --i)
#define Rep(i, n) for (int i = 1; i <= (n); ++i)
#define clr(x, a) memset(x, (a), sizeof x)

typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> pii;

int const N = 55;
struct node {
	string name;
	int n, m, u, v;
	ll t;
	friend bool operator < (node a, node b) {
		if (a.t == b.t) return a.name < b.name;
		else return a.t < b.t;
	}
} p[N];

ll dp[11][111];
ll cal(int n, int m, int u, int v) {
	ll ret;
	if (u == 0 && v == 0) {
		ret = 1LL;
		rep(i, m) ret *= n;
	}
	else if (u == 1 && v == 0) {
		clr(dp, 0); dp[0][1] = 1;
		rep(i, m) Rep(j, n) if (dp[i][j]) {
			for (int k = j; k <= n; ++k) dp[i + 1][k] += dp[i][j];
		}
		ret = 0; Rep(i, n) ret += dp[m][i];
	}
	else if (u == 0 && v == 1) {
		ret = 1LL;
		rep(i, m) ret *= (n - i);
	}
	else {
		clr(dp, 0); dp[0][0] = 1;
		rep(i, m) rep(j, n) if (dp[i][j]) {
			for (int k = j + 1; k <= n; ++k) dp[i + 1][k] += dp[i][j];
		}
		ret = 0; Rep(i, n) ret += dp[m][i];
	}
	return ret;
}

class Lottery
{
	public:
		vector <string> sortByOdds(vector <string> s)
		{
			int n = s.size(); string t;
			rep(i, n) {
				p[i].name = "";
				rep(j, s[i].size()) {
					if (s[i][j] == ':') break;
					else p[i].name += s[i][j];
				}
				istringstream is(s[i]);
				while (is >> t) if (t[t.length() - 1] == ':') break; 
				is >> p[i].n >> p[i].m;
				is >> t; p[i].u = t == "T" ? 1 : 0;
				is >> t; p[i].v = t == "T" ? 1 : 0;
				p[i].t = cal(p[i].n, p[i].m, p[i].u, p[i].v);
			}
			sort(p, p + n);
			vector <string> ret; rep(i, n) ret.push_back(p[i].name);
			return ret;
		}
		
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"PICK ANY TWO: 10 2 F F"
,"PICK TWO IN ORDER: 10 2 T F"
,"PICK TWO DIFFERENT: 10 2 F T"
,"PICK TWO LIMITED: 10 2 T T"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "PICK TWO LIMITED",  "PICK TWO IN ORDER",  "PICK TWO DIFFERENT",  "PICK ANY TWO" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, sortByOdds(Arg0)); }
	void test_case_1() { string Arr0[] = {"INDIGO: 93 8 T F",
 "ORANGE: 29 8 F T",
 "VIOLET: 76 6 F F",
 "BLUE: 100 8 T T",
 "RED: 99 8 T T",
 "GREEN: 78 6 F T",
 "YELLOW: 75 6 F F"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "RED",  "ORANGE",  "YELLOW",  "GREEN",  "BLUE",  "INDIGO",  "VIOLET" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, sortByOdds(Arg0)); }
	void test_case_2() { string Arr0[] = {}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, sortByOdds(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
	Lottery ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE



