#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>
#include <vector>
#include <cmath>
using namespace std;
typedef long long LL;
#define N 205
int n , m , K , ca;
struct edge
{
    int x , y , w;
    bool operator < (const edge& R) const{
        return w < R.w;}
}e[N * N];
int f[N];
int getf(int x) {return x == f[x] ? x : f[x] = getf(f[x]);}


void work()
{
    int i , j , k , x , y , w;
    scanf("%d%d%d",&n,&m,&K);
    for (i = 1 ; i <= n ; ++ i)
        f[i] = i;
    scanf("%d",&x);
    for (i = 2 ; i <= K ; ++ i)
    {
        scanf("%d",&y);
        f[getf(x)] = getf(y);
        y = x;
    }
    for (i = 0 ; i < m ; ++ i)
        scanf("%d%d%d",&e[i].x,&e[i].y,&e[i].w);
    sort(e , e + m);
    int ans = 0;
    for (i = 0 ; i < m ; ++ i)
        if (getf(e[i].x) != getf(e[i].y))
        {
            ans += e[i].w;
            f[getf(e[i].x)] = getf(e[i].y);
        }
    printf("Case #%d: %d\n" , ++ ca , ans);

}

int main()
{
    int _; scanf("%d",&_); while (_ --)
        work();
    return 0;
}
