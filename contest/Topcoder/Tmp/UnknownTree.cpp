/** Micro Mezzo Macro Flation -- Overheated Economy ., Last Update: Feb. 27th 2013 **/ //{

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
#define SZ(A) int(A.size())
#define PB push_back
#define MP(A, B) make_pair(A, B)
#define PTT pair<T, T>
#define fi first
#define se second

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

const int MOD = int(1e9) + 9;
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

        void calc_pi(const char *P, int n, int *pi){
            for (int i = 1, j = pi[0] = -1; i < n; ++i){
                while (j >= 0 && P[i] != P[j+1]) j = pi[j];
                if (P[i] == P[j+1]) ++j;
                pi[i] = j;
            }
            //REP(i, n) cout << pi[i] << " "; cout << endl;
        }

        bool run(const char *T, int n, const char *P, int m, const int *pi){
            for (int i = 0, j = -1; i < n; ++i){
                while (j >= 0 && T[i] != P[j+1]) j = pi[j];
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
// <<= 'Random Event .. . //{
namespace RNG{
//srand((unsigned)time(NULL));
inline unsigned int rand16(){return ((rand()) << 15) ^ rand();}
inline unsigned int rand32(){return (rand16() << 16) | rand16();}
inline ULL rand64(){return ((LL)rand32() << 32) | rand32();}
inline ULL random(LL l, LL r){return l == r ? l : rand64() % (r - l) + l;}
int dice(){return rand() % 6;}
bool coin(){return bool(rand() % 2);}
} using namespace RNG;
//}
// <<= 'Clock .. . //{
namespace CLOCK{
DB s0, s1, rd, k, T;
inline DB getTime(){
#ifdef LOCAL
    return 1.0 * clock() / CLOCKS_PER_SEC;
#else
    timeval tv;
    gettimeofday(&tv, 0);
    return tv.tv_sec + tv.tv_usec * 1e-6;
#endif
}

inline void st0(DB _T = 0.98){T = _T, s0 = getTime();}
inline void st1(DB _k = 1.618){k = _k, s1 = getTime();}
inline void ed1(){rd = getTime() - s1;}
inline DB elapsed(){return getTime() - s0;}
inline bool TLE(){return elapsed() + rd * k < T;}
} //using namespace CLOCK;
//}
// <<= 'Temp .. . //{
namespace TMP{
template<class T> PTT operator+(const PTT &p1, const PTT &p2) {
	return PTT(p1.fi + p2.fi, p1.se + p2.se);
}

template<class T> PTT operator-(const PTT &p1, const PTT &p2) {
	return PTT(p1.fi - p2.fi, p1.se - p2.se);
}

template<class T> PTT operator*(const PTT &lhs, T k){
    return PTT(lhs.fi * k, lhs.se * k);
}
} using namespace TMP;
//}
// <<= 'Bignum ., //{
namespace BIGNUM{

const int __base = 1e8;
const int P10[] = {1, 10, int(1e2), int(1e3), int(1e4), int(1e5), int(1e6), int(1e7), int(1e8), int(1e9)};
const int MAX_BUF_SIZE = 109;
char __buf[MAX_BUF_SIZE];

class bignum{
          friend istream& operator>>(istream&, bignum&);
          friend ostream& operator<<(ostream&, const bignum&);
          friend bignum operator +(const bignum&, const bignum&);
          friend bignum operator -(const bignum&, const bignum&);
          friend bignum operator *(const bignum&, const bignum&);
          friend bignum operator /(const bignum&, const bignum&);
          friend bignum operator %(const bignum&, const bignum&);
          friend bignum operator +(const bignum&, const int&);
          friend bignum operator -(const bignum&, const int&);
          friend bignum operator *(const bignum&, const int&);
          friend bignum operator /(const bignum&, const int&);
          friend bignum operator %(const bignum&, const int&);
          friend bool operator ==(const bignum&, const bignum&);
          friend bool operator !=(const bignum&, const bignum&);
          friend bool operator <(const bignum&, const bignum&);
          friend bool operator >(const bignum&, const bignum&);
          friend bool operator <=(const bignum&, const bignum&);
          friend bool operator >=(const bignum&, const bignum&);
          friend bool operator ==(const bignum&, const int&);
          friend bool operator !=(const bignum&, const int&);
          friend bool operator <(const bignum&, const int&);
          friend bool operator >(const bignum&, const int&);
          friend bool operator <=(const bignum&, const int&);
          friend bool operator >=(const bignum&, const int&);
          friend int do_comp(const bignum&, const int&);
          friend int do_comp(const bignum&, const bignum&);
          friend void divide(const bignum&, const bignum&, bignum&, bignum&);
          friend bignum pow(bignum, int);
          friend bignum pow(int, int);
    public:
        inline bignum(){};
        inline bignum(int s){
            while (s) data.PB(s%__base), s/=__base;
            if (data.empty()) data.PB(0);
        }

        inline bignum(long long s){
            while (s) data.PB(int(s%__base)), s/=__base;
            if (data.empty()) data.PB(0);
        }

        inline bignum(string s){
            int t, i; CLR(data);
            for (i=int(s.size())-8;i>0;i-=8){
                istringstream(s.substr(i, 8)) >> t;
                data.PB(t);
            }
            istringstream(s.substr(0, i+8)) >> t;
            data.PB(t);
        }

        void input(){
            CLR(data); RS(__buf); int t = 0, c = 0;
            DWN(i, strlen(__buf), 0){
                t += P10[c] * (int(__buf[i]) - '0'), ++c;
                if (c == 8) data.PB(t), c = t = 0;
            }
            if (c) data.PB(t);
        }

        void operator =(const int);
        void operator =(const string);
        void operator =(const bignum);
        bignum& operator +=(const bignum&);
        bignum& operator -=(const bignum&);
        bignum& operator *=(const bignum&);
        bignum& operator /=(const bignum&);
        bignum& operator %=(const bignum&);
        bignum& operator +=(const int&);
        bignum& operator -=(const int&);
        bignum& operator *=(const int&);
        bignum& operator /=(const int&);
        bignum& operator %=(const int&);
        bool undefined();
        int do_try(const int&);
        int do_try(const bignum&);
        void do_trim();
        list<int> data;

    int size(){
        list<int>::iterator it; int res = 0;
        for (it=data.begin(); it!=data.end();it++)
            res += 8;
        it--;
        if (*it >= 10000) {
            if ( (*it) >= 1000000) {if (*it >=10000000) ; else res--;}
            else {if ((*it) >= 100000) res-=2; else res-=3;}
        }
        else
            if ( (*it) >= 100) {if (*it >=1000) res-=4; else res-=5;}
            else {if ((*it) >= 10) res-=6; else res-=7;}

        return res;
    }

    void do_reserve(int a){
        if (a <= 0) return;
        list<int>::iterator it;
        for (it=data.begin(); it!=data.end() && a>0; it++) a-=8;
        if (it == data.end() && a>=0) return;
        a+=8, it--; int f = 1;
        for (int i=0;i<a;i++) f *= 10; (*it) %= f;
        data.erase(++it, data.end());
        do_trim();
    }
};

inline void bignum::operator =(const bignum a){
    data.clear();
    for (list<int>::const_iterator i=a.data.begin();i!=a.data.end();i++){
        data.PB(*i);
    }
}
inline void bignum::operator =(const string a){
    (*this) = bignum(a);
}
inline void bignum::operator =(const int a){
    (*this) = bignum(a);
}

inline istream& operator>>(istream& input, bignum& a){
    string s; int t, i; input >> s; a.data.clear();
    for (i=int(s.size())-8;i>0;i-=8){
        istringstream(s.substr(i, 8)) >> t;
        a.data.PB(t);
    }
    istringstream(s.substr(0, i+8)) >> t;
    a.data.PB(t);
    return input;
}

inline ostream& operator<<(ostream& output, const bignum& a){
    list<int>::const_reverse_iterator i=a.data.rbegin();
    output << *i;
    for (i++;i!=a.data.rend();i++){
        if (*i >= 10000) {
            if (*i >= 1000000) {if (*i>=10000000) cout << *i; else cout << 0 << *i;}
            else {if (*i>=100000) cout << "00" << *i; else cout << "000" << *i;}
        }
        else {
            if (*i >= 100) {if (*i>=1000)  cout << "0000" << *i; else cout << "00000" << *i;}
            else { if (*i>=10) cout << "000000" << *i; else cout << "0000000" << *i;}
        }
    }
    return output;
}

inline bool bignum::undefined(){
    return data.empty();
}

inline int do_comp(const bignum& a, const bignum& b){
    if (a.data.size()<b.data.size()) return -1; if (a.data.size()>b.data.size()) return 1;
    list<int>::const_reverse_iterator i; list<int>::const_reverse_iterator j;
    for (i=a.data.rbegin(),j=b.data.rbegin(); j!=b.data.rend(); i++,j++){
        if (*i<*j) return -1;              //!!!!
        if (*i>*j) return 1;
    }
    return 0;
}
inline int do_comp(const bignum& a, const int& b){
    return do_comp(a, bignum(b));
}

inline bool operator ==(const bignum& a, const bignum& b){
    return do_comp(a, b) == 0;
}
inline bool operator !=(const bignum& a, const bignum& b){
    return do_comp(a, b) != 0;
}
inline bool operator <(const bignum& a, const bignum& b){
    return do_comp(a, b) == -1;
}
inline bool operator >(const bignum& a, const bignum& b){
    return do_comp(a, b) == 1;
}
inline bool operator <=(const bignum& a, const bignum& b){
    return do_comp(a, b) != 1;
}
inline bool operator >=(const bignum& a, const bignum& b){
    return do_comp(a, b) != -1;
}

inline bool operator ==(const bignum& a, const int& b){
    return do_comp(a, b) == 0;
}
inline bool operator !=(const bignum& a, const int& b){
    return do_comp(a, b) != 0;
}
inline bool operator <(const bignum& a, const int& b){
    return do_comp(a, b) == -1;
}
inline bool operator >(const bignum& a, const int& b){
    return do_comp(a, b) == 1;
}
inline bool operator <=(const bignum& a, const int& b){
    return do_comp(a, b) != 1;
}
inline bool operator >=(const bignum& a, const int& b){
    return do_comp(a, b) != -1;
}

inline void bignum::do_trim(){
    while (data.size()>1&&data.back()==0) data.pop_back();
}

inline bignum& bignum::operator +=(const bignum& a){
    list<int>::iterator i; list<int>::const_iterator j; int t = 0;
    for (i=data.begin(),j=a.data.begin(); i!=data.end()&&j!=a.data.end(); i++,j++){
        *i+=*j+t; t=*i/__base; *i%=__base;
    }
    while (i!=data.end()) {*i+=t; t=*i/__base; *i%=__base; i++;}
    while (j!=a.data.end()) {data.PB(t+*j); t=data.back()/__base; data.back()%=__base; j++;}
    if (t!=0) data.PB(t);
    return *this;
}

inline bignum& bignum::operator -=(const bignum& a){
    list<int>::iterator i; list<int>::const_iterator j; int t = 0;
    for (i=data.begin(),j=a.data.begin(); j!=a.data.end(); i++,j++){
        *i -= t+*j; if (*i>=0) t=0; else *i+=__base, t=1;
    }
    while (i!=data.end()) {*i-=t; if (*i>=0) t=0;else *i+=__base, t=1; i++;}
    (*this).do_trim();
    return *this;
}

inline bignum& bignum::operator +=(const int& a){
    return (*this)+=bignum(a);
}

inline bignum& bignum::operator -=(const int& a){
    return (*this)-=bignum(a);
}

inline bignum operator +(const bignum& a, const bignum& b){
    list<int>::const_iterator i, j; bignum c; int t = 0;
    for (i=a.data.begin(),j=b.data.begin(); i!=a.data.end()&&j!=b.data.end(); i++,j++){
        c.data.PB(t+*i+*j);
        t=c.data.back()/__base; c.data.back()%=__base;
    }
    while (i!=a.data.end()) {c.data.PB(t+*i); t=c.data.back()/__base; c.data.back()%=__base; i++;}
    while (j!=b.data.end()) {c.data.PB(t+*j); t=c.data.back()/__base; c.data.back()%=__base; j++;}
    if (t!=0) c.data.PB(t);
    return c;
}

inline bignum operator -(const bignum& a, const bignum& b){
    list<int>::const_iterator i, j; bignum c; int t = 0;
    for (i=a.data.begin(),j=b.data.begin(); j!=b.data.end(); i++,j++){
        t = *i - t;
        if (t>=*j) c.data.PB(t-*j), t=0;
        else c.data.PB(t+__base-*j), t=1;
    }
    while (i!=a.data.end()) {t=*i-t; if (t>=0) c.data.PB(t), t=0;else c.data.PB(t+__base), t=1; i++;}
    c.do_trim();
    return c;
}

inline bignum operator *(const bignum& a, const bignum& b){
    list<int>::const_iterator i, j; list<int>::iterator k, kk; bignum c; long long t = 0;

    for (int i=0;i<a.data.size()+b.data.size();i++) c.data.PB(0);
    for (i=a.data.begin(),k=c.data.begin(); i!=a.data.end(); i++,k++){
        for (j=b.data.begin(),kk=k; j!=b.data.end(); j++,kk++){
            t+=(long long)(*i)*(*j)+(*kk);
            *kk=int(t%__base); t/=__base;
        }
        *kk+=t; t=0;
    }
    c.do_trim();
    return c;
}

inline int bignum::do_try(const bignum& a){
    int l = 1, r = 99999999, m, t;
    while (l+2<r){
        m = (l + r) / 2;
        t = do_comp(*this, a*bignum(m));
        if (t==0) return m;
        if (t<0) r = m - 1;
        else l = m;
    }
    while (do_comp(*this, a*bignum(r))<0) r--;
    return r;
}

inline void divide(const bignum& a, const bignum& b, bignum& d, bignum& r){
    list<int>::const_reverse_iterator i = a.data.rbegin(); int t;
    d = bignum(0); r = bignum(0);
    do {
        while (r<b&&i!=a.data.rend()){d.data.push_front(0);r.data.push_front(*i);r.do_trim();i++;}
        if (r>=b){
            t = r.do_try(b); d.data.front() = t;
            r-=(b*bignum(t));
        }
    } while (i!=a.data.rend());
    d.do_trim();
}

inline bignum operator /(const bignum& a, const bignum& b){
    bignum d, r;
    divide(a, b, d, r);
    return d;
}

inline bignum operator %(const bignum& a, const bignum& b){
    bignum d, r;
    divide(a, b, d, r);
    return r;
}

inline bignum operator +(const bignum& a, const int& b){
    return a+bignum(b);
}

inline bignum operator -(const bignum& a, const int& b){
    return a-bignum(b);
}

inline bignum operator *(const bignum& a, const int& b){
    return a*bignum(b);
}

inline bignum operator /(const bignum& a, const int& b){
    return a/bignum(b);
}

inline bignum operator %(const bignum& a, const int& b){
    return a%bignum(b);
}

inline bignum& bignum::operator *=(const bignum& a){
    (*this) = (*this) * a;
    return *this;
}

inline bignum& bignum::operator /=(const bignum& a){
    (*this) = (*this) / a;
    return *this;
}

inline bignum& bignum::operator %=(const bignum& a){
    (*this) = (*this) % a;
    return *this;
}

inline bignum& bignum::operator *=(const int& a){
    return (*this)*=bignum(a);
}

inline bignum& bignum::operator /=(const int& a){
    return (*this)/=bignum(a);
}

inline bignum& bignum::operator %=(const int& a){
    return (*this)%=bignum(a);
}

inline bignum pow(bignum a,int b){
    bignum c(1);
    while (b!=0) {
        if (b&1) c *= a;
        a = a * a; b >>= 1;
    }
    return c;
}
inline bignum pow(int a, int b){
    return pow(bignum(a), b);
}

} //using namespace BIGNUM;
//}
//}

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
    printf("%lld ", x);
    //printf("%d\n", x);
    //cout << x << endl;
    //last_ans = x;
}
//}

//}/* .................................................................................................................................. */

struct Int{
    int val;

    operator int() const{return val;}

    Int(int val = 0):val(val){
        val %= MOD; if (val < 0) val += MOD;
    }
    inline Int& operator +=(const Int& rhs){
        INC(val, rhs);
        return *this;
    }
    inline Int operator +(const Int& rhs) const{
        return sum(val, rhs.val);
    }
    inline Int operator -(const Int& rhs) const{
        return dff(val, rhs);
    }
    inline Int& operator *=(const Int& rhs){
        MUL(val, rhs);
        return *this;
    }
    inline Int operator *(const Int& rhs) const{
        return pdt(val, rhs.val);
    }
};

struct UnknownTree
{

    // The version with one root. d[] holds the d to the root.
    Int f1(VI& d){
        // Can be done in O(n), but O(n*n) is fast enough.
        int n = SZ(d); Int res = 1; REP(i, n){
            Int t = 1; REP(j, n) t += d[j] < d[i];
            res *= t;
        }
        return res;
    }

    Int f2(VII& d){

        int n = SZ(d); if (n>1 && d[0].fi == d[1].fi) return 0;
        FOR(i, 1, n) d[i].fi -= d[0].fi;

        VI bO; if (!d[0].se){
            FOR(i, 1, n){
                if (d[i].fi != d[i].se) return 0;
                bO.PB(d[i].fi);
            }
            return f1(bO);
        }

        VII bA; int ba = d[0].se; FOR(i, 1, n){
            int ia = d[i].se, ib = d[i].fi;
            if (ia - ba == ib) bO.PB(ib);
            else {
                if (ia + ib < ba) return 0;
                bA.PB(d[i]);
            }
        }

        return f1(bO) * f2(bA);
    }

    Int f31(VI& dA, VI& dB, VI& dC){

        Int res; int n = SZ(dA); REP(o, n){

            VII bA, bB, bC; VI bO;

            bA.PB(MP(0, dA[o])), bA.PB(MP(dA[o], 0));
            bB.PB(MP(0, dB[o])), bB.PB(MP(dB[o], 0));
            bC.PB(MP(0, dC[o])), bC.PB(MP(dC[o], 0));

            bool valid = true; REP(i, n) if (i != o){
                int da = dA[i] - dA[o], db = dB[i] - dB[o], dc = dC[i] - dC[o];
                if (da > 0 && da == db && db == dc) bO.PB(da);
                else if (db > 0 && db == dc) bA.PB(MP(db, dA[i]));
                else if (dc > 0 && dc == da) bB.PB(MP(dc, dB[i]));
                else if (da > 0 && da == db) bC.PB(MP(da, dC[i]));
                else {
                    valid = false;
                    break;
                }
            }

            if (valid){
                SRT(bA), SRT(bB), SRT(bC);
                res += f1(bO) * f2(bA) * f2(bB) * f2(bC);
            }
        }

        return res;
    }

    Int f32(VI& dL, VI& dR, VI& dM){

        set<PII> L; int n = SZ(dM); REP(i, n){
            L.insert(MP(abs(dL[i]-dM[i]), abs(dR[i]-dM[i])));
            if (dL[i]-dM[i]>0) L.insert(MP(dL[i]-dM[i], dR[i]+dM[i]));
            if (dR[i]-dM[i]>0) L.insert(MP(dL[i]+dM[i], dR[i]-dM[i]));
        }

        Int res; ECH(it, L){

            int lm = it->fi, mr = it->se;
            VII bA, bB; VI bO;

            bA.PB(MP(0, lm)), bA.PB(MP(lm, 0));
            bB.PB(MP(0, mr)), bB.PB(MP(mr, 0));

            bool valid = true; REP(i, n){
                int dl = dL[i] - lm, dr = dR[i] - mr, dm = dM[i];
                if (dm == dl && dm == dr) bO.PB(dm);
                else if (dl == dm) bB.PB(MP(dm, dR[i]));
                else if (dr == dm) bA.PB(MP(dm, dL[i]));
                else {
                    valid = false;
                    break;
                }
            }

            if (valid) {
                SRT(bA), SRT(bB);
                res += f1(bO) * f2(bA) * f2(bB);
            }
        }

        return res;
    }


    int getCount(VI dA, VI dB, VI dC){
        return f31(dA, dB, dC) + f32(dB, dC, dA) + f32(dA, dC, dB) + f32(dA, dB, dC);
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
			int dA[]          = {1};
			int dB[]          = {2};
			int dC[]          = {3};
			int expected__            = 6;

			clock_t start__           = clock();
			int received__            = UnknownTree().getCount(vector <int>(dA, dA + (sizeof dA / sizeof dA[0])), vector <int>(dB, dB + (sizeof dB / sizeof dB[0])), vector <int>(dC, dC + (sizeof dC / sizeof dC[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			int dA[]          = {1, 2};
			int dB[]          = {1, 2};
			int dC[]          = {1, 2};
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = UnknownTree().getCount(vector <int>(dA, dA + (sizeof dA / sizeof dA[0])), vector <int>(dB, dB + (sizeof dB / sizeof dB[0])), vector <int>(dC, dC + (sizeof dC / sizeof dC[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			int dA[]          = {5, 4};
			int dB[]          = {3, 2};
			int dC[]          = {2, 1};
			int expected__            = 8;

			clock_t start__           = clock();
			int received__            = UnknownTree().getCount(vector <int>(dA, dA + (sizeof dA / sizeof dA[0])), vector <int>(dB, dB + (sizeof dB / sizeof dB[0])), vector <int>(dC, dC + (sizeof dC / sizeof dC[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			int dA[]          = {2, 4, 2};
			int dB[]          = {1, 3, 3};
			int dC[]          = {4, 6, 4};
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = UnknownTree().getCount(vector <int>(dA, dA + (sizeof dA / sizeof dA[0])), vector <int>(dB, dB + (sizeof dB / sizeof dB[0])), vector <int>(dC, dC + (sizeof dC / sizeof dC[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 4: {
			int dA[]          = {4, 6, 1, 5, 3, 2, 5};
			int dB[]          = {4, 2, 3, 1, 3, 2, 1};
			int dC[]          = {5, 7, 2, 6, 4, 3, 6};
			int expected__            = 12;

			clock_t start__           = clock();
			int received__            = UnknownTree().getCount(vector <int>(dA, dA + (sizeof dA / sizeof dA[0])), vector <int>(dB, dB + (sizeof dB / sizeof dB[0])), vector <int>(dC, dC + (sizeof dC / sizeof dC[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 5: {
			int dA[]          = {6, 4, 5, 6, 8, 1, 5, 6, 4, 2};
			int dB[]          = {4, 2, 3, 4, 6, 1, 3, 4, 2, 2};
			int dC[]          = {6, 4, 5, 6, 8, 3, 5, 6, 4, 4};
			int expected__            = 9000;

			clock_t start__           = clock();
			int received__            = UnknownTree().getCount(vector <int>(dA, dA + (sizeof dA / sizeof dA[0])), vector <int>(dB, dB + (sizeof dB / sizeof dB[0])), vector <int>(dC, dC + (sizeof dC / sizeof dC[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 6: {
			int dA[]          = {8, 5, 6, 8, 6, 5, 6, 10, 8, 5, 10, 8, 7, 9, 7, 1, 11, 5, 9, 6, 6, 1, 6, 9, 8, 4, 12, 7, 5, 7, 6, 8, 12, 8, 6, 6, 5, 8, 5, 3, 3, 4, 8, 6, 6, 8, 8, 9, 7, 5};
			int dB[]          = {9, 6, 7, 9, 7, 6, 7, 11, 9, 6, 11, 9, 8, 10, 8, 2, 12, 6, 10, 7, 7, 4, 7, 10, 9, 5, 13, 8, 6, 8, 7, 9, 13, 9, 7, 7, 6, 9, 6, 4, 4, 5, 9, 7, 7, 9, 9, 10, 8, 6};
			int dC[]          = {8, 9, 6, 8, 2, 5, 6, 10, 8, 5, 10, 8, 7, 9, 1, 5, 11, 5, 9, 6, 6, 7, 6, 9, 8, 4, 12, 7, 5, 7, 6, 8, 12, 8, 6, 6, 5, 8, 1, 7, 3, 4, 8, 6, 6, 8, 8, 3, 7, 5};
			int expected__            = 770724166;

			clock_t start__           = clock();
			int received__            = UnknownTree().getCount(vector <int>(dA, dA + (sizeof dA / sizeof dA[0])), vector <int>(dB, dB + (sizeof dB / sizeof dB[0])), vector <int>(dC, dC + (sizeof dC / sizeof dC[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 7: {
			int dA[]          = {33030780, 30296205, 16842859, 28857842, 37928939, 27190807, 48689043, 33328845, 24254103, 3962046, 31043603, 25699520, 11297547, 27045586, 31603483, 23207518, 44089781, 48470539, 52366295, 39786470, 45623279, 21593844, 38639305, 27260993, 43899542, 36162768, 21640232, 43580853, 33826577, 30501815, 51470990, 2157904, 27823597, 9550575, 39234641, 24163007, 34155133, 42504989, 35821444, 36054200, 29026389, 29716374, 41764139, 19392309, 44258194, 19987908, 56722905, 46771885, 32668277, 40665175};
			int dB[]          = {16191697, 13457122, 3776, 12018759, 21089856, 10351724, 31849960, 16489762, 7415020, 12877037, 14204520, 8860437, 9035480, 10206503, 14764400, 6368435, 27250698, 31631456, 35527212, 22947387, 28784196, 4754761, 21800222, 10421910, 27060459, 19323685, 4801149, 26741770, 16987494, 13662732, 34631907, 18996987, 10984514, 7288508, 22395558, 7323924, 17316050, 25665906, 18982361, 19215117, 12187306, 12877291, 24925056, 2553226, 27419111, 3148825, 39883822, 29932802, 15829194, 23826092};
			int dC[]          = {19337227, 16602652, 3149306, 15164289, 24235386, 13497254, 34995490, 19635292, 10560550, 16030119, 17350050, 12005967, 12188562, 13352033, 17909930, 3215353, 30396228, 34776986, 38672742, 26092917, 31929726, 7907843, 24945752, 13567440, 30205989, 22469215, 7946679, 29887300, 20133024, 16808262, 37777437, 22150069, 14130044, 10441590, 25541088, 10469454, 20461580, 28811436, 22127891, 22360647, 15332836, 16022821, 28070586, 5706308, 30564641, 6294355, 43029352, 33078332, 18974724, 26971622};
			int expected__            = 101733071;

			clock_t start__           = clock();
			int received__            = UnknownTree().getCount(vector <int>(dA, dA + (sizeof dA / sizeof dA[0])), vector <int>(dB, dB + (sizeof dB / sizeof dB[0])), vector <int>(dC, dC + (sizeof dC / sizeof dC[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 8: {
			int dA[]          = ;
			int dB[]          = ;
			int dC[]          = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = UnknownTree().getCount(vector <int>(dA, dA + (sizeof dA / sizeof dA[0])), vector <int>(dB, dB + (sizeof dB / sizeof dB[0])), vector <int>(dC, dC + (sizeof dC / sizeof dC[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 9: {
			int dA[]          = ;
			int dB[]          = ;
			int dC[]          = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = UnknownTree().getCount(vector <int>(dA, dA + (sizeof dA / sizeof dA[0])), vector <int>(dB, dB + (sizeof dB / sizeof dB[0])), vector <int>(dC, dC + (sizeof dC / sizeof dC[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 10: {
			int dA[]          = ;
			int dB[]          = ;
			int dC[]          = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = UnknownTree().getCount(vector <int>(dA, dA + (sizeof dA / sizeof dA[0])), vector <int>(dB, dB + (sizeof dB / sizeof dB[0])), vector <int>(dC, dC + (sizeof dC / sizeof dC[0])));
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
