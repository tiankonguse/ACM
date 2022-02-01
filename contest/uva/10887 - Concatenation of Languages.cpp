#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define N 1505
int n , m , ca;
ULL power[100] , MAGIC = 10007 , hash[N];
char str[100];

void work()
{
    int i , j , l; ULL x;
    set<ULL> uni;
    scanf("%d%d",&n,&m); getchar();
    for (i = 0 ; i < n ; ++ i)
    {
        gets(str) , hash[i] = 0;
        for (j = 0 ; str[j] ; ++ j)
            hash[i] *= MAGIC , hash[i] += str[j] - 'a' + 1;
    }
    for (i = 0 ; i < m ; ++ i)
    {
        gets(str) , x = 0;
        for (l = 0 ; str[l] ; ++ l)
            x *= MAGIC , x += str[l] - 'a' + 1;
        for (j = 0 ; j < n ; ++ j)
            uni.insert(hash[j] * power[l] + x);
    }
    printf("Case %d: %d\n" , ++ ca , uni.size());
}
int main()
{
    freopen("~input.txt" , "r" , stdin);

    power[0] = 1;
    for (int i = 1 ; i < 100 ; ++ i)
        power[i] = power[i - 1] * MAGIC;
    int _; scanf("%d",&_); while (_ --)
    //while (scanf("%s", s) , *s != '.')
        work();
    return 0;
}
