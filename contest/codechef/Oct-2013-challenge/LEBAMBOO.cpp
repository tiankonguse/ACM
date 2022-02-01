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
//#pragma comment(linker, "/STACK:16777216")
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

#define N 1005
int n , a[N] , b[N];

void work()
{
    int i , x , y;
    int sa = 0 , sb = 0;
    scanf("%d",&n);
    for (i = 1 ; i <= n ; ++ i)
        cin >> a[i] , sa += a[i];
    for (i = 1 ; i <= n ; ++ i)
        cin >> b[i] , sb += b[i];
    if (n == 1)
    {
        if (sa < sb)
            puts("-1");
        else printf("%d\n" , sa - sb);
        return;
    }
    if (n == 2)
    {
        if (sa != sb)
            puts("-1");
        else printf("%d\n" , abs(a[1] - b[1]));
        return;
    }
    if (sa > sb)
        puts("-1");
    else
    {
        x = sb - sa;
        y = n - 2;
        if (x % y)
            puts("-1");
        else
        {
            x /= y;
            for (i = 1 ; i <= n ; ++ i)
                b[i] -= a[i];
            if (x & 1)
            {
                for (i = 1 ; i <= n ; ++ i)
                    if ((b[i] & 1) != 1 || abs(b[i]) > x)
                        break;
                if (i <= n)
                    puts("-1");
                else printf("%d\n" , x);
            }
            else
            {
                for (i = 1 ; i <= n ; ++ i)
                    if ((b[i] & 1) != 0 || abs(b[i]) > x)
                        break;
                if (i <= n)
                    puts("-1");
                else printf("%d\n" , x);
            }
        }
    }
}

int main()
{
    freopen("~input.txt" , "r" , stdin);
    int _; scanf("%d",&_); while (_ --)
    //while (~scanf("%d",&n))
        work();
    return 0;
}
