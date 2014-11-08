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
typedef pair <int, int> PII;
typedef vector <int> VI;
const int N = 55;
int n, m;
int a[N][N];
int used[N];

bool ok(vector <int> result) {
    clr(used, 0);
    vector <int> g(1, n);
    rep (k, m) {
        int cur = -1;
        rep (c, m) if (!used[c]) {
            bool flag = 1;
            int base = 0;
            rep (i, g.size()) {
                rep (j, g[i] - 1) {
                    int idx = base + j;
                    if (a[result[idx]][c] > a[result[idx + 1]][c]) {
                        flag = 0;
                    }
                }
                base += g[i];
            }
            if (flag) {
                cur = c;
                break;
            }
        }
        if (cur == -1) return 0;
        //printf("%d\n", cur);
        vector <int> newg;
        used[cur] = 1;
        int base = 0;
        rep (i, g.size()) {
            rep (j, g[i]) {
                int idx = base + j;
                if (j == 0 || a[result[idx]][cur] != a[result[idx - 1]][cur]) {
                    newg.push_back(1);
                } else {
                    newg.back()++;
                }
            }
            base += g[i];
        }
        g = newg;
        //printf("g : ");
        //rep (i, g.size()) printf("%d, ", g[i]);
        //puts("");
    }
    return 1;
}

class CandidatesSelection { 
    public: 
    string possible(vector <string> score, vector <int> result)  { 
        n = score.size();
        m = score[0].size();
        rep (i, n) {
            rep (j, m) {
                a[i][j] = score[i][j] - 'A';
            }
            a[i][m] = i;
        }
        m++;
        return ok(result) ? "Possible" : "Impossible";
    } 
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"CC", "AA", "BB"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2,0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Possible"; verify_case(0, Arg2, possible(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"BAB", "ABB", "AAB", "ABA"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2,0,1,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Possible"; verify_case(1, Arg2, possible(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"BAB", "ABB", "AAB", "ABA"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 1, 3, 2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Impossible"; verify_case(2, Arg2, possible(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"AAA", "ZZZ"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Impossible"; verify_case(3, Arg2, possible(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"ZZZ", "AAA"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Possible"; verify_case(4, Arg2, possible(Arg0, Arg1)); }
	void test_case_5() { string Arr0[] = {"ZYYYYX","YXZYXY","ZZZZXX","XZXYYX","ZZZYYZ","ZZXXYZ","ZYZZXZ","XZYYZX"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {3,7,1,0,2,5,6,4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Possible"; verify_case(5, Arg2, possible(Arg0, Arg1)); }

// END CUT HERE
 
}; 
 
    // BEGIN CUT HERE 
int main() {
    CandidatesSelection ___test; 
    ___test.run_test(-1); 
} 
    // END CUT HERE 
