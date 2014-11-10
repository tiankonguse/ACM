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
#define N 100005

LL m , p , a , b;

LL power(LL A , LL B)
{
    LL ans = 1;
    while (B)
    {
        if (B & 1)
            ans *= A;
        A *= A , B >>= 1;
    }
    return ans;
}

void work()
{
    LL res = a * b , ans = 0 , sum = 0 , x;
    for (int i = 1 ; i <= m ; ++ i)
    {
        if (sum + (m - i) * -1 > res)
        {
            sum += -1;
            ans += power(-1 , p);
        }
        else
        {
            x = min(a , res - sum + (m - i));
            sum += x , ans += power(x , p);
        }
    }
    printf("%.0f\n" , (double)ans / power(a , p >> 1));
}

void init()
{

}

int main()
{
    freopen("~input.txt" , "r" , stdin);
    //int _; scanf("%d",&_); while (_ --)
    //init();

    //int _; scanf("%d",&_); while (_ --)
    //init();
    while (cin >> m >> p >> a >> b)
        work();
    return 0;
}
