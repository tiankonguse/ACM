#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
#define N 200005
int n , m , Q , num;
int a[N];
int t[N] , p[N];
int main()
{
    freopen("~input.txt" , "r" , stdin);
    int i , j , x , y;
    scanf("%d",&n);
    m = sqrt(n) , num = n / m + (n % m != 0);
    for (i = 0 ; i < n ; ++ i)
        scanf("%d",&a[i]);
    scanf("%d",&Q);
    for (i = 0 ; i < num ; ++ i)
    {
        int out = min(n , (i + 1) * m); y = i * m;
        for (j = out - 1 ; j >= y ; -- j)
        {
            if (j + a[j] < out)
                t[j] = t[j + a[j]] + 1 , p[j] = p[j + a[j]];
            else t[j] = 1 , p[j] = min(j + a[j] , n);
        }
    }

    while (Q --)
    {
        scanf("%d",&i);
        if (i == 1)
        {
            scanf("%d",&x);
            int ret = 0;
            while (x < n)
                ret += t[x] , x = p[x];
            printf("%d\n" , ret);
        }
        else
        {
            scanf("%d%d",&x,&y);
            a[x] = y , i = x / m , y = i * m;
            int out = min(n , (i + 1) * m);
            for (j = x ; j >= y ; -- j)
            {
                if (j + a[j] < out)
                    t[j] = t[j + a[j]] + 1 , p[j] = p[j + a[j]];
                else t[j] = 1 , p[j] = min(j + a[j] , n);
            }
        }
    }
    return 0;

}
