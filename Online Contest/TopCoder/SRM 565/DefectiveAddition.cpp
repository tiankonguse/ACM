/* &*#()&*#)&E*F& */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <cmath>
#include <algorithm>
#include <sstream>
#include <string>
#include <vector>
#include <map>

using namespace std;

#define REP(i, n) for (int i=0;i<int(n);++i)
#define FOR(i, a, b) for (int i=int(a);i<int(b);++i)
#define DWN(i, b, a) for (int i=int(b-1);i>=int(a);--i)
#define REP_1(i, n) for (int i=1;i<=int(n);++i)
#define FOR_1(i, a, b) for (int i=int(a);i<=int(b);++i)
#define DWN_1(i, b, a) for (int i=int(b);i>=int(a);--i)
#define REP_C(i, n) for (int n____=int(n),i=0;i<n____;++i)
#define FOR_C(i, a, b) for (int b____=int(b),i=a;i<b____;++i)
#define DWN_C(i, b, a) for (int a____=int(a),i=b-1;i>=a____;--i)
#define REP_N(i, n) for (i=0;i<int(n);++i)
#define FOR_N(i, a, b) for (i=int(a);i<int(b);++i)
#define DWN_N(i, b, a) for (i=int(b-1);i>=int(a);--i)
#define REP_1_C(i, n) for (int n____=int(n),i=1;i<=n____;++i)
#define FOR_1_C(i, a, b) for (int b____=int(b),i=a;i<=b____;++i)
#define DWN_1_C(i, b, a) for (int a____=int(a),i=b;i>=a____;--i)
#define REP_1_N(i, n) for (i=1;i<=int(n);++i)
#define FOR_1_N(i, a, b) for (i=int(a);i<=int(b);++i)
#define DWN_1_N(i, b, a) for (i=int(b);i>=int(a);--i)
#define REP_C_N(i, n) for (int n____=(i=0,int(n));i<n____;++i)
#define FOR_C_N(i, a, b) for (int b____=(i=0,int(b);i<b____;++i)
#define DWN_C_N(i, b, a) for (int a____=(i=b-1,int(a));i>=a____;--i)
#define REP_1_C_N(i, n) for (int n____=(i=1,int(n));i<=n____;++i)
#define FOR_1_C_N(i, a, b) for (int b____=(i=1,int(b);i<=b____;++i)
#define DWN_1_C_N(i, b, a) for (int a____=(i=b,int(a));i>=a____;--i)

#define ALL(A) A.begin(), A.end()
#define CLR(A) A.clear()
#define CPY(A, B) memcpy(A, B, sizeof(A))
#define INS(A, P, B) A.insert(A.begin() + P, B)
#define ERS(A, P) A.erase(A.begin() + P)
#define SRT(A) sort(ALL(A))
#define SZ(A) int(A.size())
#define PB push_back
#define MP(A, B) make_pair(A, B)

typedef long long LL;
typedef double DB;

template<class T> inline void RST(T &A){memset(A, 0, sizeof(A));}
template<class T> inline void FLC(T &A, int x){memset(A, x, sizeof(A));}

template<class T> inline void checkMin(T &a, T b){if (b<a) a=b;}
template<class T> inline void checkMax(T &a, T b){if (b>a) a=b;}

/* -&$&#*( &#*@)^$@&*)*/

const int MOD = 1000000007;
const int INF = 0x7fffffff;

const int N = 59;

typedef long long LL;

int result, ope[N], xorv[N][N]; bool valid[N];
int dp[N][N][2];
struct DefectiveAddition{
	int count(vector <int> cards, int k){
		result = k;
		int n = SZ(cards);
		for (int i = 1; i <= n; i++) ope[i] = cards[i - 1], ++ope[i];
		        for (int i = 0; i < 31; i++) xorv[0][i] = 0;

        REP_1(i, n) REP(j, 31)
            xorv[i][j] = xorv[i - 1][j] ^ (ope[i] & (1 << j));
        valid[31] = true;

        DWN_1(i, 30, 0) valid[i] = valid[i + 1] && (xorv[n][i] == (result & (1 << i)));
        RST(dp), dp[0][0][0] = 1;

        REP_1(i, n) REP(j, 31) REP(s, 2){
            if (dp[i - 1][j][s] == 0) continue;
            REP(k, 31) if (ope[i] & (1 << k)){
                int free, tj, ts;
                if (k > j) free = j, tj = k, ts = (xorv[i - 1][k] ? 1 : 0);
                else
                {
                    int tm = (k == j ? 0 : ope[i] & (1 << j));
                    free = k, tj = j, ts = s ^ (tm ? 1 : 0);
                }
                dp[i][tj][ts] = ((LL)dp[i - 1][j][s] * (1 << free) + dp[i][tj][ts]) % MOD;
            }
        }

        int ans = 0;
        for (int i = 30; i >= 0; i--)
        {
            if (valid[i + 1]) ans = (ans + dp[n][i][(result & (1 << i)) ? 1 : 0]) % MOD;
            else break;
        }
        return ans;
	}
};

