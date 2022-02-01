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
#define maxn 1001000
using namespace std;
char str[maxn];
int num[maxn], res[maxn];
int len;
bool check(int a) {
    if (a == 10) {
        num[0] = 1, num[1] = 0;
        int ret = 0;
        for (int i = 0; i < len + 2; ++i) {
            ret = ret * 10 + num[i];
            ret %= 11;
        }
        return ret == 0;
    }
    else {
        num[1] = a;
        int ret = 0;
        for (int i = 1; i < len + 2; ++i) {
            ret = ret * 10 + num[i];
            ret %= 11;
        }
        return ret == 0;
    }
}
void cal(int a) {
    if (a == 10) {
        num[0] = 1, num[1] = 0;
        int r = 0;
        for (int i = 0; i < len + 2; ++i) {
            r = r * 10 + num[i];
            res[i] = r / 11;
            r %= 11;
        }
    }
    else {
        num[0] = 0;
        num[1] = a;
        int r = 0;
        for (int i = 0; i < len + 2; ++i) {
            r = r * 10 + num[i];
            res[i] = r / 11;
            r %= 11;
        }
    }
}
int main() {
    int _ca = 1;
    while (scanf(" %s", str)) {
        if (strcmp(str, "0") == 0) break;
        len = strlen(str);
        for (int i = 0; i < len; ++i) num[i + 2] = str[i] - '0';
        bool flag = false;
        int ret;
        for (int i = 1; i <= 10; ++i) {
            if (check(i)) {
                flag = true;
                ret = i;
                break;
            }
        }
        if (!flag) printf("%d. IMPOSSIBLE\n", _ca++);
        else {
            printf("%d. ", _ca++);
            cal(ret);
            for (int i = 2; i < len + 2; ++i) printf("%d", res[i]);
            puts("");
        }
    }
    return 0;
}
