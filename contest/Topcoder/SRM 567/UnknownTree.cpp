/** Template for TC ., Last Update: Dec. 24th 2012 **/ //{

#include <functional>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <numeric>
#include <cstring>
#include <cassert>
#include <cstdio>
#include <string>
#include <vector>
#include <bitset>
#include <queue>
#include <stack>
#include <cmath>
#include <ctime>
#include <list>
#include <set>
#include <map>

using namespace std;

#define REP(I, N) for (int I=0;I<int(N);++I)
#define FOR(I, A, B) for (int I=int(A);I<int(B);++I)
#define DWN(I, B, A) for (int I=int(B-1);I>=int(A);--I)
#define ECH(it, A) for (typeof(A.begin()) it=A.begin(); it != A.end(); ++it)

#define ALL(A) A.begin(), A.end()
#define LLA(A) A.rbegin(), A.rend()
#define CPY(A, B) memcpy(A, B, sizeof(A))
#define INS(A, P, B) A.insert(A.begin() + P, B)
#define ERS(A, P) A.erase(A.begin() + P)
#define BSC(A, x) (lower_bound(ALL(A), x) - A.begin())
#define CTN(T, x) (T.find(x) != T.end())
#define SZ(A) int(A.size())
#define PB push_back
#define MP(A, B) make_pair(A, B)

#define fi first
#define se second

typedef long long LL;
typedef double DB;

template<class T> inline void RST(T &A){memset(A, 0, sizeof(A));}
template<class T> inline void FLC(T &A, int x){memset(A, x, sizeof(A));}
template<class T> inline void CLR(T &A){A.clear();}

template<class T> inline T& SRT(T &A){sort(ALL(A)); return A;}
template<class T, class C> inline T& SRT(T &A, C B){sort(ALL(A), B); return A;}
template<class T> inline T& UNQ(T &A){A.resize(unique(ALL(SRT(A)))-A.begin());return A;}

template<class T> inline void checkMin(T &a, T b){if (b<a) a=b;}
template<class T> inline void checkMax(T &a, T b){if (b>a) a=b;}

const int MOD = int(1e9 + 7);
const int INF = 0x7fffffff;

//}/* .................................................................................................................................. */

const int N = 50;

