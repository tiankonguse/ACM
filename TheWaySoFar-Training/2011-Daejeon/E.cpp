#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
#define N 1005
#define M 500005
int n , m , s , t;
struct edge {
    int x , f , next;
}e[M];
int pre[N] , mcnt;
void addarc(int x , int y , int z) {
    //printf("%d %d %d\n" , x , y , z);
    e[mcnt] = (edge) {y , z , pre[x]} , pre[x] = mcnt ++;
    e[mcnt] = (edge) {x , 0 , pre[y]} , pre[y] = mcnt ++;
}
int d[N] , cur[N];

bool BFS()
{
    memset(d , -1 , sizeof(d));
    queue<int> q;
    q.push(s) , d[s] = 0;
    while (!q.empty()) {
        int x = q.front(); q.pop();
        for (int i = pre[x] ; ~i ; i = e[i].next) {
            int y = e[i].x;
            if (e[i].f && !~d[y])
                d[y] = d[x] + 1 , q.push(y);
        }
    }
    return d[t] != -1;
}
int dfs(int x , int flow = 1 << 30) {
    if (x == t || !flow) return flow;
    int sum = 0 , u;
    for (int& i = cur[x] ; ~i ; i = e[i].next) {
        int y = e[i].x;
        if (d[y] == d[x] + 1 && (u = dfs(y , min(flow , e[i].f)))) {
            e[i].f -= u , e[i ^ 1].f += u;
            sum += u , flow -= u;
            if (!flow) break;
        }
    }
    return sum;
}
int dinic() {
    int ans = 0;
    while (BFS())
        memcpy(cur , pre , sizeof(cur)) , ans += dfs(s);
    return ans;
}
bool f[N];
void work()
{
    int i , j , k , x , y , z , sum = 0;
    scanf("%d%d",&n,&m);
    memset(pre , -1 , sizeof(pre)) , mcnt = 0;
    s = 500 + m + 1 , t = s + 1;
    for (i = 1 ; i <= m ; ++ i) {
        scanf("%d%d%d",&x,&y,&z);
        addarc(s , i , y);
        sum += y;
        for (j = x ; j < z ; ++ j) {
            addarc(i , j + m , 1);
        }
    }
    for (i = 1 ; i < 500 ; ++ i)
        addarc(i + m , t , n);
    x = dinic();
    if (x != sum) {
        puts("0");
        return;
    }
    for (i = 1 ; i <= m ; ++ i) {
        memset(f , 0 , sizeof(f));
        for (j = pre[i] ; ~j ; j = e[j].next) {
            if (!e[j].f)
                f[e[j].x - m] = 1;
        }
        y = 0;
        for (k = 1 ; k < 500 ; ++ k) if (f[k]) {
            j = 0;
            while (f[j + k])
                ++ j;
            ++ y;
            //printf("%d %d\n" , k , j);
            k += j - 1;
        }
        printf("%d" , y);
        for (k = 1 ; k < 500 ; ++ k) if (f[k]) {
            j = 0;
            while (f[j + k])
                ++ j;
            printf(" %d %d" , k , j + k);
            k += j - 1;
        }
        puts("");
    }
}

int main()
{
    //freopen("1.txt" , "r" , stdin);
    int _; scanf("%d",&_); while (_ --)
        work();
    return 0;
}

