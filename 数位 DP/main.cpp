/** Micro Mezz  o Macro Flation -- Overheated Economy ., Last Update: Mar. 3th 2013 **/ //{

/** Header .. **/ //{
#define LOCAL

#include <functional>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <numeric>
#include <cstring>
#include <climits>
#include <cassert>
#include <complex>
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

//#include <tr1/unordered_set>
//#include <tr1/unordered_map>
//#include <array>

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

#define ECH(it, A) for (__typeof(A.begin()) it=A.begin(); it != A.end(); ++it)
#define REP_S(i, str) for (char*i=str;*i;++i)
#define REP_L(i, hd, nxt) for (int i=hd;i;i=nxt[i])
#define REP_G(i, u) REP_L(i,hd[u],suc)
#define DO(n) for ( int ____n ## __line__ = n; ____n ## __line__ -- ; )
#define REP_2(i, j, n, m) REP(i, n) REP(j, m)
#define REP_2_1(i, j, n, m) REP_1(i, n) REP_1(j, m)
#define REP_3(i, j, k, n, m, l) REP(i, n) REP(j, m) REP(k, l)
#define REP_3_1(i, j, k, n, m, l) REP_1(i, n) REP_1(j, m) REP_1(k, l)
#define REP_4(i, j, k, ii, n, m, l, nn) REP(i, n) REP(j, m) REP(k, l) REP(ii, nn)
#define REP_4_1(i, j, k, ii, n, m, l, nn) REP_1(i, n) REP_1(j, m) REP_1(k, l) REP_1(ii, nn)

#define ALL(A) A.begin(), A.end()
#define LLA(A) A.rbegin(), A.rend()
#define CPY(A, B) memcpy(A, B, sizeof(A))
#define INS(A, P, B) A.insert(A.begin() + P, B)
#define ERS(A, P) A.erase(A.begin() + P)
#define BSC(A, x) (lower_bound(ALL(A), x) - A.begin())
#define CTN(T, x) (T.find(x) != T.end())
#define SZ(A) int((A).size())
#define PB push_back
#define MP(A, B) make_pair(A, B)
#define PTT pair<T, T>
#define fi first
#define se second
#define re real()
#define im imag()

#define Rush for(int ____T=RD(); ____T--;)

#define Display(A, n, m) {                      \
	REP(i, n){		                            \
        REP(j, m) cout << A[i][j] << " ";       \
        cout << endl;				            \
	}						                    \
}

#define Display_1(A, n, m) {				    \
	REP_1(i, n){		                        \
        REP_1(j, m) cout << A[i][j] << " ";     \
		cout << endl;		            		\
	}						                    \
}

#pragma comment(linker, "/STACK:36777216")
//#pragma GCC optimize ("O2")

string __file__(){
    string res = __FILE__;
    int r = SZ(res) - 1; while (res[r] !=  '.') --r;
    int l = r - 1; while (res[l] != '\\') --l; ++l;
    return res.substr(l, r-l);
}

void Exec(string a, string b, string c){
    if (b.empty()) b = __file__();
    string cmd = a + ' ' + b + '.' + c;
    system(cmd.c_str());
}

void Ruby(string file = ""){Exec("ruby", file, "rb");}
void Python(string file = ""){Exec("python", file, "py");}
void Haskell(string file = ""){Exec("runghc", file, "hs");}
void Pascal(string file = ""){Exec("pascal", file, "pas");}

typedef long long LL;
//typedef long double DB;
typedef double DB;
typedef unsigned UINT;
typedef unsigned long long ULL;

typedef vector<int> VI;
typedef vector<char> VC;
typedef vector<string> VS;
typedef vector<LL> VL;
typedef vector<DB> VF;
typedef set<int> SI;
typedef set<string> SS;
typedef map<int, int> MII;
typedef map<string, int> MSI;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
typedef vector<PII> VII;
typedef vector<VI> VVI;
typedef vector<VII> VVII;

template<class T> inline T& RD(T &);
template<class T> inline void OT(const T &);
//inline int RD(){int x; return RD(x);}
inline LL RD(){LL x; return RD(x);}
inline DB& RF(DB &);
inline DB RF(){DB x; return RF(x);}
inline char* RS(char *s);
inline char& RC(char &c);
inline char RC();
inline char& RC(char &c){scanf(" %c", &c); return c;}
inline char RC(){char c; return RC(c);}
//inline char& RC(char &c){c = getchar(); return c;}
//inline char RC(){return getchar();}

