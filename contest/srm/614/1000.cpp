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

double f[105][105];

class TorusSailing { 
    public: 
    double expectedTime(int N, int M, int goalX, int goalY)  { 
        clr(f, 0);
        rep (it, 10000) {
            rep (_i, N) rep (_j, M) {
                int i = goalX - _i, j = goalY - _j;
                if (i < 0) i += N;
                if (j < 0) j += M;
                if (i != goalX || j != goalY) {
                    int ni = (i + 1) % N, nj = (j + 1) % M;
                    f[i][j] = 1 + (f[ni][j] + f[i][nj]) / 2;
                }
            }
        }
        return f[0][0];
    } 
    
 
}; 
 


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
