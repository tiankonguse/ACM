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
#define maxn 100100
using namespace std;
char str[maxn];

int main() {
    int n;
    while (~scanf("%d", &n)) {
        scanf(" %s", str);
        int lc = 0, rc = 0, oc = 0, cc = 0;
        int f1 = -1;
        int len = strlen(str);
        for (int i = 0; i < len; ++i) {
            if (str[i] != '0') {
                if (f1 == -1) lc = i;
                else {
                    if (cc != 0 && str[i] - '0' == f1) ++oc;
                }
                f1 = str[i] - '0';
                cc = 0;
            }
            else ++cc;
        }
        if (cc == len) {
            if (cc % 2 == 1) puts("FIRST");
            else puts("SECOND");
            continue;
        }
        rc = cc;
        bool flagL = true, flagR = true;
        if (lc == 0) flagL = false;
        if (lc == 1) flagL = false, ++oc;
        if (rc == 0) flagR = false;
        if (rc == 1) flagR = false, ++oc;
        if (flagL && flagR) {
            if (lc == rc) {
                if (oc % 2 == 0) puts("SECOND");
                else puts("FIRST");
            }
            else {
                if (oc % 2 == 0) puts("FIRST");
                else {
                    if (abs(lc - rc) == 1) {
                       puts("SECOND");
                    }
                    else puts("FIRST");
                }
            }
        }
        else {
            if (flagL != flagR) puts("FIRST");
            else {
                if (oc % 2 == 0) puts("SECOND");
                else puts("FIRST");
            }
        }
    }
    return 0;
}

