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
template<class T0, class T1, class T2> inline void RST(T0 &A0, T1 &A1, T2 &A2){RST(A0), RST(A1), RST(A2);}
template<class T> inline void checkMin(T &a, T b){if (b<a) a=b;}
template<class T> inline void checkMax(T &a, T b){if (b>a) a=b;}

/* -&$&#*( &#*@)^$@&*)*/

const int MOD = 1000000007;
const int INF = 0x7fffffff;

int cnt[256], tot[256], out[256];

class FoxAndHandle {
public:
	string lexSmallestName(string s) {

	    int n = SZ(s); RST(cnt, tot, out);

	    char mm = 'z'; REP(i, n){
	        checkMin(mm, s[i]), ++tot[s[i]];
	    }

	    string res; REP(i, n){
	        ++cnt[s[i]];
	        if (out[s[i]] * 2 == tot[s[i]]) continue;

	        if (s[i] == mm){
	            res.PB(s[i]), ++out[s[i]];
	            if (out[s[i]] * 2 == tot[s[i]]){
	                a:
                    FOR_N(mm, mm+1, 'z'+1) if (out[mm] * 2 < tot[mm]) break;
                    if (mm > 'z') break;
	            }
	        }
	        else {
	            if (cnt[s[i]] * 2> tot[s[i]]){

                    FOR(c, 'a', s[i]) while (out[c] * 2 < tot[c] && cnt[c] > 2 * out[c]){

                        res.PB(c), ++out[c];
	                }

	                res.PB(s[i]), ++out[s[i]];
	            }
	        }
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

	int verify_case(int casenum, const string &expected, const string &received, clock_t elapsed) {
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
			cerr << "    Expected: \"" << expected << "\"" << endl;
			cerr << "    Received: \"" << received << "\"" << endl;
		}

		return verdict == "PASSED";
	}

	int run_test_case(int casenum) {
		switch (casenum) {
		case 0: {
			string S                  = "bkbkaajaajkkmfmfliffajaelhihlihajaeohggholihoggo";
			string expected__         = "baaaajkkfmfehhlihjgglioo";

			clock_t start__           = clock();
			string received__         = FoxAndHandle().lexSmallestName(S);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			string S                  = "ccieliel";
			string expected__         = "ceil";

			clock_t start__           = clock();
			string received__         = FoxAndHandle().lexSmallestName(S);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			string S                  = "abaabbab";
			string expected__         = "aabb";

			clock_t start__           = clock();
			string received__         = FoxAndHandle().lexSmallestName(S);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			string S                  = "bbbbaaaa";
			string expected__         = "bbaa";

			clock_t start__           = clock();
			string received__         = FoxAndHandle().lexSmallestName(S);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 4: {
			string S                  = "fedcbafedcba";
			string expected__         = "afedcb";

			clock_t start__           = clock();
			string received__         = FoxAndHandle().lexSmallestName(S);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 5: {
			string S                  = "nodevillivedon";
			string expected__         = "deilvon";

			clock_t start__           = clock();
			string received__         = FoxAndHandle().lexSmallestName(S);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			string S                  = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = FoxAndHandle().lexSmallestName(S);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string S                  = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = FoxAndHandle().lexSmallestName(S);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			string S                  = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = FoxAndHandle().lexSmallestName(S);
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
