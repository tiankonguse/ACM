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

#define rep(i,n) for(int i=0;i<(n);++i)
#define repi(i,l,h) for(int i=(l);i<=(h);++i)
#define repd(i,h,l) for(int i=(h);i>=(l);--i)
#define Rep(i, n) for (int i = 1; i <= (n); ++i)
#define clr(x, a) memset(x, (a), sizeof x)

typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> pii;

int const N = 55;
int a[N], b[N];
class BinaryCode
{
        public:
        vector <string> decode(string s)
        {
			int n = s.length(); rep(i, n) a[i] = s[i] - '0';
			string r1 = "", r2 = "";
			
			b[0] = 0;
			rep(i, n - 1) b[i + 1] = a[i] - b[i] - (i == 0 ? 0 : b[i - 1]);
			if (a[n - 1] != b[n - 1] + (n == 1 ? 0 : b[n - 2])) b[0] = -1;
			rep(i, n) {
				if (b[i] != 0 && b[i] != 1) {
					r1 = "NONE";
					break;
				}
				else r1 += (b[i] + '0');
			}
			b[0] = 1;
			rep(i, n - 1) b[i + 1] = a[i] - b[i] - (i == 0 ? 0 : b[i - 1]);
			if (a[n - 1] != b[n - 1] + (n == 1 ? 0 : b[n - 2])) b[0] = -1;
			rep(i, n) {
				if (b[i] != 0 && b[i] != 1) {
					r2 = "NONE";
					break;
				}
				else r2 += (b[i] + '0');
			}
			vector <string> ret; ret.push_back(r1), ret.push_back(r2);
            return ret;
        }
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arg0 = "123210122"; string Arr1[] = { "011100011",  "NONE" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, decode(Arg0)); }
	void test_case_1() { string Arg0 = "11"; string Arr1[] = { "01",  "10" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, decode(Arg0)); }
	void test_case_2() { string Arg0 = "22111"; string Arr1[] = { "NONE",  "11001" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, decode(Arg0)); }
	void test_case_3() { string Arg0 = "123210120"; string Arr1[] = { "NONE",  "NONE" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, decode(Arg0)); }
	void test_case_4() { string Arg0 = "3"; string Arr1[] = { "NONE",  "NONE" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(4, Arg1, decode(Arg0)); }
	void test_case_5() { string Arg0 = "12221112222221112221111111112221111"; string Arr1[] = { "01101001101101001101001001001101001",  "10110010110110010110010010010110010" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(5, Arg1, decode(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
        BinaryCode ___test;
        ___test.run_test(-1);
        return 0;
}
// END CUT HERE
