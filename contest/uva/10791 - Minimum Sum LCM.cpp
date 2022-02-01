#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
#include <set>
using namespace std;
typedef long long LL;
#define N 10005

int n , m , ca;

void work()
{
    int i , j , ans = 0 , x , y = 0;
    printf("Case %d: " , ++ ca);
    if (n == 2147483647)
    {
        printf("2147483648\n");
        return;
    }
    m = n;
    for (i = 2 ; i * i <= m ; ++ i)
        if (m % i == 0)
        {
            x = 1 , ++ y;
            while (m % i == 0)
                x *= i , m /= i;
            ans += x;
        }
    if (m > 1)
        ans += m , ++ y;
    if (y <= 1)
    {
        printf("%d\n" , n + 1);
        return;
    }
    printf("%d\n" , ans);
}

void init()
{

}

int main()
{
    //freopen("~input.txt" , "r" , stdin);
    //int _; scanf("%d",&_); while (_ --)
    //init();

    //int _; scanf("%d",&_); while (_ --)
    while (scanf("%d",&n) , n)
        work();
    return 0;
}