template<class T> inline T& RDD(T &x){
    char c; for (c = getchar(); c < '-'; c = getchar());
    if (c == '-'){x = '0' - getchar(); for (c = getchar(); '0' <= c && c <= '9'; c = getchar()) x = x * 10 + '0' - c;}
    else {x = c - '0'; for (c = getchar(); '0' <= c && c <= '9'; c = getchar()) x = x * 10 + c - '0';}
    return x;
}

inline LL RDD(){LL x; return RDD(x);}

template<class T0, class T1> inline T0& RD(T0 &x0, T1 &x1){RD(x0), RD(x1); return x0;}
template<class T0, class T1, class T2> inline T0& RD(T0 &x0, T1 &x1, T2 &x2){RD(x0), RD(x1), RD(x2); return x0;}
template<class T0, class T1, class T2, class T3> inline T0& RD(T0 &x0, T1 &x1, T2 &x2, T3 &x3){RD(x0), RD(x1), RD(x2), RD(x3); return x0;}
template<class T0, class T1, class T2, class T3, class T4> inline T0& RD(T0 &x0, T1 &x1, T2 &x2, T3 &x3, T4 &x4){RD(x0), RD(x1), RD(x2), RD(x3), RD(x4); return x0;}
template<class T0, class T1, class T2, class T3, class T4, class T5> inline T0& RD(T0 &x0, T1 &x1, T2 &x2, T3 &x3, T4 &x4, T5 &x5){RD(x0), RD(x1), RD(x2), RD(x3), RD(x4), RD(x5); return x0;}
template<class T0, class T1, class T2, class T3, class T4, class T5, class T6> inline T0& RD(T0 &x0, T1 &x1, T2 &x2, T3 &x3, T4 &x4, T5 &x5, T6 &x6){RD(x0), RD(x1), RD(x2), RD(x3), RD(x4), RD(x5), RD(x6); return x0;}
template<class T0, class T1> inline void OT(const T0 &x0, const T1 &x1){OT(x0), OT(x1);}
template<class T0, class T1, class T2> inline void OT(const T0 &x0, const T1 &x1, const T2 &x2){OT(x0), OT(x1), OT(x2);}
template<class T0, class T1, class T2, class T3> inline void OT(const T0 &x0, const T1 &x1, const T2 &x2, const T3 &x3){OT(x0), OT(x1), OT(x2), OT(x3);}
template<class T0, class T1, class T2, class T3, class T4> inline void OT(const T0 &x0, const T1 &x1, const T2 &x2, const T3 &x3, const T4 &x4){OT(x0), OT(x1), OT(x2), OT(x3), OT(x4);}
template<class T0, class T1, class T2, class T3, class T4, class T5> inline void OT(const T0 &x0, const T1 &x1, const T2 &x2, const T3 &x3, const T4 &x4, const T5 &x5){OT(x0), OT(x1), OT(x2), OT(x3), OT(x4), OT(x5);}
template<class T0, class T1, class T2, class T3, class T4, class T5, class T6> inline void OT(const T0 &x0, const T1 &x1, const T2 &x2, const T3 &x3, const T4 &x4, const T5 &x5, const T6 &x6){OT(x0), OT(x1), OT(x2), OT(x3), OT(x4), OT(x5), OT(x6);}
inline char& RC(char &a, char &b){RC(a), RC(b); return a;}
inline char& RC(char &a, char &b, char &c){RC(a), RC(b), RC(c); return a;}
inline char& RC(char &a, char &b, char &c, char &d){RC(a), RC(b), RC(c), RC(d); return a;}
inline char& RC(char &a, char &b, char &c, char &d, char &e){RC(a), RC(b), RC(c), RC(d), RC(e); return a;}
inline char& RC(char &a, char &b, char &c, char &d, char &e, char &f){RC(a), RC(b), RC(c), RC(d), RC(e), RC(f); return a;}
inline char& RC(char &a, char &b, char &c, char &d, char &e, char &f, char &g){RC(a), RC(b), RC(c), RC(d), RC(e), RC(f), RC(g); return a;}
inline DB& RF(DB &a, DB &b){RF(a), RF(b); return a;}
inline DB& RF(DB &a, DB &b, DB &c){RF(a), RF(b), RF(c); return a;}
inline DB& RF(DB &a, DB &b, DB &c, DB &d){RF(a), RF(b), RF(c), RF(d); return a;}
inline DB& RF(DB &a, DB &b, DB &c, DB &d, DB &e){RF(a), RF(b), RF(c), RF(d), RF(e); return a;}
inline DB& RF(DB &a, DB &b, DB &c, DB &d, DB &e, DB &f){RF(a), RF(b), RF(c), RF(d), RF(e), RF(f); return a;}
inline DB& RF(DB &a, DB &b, DB &c, DB &d, DB &e, DB &f, DB &g){RF(a), RF(b), RF(c), RF(d), RF(e), RF(f), RF(g); return a;}
inline void RS(char *s1, char *s2){RS(s1), RS(s2);}
inline void RS(char *s1, char *s2, char *s3){RS(s1), RS(s2), RS(s3);}
template<class T0,class T1>inline void RDD(const T0&a, const T1&b){RDD(a),RDD(b);}
template<class T0,class T1,class T2>inline void RDD(const T0&a, const T1&b, const T2&c){RDD(a),RDD(b),RDD(c);}

