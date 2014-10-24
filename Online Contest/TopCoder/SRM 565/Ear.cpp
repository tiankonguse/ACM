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
#define REP_C_N(i, n) for (n____=int(n),i=0;i<n____;++i)
#define FOR_C_N(i, a, b) for (b____=int(b),i=a;i<b____;++i)
#define DWN_C_N(i, b, a) for (a____=int(a),i=b-1;i>=a____;--i)
#define REP_1_C_N(i, n) for (n____=int(n),i=1;i<=n____;++i)
#define FOR_1_C_N(i, a, b) for (b____=int(b),i=a;i<=b____;++i)
#define DWN_1_C_N(i, b, a) for (a____=int(a),i=b;i>=a____;--i)

#define ALL(A) A.begin(), A.end()
#define CLR(A) A.clear()
#define CPY(A, B) memcpy(A, B, sizeof(A))
#define INS(A, P, B) A.insert(A.begin() + P, B)
#define ERS(A, P) A.erase(A.begin() + P)
#define SRT(A) sort(ALL(A))
#define SZ(A) int(A.size())
#define PB push_back
#define MP(A, B) make_pair(A, B)

#define fi first
#define se second

typedef long long LL;
typedef double DB;
typedef pair<int, int> PII;

template<class T> inline void RST(T &A){memset(A, 0, sizeof(A));}
template<class T> inline void FLC(T &A, int x){memset(A, x, sizeof(A));}

// <<= ` 0. Daily Use .,

template<class T> inline void checkMin(T &a,const T b){if (b<a) a=b;}
template<class T> inline void checkMax(T &a,const T b){if (b>a) a=b;}
template <class T, class C> inline void checkMin(T& a, const T b, C c){if (c(b,a)) a = b;}
template <class T, class C> inline void checkMax(T& a, const T b, C c){if (c(a,b)) a = b;}
template<class T> inline T min(T a, T b, T c){return min(min(a, b), c);}
template<class T> inline T max(T a, T b, T c){return max(max(a, b), c);}
template<class T> inline T min(T a, T b, T c, T d){return min(min(a, b), min(c, d));}
template<class T> inline T max(T a, T b, T c, T d){return max(max(a, b), max(c, d));}
template<class T> inline T sqr(T a){return a*a;}
template<class T> inline T cub(T a){return a*a*a;}
int Ceil(int x, int y){return (x - 1) / y + 1;}


/** Add - On **/

const int MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const DB EPS = 1e-9;
const DB OO = 1e15;
const DB PI = acos(-1.0); //M_PI;

// <<= '9. Comutational Geometry .,

struct Po; struct Line; struct Seg;

inline int sgn(DB x){return x < -EPS ? -1 : x > EPS;}
inline int sgn(DB x, DB y){return sgn(x - y);}

struct Po{
    DB x, y;
    Po(DB _x = 0, DB _y = 0):x(_x), y(_y){}

    friend istream& operator >>(istream& in, Po &p){return in >> p.x >> p.y;}
    friend ostream& operator <<(ostream& out, Po p){return out << "(" << p.x << ", " << p.y << ")";}

    friend bool operator ==(Po, Po);
    friend bool operator !=(Po, Po);
    friend Po operator +(Po, Po);
    friend Po operator -(Po, Po);
    friend Po operator *(Po, DB);
    friend Po operator /(Po, DB);

    bool operator < (const Po &rhs) const{return sgn(x, rhs.x) < 0 || sgn(x, rhs.x) == 0 && sgn(y, rhs.y) < 0;}
    Po operator-() const{return Po(-x, -y);}
    Po& operator +=(Po rhs){x += rhs.x, y += rhs.y; return *this;}
    Po& operator -=(Po rhs){x -= rhs.x, y -= rhs.y; return *this;}
    Po& operator *=(DB k){x *= k, y *= k; return *this;}
    Po& operator /=(DB k){x /= k, y /= k; return *this;}

    DB length_sqr(){return sqr(x) + sqr(y);}
    DB length(){return sqrt(length_sqr());}

    DB atan(){
        return atan2(y, x);
    }

    void input(){
        scanf("%lf %lf", &x, &y);
    }
};

