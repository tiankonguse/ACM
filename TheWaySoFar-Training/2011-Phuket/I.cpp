#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>
#include <vector>
#include <stack>
#include <cmath>
using namespace std;
typedef long long LL;

#define N 40010
#define M 400005
int n , m , s , t , ca;
struct edge {
    int x , f , next;
}e[M];
int pre[N] , mcnt;
void addarc(int x , int y , int z) {
    e[mcnt] = (edge) {y , z , pre[x]} , pre[x] = mcnt ++;
    e[mcnt] = (edge) {x , 0 , pre[y]} , pre[y] = mcnt ++;
}

int d[N] , cur[N] , q[N];
bool BFS() {
    memset(d , 0 , sizeof(int) * (t + 1));
    int top = 0 , bot = -1;
    q[++ bot] = s , d[s] = 1;
    while (top != bot + 1) {
        int x = q[top ++];
        for (int i = pre[x] ; ~i ; i = e[i].next) {
            int y = e[i].x;
            if (!d[y] && e[i].f) {
                d[y] = d[x] + 1 , q[++ bot] = y;
                if (y == t) return 1;
            }
        }
    }
    return 0;
}

int DFS(int x , int flow = 1 << 30) {
    if (x == t || !flow)
        return flow;
    int sum = 0 , u;
    for (int& i = cur[x] ; ~i ; i = e[i].next) {
        int y = e[i].x;
        if (e[i].f && d[y] == d[x] + 1 && (u = DFS(y , min(flow , e[i].f)))) {
            e[i].f -= u , e[i ^ 1].f += u;
            sum += u , flow -= u;
            if (!flow) break;
        }
    }
    if (sum == flow)
        d[x] = -1;
    return sum;
}

int dinic() {
    int ans = 0;
    while (BFS()) {
        memcpy(cur , pre , sizeof(int) * (t + 1));
        ans += DFS(s);
    }
    return ans;
}
int id[N] , od[N];
void work()
{
    int i , j , x , y,  z;
    scanf("%d",&n);
    int SS = n + 1 , TT = n + 2;
    s = TT + 1 , t = TT + 2;
    memset(pre , -1 , sizeof(pre)) , mcnt = 0;
    memset(id , 0 , sizeof(id));
    memset(od , 0 , sizeof(od));
    for (i = 1 ; i < n ; ++ i) {
        scanf("%d%d",&x,&y);
        ++ x , ++ y;
        ++ od[y] , ++ id[x];
        addarc(y , t , 1) , addarc(s , x , 1) , addarc(y , x , 1 << 30);
    }
    for (i = 1 ; i <= n ; ++ i) {
        if (!od[i]) {
            addarc(i , TT , 1 << 30);
        }
        if (!id[i]) {
            addarc(SS , i , 1 << 30);
        }
    }
    dinic();
    addarc(TT , SS , 1 << 30);
    printf("Case %d: %d\n" , ++ ca , dinic());
}

int main(){
    //freopen("1.txt" , "r" , stdin);
    int _; scanf("%d",&_); while (_ --)
        work();
    return 0;
}
