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
const int N = 2505;
const int M = 22500;
const int INF = 1 << 20;
int n;
int _f[(M + 5) * 2], *f = _f + M + 5;
string S, T;

void checkmin(int &t, int x) {
    if (x < t) t = x;
}

int fix(int x) {
    return ((x % 10) + 10) % 10;
}

class CombinationLockDiv1 { 
    public: 
    int minimumMoves(vector <string> P, vector <string> Q)  { 
        S = T = "";
        foreach (it, P) S += *it;
        foreach (it, Q) T += *it;
        n = S.size();
        for (int i = -M; i <= M; i++) f[i] = INF;
        f[0] = 0;
        rep (i, n) {
            for (int j = M - 1; j >= 0; j--)
                checkmin(f[j], f[j + 1]);
            for (int j = -M + 1; j <= 0; j++)
                checkmin(f[j], f[j - 1]);
            for (int j = 0; j < M; j++)
                checkmin(f[j + 1], f[j] + 1);
            for (int j = 0; j > -M; j--)
                checkmin(f[j - 1], f[j] + 1);
            int cnt = fix(T[i] - S[i] - M);
            for (int j = M; j >= -M; j--) {
                if (cnt) f[j] = INF;
                cnt++;
                if (cnt == 10) cnt = 0;
            }
        }
        int ans = 1 << 30;
        for (int j = -M; j <= M; j++)
            checkmin(ans, f[j]);
        return ans;
    } 
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"123"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"112"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; verify_case(0, Arg2, minimumMoves(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"7"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 4; verify_case(1, Arg2, minimumMoves(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"6","07"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"","60","7"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(2, Arg2, minimumMoves(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"1234"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"4567"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; verify_case(3, Arg2, minimumMoves(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"020"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"909"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; verify_case(4, Arg2, minimumMoves(Arg0, Arg1)); }
	void test_case_5() { string Arr0[] = {"4423232218340"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"6290421476245"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 18; verify_case(5, Arg2, minimumMoves(Arg0, Arg1)); }

// END CUT HERE
 
}; 
 
    // BEGIN CUT HERE 
int main() {
    CombinationLockDiv1 ___test; 
    ___test.run_test(-1); 
} 
    // END CUT HERE 
