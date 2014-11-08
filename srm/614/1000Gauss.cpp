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
#include <cassert>
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
typedef pair <int, int> PII;
typedef vector <int> VI;
typedef vector <double> VD;
const int N = 205;
int v;
VD co[105][105];
double a[205][205], x[205];

VD add(const VD &a, const VD &b) {
    VD res = VD(v, 0);
    rep (i, v) res[i] = a[i] + b[i];
    return res;
}

VD mul(const VD &a, const double &b) {
    VD res = VD(v, 0);
    rep (i, v) res[i] = a[i] * b;
    return res;
}

void solve(int m, int n) {
    rep (k, n) {
        bool flag = 0;
        int idx = k;
        for (int i = k + 1; i < m; i++) {
            if (fabs(a[i][k]) > fabs(a[idx][k])) {
                idx = i;
            }
        }
        rep (j, n + 1) swap(a[k][j], a[idx][j]);
        for (int i = k + 1; i < m; i++) {
            double mul = a[i][k] / a[k][k];
            for (int j = k; j < n + 1; j++) {
                a[i][j] -= a[k][j] * mul;
            }
        }
    }
    for (int k = n - 1; ~k; k--) {
        double &res = x[k];
        res = 0;
        for (int i = k + 1; i < n; i++) {
            res += x[i] * a[k][i];
        }
        res += a[k][n];
        res = -res / a[k][k];
    }
}

class TorusSailing { 
    public: 
    double expectedTime(int N, int M, int goalY, int goalX)  { 
        v = N + M;
        for (int i = 0; i < N; i++) {
            co[0][i] = VD(v, 0);
            co[0][i][i] = i > 0;
        }
        for (int i = 1; i < M; i++) {
            co[i][0] = VD(v, 0);
            co[i][0][i + N - 1] = 1;
        }
        for (int i = 1; i < M; i++) {
            for (int j = 1; j < N; j++) {
                co[i][j] = mul(add(co[i - 1][j], co[i][j - 1]), 0.5);
                co[i][j][v - 1]++;
            }
        }
        int c = 1;
        clr(a, 0);
        a[0][0] = 1;
        for (int i = 1; i < N; i++) {
            VD cur = mul(add(co[0][(i - 1 + N) % N], co[M - 1][i]), 0.5);
            cur[v - 1]++;
            cur[i]--;
            rep (j, v) a[c][j] = cur[j];
            c++;
        }
        for (int i = 1; i < M; i++) {
            VD cur = mul(add(co[i - 1][0], co[i][N - 1]), 0.5);
            cur[v - 1]++;
            cur[N + i - 1]--;
            rep (j, v) a[c][j] = cur[j];
            c++;
        }
        solve(c, c);
        double ans = 0;
        rep (i, v - 1) ans += co[goalX][goalY][i] * x[i];
        ans += co[goalX][goalY][v - 1];
        return ans;
    } 
    
// BEGIN CUT HERE
    public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
    private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { int Arg0 = 2; int Arg1 = 2; int Arg2 = 1; int Arg3 = 1; double Arg4 = 4.0; verify_case(0, Arg4, expectedTime(Arg0, Arg1, Arg2, Arg3)); }
    void test_case_1() { int Arg0 = 3; int Arg1 = 3; int Arg2 = 0; int Arg3 = 2; double Arg4 = 8.0; verify_case(1, Arg4, expectedTime(Arg0, Arg1, Arg2, Arg3)); }
    void test_case_2() { int Arg0 = 7; int Arg1 = 10; int Arg2 = 3; int Arg3 = 2; double Arg4 = 51.80060107964039; verify_case(2, Arg4, expectedTime(Arg0, Arg1, Arg2, Arg3)); }
    void test_case_3() { int Arg0 = 100; int Arg1 = 100; int Arg2 = 99; int Arg3 = 99; double Arg4 = 9992.616372325532; verify_case(3, Arg4, expectedTime(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE
 
}; 
 
    // BEGIN CUT HERE 
int main() {
    TorusSailing ___test; 
    ___test.run_test(-1); 
} 
    // END CUT HERE 
