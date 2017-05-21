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
#define maxn 101
using namespace std;
char sa[maxn], sb[maxn];
int a[maxn], b[maxn], c[maxn];

int canonical(int s[], int len) {
    bool flag;
    while (1) {
        flag = false;
        for (int i = 0; i < len - 1; ++i) {
            if (s[i] >= 1 && s[i + 1] >= 1) {
                flag = true;
                break;
            }
        }
        if (!flag) break;
        for (int i = len - 1; i > 0; -- i) {
            if (s[i] >= 1 && s[i - 1] >= 1) {
                s[i + 1]++, s[i]--, s[i - 1]--;
                len = max(len, i + 2);
            }
        }
    }
    for (int i = len - 1; i > 0; --i) {
        if (s[i] == 0) --len;
        else break;
    }
    return len;
}
int solve(int s[], int len) {
    bool flag;
    while (1) {
        flag = false;
        for (int i = 0; i < len; ++i) {
            if (s[i] > 1) {
                flag = true;
                s[i] -= 2;
                len = max(len, i + 2);
                if (i == 0) {
                    s[i + 1]++;
                }
                else if (i == 1) {
                    s[i - 1]++;
                    s[i + 1]++;
                }
                else {
                    s[i + 1]++;
                    s[i - 2]++;
                }
            }
        }
        if (!flag) break;
    }
    return len;
}
int main() {
    int la, lb, lc;
    while (~scanf(" %s %s", sa, sb)) {
        la = strlen(sa), lb = strlen(sb);
        reverse(sa, sa + la), reverse(sb, sb + lb);
        memset(a, 0, sizeof a);
        memset(b, 0, sizeof b);
        for (int i = 0; i < la; ++i) a[i] = sa[i] - '0';
        for (int i = 0; i < lb; ++i) b[i] = sb[i] - '0';
        la = canonical(a, la);
        lb = canonical(b, lb);
//        for (int i = la - 1; i >= 0; --i) cout << a[i]; cout << endl;
//        for (int i = lb - 1; i >= 0; --i) cout << b[i]; cout << endl;
        lc = max(la, lb);
        memset(c, 0, sizeof c);
        for (int i = 0; i < lc; ++i) {
            if (i < la) c[i] += a[i];
            if (i < lb) c[i] += b[i];
        }
        lc = solve(c, lc);
        lc = canonical(c, lc);
//        for (int i = lc - 1; i >= 0; --i) cout << c[i] ; cout << endl;
        int len = max(la, max(lb, lc)) + 2;
        int pa = len - la, pb = len - lb - 1, pc = len - lc;
        for (int i = 0; i < pa; ++i) putchar(' ');
        for (int i = la - 1; i >= 0; --i) printf("%d", a[i]); puts("");
        putchar('+'); for (int i = 0; i < pb; ++i) putchar(' ');
        for (int i = lb - 1; i >= 0; --i) printf("%d", b[i]); puts("");
        for (int i = 0; i < pc; ++i) putchar(' '); for (int i = 0; i < lc; ++i) putchar('-'); puts("");
        for (int i = 0; i < pc; ++i) putchar(' '); for (int i = lc - 1; i >= 0; --i) printf("%d", c[i]); puts("");
        puts("");
    }
    return 0;
}
