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

#define inf 0x3f3f3f3f
#define Inf 0x3FFFFFFFFFFFFFFFLL
#define N 305
using namespace std;
char word[100100][N];
char str[N];
int lenw[100100];
int n, m;
int len;

int dp[N][2];

int rc, k;
int res[N];

void solve(int z) {
    memset(dp, 0xff, sizeof dp);
    dp[0][0] = dp[0][1] = 0;
    for (int i = 0; i < len; ++i) {
        if (dp[i][0] != -1) {
            for (int j = 0; j < n; ++j) {
                if (lenw[dp[i][0]] == 1 && lenw[j] == 1) continue;
                if (i + lenw[j] > len) continue;

                bool flag = true;
                for (int k = 0; k < lenw[j]; ++k) {
                    if (str[i + k] != word[j][k]) {
                        flag = false;
                        break;
                    }
                }
                if (flag) {
                    if (dp[i + lenw[j]][1] == -1 || dp[i][1] + 1 < dp[i + lenw[j]][1]) {
                        dp[i + lenw[j]][0] = j;
                        dp[i + lenw[j]][1] = dp[i][1] + 1;
                    }
                }
            }
        }
    }
    if (dp[len][0] != -1 && dp[len][1] * 2 < len) {
        if (dp[len][1] > rc) {
            k = z;
            rc = dp[len][1];
            int p = len, cc = 0;
            while (p != 0) {
                res[cc++] = dp[p][0];
                p -= lenw[ dp[p][0] ];
            }
        }
    }
}


int main() {
    n = 0, m = 0;
    while (gets(word[n])) {
        if ( strcmp(word[n], "") == 0 ) break;
        lenw[n] = strlen(word[n]);
        ++n;
    }
    while (gets(str)) {
        if ( strcmp(str, "0") == 0 ) break;
        len = strlen(str);
        rc = 0;
        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < len; ++j) {
                ++str[j]; if (str[j] > 'z') str[j] = 'a';
            }
            solve(25 - i);
        }
        if (rc == 0) puts("NO SOLUTIONS");
        else {
            printf("k=%d:", k);
            for (int i = rc - 1; i >= 0; --i) printf(" %s", word[res[i]]);
            puts("");
        }
    }

    return 0;
}
