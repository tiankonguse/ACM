// BEGIN CUT HERE

// END CUT HERE
#line 5 "TypoCoderDiv1.cpp"
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
int f[51][2200];
class TypoCoderDiv1
{
        public:
        int getmax(vector <int> D, int X)
        {

            int i , j , x , y , n = D.size();
            for (i = 0 ; i < 2200 ; ++ i)
                f[0][i] = -1 << 30;
            f[0][X] = 0;
            for (i = 1 ; i <= n ; ++ i)
            {
                x = D[i - 1];
                for (j = 0 ; j < 2200 ; ++ j)
                    f[i][j] = -1 << 30;
                for (j = 0 ; j < 2200 ; ++ j)
                {
                    if (j + x < 2200)
                        f[i][j + x] = max(f[i][j + x] , f[i - 1][j]);
                    f[i][max(0 , j - x)] = max(f[i][max(0 , j - x)] , f[i - 1][j]);
                }
                if (i > 1)
                {
                    for (j = 0 ; j < 2200 ; ++ j)
                    {
                        y = max(j + D[i - 2] - x  , 0);
                        if (j + D[i - 2] >= 2200 && y < 2200)
                            f[i][y] = max(f[i][y] , f[i - 2][j] + 2);
                    }
                }
            }
            int ans = -1 << 30;
            for (i = 0 ; i < 2200 ; ++ i)
                ans = max(ans , f[n][i]);
            if (D[n - 1] > 0)
                for (i = 0 ; i < 2200 ; ++ i)
                    if (i + D[n - 1] >= 2200)
                        ans = max(ans , f[n - 1][i] + 1);
            return ans;
        }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {100,200,100,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2000; int Arg2 = 3; verify_case(0, Arg2, getmax(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {0,0,0,0,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2199; int Arg2 = 0; verify_case(1, Arg2, getmax(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {90000,80000,70000,60000,50000,40000,30000,20000,10000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; int Arg2 = 1; verify_case(2, Arg2, getmax(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {1000000000,1000000000,10000,100000,2202,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1000; int Arg2 = 4; verify_case(3, Arg2, getmax(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {2048,1024,5012,256,128,64,32,16,8,4,2,1,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2199; int Arg2 = 0; verify_case(4, Arg2, getmax(Arg0, Arg1)); }
	void test_case_5() { int Arr0[] = {61,666,512,229,618,419,757,217,458,883,23,932,547,679,565,767,513,798,870,31,379,294,929,892,173,127,796,353,913,115,802,803,948,592,959,127,501,319,140,694,851,189,924,590,790,3,669,541,342,272}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1223; int Arg2 = 29; verify_case(5, Arg2, getmax(Arg0, Arg1)); }
	void test_case_6() { int Arr0[] = {34,64,43,14,58,30,2,16,90,58,35,55,46,24,14,73,96,13,9,42,64,36,89,42,42,64,52,68,53,76,52,54,23,88,32,52,28,96,70,32,26,3,23,78,47,23,54,30,86,32}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1328; int Arg2 = 20; verify_case(6, Arg2, getmax(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
        TypoCoderDiv1 ___test;
        ___test.run_test(-1);
        return 0;
}
// END CUT HERE
