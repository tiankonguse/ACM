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

const int M = 32000;
const int N = 405;
const int Mod = 1000000007;
int n, len;
bitset <N> a[N];

void add(const bitset <N> &se) {
    if (len == -1) return;
    a[len++] = se;
    int st = 0;
    rep (k, n) {
        bool flag = 0;
        for (int i = st; i < len; i++) {
            if (a[i][k]) {
                flag = 1;
                swap(a[i], a[st]);
                break;
            }
        }
        if (!flag) continue;
        for (int i = st + 1; i < len; i++) {
            if (a[i][k]) {
                a[i] ^= a[st];
            }
        }
        st++;
    }
    while (len > 0 && a[len - 1].count() == 0) len--;
    rep (i, len) {
        if (a[i].count() == 1 && a[i][n]) {
            len = -1;
            return;
        }
    }
}

int powmod(ll a, int b) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % Mod;
        a = a * a % Mod;
        b >>= 1;
    }
    return res;
}

class PerfectSquare { 
    public: 
    int ways(vector <int> x)  { 
        clr(a, 0);
        n = x.size();
        map <int, vector <int> > mp;
        rep (i, n) {
            int e = x[i];
            for (int k = 2; k * k <= e; k++) {
                if (e % k == 0) {
                    int cnt = 0;
                    while (e % k == 0) {
                        e /= k;
                        cnt ^= 1;
                    }
                    if (cnt == 1) {
                        mp[k].push_back(i);
                    }
                }
            }
            if (e != 1) mp[e].push_back(i);
        }
        int m = 1;
        while (m * m < n) m++;
        len = 0;
        rep (i, m) {
            bitset <N> cur;
            rep (j, m) cur[i * m + j] = 1;
            cur[n] = 1;
            add(cur);
            cur.reset();
            rep (j, m) cur[j * m + i] = 1;
            cur[n] = 1;
            add(cur);
        }
        foreach (it, mp) {
            bitset <N> cur;
            for (int idx : it->second) {
                cur[idx] = 1;
            }
            cur[n] = 0;
            add(cur);
        }
        if (len == -1) return 0;
        return powmod(2, n - len);
    }
    
 
}; 
 


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
