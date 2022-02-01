#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

#define N 100005
int n , a[N] , d[N] , f[N] , m , l[N] , r[N];
int getf(int x) {return x == f[x] ? x : f[x] = getf(f[x]);}

int merge(int x , int y)
{
    if (!x || !y) return x | y;
    if (a[x] < a[y])  swap(x , y);
    r[x] = merge(r[x] , y) , f[r[x]] = x;
    if (d[l[x]] < d[r[x]])
        swap(l[x] , r[x]);
    d[x] = r[x] ? d[r[x]] + 1 : 0;
    return x;
}

void work()
{
    int i , j , k , x , y , xx , yy;
    for (i = 1 ; i <= n ; ++ i)
        scanf("%d",&a[i]) , f[i] = i , d[i] = l[i] = r[i] = 0;
    scanf("%d",&m);
    while (m --)
    {
        scanf("%d%d",&x,&y);
        xx = getf(x) , yy = getf(y);
        if (xx == yy)
            puts("-1");
        else
        {
            i = merge(l[xx] , r[xx]);
            a[xx] >>= 1 , l[xx] = r[xx] = d[xx] = 0;
            i = merge(i , xx);
            j = merge(l[yy] , r[yy]);
            a[yy] >>= 1 , l[yy] = r[yy] = d[yy] = 0;
            j = merge(j , yy);

            k = merge(i , j);
            printf("%d\n" , a[k]);
            f[i] = f[j] = k;
        }
    }
    }
}

int main()
{
    freopen("0","r",stdin);
    while (~scanf("%d",&n))
        work();
    return 0;
}