template<class T> inline void RST(T &A){memset(A, 0, sizeof(A));}
template<class T> inline void FLC(T &A, int x){memset(A, x, sizeof(A));}
template<class T> inline void CLR(T &A){A.clear();}

template<class T0, class T1> inline void RST(T0 &A0, T1 &A1){RST(A0), RST(A1);}
template<class T0, class T1, class T2> inline void RST(T0 &A0, T1 &A1, T2 &A2){RST(A0), RST(A1), RST(A2);}
template<class T0, class T1, class T2, class T3> inline void RST(T0 &A0, T1 &A1, T2 &A2, T3 &A3){RST(A0), RST(A1), RST(A2), RST(A3);}
template<class T0, class T1, class T2, class T3, class T4> inline void RST(T0 &A0, T1 &A1, T2 &A2, T3 &A3, T4 &A4){RST(A0), RST(A1), RST(A2), RST(A3), RST(A4);}
template<class T0, class T1, class T2, class T3, class T4, class T5> inline void RST(T0 &A0, T1 &A1, T2 &A2, T3 &A3, T4 &A4, T5 &A5){RST(A0), RST(A1), RST(A2), RST(A3), RST(A4), RST(A5);}
template<class T0, class T1, class T2, class T3, class T4, class T5, class T6> inline void RST(T0 &A0, T1 &A1, T2 &A2, T3 &A3, T4 &A4, T5 &A5, T6 &A6){RST(A0), RST(A1), RST(A2), RST(A3), RST(A4), RST(A5), RST(A6);}
template<class T0, class T1> inline void FLC(T0 &A0, T1 &A1, int x){FLC(A0, x), FLC(A1, x);}
template<class T0, class T1, class T2> inline void FLC(T0 &A0, T1 &A1, T2 &A2, int x){FLC(A0, x), FLC(A1, x), FLC(A2, x);}
template<class T0, class T1, class T2, class T3> inline void FLC(T0 &A0, T1 &A1, T2 &A2, T3 &A3, int x){FLC(A0, x), FLC(A1, x), FLC(A2, x), FLC(A3, x);}
template<class T0, class T1, class T2, class T3, class T4> inline void FLC(T0 &A0, T1 &A1, T2 &A2, T3 &A3, T4 &A4, int x){FLC(A0, x), FLC(A1, x), FLC(A2, x), FLC(A3, x), FLC(A4, x);}
template<class T0, class T1, class T2, class T3, class T4, class T5> inline void FLC(T0 &A0, T1 &A1, T2 &A2, T3 &A3, T4 &A4, T5 &A5, int x){FLC(A0, x), FLC(A1, x), FLC(A2, x), FLC(A3, x), FLC(A4, x), FLC(A5, x);}
template<class T0, class T1, class T2, class T3, class T4, class T5, class T6> inline void FLC(T0 &A0, T1 &A1, T2 &A2, T3 &A3, T4 &A4, T5 &A5, T6 &A6, int x){FLC(A0, x), FLC(A1, x), FLC(A2, x), FLC(A3, x), FLC(A4, x), FLC(A5, x), FLC(A6, x);}
template<class T> inline void CLR(priority_queue<T, vector<T>, less<T> > &Q){while (!Q.empty()) Q.pop();}
template<class T> inline void CLR(priority_queue<T, vector<T>, greater<T> > &Q){while (!Q.empty()) Q.pop();}
template<class T0, class T1> inline void CLR(T0 &A0, T1 &A1){CLR(A0), CLR(A1);}
template<class T0, class T1, class T2> inline void CLR(T0 &A0, T1 &A1, T2 &A2){CLR(A0), CLR(A1), CLR(A2);}
template<class T0, class T1, class T2, class T3> inline void CLR(T0 &A0, T1 &A1, T2 &A2, T3 &A3){CLR(A0), CLR(A1), CLR(A2), CLR(A3);}
template<class T0, class T1, class T2, class T3, class T4> inline void CLR(T0 &A0, T1 &A1, T2 &A2, T3 &A3, T4 &A4){CLR(A0), CLR(A1), CLR(A2), CLR(A3), CLR(A4);}
template<class T0, class T1, class T2, class T3, class T4, class T5> inline void CLR(T0 &A0, T1 &A1, T2 &A2, T3 &A3, T4 &A4, T5 &A5){CLR(A0), CLR(A1), CLR(A2), CLR(A3), CLR(A4), CLR(A5);}
template<class T0, class T1, class T2, class T3, class T4, class T5, class T6> inline void CLR(T0 &A0, T1 &A1, T2 &A2, T3 &A3, T4 &A4, T5 &A5, T6 &A6){CLR(A0), CLR(A1), CLR(A2), CLR(A3), CLR(A4), CLR(A5), CLR(A6);}
template<class T> inline void CLR(T &A, int n){REP(i, n) CLR(A[i]);}