bool operator ==(Po a, Po b){return sgn(a.x - b.x) == 0 && sgn(a.y - b.y) == 0;}
bool operator !=(Po a, Po b){return sgn(a.x - b.x) != 0 || sgn(a.y - b.y) != 0;}
Po operator +(Po a, Po b){return Po(a.x + b.x, a.y + b.y);}
Po operator -(Po a, Po b){return Po(a.x - b.x, a.y - b.y);}
Po operator *(Po a, DB k){return Po(a.x * k, a.y * k);}
Po operator *(DB k, Po a){return a * k;}
Po operator /(Po a, DB k){return Po(a.x / k, a.y / k);}

struct Line{
    Po a, b;
    Line(Po _a = Po(), Po _b = Po()):a(_a), b(_b){}
    Line(DB x0, DB y0, DB x1, DB y1):a(Po(x0, y0)), b(Po(x1, y1)){}
    Line(Seg);

    friend ostream& operator <<(ostream& out, Line p){return out << p.a << "-" << p.b;}
};

struct Seg{
    Po a, b;
    Seg(Po _a = Po(), Po _b = Po()):a(_a), b(_b){}
    Seg(DB x0, DB y0, DB x1, DB y1):a(Po(x0, y0)), b(Po(x1, y1)){}
    Seg(Line l);

    friend ostream& operator <<(ostream& out, Seg p){return out << p.a << "-" << p.b;}
    DB length(){return (b - a).length();}
};

Line::Line(Seg l):a(l.a), b(l.b){}
Seg::Seg(Line l):a(l.a), b(l.b){}

#define innerProduct dot
#define scalarProduct dot
#define dotProduct dot
#define outerProduct det
#define crossProduct det

inline DB dot(DB x1, DB y1, DB x2, DB y2){return x1 * x2 + y1 * y2;}
inline DB dot(Po a, Po b){return dot(a.x, a.y, b.x, b.y);}
inline DB dot(Po p0, Po p1, Po p2){return dot(p1 - p0, p2 - p0);}
inline DB dot(Line l1, Line l2){return dot(l1.b - l1.a, l2.b - l2.a);}
inline DB det(DB x1, DB y1, DB x2, DB y2){return x1 * y2 - x2 * y1;}
inline DB det(Po a, Po b){return det(a.x, a.y, b.x, b.y);}
inline DB det(Po p0, Po p1, Po p2){return det(p1 - p0, p2 - p0);}
inline DB det(Line l1, Line l2){return det(l1.b - l1.a, l2.b - l2.a);}

template<class T1, class T2> inline DB dist(T1 x, T2 y){return sqrt(dist_sqr(x, y));}

inline DB dist_sqr(Po a, Po b){return sqr(a.x - b.x) + sqr(a.y - b.y);}
inline DB dist_sqr(Po p, Line l){Po v0 = l.b - l.a, v1 = p - l.a; return sqr(fabs(det(v0, v1))) / v0.length_sqr();}
inline DB dist_sqr(Po p, Seg l){
    Po v0 = l.b - l.a, v1 = p - l.a, v2 = p - l.b;
    if (sgn(dot(v0, v1)) * sgn(dot(v0, v2)) <= 0) return dist_sqr(p, Line(l));
    else return min(v1.length_sqr(), v2.length_sqr());
}

inline DB dist_sqr(Line l, Po p){return dist_sqr(p, l);}
inline DB dist_sqr(Seg l, Po p){return dist_sqr(p, l);}

inline DB dist_sqr(Line l1, Line l2){
    if (sgn(det(l1, l2)) != 0) return 0;
    return dist_sqr(l1.a, l2);
}
inline DB dist_sqr(Line l1, Seg l2){
    Po v0 = l1.b - l1.a, v1 = l2.a - l1.a, v2 = l2.b - l1.a; DB c1 = det(v0, v1), c2 = det(v0, v2);
    return sgn(c1) != sgn(c2) ? 0 : sqr(min(fabs(c1), fabs(c2))) / v0.length_sqr();
}

