#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
typedef unsigned long long ULL;
#define N 1005
ULL power[N + N] , MAGIC = 31;
char T[N][N] , P[105][105];
ULL hash[N][N] , mew , maw;
int n , m , n1 , m1;
void work()
{
    int i , j , x , y;
    scanf("%d%d",&n,&m);
    for (i = 1 ; i <= n ; ++ i)
        scanf("%s" , T[i] + 1);
    for (i = 1 ; i <= n ; ++ i)
        for (j = 1 ; j <= m ; ++ j)
            hash[i][j] = MAGIC * (hash[i - 1][j] + hash[i][j - 1]) - power[2] * hash[i - 1][j - 1] + T[i][j] - 'a' + 1;
    scanf("%d%d",&n1,&m1);
    for (i = 1 ; i <= n1 ; ++ i)
        scanf("%s" , P[i] + 1);
    mew = 0;
    for (i = 1 ; i <= n1 ; ++ i)
        for (j = 1 ; j <= m1 ; ++ j)
            mew += (P[i][j] - 'a' + 1) * power[n1 + m1 - i - j];
    int ans = 0;
    for (i = 1 ; i + n1 - 1 <= n ; ++ i)
        for (j = 1 ; j + m1 - 1 <= m ; ++ j)
        {
            x = i + n1 - 1 , y = j + m1 - 1;
            maw = hash[x][y] - power[n1] * hash[x - n1][y] - power[m1] * hash[x][y - m1] + power[n1 + m1] * hash[x - n1][y - m1];
            ans += maw == mew;
        }
    printf("%d\n" , ans);
}

int main()
{
    freopen("~input.txt" , "r" , stdin);

    power[0] = 1;
    for (int i = 1 ; i <= 2000 ; ++ i)
        power[i] = power[i - 1] * MAGIC;

    int _; scanf("%d",&_); while (_ --)
    //while (scanf("%d",&n) , n)
        work();
    return 0;
}