template<class T> inline bool EPT(T &a){return a.empty();}
template<class T> inline T& SRT(T &A){sort(ALL(A)); return A;}
template<class T> inline T& RVS(T &A){reverse(ALL(A)); return A;}
template<class T> inline T& UNQ(T &A){A.resize(unique(ALL(SRT(A)))-A.begin());return A;}

template<class T, class C> inline T& SRT(T &A, C B){sort(ALL(A), B); return A;}

//}

/** Constant List .. **/ //{

const int MOD = int(1e9) + 7;
//int MOD = 99990001;
const int INF = 0x3f3f3f3f;
const LL INFF = 1LL << 60;
const DB EPS = 1e-9;
const DB OO = 1e20;
const DB PI = acos(-1.0); //M_PI;

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};

//}

/** Add On .. **/ //{
// <<= '0. Nichi Joo ., //{
template<class T> inline void checkMin(T &a,const T b){if (b<a) a=b;}
template<class T> inline void checkMax(T &a,const T b){if (a<b) a=b;}
template<class T> inline void checkMin(T &a, T &b, const T x){checkMin(a, x), checkMin(b, x);}
template<class T> inline void checkMax(T &a, T &b, const T x){checkMax(a, x), checkMax(b, x);}
template <class T, class C> inline void checkMin(T& a, const T b, C c){if (c(b,a)) a = b;}
template <class T, class C> inline void checkMax(T& a, const T b, C c){if (c(a,b)) a = b;}
template<class T> inline T min(T a, T b, T c){return min(min(a, b), c);}
template<class T> inline T max(T a, T b, T c){return max(max(a, b), c);}
template<class T> inline T min(T a, T b, T c, T d){return min(min(a, b), min(c, d));}
template<class T> inline T max(T a, T b, T c, T d){return max(max(a, b), max(c, d));}
template<class T> inline T sqr(T a){return a*a;}
template<class T> inline T cub(T a){return a*a*a;}
inline int ceil(int x, int y){return (x - 1) / y + 1;}
inline int sgn(DB x){return x < -EPS ? -1 : x > EPS;}
inline int sgn(DB x, DB y){return sgn(x - y);}

inline DB cot(DB x){return (DB)1/tan(x);};
inline DB sec(DB x){return (DB)1/cos(x);};
inline DB csc(DB x){return (DB)1/sin(x);};

//}
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
template<class T> inline int cover_idx(T x){int p = 0; while (_1(p) < x ) ++p; return p;}

