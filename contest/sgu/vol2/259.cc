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
#define maxn 110
using namespace std;
struct node {
    int a, b;
    friend bool operator < (node x, node y) {
        return x.b > y.b;
    }
} p[maxn];

int main() {
    int n, s, a, b;
    int ret = 0;
    while (~scanf("%d", &n)) {
        s = 0;
        ret = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%d", &p[i].a);
        }
        for (int i = 0; i < n; ++i) {
            scanf("%d", &p[i].b);
        }
        sort(p, p + n);
        for (int i = 0; i < n; ++i) {
            s += p[i].a;
            ret = max(ret, s + p[i].b);
        }
        printf("%d\n", ret);
    }
    return 0;
}
