// DP + BIT
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

#define N 200005

int n , D , d[N];
int a[N] , p[N] , s[N] , c[N];

void add(int x , int w)
{
    for (int i = x ; i > 0 ; i -= i & -i)
        c[i] = max(c[i] , w);
}
int sum(int x)
{
    int res = 0;
    for (int i = x ; i <= D ; i += i & -i)
        res = max(res , c[i]);
    return res;
}

void work()
{
    int i , ans = 0 , x; D = 0;
    scanf("%d",&n);
    for (i = 1 ; i <= n ; ++ i)
        scanf("%d",&a[i]) , d[D ++] = a[i];
    sort(d , d + D) , D = unique(d , d + D) - d;
    for (i = 1 ; i <= n ; ++ i)
    {
        a[i] = lower_bound(d , d + D , a[i]) - d + 1;
        if (i == 1 || a[i] <= a[i - 1])
            p[i] = 0;
        else p[i] = p[i - 1];
        ++ p[i];
    }
    for (i = n ; i > 0 ; -- i)
    {
        if (i == n || a[i] >= a[i + 1])
            s[i] = 0;
        else s[i] = s[i + 1];
        ++ s[i];
    }
    memset(c , 0 , sizeof(c));
    for (i = n ; i > 0 ; -- i)
    {
        x = sum(a[i] + 1);
        ans = max(ans , x + p[i]);
        add(a[i] , s[i]);
    }
    printf("%d\n" , ans);
}

int main()
{
    freopen("~input.txt" , "r" , stdin);
    int _; scanf("%d",&_); while (_ --)
    //while (scanf("%d\n",&n) , n)
        work();
    return 0;
}
