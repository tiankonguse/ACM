#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
using namespace std;
typedef long long LL;
#define N 105

int n , K , f[N][N] , Q = 1e6;
void work()
{
    int i , j , k;
    if (!f[0][0]){
    f[0][0] = 1;
    for (i = 1 ; i <= 100 ; ++ i)
    {
        f[i][0] = 1;
        for (j = 1 ; j <= 100 ; ++ j)
            f[i][j] = f[i - 1][j] + f[i][j - 1] , f[i][j] %= Q;
    }}
    printf("%d\n" , f[K][n]);
}

int main()
{
    //freopen("~input.txt" , "r" , stdin);
    while (scanf("%d%d",&n,&K) , n || K)
    //int _; scanf("%d",&_); while (_ --)
        work();
    return 0;
}
