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
#define maxn 300
using namespace std;
char str[maxn], res[maxn];
int sLen, rLen;
bool rem[maxn];
void fun(int pos, int top, bool flag) {
    if (pos == sLen) {
        res[rLen] = 0;
        return;
    }
    else if (str[pos] == ' ') fun(pos + 1, top, flag);
    else if (str[pos] == '(') {
        rem[++top] = flag;
        if (flag) res[rLen++] = '(';
        fun(pos + 1, top, false);
    }
    else if (str[pos] == ')') {
        if (rem[top]) res[rLen++] = ')';
        fun(pos + 1, top - 1, false);
    }
    else if (str[pos] == '+') {
        res[rLen++] = '+';
        fun(pos + 1, top, false);
    }
    else if (str[pos] == '-') {
        res[rLen++] = '-';
        fun(pos + 1, top, true);
    }
    else {
        res[rLen++] = str[pos];
        fun(pos + 1, top, flag);
    }
}

bool scan() {
    bool flag = false;
    for (int i = 1; i < rLen - 1; ++i) {
        if (isupper(res[i]) && res[i - 1] == '(' && res[i + 1] == ')') {
            res[i - 1] = res[i + 1] = '?';
            flag = true;
        }
    }
    int tLen = rLen;
    rLen = 0;
    for (int i = 0; i < tLen; ++i) {
        if (res[i] != '?') res[rLen++] = res[i];
    }
    res[rLen] = 0;
    return flag;
}
int main() {
    int T;
    for (scanf("%d\n", &T); T--; ) {
        gets(str + 1);
        sLen = 1 + strlen(str + 1);
        str[0] = '(', str[sLen++] = ')';
        str[sLen] = 0;
        rLen = 0;
        memset(rem, false, sizeof rem);
        fun(0, 0, 0);
        while (scan()) ;
        puts(res);
    }
    return 0;
}
