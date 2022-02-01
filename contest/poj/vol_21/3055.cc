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
#include <ctime>

#define inf 0x3f3f3f3f
#define Inf 0x3FFFFFFFFFFFFFFFLL

using namespace std;
int const maxn = 110;
char A[maxn], B[maxn];
int cA[10], cB[10];

int main() {
    int T;
    for (scanf("%d", &T); T--; ) {
        scanf(" %s %s", A, B);
        int rA = 0, rB = 0;
        memset(cA, 0, sizeof cA);
        memset(cB, 0, sizeof cB);
        for (int i = 0; A[i]; ++i) cA[ A[i] - '0' ]++;
        for (int i = 0; B[i]; ++i) cB[ B[i] - '0' ]++;
        for (int i = 0; i <= 9; ++i) {
            if (cA[i]) rA |= (1 << i);
            if (cB[i]) rB |= (1 << i);
        }

        if (rA == rB) puts("friends");
        else {
            bool flag = false;
            for (int i = 0; A[i + 1] && !flag; ++i) {
                int a = A[i] - '0', b = A[i + 1] - '0';
                if (a - 1 >= 0 && b + 1 <= 9 && !(a - 1 == 0 && i == 0) ) {
                    int c = 0, t = 0;
                    for (int k = 0; k < 10; ++k) {
                        c = cA[k];
                        if (k == a) --c;
                        if (k == a - 1) ++c;
                        if (k == b) --c;
                        if (k == b + 1) ++c;
                        if (c) t |= (1 << k);
                    }
                    if (t == rB) flag = true;
                }
                if (a + 1 <= 9 && b - 1 >= 0) {
                    int c = 0, t = 0;
                    for (int k = 0; k < 10; ++k) {
                        c = cA[k];
                        if (k == a) --c;
                        if (k == a + 1) ++c;
                        if (k == b) --c;
                        if (k == b - 1) ++c;
                        if (c) t |= (1 << k);
                    }
                    if (t == rB) flag = true;
                }
            }
            for (int i = 0; B[i + 1]; ++i) {
                int a = B[i] - '0', b = B[i + 1] - '0';
                if (a - 1 >= 0 && b + 1 <= 9 && !(a - 1 == 0 && i == 0) ) {
                    int c = 0, t = 0;
                    for (int k = 0; k < 10; ++k) {
                        c = cB[k];
                        if (k == a) --c;
                        if (k == a - 1) ++c;
                        if (k == b) --c;
                        if (k == b + 1) ++c;
                        if (c) t |= (1 << k);
                    }
                    if (t == rA) flag = true;
                }
                if (a + 1 <= 9 && b - 1 >= 0) {
                    int c = 0, t = 0;
                    for (int k = 0; k < 10; ++k) {
                        c = cB[k];
                        if (k == a) --c;
                        if (k == a + 1) ++c;
                        if (k == b) --c;
                        if (k == b - 1) ++c;
                        if (c) t |= (1 << k);
                    }
                    if (t == rA) flag = true;
                }
            }
            if (flag) puts("almost friends");
            else puts("nothing");
        }
    }
    return 0;
}
