#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
const int N = 300005;

int n , m , u , a[N] , bnum;
int L[N];
const int M = 2048;
struct block
{
    int size , s[M];
}b[200];

void work()
{
    int i , j , k , x , y , id , ll , rr , l , r , p , v;
    for (i = 0 ; i < n ; ++ i)
        scanf("%d",&a[i]);
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
        scanf("%d%d%d%d",&l , &r , &v , &p);
        -- l , -- p;// [l , r)
        ll = l / M , rr = r / M , k = 0;
        if (ll == rr)
        {
            for (i = l ; i < r ; ++ i)
                if (a[i] < v)
                    ++ k;
        }
        else
        {
            //Left
            for (i = l ; i < L[ll + 1] ; ++ i)
                if (a[i] < v)
                    ++ k;
            //Right
            for (i = L[rr] ; i < r ; ++ i)
                if (a[i] < v)
                    ++ k;
            for (i = ll + 1 ; i < rr ; ++ i)
                k += upper_bound(b[i].s , b[i].s + b[i].size , v - 1) - b[i].s;
        }
        //update
        k = (long long) u * k / (r - l) , id = p / M;
        for (i = 0 ; i < L[id + 1] - L[id]; ++ i)
            if (b[id].s[i] == a[p])
            {
                b[id].s[i] = k;
                while (i + 1 < b[id].size && b[id].s[i] > b[id].s[i + 1])
                    swap(b[id].s[i] , b[id].s[i + 1]) , ++ i;
                while (i - 1 >= 0 && b[id].s[i] < b[id].s[i - 1])
                    swap(b[id].s[i] , b[id].s[i - 1]) , -- i;
                break;
            }
        a[p] = k;
        //Left
    }
    for (i = 0 ; i < n ; ++ i)
        printf("%d\n" , a[i]);
}

int main()
{
    freopen("~input.txt" , "r" , stdin);
    //int _; scanf("%d",&_); while (_ --)
    while (~scanf("%d%d%d",&n,&m,&u))
        work();
    return 0;
}
