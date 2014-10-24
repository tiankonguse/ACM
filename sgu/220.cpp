#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;
typedef long long LL;
#define N 105
int n , m1 , m2 , K;
int cnt[N] , a[N] , b[N];
LL f[35][70] , g[35][70];
void work()
{
    int i , j , k;
    memset(cnt , 0 , sizeof(cnt));
    for (i = 1 ; i <= n ; ++ i)
        for (j = 1 ; j <= n ; ++ j)
            ++ cnt[i + j];
    m1 = m2 = 0;
    for (i = 2 ; i <= n + n ; ++ i)
        if (i & 1)
            a[++ m1] = cnt[i];
        else
            b[++ m2] = cnt[i];
    if (K > m1 + m2)
    {
        puts("0");
        return;
    }
    sort(a + 1 , a + 1 + m1);
    sort(b + 1 , b + 1 + m2);
    memset(f , 0 , sizeof(f));
    f[0][0] = 1;
    for (i = 1 ; i <= m1 ; ++ i)
        for (j = 0 ; j <= K ; ++ j)
        {
            f[i][j] += f[i - 1][j];
            if (j)
                f[i][j] += f[i - 1][j - 1] * (a[i] - j + 1);
        }
    memset(g , 0 , sizeof(g));
    g[0][0] = 1;
    for (i = 1 ; i <= m2 ; ++ i)
        for (j = 0 ; j <= K ; ++ j)
        {
            g[i][j] += g[i - 1][j];
            if (j)
                g[i][j] += g[i - 1][j - 1] * (b[i] - j + 1);
        }
    long long ans = 0;
    for (i = 0 ; i <= K ; ++ i)
        ans += f[m1][i] * g[m2][K - i];
    cout << ans << endl;
}

int main()
{
    while (scanf("%d%d",&n,&K) , n || K)
        work();
    return 0;
}