bool isIntersect(Seg l1, Seg l2){

    //if (l1.a == l2.a || l1.a == l2.b || l1.b == l2.a || l1.b == l2.b) return true;

    return
        min(l1.a.x, l1.b.x) <= max(l2.a.x, l2.b.x) &&
        min(l2.a.x, l2.b.x) <= max(l1.a.x, l1.b.x) &&
        min(l1.a.y, l1.b.y) <= max(l2.a.y, l2.b.y) &&
        min(l2.a.y, l2.b.y) <= max(l1.a.y, l1.b.y) &&
    sgn( det(l1.a, l2.a, l2.b) ) * sgn( det(l1.b, l2.a, l2.b) ) <= 0 &&
    sgn( det(l2.a, l1.a, l1.b) ) * sgn( det(l2.b, l1.a, l1.b) ) <= 0;

}

inline DB dist_sqr(Seg l1, Seg l2){
    if (isIntersect(l1, l2)) return 0;
    else return min(dist_sqr(l1.a, l2), dist_sqr(l1.b, l2), dist_sqr(l2.a, l1), dist_sqr(l2.b, l1));
}

inline bool isOnExtremePoint(const Po &p, const Seg &l){
    return p == l.a || p == l.b;
}

inline bool isOnseg(const Po &p, const Seg &l){

    //if (p == l.a || p == l.b) return false;

    return sgn(det(p, l.a, l.b)) == 0 &&
        sgn(l.a.x, p.x) * sgn(l.b.x, p.x) <= 0 && sgn(l.a.y, p.y) * sgn(l.b.y, p.y) <= 0;
}

inline Po intersect(const Line &l1, const Line &l2){
    return l1.a + (l1.b - l1.a) * (det(l2.a, l1.a, l2.b) / det(l2, l1));
}

// perpendicular foot
inline Po intersect(const Po & p, const Line &l){
    return intersect(Line(p, p + Po(l.a.y - l.b.y, l.b.x - l.a.x)), l);
}

inline Po rotate(Po p, DB alpha, Po o = Po()){
    p.x -= o.x, p.y -= o .y;
    return Po(p.x * cos(alpha) - p.y * sin(alpha), p.y * cos(alpha) + p.x * sin(alpha)) + o;
}

/* -&$&#*( &#*@)^$@&*)*/

const int N = 309;
int Red[N]; Po Blue[N];
int n, m;

int stoi(string str) {
    int res = 0; REP(i,SZ(str)) res *= 10, res += str[i]-'0';
    return res;
}