class UnknownTree {
public:
	int getCount(vector <int> distancesA, vector <int> distancesB, vector <int> distancesC) {	
		
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
			int distancesA[]          = {1};
			int distancesB[]          = {2};
			int distancesC[]          = {3};
			int expected__            = 6;

			clock_t start__           = clock();
			int received__            = UnknownTree().getCount(vector <int>(distancesA, distancesA + (sizeof distancesA / sizeof distancesA[0])), vector <int>(distancesB, distancesB + (sizeof distancesB / sizeof distancesB[0])), vector <int>(distancesC, distancesC + (sizeof distancesC / sizeof distancesC[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			int distancesA[]          = {1, 2};
			int distancesB[]          = {1, 2};
			int distancesC[]          = {1, 2};
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = UnknownTree().getCount(vector <int>(distancesA, distancesA + (sizeof distancesA / sizeof distancesA[0])), vector <int>(distancesB, distancesB + (sizeof distancesB / sizeof distancesB[0])), vector <int>(distancesC, distancesC + (sizeof distancesC / sizeof distancesC[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			int distancesA[]          = {5, 4};
			int distancesB[]          = {3, 2};
			int distancesC[]          = {2, 1};
			int expected__            = 8;

			clock_t start__           = clock();
			int received__            = UnknownTree().getCount(vector <int>(distancesA, distancesA + (sizeof distancesA / sizeof distancesA[0])), vector <int>(distancesB, distancesB + (sizeof distancesB / sizeof distancesB[0])), vector <int>(distancesC, distancesC + (sizeof distancesC / sizeof distancesC[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			int distancesA[]          = {2, 4, 2};
			int distancesB[]          = {1, 3, 3};
			int distancesC[]          = {4, 6, 4};
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = UnknownTree().getCount(vector <int>(distancesA, distancesA + (sizeof distancesA / sizeof distancesA[0])), vector <int>(distancesB, distancesB + (sizeof distancesB / sizeof distancesB[0])), vector <int>(distancesC, distancesC + (sizeof distancesC / sizeof distancesC[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 4: {
			int distancesA[]          = {4, 6, 1, 5, 3, 2, 5};
			int distancesB[]          = {4, 2, 3, 1, 3, 2, 1};
			int distancesC[]          = {5, 7, 2, 6, 4, 3, 6};
			int expected__            = 12;

			clock_t start__           = clock();
			int received__            = UnknownTree().getCount(vector <int>(distancesA, distancesA + (sizeof distancesA / sizeof distancesA[0])), vector <int>(distancesB, distancesB + (sizeof distancesB / sizeof distancesB[0])), vector <int>(distancesC, distancesC + (sizeof distancesC / sizeof distancesC[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 5: {
			int distancesA[]          = {6, 4, 5, 6, 8, 1, 5, 6, 4, 2};
			int distancesB[]          = {4, 2, 3, 4, 6, 1, 3, 4, 2, 2};
			int distancesC[]          = {6, 4, 5, 6, 8, 3, 5, 6, 4, 4};
			int expected__            = 9000;

			clock_t start__           = clock();
			int received__            = UnknownTree().getCount(vector <int>(distancesA, distancesA + (sizeof distancesA / sizeof distancesA[0])), vector <int>(distancesB, distancesB + (sizeof distancesB / sizeof distancesB[0])), vector <int>(distancesC, distancesC + (sizeof distancesC / sizeof distancesC[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 6: {
			int distancesA[]          = {8, 5, 6, 8, 6, 5, 6, 10, 8, 5, 10, 8, 7, 9, 7, 1, 11, 5, 9, 6, 6, 1, 6, 9, 8, 4, 12, 7, 5, 7, 6, 8, 12, 8, 6, 6, 5, 8, 5, 3, 3, 4, 8, 6, 6, 8, 8, 9, 7, 5};
			int distancesB[]          = {9, 6, 7, 9, 7, 6, 7, 11, 9, 6, 11, 9, 8, 10, 8, 2, 12, 6, 10, 7, 7, 4, 7, 10, 9, 5, 13, 8, 6, 8, 7, 9, 13, 9, 7, 7, 6, 9, 6, 4, 4, 5, 9, 7, 7, 9, 9, 10, 8, 6};
			int distancesC[]          = {8, 9, 6, 8, 2, 5, 6, 10, 8, 5, 10, 8, 7, 9, 1, 5, 11, 5, 9, 6, 6, 7, 6, 9, 8, 4, 12, 7, 5, 7, 6, 8, 12, 8, 6, 6, 5, 8, 1, 7, 3, 4, 8, 6, 6, 8, 8, 3, 7, 5};
			int expected__            = 770724166;

			clock_t start__           = clock();
			int received__            = UnknownTree().getCount(vector <int>(distancesA, distancesA + (sizeof distancesA / sizeof distancesA[0])), vector <int>(distancesB, distancesB + (sizeof distancesB / sizeof distancesB[0])), vector <int>(distancesC, distancesC + (sizeof distancesC / sizeof distancesC[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 7: {
			int distancesA[]          = {33030780, 30296205, 16842859, 28857842, 37928939, 27190807, 48689043, 33328845, 24254103, 3962046, 31043603, 25699520, 11297547, 27045586, 31603483, 23207518, 44089781, 48470539, 52366295, 39786470, 45623279, 21593844, 38639305, 27260993, 43899542, 36162768, 21640232, 43580853, 33826577, 30501815, 51470990, 2157904, 27823597, 9550575, 39234641, 24163007, 34155133, 42504989, 35821444, 36054200, 29026389, 29716374, 41764139, 19392309, 44258194, 19987908, 56722905, 46771885, 32668277, 40665175};
			int distancesB[]          = {16191697, 13457122, 3776, 12018759, 21089856, 10351724, 31849960, 16489762, 7415020, 12877037, 14204520, 8860437, 9035480, 10206503, 14764400, 6368435, 27250698, 31631456, 35527212, 22947387, 28784196, 4754761, 21800222, 10421910, 27060459, 19323685, 4801149, 26741770, 16987494, 13662732, 34631907, 18996987, 10984514, 7288508, 22395558, 7323924, 17316050, 25665906, 18982361, 19215117, 12187306, 12877291, 24925056, 2553226, 27419111, 3148825, 39883822, 29932802, 15829194, 23826092};
			int distancesC[]          = {19337227, 16602652, 3149306, 15164289, 24235386, 13497254, 34995490, 19635292, 10560550, 16030119, 17350050, 12005967, 12188562, 13352033, 17909930, 3215353, 30396228, 34776986, 38672742, 26092917, 31929726, 7907843, 24945752, 13567440, 30205989, 22469215, 7946679, 29887300, 20133024, 16808262, 37777437, 22150069, 14130044, 10441590, 25541088, 10469454, 20461580, 28811436, 22127891, 22360647, 15332836, 16022821, 28070586, 5706308, 30564641, 6294355, 43029352, 33078332, 18974724, 26971622};
			int expected__            = 101733071;

			clock_t start__           = clock();
			int received__            = UnknownTree().getCount(vector <int>(distancesA, distancesA + (sizeof distancesA / sizeof distancesA[0])), vector <int>(distancesB, distancesB + (sizeof distancesB / sizeof distancesB[0])), vector <int>(distancesC, distancesC + (sizeof distancesC / sizeof distancesC[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 8: {
			int distancesA[]          = ;
			int distancesB[]          = ;
			int distancesC[]          = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = UnknownTree().getCount(vector <int>(distancesA, distancesA + (sizeof distancesA / sizeof distancesA[0])), vector <int>(distancesB, distancesB + (sizeof distancesB / sizeof distancesB[0])), vector <int>(distancesC, distancesC + (sizeof distancesC / sizeof distancesC[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 9: {
			int distancesA[]          = ;
			int distancesB[]          = ;
			int distancesC[]          = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = UnknownTree().getCount(vector <int>(distancesA, distancesA + (sizeof distancesA / sizeof distancesA[0])), vector <int>(distancesB, distancesB + (sizeof distancesB / sizeof distancesB[0])), vector <int>(distancesC, distancesC + (sizeof distancesC / sizeof distancesC[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 10: {
			int distancesA[]          = ;
			int distancesB[]          = ;
			int distancesC[]          = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = UnknownTree().getCount(vector <int>(distancesA, distancesA + (sizeof distancesA / sizeof distancesA[0])), vector <int>(distancesB, distancesB + (sizeof distancesB / sizeof distancesB[0])), vector <int>(distancesC, distancesC + (sizeof distancesC / sizeof distancesC[0])));
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
