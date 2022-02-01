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
typedef pair <int, int> PII;

namespace S1 {
const int N = 55;
const int INF = 1e9;
int n;
PII a[N];
int f[N][5005];

void checkmax(int &t, int x) {
    if (x > t) t = x;
}

bool cmp(const PII &a, const PII &b) {
    return min(-a.first, -a.first + a.second - b.first) > min(-b.first, -b.first + b.second - a.first);
} 

class AlbertoTheAviator { 
    public: 
    int MaximumFlights(int F, vector <int> duration, vector <int> refuel)  { 
        n = duration.size();
        rep (i, n) a[i] = make_pair(duration[i], refuel[i]);
        sort(a, a + n, cmp);
        rep (i, n + 1) rep (j, 5001) f[i][j] = -INF; 
        f[0][F] = 0;
        rep (i, n) rep (j, 5001) if (f[i][j] >= 0) {
            if (j >= a[i].first) {
                checkmax(f[i + 1][j - a[i].first + a[i].second], f[i][j] + 1);
            }
            checkmax(f[i + 1][j], f[i][j]);
        }
        int ans = 0;
        rep (j, 5001) if (f[n][j] > ans) ans = f[n][j];
        return ans;
    } 
};
}

namespace S2 {
const int N = 55;
const int INF = 1e9;
int n;
PII a[N];
int f[N][5005];

void checkmax(int &t, int x) {
    if (x > t) t = x;
}

bool cmp(const PII &a, const PII &b) {
    return min(-a.first, -a.first + a.second - b.first) > min(-b.first, -b.first + b.second - a.first);
} 

class AlbertoTheAviator { 
    public: 
    int MaximumFlights(int F, vector <int> duration, vector <int> refuel)  { 
        n = duration.size();
        rep (i, n) a[i] = make_pair(duration[i], refuel[i]);
        sort(a, a + n, cmp);
        rep (i, n + 1) rep (j, 5001) f[i][j] = -INF; 
        f[0][F] = 0;
        rep (i, n) rep (j, 5001) if (f[i][j] >= 0) {
            if (j >= a[i].first) {
                checkmax(f[i + 1][j - a[i].first + a[i].second], f[i][j] + 1);
            }
            checkmax(f[i + 1][j], f[i][j]);
        }
        int ans = 0;
        rep (j, 5001) if (f[n][j] > ans) ans = f[n][j];
        return ans;
    } 
};   
}

