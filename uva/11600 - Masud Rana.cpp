#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <map>
using namespace std;
const int N = 32;
typedef unsigned long long ULL;

int n , m , f[N] , s[N] , id[N] , cnt , ca;
int getf(int x) {return x == f[x] ? x : f[x] = getf(f[x]);}
map<int , double> h[N];
double F(int x , int mask)
{
    if (mask + 1 == 1 << cnt) return 0;
    if (h[x].count(mask)) return h[x][mask];
    double ans = n - 1 ; int sum = 0;
    for (int i = 0 ; i < cnt ; ++ i)
        if (~mask >> i & 1)
            sum += s[i] , ans += s[i] * F(i , mask | (1 << i));
    ans /= sum , h[x][mask] = ans;
    return ans;
}

void work()
{
    int i , j , x , y;
    scanf("%d%d",&n,&m);
    for (i = 1 ; i <= n ; ++ i)
        f[i] = i , s[i] = 1;
    for (i = 1 ; i <= m ; ++ i)
    {
        scanf("%d%d",&x,&y);
        x = getf(x) , y = getf(y);
        if (x != y)
            f[x] = y , s[y] += s[x];
    }
    cnt = 0;
    for (i = 1 ; i <= n ; ++ i)
        if (getf(i) == i)
        {
            id[i] = cnt;
            h[cnt].clear();
            s[cnt ++] = s[i];
        }
    printf("Case %d: %f\n" , ++ ca , F(id[getf(1)] , 1 << id[getf(1)]));
}
int main()
{
    freopen("~input.txt" , "r" , stdin);
    int _; scanf("%d",&_); while (_ --)
    //while (scanf("%d",&n) , n)
        work();
    return 0;
}
