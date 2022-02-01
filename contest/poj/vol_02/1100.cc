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
#define maxn 111
using namespace std;
struct node {
    int t; // t = 0 : num; t = 1 : operator.
    int value; // for op: +-*/()#^? == 012345678
    node (int _t, int _v) { t = _t, value = _v; }
    node () {}
} p[maxn];
char opt[] = "+-*/()#^?";
int omp[128];
int ask[13], asn;
int scan(char *str) {
    int len = strlen(str);
    int cnt = 0, idx = 0, val;

    char op;
    asn = 0;
    for (idx = 0 ;idx < len; ) {
        if ( isdigit(str[idx]) ) {
            sscanf(str + idx, "%d", &val);
            p[cnt++] = node(0, val);
            while ( isdigit(str[idx]) ) ++idx;
        }
        else {
            sscanf(str + idx, "%c", &op);
            if (op == '?') ask[asn++] = cnt;
            p[cnt++] = node(1, omp[op]);
            ++idx;
        }
    }
    return cnt;
}

const int prior[8][8] =  {
//    +   -   *   /   (   )   #   ^
    { 1,  1,  1,  1, -1,  1,  1, -1}, // +
    { 1,  1,  1,  1, -1,  1,  1, -1}, // -
    { 1,  1,  1,  1, -1,  1,  1, -1}, // *
    { 1,  1,  1,  1, -1,  1,  1, -1}, // /
    {-1, -1, -1, -1, -1,  0, -2, -1}, // (
    { 1,  1,  1,  1, -2,  1,  1,  1}, // )
    {-1, -1, -1, -1, -1, -2,  0, -1}, // #
    { 1,  1,  1,  1, -1,  1,  1,  1}  // ^
};


inline char chg(int c){
    char mp[] = "+-*/()#^";
    return mp[c];
}
struct Calculator{


    inline int atos(char* s){
        return atoi(s);
    }

    inline int operate(int a, int c, int b){
        switch (c) {
            case 0: return a + b;
            case 1: return a - b;
            case 2: return a * b;
            case 3: if(b == 0) return -inf;
                      else return a / b;
            default:  return -1;
        }
    }

    int OPTR[maxn];
    int OPND[maxn];
    int calculate(int cnt){

        int lr = 0, ld = 0;
        OPTR[++lr] = 6;

        int idx = 0;

        int a, b, c;
        for (int i = 0; i < cnt; ++i) {
            if (p[i].t == 0) OPND[++ld] = p[i].value;
            else {
                switch (prior[OPTR[lr]][p[i].value]) {
                    case -1: OPTR[++lr] = p[i].value;
                             break;
                    case  0: lr--;
                             break;
                    case  1: c = OPTR[lr--];
                             b = OPND[ld--];
                             a = OPND[ld--];
                             //cout << lr << ":" << a << chg(c) << b <<endl;
                             OPND[++ld] = (operate(a, c, b));
                             if (OPND[ld] == -inf) return -inf;
                             --i;
                             break;
                }
            }
        }

        return OPND[ld];
    }
}cal;

char str[222], tmp[222];
void shrink(char *s) {
    int l = strlen(s), idx = 0, len = 0;
    for (int i = 0; i < l; ++i) tmp[i] = s[i];
    for (int i = 0; i < l; ++i) {
        s[len++] = tmp[i];
        if (!isdigit(tmp[i])) s[len++] = ' ';
    }
//    puts(s);
    for (; s[idx] != '='; ++idx) ;
    while (s[++idx] == ' ');
    while (s[--len] == ' ');
    bool f1 = false, f2 = false;
    int cnt = 0;
    for (; idx <= len; ++idx) {
        if (isdigit(s[idx])) {
            if (f1 && f2) {
                s[cnt++] = '?';
            }
            s[cnt++] = s[idx];
            f1 = true;
            f2 = false;
        }
        else if (s[idx] == ' ') {
            f2 = true;
        }
        else {
            if (str[idx] == '(') {
                if (f1) s[cnt++] = '?';
                f1 = false;
            }
            s[cnt++] = str[idx];
        }
    }
    s[cnt++] = '#';
    s[cnt] = 0;
}

int n, ans;

bool dfs(int pos) {
    if (pos == asn) {
        return cal.calculate(n) == ans;
    }
    for (int i = 0; i < 3; ++i) {
        p[ ask[pos] ].value = i;
        if (dfs(pos + 1)) return true;
    }
    return false;
}

int main() {
    for (int i = 0; i < 9; ++i) omp[ opt[i] ] = i;

    int _ca = 1;
    while (gets(str)) {
        if (strcmp(str, "0") == 0) break;
        sscanf(str, "%d", &ans);
        shrink(str);
      //  puts(str);
        n = scan(str);
        bool flag = dfs(0);
        printf("Equation #%d:\n", _ca++);
        if (!flag) puts("Impossible\n");
        else {
            printf("%d=", ans);
            for (int i = 0; i < n - 1; ++i) {
                if (p[i].t == 0) printf("%d", p[i].value);
                else printf("%c", opt[ p[i].value ]);
            }
            puts("\n");
        }
    }
    return 0;
}
