#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
//#include <cassert>
//#pragma comment(linker, "/STACK:16777216")
using namespace std;
typedef long long LL;

const int N = 100005;
int n , pre[N] , mcnt;
struct edge {
    int x , w1 , w2 , next;
}e[N << 1];
int m , vis[N];
int f[N] , dep[N];

void dfs(int x , int fa) {
    for (int i = pre[x] ; ~i ; i = e[i].next) {
        if (i != fa) {
            int y = e[i].x;
            f[y] = i ^ 1 , dep[y] = dep[x] + 1;
            dfs(y , i ^ 1);
        }
    }
}
LL F[N];
int Rx[200] , Wx1[200] , Wx2[200] , Tx;
int Ry[200] , Wy1[200] , Wy2[200] , Ty;
void work() {
    int i , j , k , x , y ;
    memset(pre , -1 , sizeof(pre)) , mcnt = 0;
    for (i = 1 ; i < n ; ++ i) {
        scanf("%d%d%d%d",&x,&y,&j,&k);
        e[mcnt] = (edge) {x , j , k , pre[y]} , pre[y] = mcnt ++;
        e[mcnt] = (edge) {y , j , k , pre[x]} , pre[x] = mcnt ++;
    }
    for (i = 0 ; i < m ; ++ i)
        scanf("%d" , &vis[i]);
    dfs(1 , -1);
    LL cur = 0 , nxt;
    for (i = 1 ; i <= n ; ++ i)
        F[i] = 1LL << 60;
    F[vis[0]] = 0;
    LL res = 0 , SW1 = 0 , SW2 = 0;
    for (i = 1 ; i < m ; ++ i) {
        x = vis[i - 1] , y = vis[i];
        Tx = Ty = 0;
        while (dep[x] != dep[y]) {
            if (dep[x] > dep[y]) {
                Wx1[Tx] = e[f[x]].w1;
                Wx2[Tx] = e[f[x]].w2;
                x = e[f[x]].x;
                Rx[Tx] = x;
                ++ Tx;
            } else {
                Wy1[Ty] = e[f[y]].w1;
                Wy2[Ty] = e[f[y]].w2;
                Ry[Ty] = y;
                y = e[f[y]].x;
                ++ Ty;
            }
        }
        while (x != y) {
            Wx1[Tx] = e[f[x]].w1;
            Wx2[Tx] = e[f[x]].w2;
            x = e[f[x]].x;
            Rx[Tx] = x;
            ++ Tx;
            Wy1[Ty] = e[f[y]].w1;
            Wy2[Ty] = e[f[y]].w2;
            Ry[Ty] = y;
            y = e[f[y]].x;
            ++ Ty;
        }
        for (j = 0 ; j < Tx ; ++ j) {
            nxt = cur + Wx2[j] , SW1 += Wx1[j] , SW2 += Wx2[j];
            nxt = min(nxt , F[Rx[j]] + SW1);
            F[Rx[j]] = nxt - SW1;
            res = min(res , nxt - SW1);
            swap(cur , nxt);
        }
        for (j = Ty - 1 ; j >= 0 ; -- j) {
            nxt = cur + Wy2[j] , SW1 += Wy1[j] , SW2 += Wy2[j];
            nxt = min(nxt , F[Ry[j]] + SW1);
            F[Ry[j]] = nxt - SW1;
            res = min(res , nxt - SW1);
            swap(cur , nxt);
        }
    }
    cout << SW1 + res << endl;
}

int main()
{
    while (~scanf("%d%d",&n,&m))
        work();
    return 0;
}
