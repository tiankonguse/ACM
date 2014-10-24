#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;

#define N 1305
int n , m , ca;
double w[N] , c[N] , f[N][N] , g[N][N];
double a[N] , b[N];
void work()
{
    int i , j ; double x;
    scanf("%d%d",&n,&m);
    for (i = 1 ; i <= n ; ++ i)
        scanf("%lf" , &c[i]) , c[i] /= 100 ;
    for (i = 1 ; i <= n ; ++ i)
        scanf("%lf" , &w[i]) , w[i] /= 100 ;
    for (i = 1 ; i <= n ; ++ i)
    {
        x = 1 - c[i] - w[i];
        a[i] = c[i] - w[i] + x;
        b[i] = c[i] - w[i] - x;
    }
    for (i = 0 ; i <= n ; ++ i)
        for (j = 0 ; j <= m ; ++ j)
            f[i][j] = g[i][j] = 15000;
    for (i = 1 ; i <= n ; ++ i)
        for (j = 0 ; j <= m ; ++ j)
        {
            f[i][j] = max(a[i] * f[i - 1][j] , a[i] * g[i - 1][j]);
            g[i][j] = min(a[i] * f[i - 1][j] , a[i] * g[i - 1][j]);
            if (j)
            {
                f[i][j] = max(f[i][j] , max(b[i] * f[i - 1][j - 1] , b[i] * g[i - 1][j - 1]));
                g[i][j] = min(g[i][j] , min(b[i] * f[i - 1][j - 1] , b[i] * g[i - 1][j - 1]));
            }
        }
    double ans = 15000;
    for (i = 0 ; i <= m ; ++ i)
        ans = min(ans , g[n][i]);
    printf("Case #%d: %.3f\n" , ++ ca , ans);
}

int main(){
    int T;
    scanf("%d",&T);
    while (T --)
        work();
    return 0;
}
