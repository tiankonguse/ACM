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

#define ALL(A) A.begin(), A.end()
#define CLR(A) A.clear()

const int inf = 0x3f3f3f3f;
const int maxn = 60;
int F[maxn];

class Stamp {
public:
	int getMinimumCost(string S, int A, int B) {

        int n = S.size(), res = A+B*n;

        FOR(len, 2, n+1){\
            memset(F, 0x3f, sizeof(F)), F[0] = 0;
            REP(i, n-1) if (F[i] != inf){
                char c = 'N'; FOR(j, i+1, n+1){
                    if (S[j-1] != '*' && S[j-1] != c){
                        if (c == 'N') c = S[j-1];
                        else break;
                    }
                    if (j - i >= len)
                        if (F[i] + ((j - i - 1) / len) + 1 < F[j])
                            F[j] = F[i] + ((j - i - 1) / len) + 1;
                }
            }

            cout << res << " " << ( res > A*len+B*F[n]) << endl;

            if (F[n] != inf)
                if (A*len+B*F[n] < res)
                    res = A*len+B*F[n];
            //cout << F[n] << " " << inf << endl;
        }

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
			string desiredColor       = "R***";
			int stampCost             = 100;
			int pushCost              = 1;
			int expected__            = 5;

			clock_t start__           = clock();
			int received__            = Stamp().getMinimumCost(desiredColor, stampCost, pushCost);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			string desiredColor       = "R**GB*";
			int stampCost             = 1;
			int pushCost              = 1;
			int expected__            = 5;

			clock_t start__           = clock();
			int received__            = Stamp().getMinimumCost(desiredColor, stampCost, pushCost);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			string desiredColor       = "BRRB";
			int stampCost             = 2;
			int pushCost              = 7;
			int expected__            = 30;

			clock_t start__           = clock();
			int received__            = Stamp().getMinimumCost(desiredColor, stampCost, pushCost);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			string desiredColor       = "R*RR*GG";
			int stampCost             = 10;
			int pushCost              = 58;
			int expected__            = 204;

			clock_t start__           = clock();
			int received__            = Stamp().getMinimumCost(desiredColor, stampCost, pushCost);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 4: {
			string desiredColor       = "*B**B**B*BB*G*BBB**B**B*";
			int stampCost             = 5;
			int pushCost              = 2;
			int expected__            = 33;

			clock_t start__           = clock();
			int received__            = Stamp().getMinimumCost(desiredColor, stampCost, pushCost);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 5: {
			string desiredColor       = "*R*RG*G*GR*RGG*G*GGR***RR*GG";
			int stampCost             = 7;
			int pushCost              = 1;
			int expected__            = 30;

			clock_t start__           = clock();
			int received__            = Stamp().getMinimumCost(desiredColor, stampCost, pushCost);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

      case 6: {
			string desiredColor       = "****R****";
			int stampCost             = 30;
			int pushCost              = 51;
			int expected__            = 243;

			clock_t start__           = clock();
			int received__            = Stamp().getMinimumCost(desiredColor, stampCost, pushCost);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
/*      case 7: {
			string desiredColor       = ;
			int stampCost             = ;
			int pushCost              = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = Stamp().getMinimumCost(desiredColor, stampCost, pushCost);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			string desiredColor       = ;
			int stampCost             = ;
			int pushCost              = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = Stamp().getMinimumCost(desiredColor, stampCost, pushCost);
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
