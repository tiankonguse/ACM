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
class MinimumSquare { 
    public: 
    long long minArea(vector <int> x, vector <int> y, int K)  { 
        int n = x.size();
        ll ans = 1LL << 62;
        rep (i, n) {
            rep (j, n) {
                int lx, ly;
                lx = x[i] - 1;
                ly = y[j] - 1;
                rep (k, n) {
                    ll len = x[k] + 1 - lx;
                    if (len >= 1) {
                        int cnt = 0;
                        rep (o, n) {
                            if (lx < x[o] && x[o] < lx + len && ly < y[o] && y[o] < ly + len) {
                                cnt++;
                            } 
                        }
                        if (cnt >= K) {
                            ans = min(ans, (ll)(len) * len);
                        }                    
                    }
                    len = y[k] + 1 - ly;
                    if (len >= 1) {
                        int cnt = 0;
                        rep (o, n) {
                            if (lx < x[o] && x[o] < lx + len && ly < y[o] && y[o] < ly + len) {
                                cnt++;
                            } 
                        }
                        if (cnt >= K) {
                            ans = min(ans, (ll)(len) * len);
                        }
                    }
                }
            }
        }
        return ans;
    } 
    
 
}; 
 


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
