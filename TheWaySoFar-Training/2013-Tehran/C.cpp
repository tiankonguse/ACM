#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <cmath>
#include <cassert>
using namespace std;
typedef long long LL;

#define N 10005
int n , K , mcnt , pre[N] , F[N];
struct edge {
    int x , next;
}e[N];
int deg[N] , ans;
bool f[N] , u[N];
queue<int> Q;

void work() {
    int i , x , y;
    memset(pre , -1 , sizeof(pre)) , mcnt = 0;
    memset(deg , 0 , sizeof(deg));
    ans = 0;
    for (i = 1 ; i <= n ; ++ i) {
        scanf("%d",&x);
        f[i] = 1 , u[i] = 0 , F[i] = x;
        if (!x) continue;
        ++ deg[x];
        e[mcnt] = (edge) {i , pre[x]} , pre[x] = mcnt ++;
    }
    while (K --)
        scanf("%d",&x) , f[x] = 0;
    for (i = 1 ; i <= n ; ++ i)
        if (!deg[i])
            Q.push(i);
    while (!Q.empty()) {
        x = Q.front() , Q.pop();
        y = F[x];
        if (!y) continue;
        if (!-- deg[y])
            Q.push(y);

        if (f[x]) {
            if (u[x]) continue;
            if (!f[y])
                u[x] = 1 , f[y] = 1 , ++ ans;
        } else {
            if (f[y]) {
                if (u[y]) continue;
                u[y] = 1 , f[x] = 1 , ++ ans;
            } else {
                if (!u[y] && !u[x])
                    u[y] = 1 , f[x] = 1 , ++ ans;
                else if (u[y])
                    u[x] = 1 , f[y] = 1 , ++ ans;
                else if (u[x])
                    u[y] = 1 , f[x] = 1 , ++ ans;
            }
        }

    }
    printf("%d\n" , ans);
}

int main(){
    //freopen("1.txt" , "r" , stdin);
    while (scanf("%d%d",&n,&K) , n || K)
        work();
    return 0;
}
