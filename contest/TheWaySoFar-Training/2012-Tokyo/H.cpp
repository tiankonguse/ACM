#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cctype>
using namespace std;
#define N 105
int n , m;
struct query
{
    int id , x , y;
}q[N * N];
bool g[N][N] , f[N][N];
bool Q(int x , int y)
{
    for (int i = 1 ; i <= n ; ++ i)
        if (g[x][i] && f[y][i] || g[y][i] && f[x][i])
            return 1;
    return 0;
}
bool check(int V)
{
    int i , j , k, x , y;
    memset(f , 0 , sizeof(f));
    memset(g , 0 , sizeof(g));
    for (i = 1 ; i <= n ; ++ i)
        g[i][i] = 1;
    for (i = 1 ; i <= V ; ++ i)
        if (q[i].id <= 2)
        {
            x = q[i].x , y = q[i].y;
            g[x][y] = 1;
            if (q[i].id == 2)
                g[y][x] = 1;
        }
    for (k = 1 ; k <= n ; ++ k)
        for (i = 1 ; i <= n ; ++ i) if (g[i][k])
            for (j = 1 ; j <= n ; ++ j) if (g[k][j])
                g[i][j] = 1;
    for (i = 1 ; i <= V ; ++ i)
        if (q[i].id == 4)
        {
            x = q[i].x , y = q[i].y;
           /* for (j = 1 ; j <= n ; ++ j) if (g[j][x])
                for (k = 1 ; k <= n ; ++ k) if (g[k][y])
                    f[j][k] = f[k][j] = 1;*/
            for (j = 1 ; j <= n ; ++ j) if (g[j][x])
                f[j][y] = 1;
            for (j = 1 ; j <= n ; ++ j) if (g[j][y])
                f[j][x] = 1;
        }
    for (i = 1 ; i <= V ; ++ i)
    {
        x = q[i].x , y = q[i].y;
        if (q[i].id == 3) // x != y
        {//      x , y = empty           x == y
            if (g[x][y] && g[y][x])
                return 0;
            if (Q(x , x) && Q(y , y))
                return 0;
        }
        else if (q[i].id == 5) // x ins y != empty
        {    //x = empty   y = empty   x ins y == empty
            if (Q(x , x) || Q(y , y) || Q(x , y) || Q(y , x))
                return 0;
        }
    }
    return 1;
}

int main()
{
    while (scanf("%d%d",&n,&m))
    {
    	if(n == 0 && m == 0) break;
        for (int i = 1 ; i <= m ; ++ i)
           scanf("%d%d%d",&q[i].id, &q[i].x , &q[i].y);

        int top = 1 , bot = m , mid;
        while (top < bot)
        {
            mid = top + bot + 1 >> 1;
            if (check(mid))
                top = mid;
            else
                bot = mid - 1;
        }
        printf("%d\n" , top);
    }
    return 0;
}
