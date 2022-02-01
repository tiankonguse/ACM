#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define N 1005
int n , g[N][N];

void work()
{
    int i , j , ans , sum;
    scanf("%d",&n);
    ans = n * (n - 1) * (n - 2) / 6 , sum = 0;
    for (i = 1 ; i <= n ; ++ i)
        for (j = i + 1 ; j <= n ; ++ j)
            scanf("%d",&g[i][j]) , g[j][i] = g[i][j];
    for (i = 1 ; i <= n ; ++ i)
    {
        int x = 0 , y = 0;
        for (j = 1 ; j <= n ; ++ j)
            if (i != j)
                x += g[i][j] , y += !g[i][j];
        sum += x * y;
        //cout << x << ' ' << y << endl;
    }
    printf("%d\n" , ans - sum / 2);
}

int main()
{
    //freopen("1.txt" , "r" , stdin);
    int _; scanf("%d",&_); while (_ --)
        work();
    return 0;
}

