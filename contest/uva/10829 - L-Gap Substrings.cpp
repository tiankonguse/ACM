#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <queue>
#include <cctype>
#include <cmath>
using namespace std;
typedef long long LL;
#define N 100005
int n , m , K; char s[N];
int sa[N] , t1[N] , t2[N] , c[N];
int rank[N] , height[N];
int f[17][N];
void buildsa(int m)
{
    int i , k , *x = t1 , *y = t2;
    for (i = 0 ; i < m ; ++ i) c[i] = 0;
    for (i = 0 ; i < n ; ++ i) ++ c[x[i] = s[i]];
    for (i = 1 ; i < m ; ++ i) c[i] += c[i - 1];
    for (i = n - 1 ; i >= 0 ; -- i) sa[-- c[x[i]]] = i;
    for (k = 1 ; k <= n ; k <<= 1)
    {
        int p = 0;
        for (i = n - k ; i < n ; ++ i) y[p ++] = i;
        for (i = 0 ; i < n ; ++ i) if (sa[i] >= k) y[p ++] = sa[i] - k;
        for (i = 0 ; i < m ; ++ i) c[i] = 0;
        for (i = 0 ; i < n ; ++ i) ++ c[x[y[i]]];
        for (i = 1 ; i < m ; ++ i) c[i] += c[i - 1];
        for (i = n - 1 ; i >= 0 ; -- i) sa[-- c[x[y[i]]]] = y[i];
        swap(x , y) , p = 1 , x[sa[0]] = 0;
        for (i = 1 ; i < n ; ++ i)
            x[sa[i]] = (y[sa[i-1]] == y[sa[i]] && y[sa[i-1]+k] == y[sa[i]+k]) ? p - 1 : p ++;
        if (p >= n) break;
        m = p;
    }
    k = 0;
    for (i = 0 ; i < n ; ++ i) rank[sa[i]] = i;
    for (i = 0 ; i < n ; ++ i)
    {
        if (k) -- k; if (!rank[i]) continue;
        int j = sa[rank[i] - 1];
        while (s[i + k] == s[j + k]) ++ k;
        height[rank[i]] = k;
    }
    memset(f , 0 , sizeof(f));
    for (i = 0 ; i < n ; ++ i)
        f[0][i] = height[i];
    for (int j = 1 ; 1 << j <= n ; ++ j)
        for (i = 1 ; i + (1 << j) - 1 < n ; ++ i)
            f[j][i] = min(f[j - 1][i] , f[j - 1][i + (1 << j - 1)]);
}

int LCP(int x , int y)
{
    x = rank[x] , y = rank[y];
    if (x > y) swap(x , y);
    ++ x;
    int j = log2(y - x + 1);
    return min(f[j][x] , f[j][y - (1 << j) + 1]);
}

void work()
{
    int i , j , x , y;
    scanf("%d%s" , &K , s);
    n = strlen(s);
    s[n] = '%';
    for (i = n + 1 ; i <= n + n ; ++ i)
        s[i] = s[i - n - 1];
    reverse(s + n + 1 , s + n + n + 1);
    s[n + n + 1] = '$' , n = n + n + 2;
    buildsa(128);
    LL ans = 0;
    n >>= 1 , n --;
    for (j = 1 ; j + j <= n ; ++ j)
        for (i = 0 ; i + j + K < n ; i += j)
        {
            x = min(j , LCP(i , i + j + K));
            y = min(j , LCP(n + n - i , n + n - i - j - K));
            ans += max(0 , x + y - j);
        }
    printf("Case %d: %lld\n" , ++ m , ans);
}

int main()
{
    freopen("~input.txt" , "r" , stdin);

    int _; scanf("%d" , &_); while (_ --)
        work();
    return 0;
}
