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
#define N 100005

int n , a[N] , pos[N];
void work()
{
    int i , j;
    for (i = 0 ; i < n ; ++ i)
        scanf("%d",&a[i]) , pos[a[i]] = i;
    for (i = 0 ; i < n ; ++ i)
    {
        for (j = i + 2 ; j < n ; ++ j)
        {
            int x = (a[i] + a[j]);
            if (x & 1) continue;
            x = pos[x >> 1];
            if (x > i && x < j)
                break;
        }
        if (j < n) break;
    }
    puts(i < n ? "no" : "yes");
}

int main()
{
    freopen("~input.txt" , "r" , stdin);
    //int _; scanf("%d",&_); while (_ --)
    while (scanf("%d:" , &n) , n)
        work();
    return 0;
}
