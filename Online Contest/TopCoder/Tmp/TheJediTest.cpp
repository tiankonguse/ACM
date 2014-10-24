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

inline LL ceil(LL x, LL y){return (x - 1) / y + 1;}

// <<= '1. Bitwise Operation ., //{
namespace BO{

inline bool _1(int x, int i){return bool(x&1<<i);}
inline bool _1(LL x, int i){return bool(x&1LL<<i);}
inline LL _1(int i){return 1LL<<i;}
inline LL _U(int i){return _1(i) - 1;};

inline int reverse_bits(int x){
    x = ((x >> 1) & 0x55555555) | ((x << 1) & 0xaaaaaaaa);
    x = ((x >> 2) & 0x33333333) | ((x << 2) & 0xcccccccc);
    x = ((x >> 4) & 0x0f0f0f0f) | ((x << 4) & 0xf0f0f0f0);
    x = ((x >> 8) & 0x00ff00ff) | ((x << 8) & 0xff00ff00);
    x = ((x >>16) & 0x0000ffff) | ((x <<16) & 0xffff0000);
    return x;
}

inline LL reverse_bits(LL x){
    x = ((x >> 1) & 0x5555555555555555LL) | ((x << 1) & 0xaaaaaaaaaaaaaaaaLL);
    x = ((x >> 2) & 0x3333333333333333LL) | ((x << 2) & 0xccccccccccccccccLL);
    x = ((x >> 4) & 0x0f0f0f0f0f0f0f0fLL) | ((x << 4) & 0xf0f0f0f0f0f0f0f0LL);
    x = ((x >> 8) & 0x00ff00ff00ff00ffLL) | ((x << 8) & 0xff00ff00ff00ff00LL);
    x = ((x >>16) & 0x0000ffff0000ffffLL) | ((x <<16) & 0xffff0000ffff0000LL);
    x = ((x >>32) & 0x00000000ffffffffLL) | ((x <<32) & 0xffffffff00000000LL);
    return x;
}

template<class T> inline bool odd(T x){return x&1;}
template<class T> inline bool even(T x){return !odd(x);}
template<class T> inline T low_bit(T x) {return x & -x;}
template<class T> inline T high_bit(T x) {T p = low_bit(x);while (p != x) x -= p, p = low_bit(x);return p;}
template<class T> inline T cover_bit(T x){T p = 1; while (p < x) p <<= 1;return p;}

inline int low_idx(int x){return __builtin_ffs(x);}
inline int low_idx(LL x){return __builtin_ffsll(x);}
inline int high_idx(int x){return low_idx(reverse_bits(x));}
inline int high_idx(LL x){return low_idx(reverse_bits(x));}
inline int clz(int x){return __builtin_clz(x);}
inline int clz(LL x){return __builtin_clzll(x);}
inline int ctz(int x){return __builtin_ctz(x);}
inline int ctz(LL x){return __builtin_ctzll(x);}
inline int parity(int x){return __builtin_parity(x);}
inline int parity(LL x){return __builtin_parityll(x);}
inline int lg2(int a){return 31 - clz(a);}
inline int lg2(LL a){return 63 - clz(a);}
inline int count_bits(int x){return __builtin_popcount(x);}
inline int count_bits(LL x){return __builtin_popcountll(x);}

} using namespace BO;//}


const int MOD = int(1e9 + 7);
const int INF = 0x7fffffff;

//}/* .................................................................................................................................. */


const int N = 120;
int n; LL k;

bool C[N];
LL B[N]; vector<LL> A;

LL g(){
    LL res = 0;
    REP(i , n){
        if (B[i] && !C[i]) return INF;
        res += (B[i] / k) + (B[i] % k != 0);
    }
    return res;
}


LL f(int x){

    //cout << x << endl;

    REP(i , n){
        if (x & 1) C[i] = 1;
        else C[i] = 0;
        x >>= 1;
        B[i] = A[i];
    }

    REP(i , n){
        if (C[i]){
            if (i < n - 1 && C[i + 1]){
                LL delta = min(A[i] , B[i] % k);
                B[i] -= delta;
                B[i + 1] += delta;
            }
        }
        else{
            if (i && C[i - 1] && i < n - 1 && C[i + 1]){
                LL last = k - (B[i - 1] % k);
                LL r = B[i] % k;
                B[i - 1] += B[i] - r;
                B[i] = r;
                LL delta;
                        delta = min(A[i] , min(last , r));
                        B[i - 1] += delta;
                        B[i] -= delta;
                        B[i + 1] += B[i];
                        B[i] = 0;
            }
            else if (i < n - 1 && (i == 0 || C[i - 1] == 0)){
                LL delta = min(A[i] , B[i]);
                B[i + 1] += delta;
                B[i] -= delta;
            }
            else if (i && (i < n - 1 && C[i + 1] == 0) ){
                LL delta = min(A[i] , B[i]);
                B[i - 1] += delta;
                B[i] -= delta;
            }
        }
    }
    //cout << g() << endl;
    return g();
}


class TheJediTest {
public:
	int minimumSupervisors(vector <int> _A, int K) {
		k = K; n = SZ(_A); A.resize(n); REP(i, n) A[i] = _A[i];
        LL res = 0; REP(i, n) res += ceil(A[i], k);
		FOR(s, 1, _1(n)) checkMin(res, f(s));
		return res;

		/*#define a _A
		#define k K
		int n = SZ(a), res = 0;
		vector<int> b = a;
		a.PB(0), b.PB(0);
		if (n == 1) return (a[0]+k-1)/k;
		b[1] += b[0];
		FOR(i, 1, n){
		    res+= b[i]/k, b[i] %=k;
		    if (b[i]>0){
		        if (k-b[i] <= b[i+1]) ++res, b[i+1] -= k-b[i];
		        else if (b[i] <= a[i] && i+1<n) b[i+1]+=b[i];
		        else ++res;
		    }
		}
		return res;*/

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
			int students[]            = {3, 6, 3};
			int K                     = 4;
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = TheJediTest().minimumSupervisors(vector <int>(students, students + (sizeof students / sizeof students[0])), K);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			int students[]            = {1, 1, 1, 1};
			int K                     = 4;
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = TheJediTest().minimumSupervisors(vector <int>(students, students + (sizeof students / sizeof students[0])), K);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			int students[]            = {0, 0, 0, 0};
			int K                     = 12345;
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = TheJediTest().minimumSupervisors(vector <int>(students, students + (sizeof students / sizeof students[0])), K);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			int students[]            = {15, 0, 13, 4, 29, 6, 2};
			int K                     = 7;
			int expected__            = 10;

			clock_t start__           = clock();
			int received__            = TheJediTest().minimumSupervisors(vector <int>(students, students + (sizeof students / sizeof students[0])), K);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 4: {
			int students[]            = {5, 5, 5, 0, 1009228, 1284912, 0, 0, 0, 0, 9289247, 2157, 2518, 52781, 2, 2818, 68, 1000000, 0, 0};
			int K                     = 13;
			int expected__            = 102138;

			clock_t start__           = clock();
			int received__            = TheJediTest().minimumSupervisors(vector <int>(students, students + (sizeof students / sizeof students[0])), K);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int students[]            = ;
			int K                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = TheJediTest().minimumSupervisors(vector <int>(students, students + (sizeof students / sizeof students[0])), K);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int students[]            = ;
			int K                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = TheJediTest().minimumSupervisors(vector <int>(students, students + (sizeof students / sizeof students[0])), K);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int students[]            = ;
			int K                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = TheJediTest().minimumSupervisors(vector <int>(students, students + (sizeof students / sizeof students[0])), K);
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
