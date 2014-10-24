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
#define N 40005

void work()
{
    int a , b , i , ans = 1;
    scanf("%d%d",&a,&b);
    if (b % a)
    {
        puts("NO SOLUTION");
        return;
    }
    for (i = 2 ; i * i <= b ; ++ i)
        if (b % i == 0)
        {
            int x = 1 , y = 1;
            while (b % i == 0)
                y *= i , b /= i;
            while (a % i == 0)
                x *= i , a /= i;
            if (x != y)
                ans *= y;
        }
    if (b > 1) i = b;
    int x = 1 , y = 1;
    while (b % i == 0)
        y *= i , b /= i;
    while (a % i == 0)
        x *= i , a /= i;
    if (x != y)
        ans *= y;
    printf("%d\n" , ans);
}

int main()
{
    //freopen("~input.txt" , "r" , stdin);

    int _; scanf("%d",&_); while (_ --)
        work();
    return 0;
}
