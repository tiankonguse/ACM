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

#define maxn 10010
using namespace std;
int mp[128], arr[10];
bool alp[128];
char chset[10];

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
    for (int i = 0; i < 9; ++i) omp[ opt[i] ] = i;
    int len = strlen(str);
    int cnt = 0, idx = 0, val;

    char op;
    asn = 0;
    for (idx = 0 ;idx < len; ) {
        if ( islower(str[idx]) ) {
            val = mp[ str[idx] ];
            p[cnt++] = node(0, val);
            ++idx;
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

char str[1024];
int main() {
    int n, m;
    while (~scanf("%d%d", &n, &arr[0])) {
        if (n == 0 && arr[0] == 0) break;
        for (int i = 1; i < n; ++i) scanf("%d", &arr[i]);
        scanf("%d", &m);
        scanf(" %s", str);
        int len = strlen(str);
        int top = 0;
        memset(alp, false, sizeof alp);
        for (int i = 0; i < len; ++i) {
            if (islower(str[i])) alp[str[i]] = true;
        }
        for (int i = 0; i < 128; ++i) if (alp[i]) chset[top++] = i;
        bool flag = false;
        sort(arr, arr + n); //must!
        do {
            for (int i = 0; i < n; ++i) mp[ chset[i] ] = arr[i];
//            for (int i = 0; i < n; ++i) {
//                printf("%c: %d, ", chset[i], arr[i]);
//            }puts("");
            int cc = scan(str);
//            cout<<cc<<endl;
//            cout<<cal.calculate(cc)<<endl;
            if (cal.calculate(cc) == m) {
                flag = true;
                break;
            }
        } while (next_permutation(arr, arr + n));
        if (flag) puts("YES");
        else puts("NO");
    }
    return 0;
}
