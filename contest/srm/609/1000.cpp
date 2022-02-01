#include <cstdio>
#include <cstring>
#include <cctype>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <iostream>
#include <map>
#include <set>
#include <list>
#include <sstream>
#include <queue>
#include <deque>
#include <stack>
#include <vector>
#include <bitset>
#include <algorithm>
using namespace std;
#define foreach(it, v) for (__typeof((v).end()) it = (v).begin(); it != (v).end(); it++)
#define clr(a, x) memset(a, x, sizeof(a))
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define iter(v) __typeof((v).end())
#define all(v) (v).begin(), (v).end()
typedef vector <int> VI;
typedef long long ll;
const int N = 105;
int P;
map <ll, bool> f[N];
VI E[N];
int mat[N][N];
int Link[N];
int cover[N];

bool find(const int &n, const int &u, const int &t) {
    rep (v, n) if (cover[v] != t && mat[u][v]) {
        cover[v] = t;
        int q = Link[v];
        Link[v] = u;
        if (q == -1 || find(n, q, t)) return 1;
        Link[v] = q;
    }
    return 0;
}

int maxMatch(int n) {
    fill(Link, Link + n, -1);
    fill(cover, cover + n, 0);
    int t = 0, res = 0;
    rep (i, n)
        if (find(n, i, ++t)) 
            res++;
    /*
    rep (i, n) {
        rep (j, n) putchar(mat[i][j] ? '1' : '0');
        puts("");
    }
    puts("END GRAPH");
    */
    return res;
}

bool cross(ll i, ll n) {
    ll lhs = i * P / n;                 //floor((i / P) / (1 / n))
    ll rhs = ((i + 1) * P - 1) / n;     //floor((i+1)/P) / (1 / n) - eps)
    return lhs != rhs;
}

bool check(int u, ll i, ll n) {
    if (f[u].count(i)) return f[u][i];
    if (!cross(i, n)) return 1;
    int d = E[u].size();
    if (d == 0) return f[u][i] = 0;
    rep (_, d) rep (j, d) {
        int v = E[u][_];
        check(v, i * d + j, n * d);
    }
    rep (j, d) rep (k, d) mat[j][k] = 0;
    rep (_, d) rep (j, d) {
        int v = E[u][_];
        mat[_][j] = check(v, i * d + j, n * d);
    }
    return f[u][i] = (maxMatch(d) == d);
}

class LotteryTree { 
    public: 
    string isFairTree(VI tree, int P)  { 
        ::P = P;
        rep (i, tree.size() + 1) f[i].clear(), E[i].clear();
        rep (i, tree.size()) E[tree[i]].push_back(i + 1);
        return (check(0, 0, 1) ? "YES" : "NO");
    } 
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); if ((Case == -1) || (Case == 7)) test_case_7(); if ((Case == -1) || (Case == 8)) test_case_8(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0, 0, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; string Arg2 = "YES"; verify_case(0, Arg2, isFairTree(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {0, 0, 0, 1, 1, 2, 2, 3, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; string Arg2 = "YES"; verify_case(1, Arg2, isFairTree(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {0, 0, 1, 1, 2, 2, 4, 4, 4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; string Arg2 = "NO"; verify_case(2, Arg2, isFairTree(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {0, 0, 1, 1, 1, 3, 3, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; string Arg2 = "NO"; verify_case(3, Arg2, isFairTree(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {0, 0, 0, 3, 0, 0, 3, 6, 3, 1, 0, 2, 0, 4, 6, 15, 1, 15, 11, 11, 1, 4, 11, 2, 11, 2, 6}
; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; string Arg2 = "YES"; verify_case(4, Arg2, isFairTree(Arg0, Arg1)); }
	void test_case_5() { int Arr0[] = {0, 1, 2, 3, 1, 1, 4, 4, 0, 1, 6, 9, 1, 12, 9, 2, 4, 8, 6, 13, 8, 5, 11, 12, 17, 
 19, 13, 9, 3, 24, 30, 29, 28, 28, 11, 27, 2, 26, 6, 14, 8, 26, 15, 25, 33, 38, 
 1, 24, 15, 43, 3, 39, 26, 8, 13, 50, 28, 8, 6, 27, 8, 38, 27, 50, 17, 50, 25, 
 40, 7, 29, 22, 40, 2, 24, 22, 30, 33, 40, 19, 14, 26, 39, 5, 43, 7, 4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 9; string Arg2 = "NO"; verify_case(5, Arg2, isFairTree(Arg0, Arg1)); }
	void test_case_6() { int Arr0[] = {0, 1, 0, 0, 4, 0, 2, 2, 0, 2, 6, 1, 3, 6, 5, 9, 11, 13, 1, 10, 14, 4, 7, 21,
 16, 8, 25, 4, 5, 22, 25, 14, 12, 11, 12, 26, 21, 8, 2, 38, 3, 5, 4, 38, 27, 
 35, 38, 30, 38, 9, 16, 36, 6, 10, 7, 27, 30, 33, 17, 26, 17, 10, 35, 10, 38,
 41, 15, 9, 3, 27, 8, 15, 38, 22, 41, 33, 33, 36, 30, 13, 18, 22, 18}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 12; string Arg2 = "YES"; verify_case(6, Arg2, isFairTree(Arg0, Arg1)); }
	void test_case_7() { int Arr0[] = {0, 0, 2, 3, 4, 3, 2, 1, 8, 6, 8, 8, 2, 7, 14, 2, 8, 1, 11, 11, 12, 16, 12, 
 19, 20, 13, 7, 12, 26, 11, 18, 19, 18, 20, 4, 9, 1, 1, 6, 16, 1, 35, 27, 24,
 37, 30, 36, 41, 32, 36, 8, 2, 6, 14, 41, 1, 35, 6, 30, 16, 12, 2, 35, 25, 50,
 13, 1, 24, 8, 32, 26, 50, 9, 19, 9, 20, 26, 27, 6, 12, 25, 9, 37, 37, 9} ; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 7; string Arg2 = "NO"; verify_case(7, Arg2, isFairTree(Arg0, Arg1)); }
	void test_case_8() { int Arr0[] = {0, 0, 1, 0, 2, 3, 0, 0, 8, 5, 7, 5, 2, 12, 12, 14, 14, 13, 8, 2, 1, 7, 18,
 16, 8, 24, 18, 2, 24, 3, 11, 5, 24, 4, 34, 6, 31, 13, 38, 19, 4, 3, 22, 3,
 11, 12, 21, 34, 41, 8, 19, 4, 13, 29, 33, 8, 14, 50, 18, 45, 16, 50, 44, 50,
 38, 5, 43, 31, 29, 7, 6, 45, 38, 4, 19, 41, 50, 21, 44, 41, 43, 22, 33, 6, 8}
; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 12; string Arg2 = "YES"; verify_case(8, Arg2, isFairTree(Arg0, Arg1)); }

// END CUT HERE
 
}; 
 
    // BEGIN CUT HERE 
int main() {
    LotteryTree ___test; 
    ___test.run_test(-1); 
} 
    // END CUT HERE 
