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

#define REP(i, n) for (int i=0;i<int(n);++i)
#define FOR(i, a, b) for (int i=int(a);i<int(b);++i)
#define DWN(i, b, a) for (int i=int(b-1);i>=int(a);--i)
#define REP_1(i, n) for (int i=1;i<=int(n);++i)
#define FOR_1(i, a, b) for (int i=int(a);i<=int(b);++i)
#define DWN_1(i, b, a) for (int i=int(b);i>=int(a);--i)

#define ECH(it, A) for (__typeof(A.begin()) it=A.begin(); it != A.end(); ++it)
#define REP_S(i, str) for (char*i=str;*i;++i)
#define REP_L(i, hd, nxt) for (int i=hd;i;i=nxt[i])
#define REP_G(i, u) REP_L(i,hd[u],suc)
#define DO(n) for ( int ___nn ## __line__ = n; ___nn ## __line__ -- ; )

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

typedef long long LL;
typedef pair<int, int> PII;
typedef vector<PII> VII;

template<class T> inline T& RD(T &);
template<class T> inline void OT(const T &);
inline int RD(){int x; return RD(x);}

template<class T> inline void RST(T &A){memset(A, 0, sizeof(A));}
template<class T> inline void FLC(T &A, int x){memset(A, x, sizeof(A));}
template<class T> inline void CLR(T &A){A.clear();}

template<class T, class C> inline T& SRT(T &A, C B){sort(ALL(A), B); return A;}

//}

/** Constant List .. **/ //{
const int INF = 0x3f3f3f3f;

/** Add On .. **/
template<class T> inline void checkMin(T &a,const T b){if (b<a) a=b;}
inline LL _1(int i){return 1LL<<i;}
inline bool _1(int x, int i){return bool(x&1<<i);}

/** I/O Accelerator Interface .. **/ //{
template<class T> inline T& RD(T &x){
    char c; for (c = getchar(); c < '0'; c = getchar()); x = c - '0'; for (c = getchar(); '0' <= c && c <= '9'; c = getchar()) x = x * 10 + c - '0';
    return x;
}

inline char* RS(char *s){
    //gets(s);
    scanf("%s", s);
    return s;
}

LL last_ans; int Case; template<class T> inline void OT(const T &x){
    printf("%d\n", x);
}
//}

//}/* .................................................................................................................................. */

const int N = 509, M = 20009;

int D[N], hd[N], suc[M], to[M], cap[M];
int nn, n, m, s, t;

int A[N], AA[N]; VII E;

inline void add_edge(int x, int y, int c){
    suc[m] = hd[x], to[m] = y, cap[m] = c, hd[x] = m++;
    suc[m] = hd[y], to[m] = x, cap[m] = 0, hd[y] = m++;
}

inline void add_edgee(int x, int y, int c){
    suc[m] = hd[x], to[m] = y, cap[m] = c, hd[x] = m++;
    suc[m] = hd[y], to[m] = x, cap[m] = c, hd[y] = m++;
}

#define v to[i]
#define c cap[i]
#define r cap[i^1]

bool bfs(){
    static int Q[N]; int cz = 0, op = 1;
    fill(D, D+n, 0), D[Q[0] = s] = 1; while (cz < op){
        int u = Q[cz++]; REP_G(i, u) if (!D[v] && c){
            D[Q[op++] = v] = D[u] + 1;
            if (v == t) return 1;
        }
    }
    return 0;
}

LL Dinitz(){

    assert(to[0] == s);

    LL max_flow = 0; while (bfs()){

        static int sta[N], cur[N]; int top = 0;
        sta[0] = 0, cur[s] = hd[s]; while (top != -1){

            int u = to[sta[top]], i; if (u == t){
                int d = INF; REP_1(ii, top) i = sta[ii], checkMin(d, c); max_flow += d;
                DWN_1(ii, top, 1){i = sta[ii], c -= d, r += d; if (!c) top = ii - 1;}
                u =to[sta[top]];
            }

            for (i=cur[u];i;i=suc[i])
                if (D[u] + 1 == D[v] && c) break;

            if (!i) D[u] = 0, --top;
            else {
                cur[u] = suc[i], cur[v] = hd[v];
                sta[++top] = i;
            }
        }
    }
    return max_flow;
}


void init(){
    s = 0, t = RD(nn)+1, n = t + 1;
    CLR(E); Rush E.PB(MP(RD(), RD()));
    fill(A+1, A+t, 0); Rush A[RD()] = RD();
    REP_1(i, nn) AA[i] = A[i];
}

void solve(){
    REP(i, 32){
        m = 2, fill(hd, hd+n, 0);
        ECH(it, E) add_edgee(it->fi, it->se, 1);
        REP_1(ii, nn) if (A[ii]){
            if (_1(A[ii], i)) add_edge(s, ii, INF);
            else add_edge(ii, t, INF);
        }
        else {
            add_edge(s, ii, 1);
            add_edge(ii, t, 1);
        }
        Dinitz(); REP_1(ii, nn) if (!A[ii] && D[ii]) AA[ii] |= _1(i);
    }

    REP_1(ii, nn) OT(AA[ii]);
}

int main(){

#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif

    Rush{
        init(); solve();
    }
}
