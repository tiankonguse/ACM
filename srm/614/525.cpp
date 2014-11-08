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
typedef long long ll;
const int Mod = 1000000007;
int f[1000005][2];
int f2[1000005][2];
int g[55][2];
ll K;

void init() {
    clr(f, 0);
    clr(f2, 0);
    f[0][1] = 1;
    f[1][1] = K - 1;
    for (int i = 2; i <= 1000000; i++) {
        f[i][0] = f[i - 1][1];
        f[i][1] = (f[i - 1][0] * (K - 1) % Mod + f[i - 1][1] * (K - 2) % Mod) % Mod;
    }
    f2[0][1] = 1;
    f2[1][1] = K - 2;
    f2[1][0] = 1;
    for (int i = 2; i <= 1000000; i++) {
        f2[i][0] = f2[i - 1][1];
        f2[i][1] = (f2[i - 1][1] * (K - 2) % Mod + f2[i - 1][0] * (K - 1) % Mod) % Mod;
    }
}

int diff(int x, int y, int n) {
    if (x <= y) return y - x - 1;
    return y + n - x - 1;
}

bool near(int x, int y, int n) {
    return diff(x, y, n) == 0 || diff(y, x, n) == 0;
}

void add(int &t, ll x) {
    x %= Mod;
    t += x;
    t %= Mod;
}

ll countLink(int x, int y, int n, bool o /*same or not*/) {
    if (o) {
        if (near(x, y, n)) return 0;
        return f[diff(x, y, n)][1] * (ll)f[diff(y, x, n)][1] % Mod;
    } else {
        return f2[diff(x, y, n)][1] * (ll)f2[diff(y, x, n)][1] % Mod;
    }
}

int gao(vector <int> c, vector <int> St, vector <int> Ed, ll K) {
        ::K = K;
        set <int> s[55];
        int n = c.size();
        rep (i, n) {
            int j = (i + 1) % n;
            s[i].insert(St[i]);
            s[j].insert(Ed[i]);
        }
        init();
        clr(g, 0);
        int cnt = 0;
        if (s[0].size() == 1) {
            g[0][0] = K * f[c[0] - 1][1] % Mod;
        } else {
            int x = *s[0].begin();
            int y = *++s[0].begin();
            g[0][0] = K * countLink(x, y, c[0], 1) % Mod;
            g[0][1] = K * (K - 1) % Mod * countLink(x, y, c[0], 0) % Mod;
        }
        rep (d, n) {
            if (!d) continue;
            if (s[d].size() == 2) {
                int x = *s[d].begin();
                int y = *++s[d].begin();
                ll tmp = countLink(x, y, c[d], 1);
                add(g[d][0], tmp * g[d - 1][0] % Mod);
                add(g[d][1], tmp * g[d - 1][1] % Mod);
                tmp = countLink(x, y, c[d], 0);
                add(g[d][0], g[d - 1][1] * tmp % Mod);
                add(g[d][1], g[d - 1][1] * tmp % Mod * (K - 2) % Mod + g[d - 1][0] * tmp % Mod * (K - 1) % Mod);
            } else {
                ll tmp = f[c[d] - 1][1];
                add(g[d][1], g[d - 1][1] * tmp % Mod);
                add(g[d][0], g[d - 1][0] * tmp % Mod);
            }
        }
        return g[n - 1][0];
}

class CycleColoring { 
    public: 
    int countColorings(vector <int> c, vector <int> st, vector <int> ed, int K)  { 
        return gao(c, st, ed, K);
    } 
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {3, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0, 0}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 3; int Arg4 = 12; verify_case(0, Arg4, countColorings(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arr0[] = {6}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 3; int Arg4 = 12; verify_case(1, Arg4, countColorings(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arr0[] = {3, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1, 2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 3; int Arg4 = 0; verify_case(2, Arg4, countColorings(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arr0[] = {9, 5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {8, 3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0, 2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 8; int Arg4 = 589124602; verify_case(3, Arg4, countColorings(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arr0[] = {14, 15, 16, 17}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {5, 10, 4, 6}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {10, 3, 14, 10}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 614; int Arg4 = 818050159; verify_case(4, Arg4, countColorings(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_5() { int Arr0[] = {482373, 283712, 883, 12834, 5, 5, 482734, 99912, 35881, 277590}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {59283, 49782, 0, 0, 3, 2, 84791, 40017, 2263, 461}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {150173, 709, 11108, 0, 4, 7, 5902, 712, 190232, 390331}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 479360784; int Arg4 = 763634309; verify_case(5, Arg4, countColorings(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE
 
}; 
 
    // BEGIN CUT HERE 
int main() {
    CycleColoring ___test; 
    ___test.run_test(-1); 
} 
    // END CUT HERE 
