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
template<class T> inline T max(T a, T b, T c){return max(max(a, b), c);}

const int MOD = int(1e9 + 7);
const int INF = 0x7fffffff;

//}/* .................................................................................................................................. */

const int N = 50;

bool a[3], b[3];

class BallsSeparating {
public:
	int minOperations(vector <int> R, vector <int> G, vector <int> B) {

	    RST(a); RST(b);

	    int n = SZ(R), s = 0;

	    REP(i, n){
	        if (R[i] == max(R[i], G[i], B[i])) a[0] = 1;
	        if (G[i] == max(R[i], G[i], B[i])) a[1] = 1;
	        if (B[i] == max(R[i], G[i], B[i])) a[2] = 1;
	        if (R[i]) b[0] = 1;
	        if (G[i]) b[1] = 1;
	        if (B[i]) b[2] = 1;
	        s += R[i] + G[i] + B[i] - max(R[i], G[i], B[i]);
	    }

	    if (int(b[0])+int(b[1])+int(b[2]) > n) return -1;

	    if (int(a[0])+int(a[1])+int(a[2]) == 2){
	    if (b[0] && !a[0]){
	        int d = INF;
	        REP(i, n){
	            checkMin(d, max(R[i], G[i], B[i]) - R[i]);
	        }
	        s += d;
	    }

	    if (b[1] && !a[1]){
	        int d = INF;
	        REP(i, n){
	            checkMin(d, max(R[i], G[i], B[i]) - G[i]);
	        }
	        s += d;
	    }

	    if (b[2] && !a[2]){
	        int d = INF;
	        REP(i, n){
	            checkMin(d, max(R[i], G[i], B[i]) - B[i]);
	        }
	        s += d;
	    }
	    }
	    else if (int(a[0])+int(a[1])+int(a[2]) == 1){

	        cout << "?" << endl;

	        if (a[0]) swap(R,B);
	        if (a[1]) swap(G,B);

	        int d = INF;
	        REP(i, n) REP(j, n) if (i != j){
	            checkMin(d,
                      max(R[i], G[i], B[i]) - R[i] +
                      max(R[j], G[j], B[j]) - G[j]
                      );
	        }
	        s += d;



	    }



	    //cout << a[0] << " " << a[1] << " " << a[2] << endl;

/*	    if (!(a[0]^b[0]^a[1]^b[1]^a[2]^b[2])){

	    }*/

		return s;
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
			int red[]                 = {100, 100, 100};
			int green[]               = {100, 1, 1};
			int blue[]                = {100, 1, 1};
			int expected__            = 302;

			// 199 + 2 + 101

			clock_t start__           = clock();
			int received__            = BallsSeparating().minOperations(vector <int>(red, red + (sizeof red / sizeof red[0])), vector <int>(green, green + (sizeof green / sizeof green[0])), vector <int>(blue, blue + (sizeof blue / sizeof blue[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			int red[]                 = {5};
			int green[]               = {6};
			int blue[]                = {8};
			int expected__            = -1;

			clock_t start__           = clock();
			int received__            = BallsSeparating().minOperations(vector <int>(red, red + (sizeof red / sizeof red[0])), vector <int>(green, green + (sizeof green / sizeof green[0])), vector <int>(blue, blue + (sizeof blue / sizeof blue[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			int red[]                 = {4, 6, 5, 7};
			int green[]               = {7, 4, 6, 3};
			int blue[]                = {6, 5, 3, 8};
			int expected__            = 37;

			clock_t start__           = clock();
			int received__            = BallsSeparating().minOperations(vector <int>(red, red + (sizeof red / sizeof red[0])), vector <int>(green, green + (sizeof green / sizeof green[0])), vector <int>(blue, blue + (sizeof blue / sizeof blue[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			int red[]                 = {7, 12, 9, 9, 7};
			int green[]               = {7, 10, 8, 8, 9};
			int blue[]                = {8, 9, 5, 6, 13};
			int expected__            = 77;

			clock_t start__           = clock();
			int received__            = BallsSeparating().minOperations(vector <int>(red, red + (sizeof red / sizeof red[0])), vector <int>(green, green + (sizeof green / sizeof green[0])), vector <int>(blue, blue + (sizeof blue / sizeof blue[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 4: {
			int red[]                 = {842398, 491273, 958925, 849859, 771363, 67803, 184892, 391907, 256150, 75799};
			int green[]               = {268944, 342402, 894352, 228640, 903885, 908656, 414271, 292588, 852057, 889141};
			int blue[]                = {662939, 340220, 600081, 390298, 376707, 372199, 435097, 40266, 145590, 505103};
			int expected__            = 7230607;

			clock_t start__           = clock();
			int received__            = BallsSeparating().minOperations(vector <int>(red, red + (sizeof red / sizeof red[0])), vector <int>(green, green + (sizeof green / sizeof green[0])), vector <int>(blue, blue + (sizeof blue / sizeof blue[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int red[]                 = ;
			int green[]               = ;
			int blue[]                = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = BallsSeparating().minOperations(vector <int>(red, red + (sizeof red / sizeof red[0])), vector <int>(green, green + (sizeof green / sizeof green[0])), vector <int>(blue, blue + (sizeof blue / sizeof blue[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int red[]                 = ;
			int green[]               = ;
			int blue[]                = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = BallsSeparating().minOperations(vector <int>(red, red + (sizeof red / sizeof red[0])), vector <int>(green, green + (sizeof green / sizeof green[0])), vector <int>(blue, blue + (sizeof blue / sizeof blue[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int red[]                 = ;
			int green[]               = ;
			int blue[]                = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = BallsSeparating().minOperations(vector <int>(red, red + (sizeof red / sizeof red[0])), vector <int>(green, green + (sizeof green / sizeof green[0])), vector <int>(blue, blue + (sizeof blue / sizeof blue[0])));
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
