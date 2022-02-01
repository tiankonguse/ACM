#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <sstream>

#define inf 0x3f3f3f3f
#define Inf 0x3FFFFFFFFFFFFFFFLL
#define maxn 70
using namespace std;
typedef unsigned __int64 ull;
char const rus[] = {'A', 'B', 'C', 'E', 'H', 'K', 'M', 'O', 'P', 'T', 'X', 'a', 'c', 'e', 'o', 'p', 'x', 'y', 0};
bool mark[256];
int st[maxn], snt;
ull dp[maxn][maxn];

int main() {

    memset(mark, false, sizeof mark);
    for (int i = 0; rus[i]; ++i) mark[ rus[i] ] = true;
    int q, c;
    string str, s;
    while ( cin >> q >> c ) {
        cin.ignore();
        getline(cin, str);
        ull cnt = 0; snt = 0;
        istringstream is(str);
        while (is >> s) {
            st[snt] = s.length();
            for (int i = 0; i < st[snt]; ++i) {
                cnt += mark[ s[i] ];
            }
            ++snt;
        }
        memset(dp, 0, sizeof dp);
        dp[0][0] = 1;
        for (int i = 0; i < snt; ++i) {
            for (int j = 0; j + st[i] <= c; ++j) {
                if (dp[i][j] > 0) {
                    for (int k = 0; ; ++k) {
                        if (i == 0) {
                            if (j + k + st[i] > c) break;
                            dp[i + 1][j + k + st[i]] += dp[i][j];
                        }
                        else {
                            if (j + k + st[i] + 1 > c) break;
                            dp[i + 1][j + k + st[i] + 1] += dp[i][j];
                        }
                    }
                }
            }
        }

        ull ret = 0;
        for (int i = 0; i <= c; ++i) {
            if (dp[snt][i]) {
                if (i < q) ret += dp[snt][i] * (c - q + 1);
                else  ret += dp[snt][i] * (c - i + 1);
            }
        }
        if (ret == 0) cout << 0 << endl;
        else cout<< ret * (1ULL << cnt) - 1 << endl;
    }
    return 0;
}

