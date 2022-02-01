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
int n , m , pre[N] , mcnt , ca;
int a[N];
struct edge {
    int x ; LL w ; int next;
}e[N << 2];
int bcnt , X[N << 1] , Y[N << 1] , ncnt ;
LL W[N << 1];
int low[N] , DFN[N] , s[N];
int f[N] , S[N];
int getf(int x) {return x == f[x] ? x : f[x] = getf(f[x]);}

void dfs(int x , int fa) {
    low[x] = DFN[x] = ++ ncnt , s[x] = 1;
    int i , y;
    for (i = pre[x] ; ~i ; i = e[i].next) {
        y = e[i].x;
        if (!DFN[y]) {
            dfs(y , x);
            s[x] += s[y];
            low[x] = min(low[x] , low[y]);
            if (low[y] > DFN[x]) {
                ++ bcnt;
                X[bcnt] = x , Y[bcnt] = y , W[bcnt] = (LL)e[i].w * s[y] * (S[getf(x)] - s[y]);
            }
        } else if (DFN[y] < DFN[x] && y != fa)
            low[x] = min(low[x] , DFN[y]);
    }
}
LL val[N];
int deg[N] , tmp[N];
queue<int> Q;
bool check(LL L) {
    int i , x , y;
    while (!Q.empty()) Q.pop();
    for (i = 1 ; i <= n ; ++ i) {
        val[i] = a[i] , tmp[i] = deg[i] , DFN[i] = 0;
        if (tmp[i] == 1) {
            Q.push(i);
        }
    }
    while (!Q.empty()) {
        x = Q.front() , Q.pop() , DFN[x] = 1;
        if (tmp[x] == 0) continue;
        for (i = pre[x] ; ~i ; i = e[i].next) {
            y = e[i].x; if (DFN[y]) continue;
            if (val[x] + e[i].w <= L) {
                val[x] += e[i].w;
            } else {
                val[y] += e[i].w;
                if (val[y] > L)
                    return 0;
            }
            -- tmp[y];
            if (tmp[y] == 1) {
                Q.push(y);
            }
        }
    }
    return 1;
}
void work() {
    int i , j , x , y , z;
    scanf("%d%d",&n,&m);
    for (i = 1 ; i <= n ; ++ i)
        scanf("%d",&a[i]) , f[i] = i , S[i] = 1;
    memset(pre , -1 , sizeof(pre)) , mcnt = 0;
    for (i = 1 ; i <= m ; ++ i) {
        scanf("%d%d%d",&x,&y,&z);
        e[mcnt] = (edge) {y , z , pre[x]} , pre[x] = mcnt ++;
        e[mcnt] = (edge) {x , z , pre[y]} , pre[y] = mcnt ++;
        x = getf(x) , y = getf(y);
        if (x != y)
            f[x] = y , S[y] += S[x];
    }
    memset(DFN , 0 , sizeof(DFN));
    memset(low , 0 , sizeof(low));
    bcnt = ncnt = 0 ;
    for (i = 1 ; i <= n ; ++ i) {
        if (!DFN[i])
            dfs(i , 0);
    }
    memset(pre , -1 , sizeof(pre)) , mcnt = 0;
    memset(deg , 0 , sizeof(deg));
    for (i = 1 ; i <= bcnt ; ++ i) {
        //printf("%d %d %lld\n" , X[i] , Y[i] , W[i]);
        x = X[i] , y = Y[i];
        ++ deg[x] , ++ deg[y];
        e[mcnt] = (edge) {y , W[i] , pre[x]} , pre[x] = mcnt ++;
        e[mcnt] = (edge) {x , W[i] , pre[y]} , pre[y] = mcnt ++;
    }//puts("");
    LL l = 0 , r = 1e12 , mid;
    for (i = 1 ; i <= n ; ++ i)
        l = max(l , (LL)a[i]);
    while (l < r) {
        mid = l + r >> 1;
        if (check(mid))
            r = mid;
        else
            l = mid + 1;
    }
    printf("Case %d: %lld\n" ,  ++ ca , l);
}

int main(){
    //freopen("1.txt","r",stdin);
    int _ ; scanf("%d",&_); while (_ --)
        work();
    return 0;
}
