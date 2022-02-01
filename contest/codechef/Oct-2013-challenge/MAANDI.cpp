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

#define N 50005
int n;
void work()
{
    int i , x , y , ans = 0;
    scanf("%d",&n);
    for (i = 1 ; i * i <= n ; ++ i)
        if (n % i == 0)
        {
            x = i , y = 0;
            while (x)
            {
                if (x % 10 == 4 || x % 10 == 7)
                    y = 1;
                x /= 10;
            }
            if (y) ++ ans;
            if (i * i == n) break;
            x = n / i , y = 0;
            while (x)
            {
                if (x % 10 == 4 || x % 10 == 7)
                    y = 1;
                x /= 10;
            }
            if (y) ++ ans;
        }
    printf("%d\n" , ans);
}

int main()
{
    freopen("~input.txt" , "r" , stdin);
    int _; scanf("%d",&_); while (_ --)
    //while (~scanf("%d",&n))
        work();
    return 0;
}
