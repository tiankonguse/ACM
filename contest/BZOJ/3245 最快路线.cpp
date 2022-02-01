#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <set>
#include <queue>
using namespace std;
typedef long long LL;
#define N 155

int n , m , T;
int v[N][N] , L[N][N];

double d[N][501];
bool f[N][501];
struct P
{
    int x , y;
    P(int _x , int _y)
    {
        x = _x , y = _y;
    }
    P(){}
};
queue< P > Q;
P p[N][501];

void print(int x , int j)
{
    if (p[x][j].x)
        print(p[x][j].x , p[x][j].y);
    printf("%d%c" , x - 1 , " \n"[x == T]);
}

int main()
{
    freopen("~input.txt" , "r" , stdin);

    int i , j , k , x , y ; double z;
    scanf("%d%d%d",&n,&m,&T) , ++ T;
    v[0][0] = 70 , memset(L , -1 , sizeof(L));
    for (i = 0 ; i < m ; ++ i)
    {
        scanf("%d%d",&x,&y);
        ++ x , ++ y;
        scanf("%d%d",&v[x][y],&L[x][y]);
    }
    for (i = 0 ; i <= n ; ++ i)
        for (j = 0 ; j <= 500 ; ++ j)
            d[i][j] = 1e30;
    Q.push(P(1 , 70));
    f[1][70] = 1 , d[1][70] = 0;
    while (!Q.empty())
    {
        x = Q.front().x , j = Q.front().y , Q.pop() , f[x][j] = 0;
        for (y = 1 ; y <= n ; ++ y)
            if (~L[x][y])
            {
                if (v[x][y])
                {
                    z = d[x][j] + (double)L[x][y] / v[x][y];
                    if (z < d[y][v[x][y]])
                    {
                        d[y][v[x][y]] = z;
                        p[y][v[x][y]] = P(x , j);
                        if (!f[y][v[x][y]])
                            f[y][v[x][y]] = 1 , Q.push(P(y , v[x][y]));
                    }
                }
                else
                {
                    z = d[x][j] + (double)L[x][y] / j;
                    if (z < d[y][j])
                    {
                        d[y][j] = z;
                        p[y][j] = P(x , j);
                        if (!f[y][j])
                            f[y][j] = 1 , Q.push(P(y , j));
                    }
                }
            }
    }
    double ans = 1e61;
    for (i = 0 ; i <= 500 ; ++ i)
        if (d[T][i] < ans)
            ans = d[T][i] , x = i;
    //cout << ans << endl;
    print(T , x);
    return 0;
}
