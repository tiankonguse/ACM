#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <map>
using namespace std;
const int N = 102 , M = 10002;
typedef unsigned long long ULL;

int n , m , K;
int v[N][M] , s[N][M];
int f[2][M] , q[M];

void work()
{
    int i , j , x , y;
    for (i = n ; i >= 0 ; -- i)
        for (j = 1 ; j <= m ; ++ j)
            scanf("%d",&v[i][j]) , v[i][j] += v[i][j - 1];
    for (i = n ; i >= 0 ; -- i)
        for (j = 1 ; j <= m ; ++ j)
            scanf("%d",&s[i][j]) , s[i][j] += s[i][j - 1];
    int cur = 1 , nxt = 0;
    memset(f[cur] , 0 , sizeof(f[cur]));
    #define k q[top]
    #define l q[bot]

    for (i = 0 ; i <= n ; ++ i)
    {
        int top = 0 , bot = -1;
        for (j = 0 ; j <= m ; ++ j)
        {
            while (top <= bot && f[cur][j] - v[i][j] >= f[cur][l] - v[i][l])
                -- bot;
            q[++ bot] = j;
            while (top <= bot && s[i][j] - s[i][k] > K)
                ++ top;
            f[nxt][j] = f[cur][k] + v[i][j] - v[i][k];
        }
        top = 0 , bot = -1;
        for (j = m ; j >= 0 ; -- j)
        {
            while (top <= bot && f[cur][j] + v[i][j] >= f[cur][l] + v[i][l])
                -- bot;
            q[++ bot] = j;
            while (top <= bot && s[i][k] - s[i][j] > K)
                ++ top;
            f[nxt][j] = max(f[nxt][j] , f[cur][k] - v[i][j] + v[i][k]);
        }
        swap(cur , nxt);
    }
    int ans = 0;
    for (i = 0 ; i <= m ; ++ i)
        ans = max(ans , f[cur][i]);
    printf("%d\n" , ans);
}
int main()
{
    freopen("~input.txt" , "r" , stdin);
//    int _; scanf("%d",&_); while (_ --)
    while (scanf("%d%d%d",&n,&m,&K) , n || m || K)
        work();
    return 0;
}
