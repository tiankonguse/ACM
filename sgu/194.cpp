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

#define N 20005
#define M 2000005
using namespace std;
int n , m , s , t;
struct arc
{
    int x , f , next;
}e[M];
int pre[N] , mcnt;
void addarc(int x ,int y ,int z)
{
    e[mcnt] = (arc) {y , z , pre[x]} , pre[x] = mcnt ++;
    e[mcnt] = (arc) {x , 0 , pre[y]} , pre[y] = mcnt ++;
}
int d[N] , cur[N] , q[N];
bool BFS()
{
    memset(d , 0 , sizeof(int) * (t + 1));
    int top = 0 , bot = -1;
    q[++ bot] = s , d[s] = 1;
    while (top != bot + 1)
    {
        int x = q[top ++];
        for (int i = pre[x] ; ~i ;i = e[i].next)
        {
            int y = e[i].x;
            if (!d[y] && e[i].f)
            {
                d[y] = d[x] + 1 , q[++ bot] = y;
                if (y == t) return 1;
            }
        }
    }
    return 0;
}
int DFS(int x , int flow = 1 << 30)
{
    if (x == t || !flow) return flow;
    int sum = 0 , u;
    for (int& i = cur[x] ; ~i ; i = e[i].next)
    {
        int y = e[i].x;
        if (d[y] == d[x] + 1 && (u = DFS(y , min(flow , e[i].f))))
        {
            e[i].f -= u ,  e[i ^ 1].f += u;
            sum += u , flow -= u;
            if (!flow) break;
        }
    }
    if (sum == flow) d[x] = -1;
    return sum;
}

int dinic()
{
    int ans = 0;
    while (BFS())
    {
        memcpy(cur , pre , (t + 1) * sizeof(int));
        ans += DFS(s);
    }
    return ans;
}

void work()
{
    int i , j , x , y , z , w , sum = 0;
    scanf("%d%d",&n,&m);
    memset(pre , -1 , sizeof(pre)) , mcnt = 0;
    s = n + 1 , t = n + 2;
    for (i = 1 ; i <= m ; ++ i) {
        scanf("%d%d%d%d",&x,&y,&z,&w);
        addarc(x , t , z);
        addarc(s , y , z);
        addarc(x , y , w - z);
        sum += z;
    }
    addarc(t , s ,  1 << 30);
    w = dinic();
    if (w != sum) {
        puts("NO");
    } else {
        puts("YES");
        for (i = 5 ; i < mcnt ; i += 6)
            printf("%d\n" , e[i].f + e[i - 4].f);
    }

}


int main()
{
    freopen("1.txt" , "r" , stdin);
    work();
    return 0;
}


