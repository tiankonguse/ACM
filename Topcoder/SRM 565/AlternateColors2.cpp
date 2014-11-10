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

LL dp[10][100005];

class AlternateColors2 {
public:


long long countWays(int n, int k) {

    long long res = 0;
    int max_rgb=(k+1)/2*2, min_gb=(k+2)/3*3;

    for(int i=0;3*i<k;i++){
        res+=(k-1-3*i)/2*2;
        res++;
    }

    if(k%3==1&&min_gb<=n){
        int u=n-min_gb;
        res += (LL) (u+2)*(u+1)/2;
    }

    for(int i=0;i*3<k;i++)
        if((k-3*i)%2==1) res += 2LL*(n-3*i-(k-3*i+1)/2*2+1);
    return res;
}


/*
LL countWays(int n, int k){
    --k;
    RST(dp);
    dp[7][0] = 1;


    REP(i, n) FOR(bit, 1, 8) if (dp[bit][i] > 0){

        FOR(nxt, 1, 8) if ( (nxt & bit) == nxt){
            int cnt = (nxt & 1) + (nxt >> 1 & 1) + (nxt >> 2 & 1 );
            if (i <= k && k < i + cnt){
                int k2 = k - i;
                if ((nxt&1)&&k2 == 0) dp[nxt][i + cnt] += dp[bit][i];
            }
            else {
                dp[nxt][i+cnt] += dp[bit][i];
            }
        }
    }

    LL res = 0;
    FOR(i, 1, 8) res += dp[i][n];
    return res;
}*/

};


aab

aabaab

aabaabbaabaabb


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

	int verify_case(int casenum, const long long &expected, const long long &received, clock_t elapsed) {
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
			int n                     = 1;
			int k                     = 1;
			long long expected__      = 1;

			clock_t start__           = clock();
			long long received__      = AlternateColors2().countWays(n, k);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			int n                     = 3;
			int k                     = 3;
			long long expected__      = 3;

			clock_t start__           = clock();
			long long received__      = AlternateColors2().countWays(n, k);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			int n                     = 6;
			int k                     = 4;
			long long expected__      = 9;

			clock_t start__           = clock();
			long long received__      = AlternateColors2().countWays(n, k);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			int n                     = 6;
			int k                     = 1;
			long long expected__      = 21;

			clock_t start__           = clock();
			long long received__      = AlternateColors2().countWays(n, k);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 4: {
			int n                     = 14340;
			int k                     = 254;
			long long expected__      = 1194061;

			clock_t start__           = clock();
			long long received__      = AlternateColors2().countWays(n, k);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 5: {
			int n                     = 98765;
			int k                     = 85;
			long long expected__      = 4871783493;

			clock_t start__           = clock();
			long long received__      = AlternateColors2().countWays(n, k);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			int n                     = ;
			int k                     = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = AlternateColors2().countWays(n, k);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int n                     = ;
			int k                     = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = AlternateColors2().countWays(n, k);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			int n                     = ;
			int k                     = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = AlternateColors2().countWays(n, k);
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
