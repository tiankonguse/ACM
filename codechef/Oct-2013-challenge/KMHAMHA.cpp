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
int n , dx[N] , Dx , dy[N] , Dy , ans;
pair<int , int> a[N];
vector<int> e[N];
int re[N] , f[N];
bool find(int x)
{
    for (int i = 0 ; i < e[x].size() ; ++ i)
    {
        int y = e[x][i];
        if (!f[y])
        {
            f[y] = 1;
            if (!re[y] || find(re[y]))
            {
                re[y] = x;
                return 1;
            }
        }
    }
    return 0;
}

void work()
{
    int i , x , y;
    scanf("%d",&n);
    Dx = Dy = ans = 0;
    for (i = 1 ; i <= n ; ++ i)
    {
        scanf("%d%d" , &a[i].fi , &a[i].se);
        dx[Dx ++] = a[i].fi , dy[Dy ++] = a[i].se;
    }
    sort(dx , Dx + dx) , sort(dy , dy + Dy);
    Dx = unique(dx , Dx + dx) - dx , Dy = unique(dy , Dy + dy) - dy;
    for (i = 1 ; i <= Dx ; ++ i)
        e[i].clear();
    for (i = 1 ; i <= n ; ++ i)
    {
        a[i].fi = lower_bound(dx , dx + Dx , a[i].fi) - dx + 1;
        a[i].se = lower_bound(dy , dy + Dy , a[i].se) - dy + 1;
        e[a[i].fi].push_back(a[i].se);
    }
    memset(re , 0 , sizeof(re));
    for (i = 1 ; i <= Dx ; ++ i)
    {
        memset(f , 0 , sizeof(f));
        ans += find(i);
    }
    printf("%d\n" , ans);
}

int main()
{
    int _; scanf("%d",&_); while (_ --)
    //while (~scanf("%d",&n))
        work();
    return 0;
}
