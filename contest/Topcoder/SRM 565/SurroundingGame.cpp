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

#define REP(I, N) for (int I=0;I<int(N);++I)
#define FOR(I, A, B) for (int I=int(A);I<int(B);++I)
#define DWN(I, B, A) for (int I=int(B-1);I>=int(A);--I)
#define ECH(it, A) for (typeof(A.begin()) it=A.begin(); it != A.end(); ++it)

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

const int N = 50;


class SurroundingGame {
public:
	int maxScore(vector <string> cost, vector <string> benefit) {	
		

		



		int res = 0;

		
		return res;
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
			string cost[]             = {"21","12"};
			string benefit[]          = {"21","12"};
			int expected__            = 4;

			clock_t start__           = clock();
			int received__            = SurroundingGame().maxScore(vector <string>(cost, cost + (sizeof cost / sizeof cost[0])), vector <string>(benefit, benefit + (sizeof benefit / sizeof benefit[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			string cost[]             = {"ZZ","ZZ"};
			string benefit[]          = {"11","11"};
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = SurroundingGame().maxScore(vector <string>(cost, cost + (sizeof cost / sizeof cost[0])), vector <string>(benefit, benefit + (sizeof benefit / sizeof benefit[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			string cost[]             = {"XXX","XXX","XXX"};
			string benefit[]          = {"aaa","aZa","aaa"};
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = SurroundingGame().maxScore(vector <string>(cost, cost + (sizeof cost / sizeof cost[0])), vector <string>(benefit, benefit + (sizeof benefit / sizeof benefit[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			string cost[]             = {"asam","atik"};
			string benefit[]          = {"123A","45BC"};
			int expected__            = 71;

			clock_t start__           = clock();
			int received__            = SurroundingGame().maxScore(vector <string>(cost, cost + (sizeof cost / sizeof cost[0])), vector <string>(benefit, benefit + (sizeof benefit / sizeof benefit[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 4: {
			string cost[]             = {"IIIIIIII",
 "IIWWWWII",
 "IIWIIIII",
 "IIWIIIII",
 "IIWWWWII",
 "IIIIIWII",
 "IIIIIWII",
 "IIWWWWII",
 "IIIIIIII"}
;
			string benefit[]          = {"IIIIIIII",
 "II0000II",
 "II0II0II",
 "II0II0II",
 "II0000II",
 "II0II0II",
 "II0II0II",
 "II0000II",
 "IIIIIIII"}
;
			int expected__            = 606;

			clock_t start__           = clock();
			int received__            = SurroundingGame().maxScore(vector <string>(cost, cost + (sizeof cost / sizeof cost[0])), vector <string>(benefit, benefit + (sizeof benefit / sizeof benefit[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			string cost[]             = ;
			string benefit[]          = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = SurroundingGame().maxScore(vector <string>(cost, cost + (sizeof cost / sizeof cost[0])), vector <string>(benefit, benefit + (sizeof benefit / sizeof benefit[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string cost[]             = ;
			string benefit[]          = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = SurroundingGame().maxScore(vector <string>(cost, cost + (sizeof cost / sizeof cost[0])), vector <string>(benefit, benefit + (sizeof benefit / sizeof benefit[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string cost[]             = ;
			string benefit[]          = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = SurroundingGame().maxScore(vector <string>(cost, cost + (sizeof cost / sizeof cost[0])), vector <string>(benefit, benefit + (sizeof benefit / sizeof benefit[0])));
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
