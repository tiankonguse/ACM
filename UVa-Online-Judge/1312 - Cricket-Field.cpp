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
#define N 105

int n , W , H , ca;
pair<int , int> a[N] , b[N] , res;

bool check(int L)
{
    int i , j;
    for (i = 0 ; i <= n ; ++ i)
    {
        int y = a[i].se , x = 0;
        if (y + L > H) continue;
        for (j = 1 ; j <= n ; ++ j)
            if (a[j].se > y && a[j].se < y + L)
            {
                if (a[j].fi - x >= L)
                {
                    res = make_pair(x , y);
                    return 1;
                }
                x = a[j].fi;
            }
        if (W - x >= L)
        {
            res = make_pair(x , y);
            return 1;
        }
    }
    return 0;
}

void work()
{
    int i ;
    if (ca ++) puts("");
    scanf("%d%d%d",&n,&W,&H);
    for (i = 1 ; i <= n ; ++ i)
        scanf("%d%d",&a[i].fi , &a[i].se);
    sort(a + 1 , a + 1 + n);

    int top = 1 , bot = min(W , H) , mid;
    while (top < bot)
    {
        mid = (top + bot + 1) >> 1;
        if (check(mid))
            top = mid;
        else bot = mid - 1;
    }
    printf("%d %d %d\n" , res.fi , res.se , top);
}

int main()
{
    freopen("~input.txt" , "r" , stdin);
    int _; scanf("%d",&_); while (_ --)
    //while (~)
        work();
    return 0;
}
