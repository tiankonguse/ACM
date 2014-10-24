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

#define N 25

int n , Q = 9999991;
int L[N] , R[N] , Key[N] , sum[N];
int C[N][N] , f[N] , a[N];

void insert(int x , int fa , int y , int d)
{
    if (!x)
    {
        !d ? L[fa] = y : R[fa] = y;
        return;
    }
    if (a[y] < a[x])
        insert(L[x] , x , y , 0);
    else insert(R[x] , x , y , 1);
}

void dfs(int x)
{
    if (!x) return;
    sum[x] = 1;
    dfs(L[x]); dfs(R[x]);
    sum[x] += sum[L[x]] , sum[x] += sum[R[x]];
    f[x] = (LL)f[L[x]] * f[R[x]] % Q * C[sum[x] - 1][sum[L[x]]] % Q;
}

void work()
{
    int i , j , root = 0;
    scanf("%d",&n);
    for (i = 0 ; i <= n ; ++ i)
    {
        C[i][0] = 1;
        for (j = 1 ; j <= n ; ++ j)
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % Q;
    }
    for (i = 1 ; i <= n ; ++ i)
        scanf("%d",&a[i]);
    memset(L , 0 , sizeof(L));
    memset(R , 0 , sizeof(R));
    f[0] = 1;
    root = 1;
    for (i = 2 ; i <= n ; ++ i)
        insert(root , 0 , i ,  -1);
    dfs(root);
    printf("%d\n" , f[root]);
}

int main()
{
    freopen("~input.txt" , "r" , stdin);
    int _; scanf("%d",&_); while (_ --)
    //while (scanf("%d\n",&n) , n)
        work();
    return 0;
}
