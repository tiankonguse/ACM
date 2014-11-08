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
const int Mod = 1e9 + 7.5;
bool is[100005];

int powmod(ll a, int b) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % Mod;
        a = a * a % Mod;
        b >>= 1;
    }
    return res;
}

class RandomGCD { 
    public: 
    int countTuples(int N, int K, int low, int high)  { 
        clr(is, 1);
        for (int i = 2; i <= 100000; i++)
            for (int j = i + i; j <= 100000; j += i)
                is[j] = 0;
        low = (low + K - 1) / K;
        high = high / K;
        if (low > high) return 0;
        static int a[100005];
        static vector <int> factor[100005];
        for (int i = low; i <= high; i++) a[i - low] = i, factor[i - low].clear();
        for (int i = 2; i * i <= high; i++) {
            if (is[i]) {
                for (int j = low / i * i; j <= high; j += i) {
                    if (j >= low) {
                        factor[j - low].push_back(i);
                        while (a[j - low] % i == 0) {
                            a[j - low] /= i;
                        }
                    }
                }
            }
        }
        for (int i = low; i <= high; i++) {
            if (a[i - low] != 1) {
                factor[i - low].push_back(a[i - low]);
            }
        }
        //printf("%d %d\n", low, high);
        map <PII, int> mp;
        for (int i = low; i <= high; i++) {
            vector <int> &f = factor[i - low];
            for (int mask = 1; mask < 1 << f.size(); mask++) {
                int sgn = 1;
                int num = 1;
                rep (j, f.size()) {
                    if (mask & 1 << j) {
                        num *= f[j];
                        sgn = -sgn;
                    }
                }
                mp[PII(num, sgn)]++;
            }
        }
        ll ans = powmod(high - low + 1, N);
        foreach (it, mp) {
            //printf("mp %d %d %d\n", it->first.first, it->first.second, it->second);
            ans += it->first.second * (ll)powmod(it->second, N) % Mod;
            if (ans >= Mod) ans -= Mod;
            if (ans < 0) ans += Mod;
        }
        return ans;
    }
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 2; int Arg2 = 2; int Arg3 = 4; int Arg4 = 3; verify_case(0, Arg4, countTuples(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 100; int Arg2 = 2; int Arg3 = 4; int Arg4 = 0; verify_case(1, Arg4, countTuples(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 1; int Arg1 = 5; int Arg2 = 5; int Arg3 = 5; int Arg4 = 1; verify_case(2, Arg4, countTuples(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 73824; int Arg1 = 17347; int Arg2 = 9293482; int Arg3 = 9313482; int Arg4 = 0; verify_case(3, Arg4, countTuples(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arg0 = 222; int Arg1 = 222; int Arg2 = 222; int Arg3 = 22222; int Arg4 = 339886855; verify_case(4, Arg4, countTuples(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE
 
}; 
 
    // BEGIN CUT HERE 
int main() {
    RandomGCD ___test; 
    ___test.run_test(-1); 
} 
    // END CUT HERE 
