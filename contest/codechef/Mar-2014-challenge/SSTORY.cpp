#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
#define N 500505
int n ; char s[N];
int sa[N] , t1[N] , t2[N] , c[N];
int rank[N] , height[N];
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
}

void work()
{
    int i , j , k , l , m;
    scanf("%s" , s);
    m = n = strlen(s) , s[n] = '$' ;
    scanf("%s" , s + n + 1);
    n = strlen(s) + 1 , s[n - 1] = '#';
    buildsa(256);
    //for (int i = 0 ; i < n ; ++ i)printf("%d : %d " , i , height[i]) , puts(s + sa[i]);
    int ans = 0;

    for (int i = 3 ; i < n ; ++ i)
        if ((sa[i] > m && sa[i - 1] < m) || (sa[i - 1] > m && sa[i] < m))
            ans = max(ans , height[i]);
    if (ans)
    {
        int x = 1 << 30;
        j = 2;
        for (i = 3 ; i <= n ; ++ i) {
            if (i == n || height[i] < ans) {
                k = i - 1;
                if (j != k) {
                    //printf("%d %d\n" ,j , k);
                    for (l = j ; l <= k ; ++ l)
                        if (sa[l] < m)
                            break;
                    if (l <= k)
                        for (l = j ; l <= k ; ++ l)
                            if (sa[l] > m)
                                x = min(x , sa[l]);
                }
                j = i;
            }
        }
        s[x + ans] = 0;
        puts(s + x);
    }
    printf("%d\n" , ans);
}

int main()
{
    //freopen("~input.txt" ,"r" , stdin);
    work();
    return 0;
}
