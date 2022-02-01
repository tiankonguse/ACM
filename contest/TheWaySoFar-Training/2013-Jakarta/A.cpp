#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>
#include <vector>
#include <cmath>
using namespace std;
typedef long long LL;
#define N 105
int n , m , a[N] , ca;
LL f[N][N];

void work()
{
    int i , j , k;
    scanf("%d%d",&n,&m);
    for (i = 1 ; i <= n ; ++ i)
        scanf("%d" , &a[i]);
    sort(a + 1 , a + 1 + n);

    memset(f , 63 , sizeof(f));
    f[0][0] = 0;
    for (i = 1 ; i <= n ; ++ i)
        for (j = 1 ; j <= m ; ++ j)
        {
            for (k = 0 ; k < i ; ++ k)
                f[i][j] = min(f[i][j] , f[k][j - 1] + a[i] - a[k + 1]);
        }
    printf("Case #%d: %lld\n" , ++ ca , f[n][m]);

}

int main()
{
    int _; scanf("%d",&_); while (_ --)
        work();
    return 0;
}
