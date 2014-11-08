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
#define rep(i,n) for(int (i) = 0; (i) < (int)(n); (i)++)
#define foreach(it, v) for (__typeof((v).end()) it = (v).begin(); it != (v).end(); it++)
#define clr(a, x) memset(a, x, sizeof(a))
#define iter(v) __typeof((v).end())
#define all(v) (v).begin(), (v).end()
using namespace std;
const int Mod = 1000000007;

void add(int &t, int x) {
    t += x;
    if (t >= Mod) t -= Mod;
}

typedef long long ll;
class TaroCheckers { 
    public: 
    int getNumber(vector <int> a, vector <int> b, int m)  { 
        int n = a.size();
        static int lc[205], rc[205], em[205];
        static int f[205][55][55];
        static int C[205][205];
        static int fac[205];
        clr(C, 0);
        fac[0] = 1;
        rep (i, 203) fac[i + 1] = fac[i] * (ll)(i + 1) % Mod;
        rep (i, 203) rep (j, i + 1)
            C[i][j] = (!i || !j) ? 1 : (C[i - 1][j - 1] + C[i - 1][j]) % Mod;
        clr(lc, 0);
        clr(rc, 0);
        clr(em, 0);
        rep (i, n) {
            lc[a[i] - 1]++;
            rc[m - b[i]]++;
            for (int j = a[i]; j < m - b[i]; j++)
                em[j]++;
        }
        clr(f, 0);
        f[0][0][0] = 1;
        rep (i, m) rep (j, 51) rep (k, 51) {
            if (!f[i][j][k]) continue;
            //printf("f[%d][%d][%d] = %d\n", i, j, k, f[i][j][k]);
            //give left
            if (j + 1 - lc[i] >= 0)
                add(f[i + 1][j + 1 - lc[i]][k + rc[i]], f[i][j][k] * (ll)C[j + 1][lc[i]] % Mod * fac[lc[i]] % Mod);
            //give right
            if (k - 1 + rc[i] >= 0 && j - lc[i] >= 0)
                add(f[i + 1][j - lc[i]][k - 1 + rc[i]], f[i][j][k] * (ll)C[j][lc[i]] % Mod * fac[lc[i]] % Mod * (k + rc[i]) % Mod);
            //empty
            if (j - lc[i] >= 0)
                add(f[i + 1][j - lc[i]][k + rc[i]], f[i][j][k] * (ll)C[j][lc[i]] % Mod * fac[lc[i]] % Mod * (em[i] + 1) % Mod);
        }
        return f[m][0][0];
    } 
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 4; int Arg3 = 1; verify_case(0, Arg3, getNumber(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {1, 4, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2, 3, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 7; int Arg3 = 6; verify_case(1, Arg3, getNumber(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {4, 7, 4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {7, 4, 7}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 11; int Arg3 = 5760; verify_case(2, Arg3, getNumber(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {10, 25, 100, 74}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {100, 47, 27, 100}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 200; int Arg3 = 796178974; verify_case(3, Arg3, getNumber(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arr0[] = {21, 99, 87, 12, 138, 16, 78, 36, 98, 40, 57, 10, 61, 100, 8, 110, 96, 9, 69, 110, 14, 71}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {83, 8, 25, 169, 1, 89, 109, 89, 19, 112, 39, 112, 87, 66, 116, 16, 41, 97, 52, 70, 111, 23}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 190; int Arg3 = 235017573; verify_case(4, Arg3, getNumber(Arg0, Arg1, Arg2)); }
	void test_case_5() { int Arr0[] = {3, 37, 26, 50, 8, 3, 38, 15, 58, 47, 35, 8, 27, 22, 5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {19, 26, 62, 15, 84, 13, 6, 46, 22, 53, 23, 8, 29, 55, 6}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 102; int Arg3 = 528024858; verify_case(5, Arg3, getNumber(Arg0, Arg1, Arg2)); }

// END CUT HERE
 
}; 
 
    // BEGIN CUT HERE 
int main() {
    TaroCheckers ___test; 
    ___test.run_test(-1); 
} 
    // END CUT HERE 