class Ear {
public:
		long long getCount(vector <string> redX, vector <string> blueX, vector <string> blueY) {

			string rX, bX, bY;
			REP(i,SZ(redX)) rX+=redX[i];
			REP(i,SZ(blueX)) bX+=blueX[i];
			REP(i,SZ(blueY)) bY+=blueY[i];

			string tmps; stringstream sin(rX.c_str()); n = m = 0;
			while (sin >> tmps) Red[++n] = stoi(tmps);
			stringstream tin(bX.c_str());
			while (tin >> tmps) Blue[++m].x = stoi(tmps);
			m = 0; stringstream uin(bY.c_str());
			while (uin >> tmps) Blue[++m].y = stoi(tmps);

			if (n < 4 || m < 2) return 0;

			sort(Red+1 , Red+n+1); LL res = 0; REP_1(i, m) REP_1(j, m) if (Red[1] < Blue[i].x && Red[2] < Blue[j].x && Red[n] > Blue[i].x && Red[n-1] > Blue[j].x){
				int A=0, B=0 , C=n+1 , D=n+1;
				DWN_1(k,n,1) if (Red[k] < Blue[j].x){B = k; break;}
				DWN_1(k,n,1) if (Red[k] < Blue[i].x && det(Po(Red[k], 0), Blue[j], Blue[i]) > 0){A = k; break;}
				FOR_1(k,1,n) if (Red[k] > Blue[j].x) {C = k; break;}
				FOR_1(k,1,n) if (Red[k] > Blue[i].x && det(Po(Red[k], 0), Blue[i], Blue[j]) > 0){D = k; break;}
				if (A && B && C != n+1 && D != n+1) res += ((B-A)*A + (A>=2 ? A*(A-1)/2 : 0)) * ((D-C)*(n+1-D) + (n+1-D>=2 ? (n+1-D)*(n-D)/2 : 0));
			}

			return res;
		}
} ;


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
			string redX[]             = {"3 2 8 7"};
			string blueX[]            = {"5 4"};
			string blueY[]            = {"2 4"};
			long long expected__      = 1;

			clock_t start__           = clock();
			long long received__      = Ear().getCount(vector <string>(redX, redX + (sizeof redX / sizeof redX[0])), vector <string>(blueX, blueX + (sizeof blueX / sizeof blueX[0])), vector <string>(blueY, blueY + (sizeof blueY / sizeof blueY[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			string redX[]             = {"3 2 8 7"};
			string blueX[]            = {"2 8"};
			string blueY[]            = {"3 4"};
			long long expected__      = 0;

			clock_t start__           = clock();
			long long received__      = Ear().getCount(vector <string>(redX, redX + (sizeof redX / sizeof redX[0])), vector <string>(blueX, blueX + (sizeof blueX / sizeof blueX[0])), vector <string>(blueY, blueY + (sizeof blueY / sizeof blueY[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			string redX[]             = {"1 2 6 9"};
			string blueX[]            = {"3 6 8 5"};
			string blueY[]            = {"1 5 4 3"};
			long long expected__      = 4;

			clock_t start__           = clock();
			long long received__      = Ear().getCount(vector <string>(redX, redX + (sizeof redX / sizeof redX[0])), vector <string>(blueX, blueX + (sizeof blueX / sizeof blueX[0])), vector <string>(blueY, blueY + (sizeof blueY / sizeof blueY[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			string redX[]             = {"10000"};
			string blueX[]            = {"10000 9999"};
			string blueY[]            = {"10000 9999"};
			long long expected__      = 0;

			clock_t start__           = clock();
			long long received__      = Ear().getCount(vector <string>(redX, redX + (sizeof redX / sizeof redX[0])), vector <string>(blueX, blueX + (sizeof blueX / sizeof blueX[0])), vector <string>(blueY, blueY + (sizeof blueY / sizeof blueY[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 4: {
			string redX[]             = {"100 2", "00", " 39", "9", " 800 900 9", "99"};
			string blueX[]            = {"15", "0 250 ", "349"};
			string blueY[]            = {"2 3 1"};
			long long expected__      = 12;

			clock_t start__           = clock();
			long long received__      = Ear().getCount(vector <string>(redX, redX + (sizeof redX / sizeof redX[0])), vector <string>(blueX, blueX + (sizeof blueX / sizeof blueX[0])), vector <string>(blueY, blueY + (sizeof blueY / sizeof blueY[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 5: {
			string redX[]             = {"1", " ", "2", " ", "3", " ", "4 5 6", " 7 8 9"};
			string blueX[]            = {"4", " ", "5", " ", "6", " 7 ", "8"};
			string blueY[]            = {"1", " 2 ", "3 4", " 5"};
			long long expected__      = 204;

			clock_t start__           = clock();
			long long received__      = Ear().getCount(vector <string>(redX, redX + (sizeof redX / sizeof redX[0])), vector <string>(blueX, blueX + (sizeof blueX / sizeof blueX[0])), vector <string>(blueY, blueY + (sizeof blueY / sizeof blueY[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			string redX[]             = ;
			string blueX[]            = ;
			string blueY[]            = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = Ear().getCount(vector <string>(redX, redX + (sizeof redX / sizeof redX[0])), vector <string>(blueX, blueX + (sizeof blueX / sizeof blueX[0])), vector <string>(blueY, blueY + (sizeof blueY / sizeof blueY[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string redX[]             = ;
			string blueX[]            = ;
			string blueY[]            = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = Ear().getCount(vector <string>(redX, redX + (sizeof redX / sizeof redX[0])), vector <string>(blueX, blueX + (sizeof blueX / sizeof blueX[0])), vector <string>(blueY, blueY + (sizeof blueY / sizeof blueY[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			string redX[]             = ;
			string blueX[]            = ;
			string blueY[]            = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = Ear().getCount(vector <string>(redX, redX + (sizeof redX / sizeof redX[0])), vector <string>(blueX, blueX + (sizeof blueX / sizeof blueX[0])), vector <string>(blueY, blueY + (sizeof blueY / sizeof blueY[0])));
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
