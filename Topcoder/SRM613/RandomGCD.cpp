// BEGIN CUT HERE

// END CUT HERE
#line 5 "RandomGCD.cpp"
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

LL Q = 1e9 + 7;
LL f[100005];

LL power(LL a , LL b) {
    LL ans = 1;
    while (b) {
        if (b & 1)
            ans *= a , ans %= Q;
        a *= a , a %= Q , b >>= 1;
    }
    return ans;
}
class RandomGCD
{
        public:
        int countTuples(int N, int K, int low, int high)
        {
            vector<int> a;
            int i , j , k;
            memset(f , 0 , sizeof(f));
            for (i = low ; i <= high ; ++ i)
                if (i % K == 0)
                    a.push_back(i / K);
            if (!a.size()) return 0;
            int R = a[a.size() - 1] , L = a[0];
            //cout << P << endl;
            for (i = 100000 ; i >= 1 ; -- i) {
                LL x = R / i - (L - 1) / i;
                f[i] += power(x , N);
                for (j = i + i ; j <= 100000 ; j += i)
                    f[i] += Q - f[j] , f[i] %= Q;
                j = max(L , 100001);
                if (j > R) continue;
                k = j / i * i;
                while (k < j) k += i;
                for (j = k ; j <= R ; j += i)
                    f[i] += Q - 1 , f[i] %= Q;
            }
            return f[1];
        }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 5; int Arg2 = 500001; int Arg3 = 500006; int Arg4 = 3; verify_case(0, Arg4, countTuples(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 100; int Arg2 = 2; int Arg3 = 4; int Arg4 = 0; verify_case(1, Arg4, countTuples(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 1; int Arg1 = 5; int Arg2 = 5; int Arg3 = 5; int Arg4 = 1; verify_case(2, Arg4, countTuples(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 73824; int Arg1 = 17347; int Arg2 = 9293482; int Arg3 = 9313482; int Arg4 = 0; verify_case(3, Arg4, countTuples(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arg0 = 222; int Arg1 = 222; int Arg2 = 222; int Arg3 = 22222; int Arg4 = 339886855; verify_case(4, Arg4, countTuples(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    //cout << countTuples(2 , 2 , 2 , 4) << endl;
        RandomGCD ___test;
        ___test.run_test(-1);
        return 0;
}
// END CUT HERE
