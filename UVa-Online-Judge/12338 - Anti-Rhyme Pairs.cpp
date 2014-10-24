#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define N 10005
int n , m , ca , L[N * 10];
ULL power[N] , MAGIC = 10007;
vector< vector<ULL> > hash;
char str[N];
void work()
{
    printf("Case %d:\n" , ++ ca);
    int i , j , x , y;
    scanf("%d",&n);
    hash.resize(n);
    for (i = 0 ; i < n ; ++ i)
    {
        scanf("%s" , str + 1);
        L[i] = strlen(str + 1);
        hash[i].resize(L[i] + 1);
        for (j = 1 ; j <= L[i] ; ++ j)
            hash[i][j] = hash[i][j - 1] * MAGIC + str[j] - 'a' + 1;
    }
    scanf("%d",&m);
    while (m --)
    {
        scanf("%d%d",&x,&y) , -- x , -- y;
        int l = 0 , r = min(L[x] , L[y]) , mid;
        while (l < r)
        {
            mid = l + r + 1 >> 1;
            if (hash[x][mid] == hash[y][mid])
                l = mid;
            else
                r = mid - 1;
        }
        printf("%d\n" , l);
    }
}
int main()
{
    power[0] = 1;
    for (int i = 1 ; i <= 10000 ; ++ i)
        power[i] = power[i - 1] * MAGIC;
    int _; scanf("%d",&_); while (_ --)
    //while (~scanf("%s", str + 1))
        work();
    return 0;
}