inline int clz(int x){return __builtin_clz(x);}
inline int clz(LL x){return __builtin_clzll(x);}
inline int ctz(int x){return __builtin_ctz(x);}
inline int ctz(LL x){return __builtin_ctzll(x);}
inline int lg2(int x){return !x ? -1 : 31 - clz(x);}
inline int lg2(LL x){return !x ? -1 : 63 - clz(x);}
inline int low_idx(int x){return !x ? -1 : ctz(x);}
inline int low_idx(LL x){return !x ? -1 : ctz(x);}
inline int high_idx(int x){return lg2(x);}
inline int high_idx(LL x){return lg2(x);}
inline int parity(int x){return __builtin_parity(x);}
inline int parity(LL x){return __builtin_parityll(x);}
inline int count_bits(int x){return __builtin_popcount(x);}
inline int count_bits(LL x){return __builtin_popcountll(x);}

} using namespace BO;//}
// <<= '2. Number Theory .,//{
namespace NT{
inline LL __lcm(LL a, LL b){return a*b/__gcd(a,b);}
inline void INC(int &a, int b){a += b; if (a >= MOD) a -= MOD;}
inline int sum(int a, int b){a += b; if (a >= MOD) a -= MOD; return a;}
inline void DEC(int &a, int b){a -= b; if (a < 0) a += MOD;}
inline int dff(int a, int b){a -= b; if (a < 0) a  += MOD; return a;}
inline void MUL(int &a, int b){a = (LL)a * b % MOD;}
inline int pdt(int a, int b){return (LL)a * b % MOD;}

inline int sum(int a, int b, int c){return sum(sum(a, b), c);}
inline int sum(int a, int b, int c, int d){return sum(sum(a, b), sum(c, d));}
inline int pdt(int a, int b, int c){return pdt(pdt(a, b), c);}
inline int pdt(int a, int b, int c, int d){return pdt(pdt(pdt(a, b), c), d);}

inline int pow(int a, int b){
    int c(1); while (b){
        if (b&1) MUL(c, a);
        MUL(a, a), b >>= 1;
    }
    return c;
}

inline int pow(int a, LL b){
    int c(1); while (b){
        if (b&1) MUL(c, a);
        MUL(a, a), b >>= 1;
    }
    return c;
}

template<class T> inline T pow(T a, LL b){
    T c(1); while (b){
        if (b&1) c *= a;
        a *= a, b >>= 1;
    }
    return c;
}

inline int _I(int b){
    int a = MOD, x1 = 0, x2 = 1, q;
    while (true){
        q = a / b, a %= b;
        if (!a) return (x2 + MOD) % MOD;
        DEC(x1, pdt(q, x2));

        q = b / a, b %= a;
        if (!b) return (x1 + MOD) % MOD;
        DEC(x2, pdt(q, x1));
    }
}

inline void DIV(int &a, int b){MUL(a, _I(b));}
inline int qtt(int a, int b){return pdt(a, _I(b));}

inline int phi(int n){
    int res = n; for (int i=2;sqr(i)<=n;++i) if (!(n%i)){
        DEC(res, qtt(res, i));
        do{n /= i;} while(!(n%i));
    }
    if (n != 1)
        DEC(res, qtt(res, n));
    return res;
}

} using namespace NT;//}
// <<= '7. Matrix Theory .,//{
namespace MT{

    const int N = 100;
    int n = 0;

    typedef int rec;

    struct matrix{
        rec d[N][N];

        void init(rec e = 0){RST(d); if(e) REP(i, n) d[i][i] = e;}
        matrix(rec e = 0){init(e);}

        matrix operator *(const matrix &rhs) const{
            matrix res; //REP_3(i, j, k, n, n, n) res.d[i][j] += d[i][k] * rhs.d[k][j];
            REP_2(i, j, n, n){
                LL tmp = 0; REP(k, n) tmp += (LL) d[i][k] * rhs.d[k][j];
                res.d[i][j] = tmp % MOD;
            }
            return res;
        }

        matrix& operator *=(const matrix& rhs){(*this) = (*this) * rhs;}

        inline int res(){
            int res = 0;
            REP(i, n) INC(res, d[0][i]);
            //REP_2(i, j, n, n) INC(res, d[i][j]);
            return res;
        }
    };

    /*inline matrix pow_sum(const matrix& a, ULL nn){
        if (nn == 1) return matrix(1);
        matrix t; REP_2(i, j, n, n) t.d[i][j] = t.d[i][j+n] = a.d[i][j];
        FOR_C(i, n, n*2) t.d[i][i] = 1; n <<= 1; t = pow(t, nn), n >>= 1;
        REP_2(i, j, n, n) t.d[i][j] = t.d[i][j+n];
        return t;
    }*/

    inline matrix pow_sum(const matrix& a, ULL nn){
        if (nn == 1) return matrix(1);
        matrix t; REP_2(i, j, n, n) t.d[i][j] = a.d[i][j];
        REP(i, n) t.d[i][i+n] = t.d[i+n][i+n] = 1; n <<= 1; t = pow(t, nn), n >>= 1;
        REP_2(i, j, n, n) t.d[i][j] = t.d[i][j+n];
        return t;
    }

    template<class T> T pow_sum(T a, ULL nn){
        int _n = n; n = 1; matrix t; t.d[0][0] = a;
        t = pow_sum(t, nn), n = _n;
        return t.d[0][0];
    }

} // using namespace MT;//}
// <<= '8. Stringology .,//{
namespace SL{
    namespace KMP{

        void calc_PI(const char *P, int n, int *PI){
            for (int i = 1, j = PI[0] = -1; i < n; ++i){
                while (j >= 0 && P[i] != P[j+1]) j = PI[j];
                if (P[i] == P[j+1]) ++j;
                PI[i] = j;
            }
            //REP(i, n) cout << PI[i] << " "; cout << endl;
        }

        bool run(const char *T, int n, const char *P, int m, const int *PI){
            for (int i = 0, j = -1; i < n; ++i){
                while (j >= 0 && T[i] != P[j+1]) j = PI[j];
                if (T[i] == P[j+1]) ++j;
                if (j == m - 1) return true;
            }
            return false;
        }

    } //using namespace KMP;

