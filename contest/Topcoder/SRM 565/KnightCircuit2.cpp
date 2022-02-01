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
#include <queue>
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




/*
struct KnightCircuit2{
	LL maxSize(int w, int h){


		if (w > h) swap(w , h);
		if (w == 1) return 1;
		if (w == 2) return (h +1) / 2;
		LL ans = (LL) (h / 3) * 8;
		if (h % 3 >= 1) ans += 3;
		if (h % 3 >= 2) ans += 2;
		return ans;
		return -1;
	}
};
*/



typedef pair<int, int> PII;

const int N = 46000;
bool vis[N][4];
const int dx[] = {2 , 2 , -2 , -2 , 1 , 1 , -1 , -1};
const int dy[] = {1 , -1 , 1 , -1 , 2 , -2 , 2 , -2};
int n , m;
//(x+2,y+1), (x+2,y-1), (x-2,y+1), (x-2,y-1), (x+1,y+2), (x+1,y-2), (x-1,y+2), and (x-1,y-2)

queue<PII> q;
struct KnightCircuit2{
	bool inmap(int x , int y){
		return 0 <= x && x < n && 0 <= y && y < m;
	}
	int bfs(int x , int y){
		while(!q.empty()) q.pop();
		int ret = 1;
		q.push(MP(x , y));
		vis[x][y] = 1;
		while(!q.empty()){
			PII now = q.front() , go;
			q.pop();
			for (int d = 0 ; d < 8 ; ++d){
				go = MP(now.first + dx[d] , now.second + dy[d]);
				if (!inmap(go.first , go.second) || vis[go.first][go.second]) continue;

				vis[go.first][go.second] = true;
				++ret;
				q.push(go);
			}
		}
		return ret;
	}
	int maxSize(int w, int h){
		if (w >= 4 && h >= 4) return w * h;
		int ans = 0;
		RST(vis);
		if (w < h) swap(w , h);
		n = w , m = h;
		cout << n << endl << m << endl;
		for (int i = 0 ; i < n ; ++i)
		for (int j = 0 ; j < m ; ++j){
			if (vis[i][j]) continue;
			int res = bfs(i , j);
			checkMax(ans , res);
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
			int w                     = 3;
			int h                     = 3;
			LL expected__            = 1000000000;

			clock_t start__           = clock();
			int received__            = KnightCircuit2().maxSize(w, h);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			int w                     = 15;
			int h                     = 2;
			int expected__            = 8;

			clock_t start__           = clock();
			int received__            = KnightCircuit2().maxSize(w, h);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			int w                     = 100;
			int h                     = 100;
			int expected__            = 10000;

			clock_t start__           = clock();
			int received__            = KnightCircuit2().maxSize(w, h);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 3: {
			int w                     = ;
			int h                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = KnightCircuit2().maxSize(w, h);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 4: {
			int w                     = ;
			int h                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = KnightCircuit2().maxSize(w, h);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			int w                     = ;
			int h                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = KnightCircuit2().maxSize(w, h);
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
