#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
typedef unsigned long long ULL;
#define N 200005
int n , m , K; int s[N] , ca;
int sa[N] , t1[N] , t2[N] , c[N];
int rank[N] , height[N];
void buildsa(int m)
{
    int i , k , *x = t1 , *y = t2;
    for (i = 0 ; i < m ; ++ i) c[i] = 0;
    for (i = 0 ; i < n ; ++ i) ++ c[x[i] = s[i]];
    for (i = 1 ; i < m ; ++ i) c[i] += c[i - 1];
    for (i = n - 1 ; i >= 0 ; -- i) sa[-- c[x[i]]] = i;
    for (k = 1 ; k <= n ; k <<= 1) {
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
    height[n] = 0;
}
char str[1005];
int id[N];
bool F[N];
bool check(int ans)
{
    memset(F , 0 , sizeof(F));
    int res = 1; F[id[sa[m]]] = 1;
    for (int i = m + 1 , x = m ; i <= n ; ++ i)
    {
        if (height[i] < ans)
        {
            // x ~ i - 1
            for (int j = x ; j < i ; ++ j)
                F[id[sa[j]]] = 0;
            if (res + res > m)
                return 1;
            x = i , res = 0;
        }
        if (!F[id[sa[i]]]) F[id[sa[i]]] = 1 , ++ res;
    }
    return 0;
}
void print(int ans)
{
    memset(F , 0 , sizeof(F));
    int res = 1; F[id[sa[m]]] = 1;
    for (int i = m + 1 , x = m ; i <= n ; ++ i)
    {
        if (height[i] < ans)
        {
            // x ~ i - 1
            for (int j = x ; j < i ; ++ j)
                F[id[sa[j]]] = 0;
            if (res + res > m)
            {
                for (int j = 0 ; j < ans ; ++ j)
                    printf("%c" , s[sa[x] + j] - 200 + 'a' - 1);
                puts("");
            }
            x = i , res = 0;
        }
        if (!F[id[sa[i]]])
            F[id[sa[i]]] = 1 , ++ res;
    }
}

void work()
{
    n = 0;
    int i , j , x , l = 0 , r = 1000 , mid;
    for (i = 0 ; i < m ; ++ i)
    {
        scanf("%s" , str);
        for (j = 0 ; str[j] ; ++ j)
            id[n] = i , s[n ++] = 200 + str[j] - 'a' + 1;
        s[n ++] = i + 1;
    }
    s[n] = 0;
    buildsa(256);
    //for (i = 0 ; i < n ; ++ i)
    //    printf("%d " ,height[i]);puts("");
    if (ca ++) puts("");
    while (l < r)
    {
        mid = l + r + 1 >> 1;
        if (check(mid))
            l = mid;
        else
            r = mid - 1;
    }
    //printf("%d\n" , l);
    if (!l)
        puts("?");
    else
        print(l);
}

int main()
{
    freopen("~input.txt" , "r" , stdin);
    //int _; scanf("%d",&_); while (_ --)
    while (scanf("%d",&m) , m)
        work();
    return 0;
}
