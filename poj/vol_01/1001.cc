#include <iostream>
#include <cstdio>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <set>

#define inf 0x3f3f3f3f
#define Inf 0x3FFFFFFFFFFFFFFFLL

using namespace std;
int const maxn = 111111;
struct BigNum {
    int a[maxn];
    int len;
    BigNum (char *s) {
        int tl = strlen(s);
        len = 0;
        for (int i = tl - 1; i >= 0; --i) {
            if (s[i] != '.') a[len++] = s[i] - '0';
        }
    }
    BigNum () {
        len = 1;
        a[0] = 0;
    }
    void shrink() {
        for (int i = len - 1; i >= 0; --i) {
            if (a[i] != 0) {
                len = i + 1;
                break;
            }
        }
    }
    void init() {
        memset(a, 0, sizeof a);
    }
    BigNum operator * (BigNum B) {
        int tl = len + B.len + 10;
        BigNum C;
        C.init();
        for (int i = 0; i < len; ++i) {
            for (int j = 0; j < B.len; ++j) {
                C.a[i + j] += a[i] * B.a[j];
            }
        }
        for (int i = 0; i < tl; ++i) {
            C.a[i + 1] += C.a[i] / 10;
            C.a[i] %= 10;
        }
        for (int i = tl; i >= 1; --i) {
            if (C.a[i] != 0) {
                C.len = i + 1;
                break;
            }
        }
        return C;
    }
} A, B;

char str[maxn];
int ans[maxn], ant;

int main() {
    int n;
    while (~scanf("%s %d", str, &n)) {
        A = BigNum(str);
        B = A;
        for (int i = 1; i < n; ++i) {
            B = B * A;
        }
        B.shrink();
        int pos = 0;
        for (int i = strlen(str) - 1; i >= 0; --i) {
            if (str[i] == '.') {
                pos = strlen(str) - 1 - i;
                break;
            }
        }
        pos *= n;
        ant = 0;
        if (pos >= B.len) {
            ans[ant++] = -1;
            for (int i = pos - 1; i >= B.len; --i) ans[ant++] = 0;
            for (int i = B.len - 1; i >= 0; --i) ans[ant++] = B.a[i];
            for (int i = ant - 1; i >= 0; --i) {
                if (ans[i] != 0) {
                    if (ans[i] == -1) ant = i;
                    else ant = i + 1;
                    break;
                }
            }
        }
        else {
            for (int i = B.len - 1; i >= pos; --i) ans[ant++] = B.a[i];
            if (pos > 0) {
                ans[ant++] = -1;
                for (int i = pos - 1; i >= 0; --i) ans[ant++] = B.a[i];
                for (int i = ant - 1; i >= 0; --i) {
                    if (ans[i] != 0) {
                        if (ans[i] == -1) ant = i;
                        else ant = i + 1;
                        break;
                    }
                }
            }
        }
        for (int i = 0; i < ant; ++i) {
            if (ans[i] == -1) putchar('.');
            else printf("%d", ans[i]);
        }
        puts("");
    }
    return 0;
}
