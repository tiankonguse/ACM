#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <cassert>
#include <set>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <cmath>
using namespace std;
typedef long long LL;
#define N 1005
int n , m , pre[N] , mcnt;
struct edge {
    int x , next;
}e[100005];
int f[N] , s[N];
int getf(int x) {
    return f[x] == x ? x : f[x] = getf(f[x]);
}
void work(){
    int i , x , y;
    for (i = 1 ; i <= n ; ++ i) {
        f[i] = pre[i] = -1;
        s[i] = 0;
    }
    mcnt = 0;
    for (i = 1 ; i <= m ; ++ i) {
        scanf("%d%d",&x,&y);
        if (x == 1) {
            f[y] = y;
        } else {
            e[mcnt] = (edge) {x , pre[y]} , pre[y] = mcnt ++;
        }
    }
    for (x = 2 ; x <= n ; ++ x) {
        for (i = pre[x] ; ~i ; i = e[i].next) {
            y = e[i].x;
            if (!~f[x])
                f[x] = getf(y);
            else if (getf(x) != getf(y))
                f[x] = x;
        }
    }
    for (x = 2 ; x <= n ; ++ x)
        ++ s[getf(x)];
    int ans = 0;
    for (x = 2 ; x <= n ; ++ x)
        if (getf(x) == x)
            ans += s[x] * (n - s[x] - 1);
    printf("%d\n" , ans / 2 + n - 1);
}

int main(){
    while (~scanf("%d%d",&n,&m))
        work();
    return 0;
}