    namespace Z{
        void calc_z(const char *P, int n, int *z){

            z[0] = n;

            for (int i = 1, l = 0, r = 0; i < n; ++i){
                if (i > r){
                    for(l = r = i; r < n && P[r] == P[r - l];) ++r;
                    z[i] = r - l, --r;
                }
                else {
                    if (z[i - l] < r - i + 1) z[i] = z[i - l];
                    else {
                        for (l = i;r < n && P[r] == P[r - l];) ++r;
                        z[i] = r - l, --r;
                    }
                }
            }

            //REP(i, n) cout << z[i] << " "; cout << endl;
        }

        int run(const char *T, int n, const char *P, int m, const int *z){

            int ex; REP_C_N(ex, min(n, m)) if (T[ex] != P[ex]) break;

            int res = ex == m;

            for (int i = 1, l = 0, r = 0; i < n; ++i){
                if (i > r){
                    for (l = r = i; r < n && T[r] == P[r - l];) ++r;
                    ex = r - l, --r;
                }
                else {
                    if (z[i - l] < r - i + 1) ex = z[i - l];
                    else {
                        for (l = i; r < n && T[r] == P[r - l];) ++r;
                        ex = r - l, --r;
                    }
                }
                if (ex == m) ++res;
            }

            return res;
        }
    } //using namespace Z;

    void Manacher(char s[], int n, int p[]){
        const int NN = 0;
        static char ss[NN*2+2]; int nn = 2*n+2;
        ss[0] = '$', ss[nn-1] = '#', ss[nn] = 0;
        REP(i, n) ss[i*2+1] ='#', ss[i*2+2] = s[i];
        int mx = 0, id = 0; FOR(i, 1, nn){
            p[i] = mx > i ? min(p[2*id-i], mx - i) : 1;
            while (ss[i+p[i]] == ss[i-p[i]]) ++p[i];
            if (i + p[i] > mx) mx = i + p[i], id = i;
        }
    }

} //using namespace SL;//}
// <<= '9. Comutational Geometry .,//{
namespace CG{

struct Po; struct Line; struct Seg;

struct Po{
    DB x, y; Po(DB _x=0, DB _y=0):x(_x), y(_y){}
    friend istream& operator >>(istream& in, Po &p){return in >> p.x >> p.y;}
    friend ostream& operator <<(ostream& out, Po p){return out << "(" << p.x << ", " << p.y << ")";}
    bool operator ==(const Po& r)const{return !sgn(x-r.x) && !sgn(y-r.y);};
    bool operator !=(const Po& r)const{return sgn(x-r.x) || sgn(y-r.y);}
    Po operator +(const Po& r)const{return Po(x+r.x, y+r.y);}
    Po operator -(const Po& r)const{return Po(x-r.x, y-r.y);}
    Po operator *(DB k)const{return Po(x*k,y*k);}
    Po operator /(DB k)const{return Po(x/k,y/k);}
    DB operator *(const Po&) const;
    DB operator ^(const Po&) const;

    bool operator <(const Po &r) const{return sgn(x,r.x)<0||!sgn(x,r.x)&&sgn(y,r.y)<0;}
    Po operator -()const{return Po(-x,-y);}
    Po& operator +=(const Po &r){x+=r.x,y+=r.y;return *this;}
    Po& operator -=(const Po &r){x-=r.x,y-=r.y;return *this;}
    Po& operator *=(DB k){x*=k,y*=k;return*this;}
    Po& operator /=(DB k){x/=k,y/=k;return*this;}

    DB length_sqr()const{return sqr(x)+sqr(y);}
    DB length()const{return sqrt(length_sqr());}
    Po unit()const{return *this/length();}
    bool dgt()const{return !sgn(x)&&!sgn(y);}
    DB atan()const{return atan2(y,x);}
    void rotate(DB alpha, const Po& o = Po()){
        x -= o.x, y -= o.y;
        (*this) = Po(x * cos(alpha) - y * sin(alpha), y * cos(alpha) + x * sin(alpha)) + o;
    }

