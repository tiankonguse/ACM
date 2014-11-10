#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
using namespace std;
const int N = 502;
typedef unsigned long long ULL;
int n , m , pre[N] , mcnt , ca;
struct edge
{
    int x , w , next;
}e[N];
int f[N][N][2] , sum[N];

void dfs(int x)
{
    int i , j , k , y , w;
    f[x][1][0] = f[x][1][1] = 0 , sum[x] = 1;
    for (i = 2 ; i <= n ; ++ i)
        f[x][i][0] = f[x][i][1] = 1 << 29;
    for (i = pre[x] ; ~i ; i = e[i].next)
    {
        y = e[i].x , w = e[i].w;
        dfs(y) , sum[x] += sum[y];
        for (j = sum[x] ; j > 0 ; -- j)
            for (k = max(1 , j - sum[y]) ; k < j ; ++ k)
            {
                f[x][j][0] = min(f[x][j][0] , f[x][k][0] + f[y][j - k][0] + w + w);
                f[x][j][1] = min(f[x][j][1] , f[x][k][0] + f[y][j - k][1] + w);
                f[x][j][1] = min(f[x][j][1] , f[x][k][1] + f[y][j - k][0] + w + w);
            }
    }
}

void work()
{
    int i , j , x , y , w;
    memset(pre , -1 , sizeof(pre)) , mcnt = 0;
    for (i = 1 ; i < n ; ++ i)
    {
        scanf("%d%d%d",&x , &y , &w);
        e[mcnt] = (edge) {x , w , pre[y]} , pre[y] = mcnt ++;
    }
    dfs(0);
    scanf("%d" , &m);
    printf("Case %d:\n" , ++ ca);
    while (m --)
    {
        scanf("%d",&x);
        for (i = n ; i > 0 ; -- i)
            if (x >= f[0][i][1])
            {
                printf("%d\n" , i);
                break;
            }

    }
}
int main()
{
    while (scanf("%d",&n) , n)
        work();
    return 0;
}
