// BEGIN CUT HERE

// END CUT HERE
#line 5 "WinterAndSnowmen.cpp"
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <queue>
#include <stack>
#include <map>
#include <set>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

#define N 2005
int f[2][1 << 11][2] , Q = 1e9 + 7;
class WinterAndSnowmen
{
        public:
        int getNumber(int n , int m)
        {
            int i , j , k , lb , ans = 0;

            for (lb = 0 ; lb < 11 ; ++ lb)
            {
                memset(f[0] , 0 , sizeof(f[0]));
                f[0][0][0] = 1;
                int cur = 0 , nxt = 1;
                for (k = 1 ; k <= max(n , m) ; ++ k)
                {
                    memset(f[nxt] , 0 , sizeof(f[nxt]));
                    for (i = 0 ; i < 1 << 11 ; ++ i)
                        for (j = 0 ; j < 2 ; ++ j)
                            if (f[cur][i][j])
                            {
                                //printf("%d %d %d : %d\n" , k - 1 , i , j , f[k - 1][i][j]);
                                int x = f[cur][i][j];
                                f[nxt][i][j] += x , f[nxt][i][j] %= Q;
                                if (k <= n)
                                    f[nxt][i ^ (k >> lb)][j ^ (k >> lb & 1)] += x , f[nxt][i ^ (k >> lb)][j ^ (k >> lb & 1)] %= Q;
                                if (k <= m)
                                    f[nxt][i ^ (k >> lb)][j] += x , f[nxt][i ^ (k >> lb)][j] %= Q;
                            }
                    swap(cur , nxt);
                }
                //printf("%d %d\n" , lb , f[cur][1][0]);
                ans += f[cur][1][0] , ans %= Q;
            }
            return ans;
        }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 2; int Arg2 = 4; verify_case(0, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 1; int Arg1 = 1; int Arg2 = 1; verify_case(1, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 3; int Arg1 = 5; int Arg2 = 74; verify_case(2, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 7; int Arg1 = 4; int Arg2 = 216; verify_case(3, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 47; int Arg1 = 74; int Arg2 = 962557390; verify_case(4, Arg2, getNumber(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
        WinterAndSnowmen ___test;
        ___test.run_test(-1);
        return 0;
}
// END CUT HERE