    void input(){RF(x,y);}
};

Po operator *(DB k, Po a){return a * k;}

#define innerProduct dot
#define scalarProduct dot
#define outerProduct det
#define crossProduct det

inline DB dot(const DB &x1, const DB &y1, const DB &x2, const DB &y2){return x1 * x2 + y1 * y2;}
inline DB dot(const Po &a, const Po &b){return dot(a.x, a.y, b.x, b.y);}
inline DB dot(const Po &p0, const Po &p1, const Po &p2){return dot(p1 - p0, p2 - p0);}

inline DB det(const DB &x1, const DB &y1, const DB &x2, const DB &y2){return x1 * y2 - x2 * y1;}
inline DB det(const Po &a, const Po &b){return det(a.x, a.y, b.x, b.y);}
inline DB det(const Po &p0, const Po &p1, const Po &p2){return det(p1 - p0, p2 - p0);}

template<class T1, class T2> inline int dett(const T1 &x, const T2 &y){return sgn(det(x, y));}
template<class T1, class T2> inline int dott(const T1 &x, const T2 &y){return sgn(dot(x, y));}
template<class T1, class T2, class T3> inline int dett(const T1 &x, const T2 &y, const T3 &z){return sgn(det(x, y, z));}
template<class T1, class T2, class T3> inline int dott(const T1 &x, const T2 &y, const T3 &z){return sgn(dot(x, y, z));}
template<class T1, class T2, class T3, class T4> inline int dett(const T1 &x, const T2 &y, const T3 &z, const T4 &w){return sgn(det(x, y, z, w));}
template<class T1, class T2, class T3, class T4> inline int dott(const T1 &x, const T2 &y, const T3 &z, const T4 &w){return sgn(dot(x, y, z, w));}

inline DB dist_sqr(const DB &x, const DB &y){return sqr(x) + sqr(y);}
inline DB dist_sqr(const DB &x, const DB &y, const DB &z){return sqr(x) + sqr(y) + sqr(z);}
inline DB dist_sqr(const Po &a, const Po &b){return sqr(a.x - b.x) + sqr(a.y - b.y);}

template<class T1, class T2> inline DB dist(const T1 &x, const T2 &y){return sqrt(dist_sqr(x, y));}
template<class T1, class T2, class T3> inline DB dist(const T1 &x, const T2 &y, const T3 &z){return sqrt(dist_sqr(x, y, z));}

DB Po::operator *(const Po &r)const{return dot(*this, r);}
DB Po::operator ^(const Po &r)const{return det(*this, r);}

struct Line{
    Po a, b;

    Line(DB x0=0, DB y0=0, DB x1=0, DB y1=0):a(Po(x0, y0)), b(Po(x1, y1)){}
    Line(const Po &a, const Po &b):a(a), b(b){}
    Line(const Line &l):a(l.a), b(l.b){}

    friend ostream& operator <<(ostream& out, Line p){return out << p.a << "-" << p.b;}
    Line operator +(Po x)const{return Line(a + x, b + x);}
    DB length()const{return (b-a).length();}
    bool dgt()const{return (b-a).dgt();}
    void input(){a.input(), b.input();}

    int side(const Po& p){return dett(a, b, p);}
    bool same_side(const Po& p1, const Po& p2){return side(p1) == side(p2);}
    void getequation(DB& A, DB& B, DB& C) const{A = a.y - b.y, B = b.x - a.x, C = det(a, b);}
};

struct Seg: Line{
};

inline DB dot(const Line &l1, const Line &l2){return dot(l1.b - l1.a, l2.b - l2.a);}
inline DB det(const Line &l1, const Line &l2){return det(l1.b - l1.a, l2.b - l2.a);}

inline DB dist_sqr(const Po &p, const Line &l){Po v0 = l.b - l.a, v1 = p - l.a; return sqr(fabs(det(v0, v1))) / v0.length_sqr();}
inline DB dist_sqr(const Po &p, const Seg &l){
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

    if (l1.a == l2.a || l1.a == l2.b || l1.b == l2.a || l1.b == l2.b) return true;

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

inline bool isOnSide(const Po &p, const Seg &l){
    return p == l.a || p == l.b;
}

inline bool isOnSeg(const Po &p, const Seg &l){
    return sgn(det(p, l.a, l.b)) == 0 &&
        sgn(l.a.x, p.x) * sgn(l.b.x, p.x) <= 0 && sgn(l.a.y, p.y) * sgn(l.b.y, p.y) <= 0;
}

inline bool isOnSegg(const Po &p, const Seg &l){
    return sgn(det(p, l.a, l.b)) == 0 &&
        sgn(l.a.x, p.x) * sgn(l.b.x, p.x) < 0 && sgn(l.a.y, p.y) * sgn(l.b.y, p.y) < 0;
}

inline Po intersect(const Line &l1, const Line &l2){
    return l1.a + (l1.b - l1.a) * (det(l2.a, l1.a, l2.b) / det(l2, l1));
}

// perpendicular foot
inline Po intersect(const Po & p, const Line &l){
    return intersect(Line(p, p + Po(l.a.y - l.b.y, l.b.x - l.a.x)), l);
}

inline Po rotate(Po p, DB alpha, const Po &o = Po()){
    p.rotate(alpha, o);
    return p;
}

} using namespace CG;//}
//}

/** Miscellaneous .. **/ //{

/** I/O Accelerator Interface .. **/ //{
template<class T> inline T& RD(T &x){
    //cin >> x;
    //scanf("%d", &x);
    char c; for (c = getchar(); c < '0'; c = getchar()); x = c - '0'; for (c = getchar(); '0' <= c && c <= '9'; c = getchar()) x = x * 10 + c - '0';
    //char c; c = getchar(); x = c - '0'; for (c = getchar(); c >= '0'; c = getchar()) x = x * 10 + c - '0';
    return x;
}

inline DB& RF(DB &x){
    //cin >> x;
    scanf("%lf", &x);
    /*char t; while ((t=getchar())==' '||t=='\n'); x = t - '0';
    while ((t=getchar())!=' '&&t!='\n'&&t!='.')x*=10,x+=t-'0';
    if (t=='.'){DB l=1; while ((t=getchar())!=' '&&t!='\n')l*=0.1,x += (t-'0')*l;}*/
    return x;
}

inline char* RS(char *s){
    //gets(s);
    scanf("%s", s);
    return s;
}

LL last_ans; int Case; template<class T> inline void OT(const T &x){
    //printf("Case %d: %d\n", ++Case, x);
    //printf("%lld ", x);
    printf("%d\n", x);
    //cout << x << endl;
    //last_ans = x;
}
//}

//}/* .................................................................................................................................. */

struct Int{
    int val;

