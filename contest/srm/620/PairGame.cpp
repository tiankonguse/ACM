#include <cstdio>
#include <cstring>
#include <cctype>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <iostream>
#include <map>
#include <set>
#include <list>
#include <sstream>
#include <queue>
#include <deque>
#include <stack>
#include <vector>
#include <bitset>
#include <algorithm>
using namespace std;
#define foreach(it, v) for (__typeof((v).end()) it = (v).begin(); it != (v).end(); it++)
#define clr(a, x) memset(a, x, sizeof(a))
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define iter(v) __typeof((v).end())
#define all(v) (v).begin(), (v).end()
typedef long long ll;
typedef pair <int, int> PII;
typedef vector <int> VI;

void gao(set <PII> &s, int x, int y) {
    while (1) {
        if (x == 0 || y == 0) break;
        s.insert(PII(x, y));
        if (x > y) {
            x -= y;
        } else {
            y -= x;
        }
    }
}

class PairGame { 
    public: 
    int maxSum(int a, int b, int c, int d)  { 
        set <PII> sa, sb;
        gao(sa, a, b);
        gao(sb, c, d);
        int ans = -1;
        foreach (it, sa) {
            if (sb.count(*it)) {
                if (it->first + it->second > ans) {
                    ans = it->first + it->second;
                    //printf("%d %d\n", it->first, it->second);
                }
            }
        }
        return ans;
    } 
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 2; int Arg2 = 2; int Arg3 = 1; int Arg4 = 2; verify_case(0, Arg4, maxSum(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 15; int Arg1 = 4; int Arg2 = 10; int Arg3 = 7; int Arg4 = 7; verify_case(1, Arg4, maxSum(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 1; int Arg1 = 1; int Arg2 = 10; int Arg3 = 10; int Arg4 = -1; verify_case(2, Arg4, maxSum(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 1000; int Arg1 = 1001; int Arg2 = 2000; int Arg3 = 2001; int Arg4 = 1001; verify_case(3, Arg4, maxSum(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arg0 = 10944; int Arg1 = 17928; int Arg2 = 7704; int Arg3 = 21888; int Arg4 = 144; verify_case(4, Arg4, maxSum(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_5() { int Arg0 = 1; int Arg1 = 1; int Arg2 = 1; int Arg3 = 1; int Arg4 = 2; verify_case(5, Arg4, maxSum(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE
 
}; 
 
    // BEGIN CUT HERE 
int main() {
    PairGame ___test; 
    ___test.run_test(-1); 
} 
    // END CUT HERE 
