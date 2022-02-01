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

using namespace std;
char a[11], b[11];
bool marka[11];
bool markb[11];
int main() {
    int r1, r2;
    while (~scanf(" %s %s", a, b)) {
        r1 = r2 = 0;
        memset(marka, false, sizeof marka);
        memset(markb, false, sizeof markb);
        for (int i = 0; i < 4; ++i) {
            if (a[i] == b[i]) {
                ++r1;
                marka[i] = markb[i] = true;
            }
        }
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                if (!marka[i] && !markb[j] && a[i] == b[j]) {
                    ++r2;
                    marka[i] = markb[j] = true;
                }
            }
        }
        printf("%d %d\n", r1, r2);
    }
    return 0;
}
