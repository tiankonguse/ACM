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

int n , L , a[N];
int f[N][N];
void work()
{
    int i , j , k , l;
    scanf("%d",&n);
    for (i = 2 ; i <= n + 1 ; ++ i)
        scanf("%d",&a[i]);
    a[1] = 0 , a[n + 2] = L ; n += 2;
    for (k = 2 ; k < n ; ++ k)
        for (i = 1 , j = k ; j < n ; ++ i , ++ j)
        {
            f[i][j] = 1 << 30;
            for (l = i ; l < j ; ++ l)
                f[i][j] = min(f[i][j] , f[i][l] + f[l + 1][j]);
            f[i][j] += a[j + 1] - a[i];
        }
    printf("The minimum cutting is %d.\n" , f[1][n - 1]);
}
int main()
{
    freopen("~input.txt" , "r" , stdin);
//    int _; scanf("%d",&_); while (_ --)
    while (scanf("%d",&L) , L)
        work();
    return 0;
}