// BEGIN CUT HERE
namespace moj_harness {
	int run_test_case(int);
	void run_test(int casenum = -1, bool quiet = false) {
		if (casenum != -1) {
			if (run_test_case(casenum) == -1 && !quiet) {
				cerr << "Illegal input! Test case " << casenum << " does not exist." << endl;
			}
			return;
		}

		int correct = 0, total = 0;
		for (int i=0;; ++i) {
			int x = run_test_case(i);
			if (x == -1) {
				if (i >= 100) break;
				continue;
			}
			correct += x;
			++total;
		}

		if (total == 0) {
			cerr << "No test cases run." << endl;
		} else if (correct < total) {
			cerr << "Some cases FAILED (passed " << correct << " of " << total << ")." << endl;
		} else {
			cerr << "All " << total << " tests passed!" << endl;
		}
	}

	int verify_case(int casenum, const int &expected, const int &received, clock_t elapsed) {
		cerr << "Example " << casenum << "... ";

		string verdict;
		vector<string> info;
		char buf[100];

		if (elapsed > CLOCKS_PER_SEC / 200) {
			sprintf(buf, "time %.2fs", elapsed * (1.0/CLOCKS_PER_SEC));
			info.push_back(buf);
		}

		if (expected == received) {
			verdict = "PASSED";
		} else {
			verdict = "FAILED";
		}

		cerr << verdict;
		if (!info.empty()) {
			cerr << " (";
			for (int i=0; i<(int)info.size(); ++i) {
				if (i > 0) cerr << ", ";
				cerr << info[i];
			}
			cerr << ")";
		}
		cerr << endl;

		if (verdict == "FAILED") {
			cerr << "    Expected: " << expected << endl;
			cerr << "    Received: " << received << endl;
		}

		return verdict == "PASSED";
	}

	int run_test_case(int casenum) {
		switch (casenum) {
		case 0: {
			int cards[]               = {2,3};
			int n                     = 2;
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = DefectiveAddition().count(vector <int>(cards, cards + (sizeof cards / sizeof cards[0])), n);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			int cards[]               = {1,2,3};
			int n                     = 1;
			int expected__            = 6;

			clock_t start__           = clock();
			int received__            = DefectiveAddition().count(vector <int>(cards, cards + (sizeof cards / sizeof cards[0])), n);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			int cards[]               = {4, 5, 7, 11};
			int n                     = 6;
			int expected__            = 240;

			clock_t start__           = clock();
			int received__            = DefectiveAddition().count(vector <int>(cards, cards + (sizeof cards / sizeof cards[0])), n);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			int cards[]               = {1,2,3,4,5,6,7,8,9,10};
			int n                     = 15;
			int expected__            = 1965600;

			clock_t start__           = clock();
			int received__            = DefectiveAddition().count(vector <int>(cards, cards + (sizeof cards / sizeof cards[0])), n);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 4: {
			int cards[]               = {1,2,3,4,5,6,7,8,9,10};
			int n                     = 16;
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = DefectiveAddition().count(vector <int>(cards, cards + (sizeof cards / sizeof cards[0])), n);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 5: {
			int cards[]               = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
			int n                     = 1;
			int expected__            = 949480669;

			clock_t start__           = clock();
			int received__            = DefectiveAddition().count(vector <int>(cards, cards + (sizeof cards / sizeof cards[0])), n);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			int cards[]               = ;
			int n                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = DefectiveAddition().count(vector <int>(cards, cards + (sizeof cards / sizeof cards[0])), n);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int cards[]               = ;
			int n                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = DefectiveAddition().count(vector <int>(cards, cards + (sizeof cards / sizeof cards[0])), n);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			int cards[]               = ;
			int n                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = DefectiveAddition().count(vector <int>(cards, cards + (sizeof cards / sizeof cards[0])), n);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
		default:
			return -1;
		}
	}
}

int main(int argc, char *argv[]) {
	if (argc == 1) {
		moj_harness::run_test();
	} else {
		for (int i=1; i<argc; ++i)
			moj_harness::run_test(atoi(argv[i]));
	}
}
// END CUT HERE
