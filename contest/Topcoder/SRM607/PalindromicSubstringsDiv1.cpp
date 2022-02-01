// BEGIN CUT HERE

// END CUT HERE
#line 5 "PalindromicSubstringsDiv1.cpp"
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
#include <string>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define N 5005
char s[N];
string tmp;

class PalindromicSubstringsDiv1
{
        public:
        double expectedPalindromes(vector <string> S1, vector <string> S2)
        {
            int i , j , k , n;
            tmp = "" , memset(s , 0 , sizeof(s));
            for (i = 0 ; i < S1.size() ; ++ i)
                tmp += S1[i];
            for (i = 0 ; i < S2.size() ; ++ i)
                tmp += S2[i];
            //cerr << tmp << endl;
            n = tmp.size();
            for (i = 0 ; i < n ; ++ i)
                s[i] = tmp[i];
            double ans = 0 , C = 1.0 / 26;

            for (j = 0 ; j < n ; ++ j)
            {
                double p = 1;
                for (i = 0 ; i + j < n && j - i >= 0 ; ++ i)
                {
                    int x = j - i , y = j + i;
                    if (s[x] != '?' && s[y] != '?' && s[x] != s[y]) break;
                    if (s[x] != '?' && s[x] == s[y])
                        p = p;
                    else if ((s[x] == '?') ^ (s[y] == '?'))
                        p *= C;
                    else if (s[x] == '?' && s[x] == s[y])
                    {
                        if (i == 0)
                            p = p;
                        else
                            p *= C;
                    }
                    ans += p;
                }
            }
            for (j = 0 ; j < n ; ++ j)
            {
                double p = 1;
                for (i = 0 ; i + j + 1 < n && j - i >= 0 ; ++ i)
                {
                    int x = j - i , y = j + i + 1;
                    if (s[x] != '?' && s[y] != '?' && s[x] != s[y]) break;
                    if (s[x] != '?' && s[x] == s[y])
                        p = p;
                    else if ((s[x] == '?') ^ (s[y] == '?'))
                        p *= C;
                    else if (s[x] == '?' && s[x] == s[y])
                    {
                            p *= C;
                    }
                    ans += p;
                }
            }

            return ans;
        }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"a","a",""}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"a"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 6.0; verify_case(0, Arg2, expectedPalindromes(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"z??"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 3.115384615384615; verify_case(1, Arg2, expectedPalindromes(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"ab","c"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"??","a?"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 7.315088757396449; verify_case(2, Arg2, expectedPalindromes(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"?"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 1.0; verify_case(3, Arg2, expectedPalindromes(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"ab?def","?"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"f??a"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 12.545971779699588; verify_case(4, Arg2, expectedPalindromes(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
        PalindromicSubstringsDiv1 ___test;
        ___test.run_test(-1);
        return 0;
}
// END CUT HERE
