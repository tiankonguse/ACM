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
#define maxn 8000100
using namespace std;
struct node {
    int a, b;
    node (int _a, int _b) { a = _a, b = _b; }
    node () {}
    node operator + (const node &t) { return node(a + t.a, b + t.b); }
    void print(){
        printf("%d/%d\n", a, b);
    }
} st[maxn], res[maxn], tmp, tmp2;
int top, cnt;

int main() {
    int n, m, a;
    while (~scanf("%d%d", &n, &m)) {
        top = cnt = 0;
        st[++top] = node(0, 1);
        tmp = node(1, 1);
        while (top > 0) {
            tmp2 = st[top] + tmp;
            if (tmp2.b <= n) st[++top] = tmp2;
            else {
                res[cnt++] = tmp;
                tmp = st[top--];
            }
        }
        res[cnt++] = tmp;
        while (m--) {
            scanf("%d", &a);
            if (a > cnt) puts("No Solution");
            else res[cnt - a].print();
        }
    }
    return 0;
}
