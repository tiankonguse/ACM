#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int n , a , b , c , d;
int w[1000000];

void work()
{
    int i , j ; long long ans = 0;
    scanf("%d%d%d%d%d",&n,&a,&b,&c,&d);
    for (i = 0 ; i < n ; ++ i)
    {
        ++ w[d];
        d = ((long long)a * d * d + b * d + c) % 1000000;
    }
    for (i = 999999 , j = 0 ; i >= 0 ; -- i)
        while (w[i])
            if (j & 1)
                ans -= i , ++ j , -- w[i];
            else
                ans += i , ++ j , -- w[i];
    printf("%lld\n" , abs(ans));
}

int main()
{
    int _; scanf("%d",&_); while(_ --)
        work();
    return 0;
}
