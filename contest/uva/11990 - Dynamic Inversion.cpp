#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
const int N = 200005;
 
int n , m , a[N] , p[N] , c[N] , bnum;
int L[N];
const int M = 1024;
struct block
{
    int size , s[M];
}b[200];
 
void work()
{
    int i , j , x , y , id;
    long long ans = 0;
    for (i = 0 ; i < n ; ++ i)
        scanf("%d",&a[i]) , -- a[i] , p[a[i]] = i;
    memset(c , 0 , sizeof(c));
    for (i = 0 ; i < n ; ++ i)
    {
        for (j = a[i] + 1 ; j <= n ; j += j & -j)
            ans += c[j];
        for (j = a[i] + 1 ; j > 0 ; j -= j & -j)
            ++ c[j];
    }
    bnum = (n + M - 1) / M;
    x = 0 , y = 0;
    for (i = 0 ; i < bnum ; ++ i)
    {
        y = min(y + M , n);
        b[i].size = 0;
        for (j = x ; j < y ; ++ j)
            b[i].s[b[i].size ++] = a[j];
        sort(b[i].s , b[i].s + b[i].size);
        L[i] = x;
        x = min(x + M , n);
    }
    L[i] = n;
    while (m --)
    {
        printf("%lld\n" , ans);// ans -= 左边大的，右边小的
        scanf("%d",&x) , -- x , y = p[x] , id = y / M;
        //self+del
        for (i = 0 ; i + L[id] < y  ; ++ i)
            if (~a[i + L[id]] && a[i + L[id]] > x)
                -- ans;
        for (i = y + 1 - L[id] ; i < L[id + 1] - L[id] ; ++ i)
            if (~a[i + L[id]] && a[i + L[id]] < x)
                -- ans;
        j = lower_bound(b[id].s , b[id].s + b[id].size , x) - b[id].s;
        for (i = j ; i + 1 < b[id].size ; ++ i)
            b[id].s[i] = b[id].s[i + 1];
        b[id].s[b[id].size - 1] = 0 , b[id].size -- , a[y] = -1;
        //Left
        for (i = 0 ; i < id ; ++ i)
            ans -= b[i].size - (lower_bound(b[i].s , b[i].s + b[i].size , x) - b[i].s);
        //Right
        for (i = id + 1 ; i < bnum ; ++ i)
            ans -= lower_bound(b[i].s , b[i].s + b[i].size , x) - b[i].s;
 
    }
 
}
 
int main()
{
    //freopen("1.txt" , "r" , stdin);
    //int _; scanf("%d",&_); while (_ --)
    while (~scanf("%d%d",&n,&m))
        work();
    return 0;
}