    operator int() const{return val;}

    Int(int val = -1):val(val){
        //val %= MOD; if (val < 0) val += MOD;
    }
    inline Int& operator +=(const Int& rhs){
        INC(val, rhs);
        return *this;
    }
    inline Int operator +(const Int& rhs) const{
        return sum(val, rhs.val);
    }
    inline Int& operator -=(const Int& rhs){
        DEC(val, rhs);
        return *this;
    }
    inline Int operator -(const Int& rhs) const{
        return dff(val, rhs);
    }
    inline Int& operator *=(const Int& rhs){
        MUL(val, rhs);
        return *this;
    }
    inline Int operator *(const Int& rhs) const{
        return pdt(val, rhs);
    }
    inline Int& operator /=(const Int& rhs){
        DIV(val, rhs);
        return *this;
    }
    inline Int operator /(const Int& rhs) const{
        return qtt(val, rhs);
    }
};

const int N = 20;
Int dp0[N][N], dp1[N][N], Pow10[N];
int a[N]; LL l, r; int n, k;

int w(int x){
    return x == 1 || x == 4 ? 1 : 0;
}

Int f0(int n, int k, bool b){
    if (k<0) return 0;
    if (!n) return !k;

    if (b){
        Int res = 0; int up = a[n];
        REP(i, up) res += f0(n-1, k-w(i), 0);
        res += f0(n-1, k-w(up), 1);
        return res;
    }
    else {
        Int &res = dp0[n][k];
        if (res == -1){
            res = 0; int up = 9;
            REP(i, up) res += f0(n-1, k-w(i), 0);
            res += f0(n-1, k-w(up), 0);
        }
        return res;
    }
}


Int f1(int n, int k, bool b){
    if (k<0) return 0;
    if (!n) return 0;

    if (b){
        Int res = 0; int up = a[n];
        REP(i, up) res += f1(n-1, k-w(i), 0) + f0(n-1, k-w(i), 0) * Pow10[n-1] * Int(i);
        res += f1(n-1, k-w(up), 1) + f0(n-1, k-w(up), 1) * Pow10[n-1] * Int(up);
        return res;
    }
    else {
        Int &res = dp1[n][k];
        if (res == -1){
            res = 0; int up = 9;
            REP(i, up) res += f1(n-1, k-w(i), 0) + f0(n-1, k-w(i), 0) * Pow10[n-1] * Int(i);
            res += f1(n-1, k-w(up), 0) + f0(n-1, k-w(up), 0) * Pow10[n-1] * Int(up);
        }
        return res;
    }
}

Int f(LL x){
    n = 0; while (x) a[++n] = x % 10, x /= 10;
    Int res = 0; FOR_1(i, k, n) res += f1(n, i, 1);
    return res;
}

int main(){

#ifndef ONLINE_JUDGE
    //freopen("1.in", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif

    Pow10[0] = 1; FOR(i, 1, N) Pow10[i] = Pow10[i-1] * Int(10);

    Rush{
        RD(l, r, k);
        OT(f(r) - f(l-1));
    }
}
