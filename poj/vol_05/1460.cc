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
#define maxn 222
using namespace std;

struct node {
    int t; // t = 0 : num; t = 1 : operator.
    int value; // for op: +-*/()#^? == 012345678
    node (int _t, int _v) { t = _t, value = _v; }
    node () {}
} p[maxn];
char opt[] = "+-*/()#^?";
int omp[128];
int ask[11], asn;
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
    { 1,  1, -1, -1, -1,  1,  1, -1}, // +
    { 1,  1, -1, -1, -1,  1,  1, -1}, // -
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
                            // cout << lr << ":" << a << chg(c) << b <<endl;
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

int pos[maxn];
char ops[4] = {'+', '-', '*', '/'};
char s[maxn];
int main() {
    for (int i = 0; i < 9; ++i) { omp[ opt[i] ] = i; }
    int T;
    int a;
    int len, n, mx;
    for (scanf("%d", &T); T--; ) {
        scanf(" %s %d", s, &a);
        len = strlen(s);
        s[len++] = '#'; s[len] = 0;
        n = 0;
        for (int i = 0; i < len; ++i) {
            if (s[i] == '?') {
                pos[n++] = i;
            }
        }
        mx = 1 << (n << 1);
        bool flag = false;
        int cnt = scan(s);
        for (int i = 0; i < mx; ++i) {
            int t = i, op;
            for (int j = n - 1; j >= 0; --j) { // firstly +-
                op = t & 3;
                t >>= 2;
                p[ask[j]].value = op;
            }
            if (cal.calculate(cnt) == a) {
                flag = true;
                break;
            }
        }
        puts(flag ? "yes" : "no");
    }
    return 0;
}
