#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
using namespace std;
typedef long long LL;
#define N 100005
int n , m , pre[N] , mcnt;
struct edge {
    int x , next;
}e[N << 1];
int dep[N] , SG[N];

bool dfs(int x) {
    for (int i = pre[x] ; ~i ; i = e[i].next) {
        int y = e[i].x;
        if (dep[y] == dep[x] + 1) {
            if (!dfs(y))
                return 1;
        }
    }
    return 0;
}

void work()
{
    int i , x , y;
    scanf("%d%d",&n,&m);
    memset(pre , -1 , sizeof(pre));
    for (i = 1 ; i <= m ; ++ i) {
        scanf("%d%d",&x,&y);
        e[mcnt] = (edge) {y , pre[x]} , pre[x] = mcnt ++;
        e[mcnt] = (edge) {x , pre[y]} , pre[y] = mcnt ++;
    }
    queue<int> Q;
    dep[1] = 1 , Q.push(1);
    while (!Q.empty()) {
        x = Q.front() , Q.pop();
        for (i = pre[x] ; ~i ; i = e[i].next) {
            y = e[i].x;
            if (!dep[y]) {
                dep[y] = dep[x] + 1;
                Q.push(y);
            }
        }
    }
    if (dfs(1))
        puts("Vladimir");
    else
        puts("Nikolay");
}


int main()
{
    work();
    return 0;
}

