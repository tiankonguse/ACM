#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <list>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
typedef long long LL;
#define N 105
int n , K , a[N] , ca;
int f[2][N][256][9];
void work()
{
    int i , j , k , l , ans = 1 << 30 , x = 0;
    for (i = 1 ; i <= n ; ++ i)
        scanf("%d",&a[i]) , a[i] -= 25 , x |= (1 << a[i]);
    memset(f[0] , 0x7F , sizeof(f[0]));
    f[0][0][0][8] = 0;
    int cur = 0 , nxt = 1;
    for (i = 1 ; i <= n ; ++ i)
    {
        memset(f[nxt] , 0x7F , sizeof(f[nxt]));
        for (j = 0 ; j <= K ; ++ j)
            for (k = 0 ; k < 1 << 8 ; ++ k)
                for (l = 0 ; l <= 8 ; ++ l)
                    if (f[cur][j][k][l] <= n)
                    {
                        int res = f[cur][j][k][l];
                        if (j + 1 <= K)
                            f[nxt][j + 1][k][l] = min(f[nxt][j + 1][k][l] , res);
                        if (a[i] == l)
                            f[nxt][j][k][l] = min(f[nxt][j][k][l] , res);
                        else
                            f[nxt][j][k | (1 << a[i])][a[i]] = min(f[nxt][j][k | (1 << a[i])][a[i]] , res + 1);
                    }
        swap(cur , nxt);
    }
    for (j = 0 ; j <= K ; ++ j)
        for (k = 0 ; k < 1 << 8 ; ++ k)
            for (l = 0 ; l < 8 ; ++ l) if (f[cur][j][k][l] <= n)
                ans = min(ans , f[cur][j][k][l] + __builtin_popcount(x ^ k));
    printf("Case %d: %d\n\n" , ++ ca , ans);
}

int main()
{
    freopen("~input.txt" , "r" , stdin);
    while (scanf("%d%d",&n,&K) , n || K)
        work();
    return 0;
}
