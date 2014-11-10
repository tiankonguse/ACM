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
using namespace std;
typedef long long LL;
#define N 3005
int n , X[N] , Y[N];
double f[N][N];

double dis(int i , int j)
{
    int x = X[i] - X[j] , y = Y[i] - Y[j];
    return sqrt(x * x + y * y);
}

void work()
{
    int i , j ;
    for (i = 1 ; i <= n ; ++ i)
        scanf("%d%d",&X[i],&Y[i]);
    for (i = 1 ; i <= n ; ++ i)
        for (j = i ; j <= n ; ++ j)
            f[i][j] = 1e60;
    f[1][1] = 0;
    for (i = 1 ; i < n ; ++ i)
        for (j = i ; j < n ; ++ j)
        {
            f[i][j + 1] = min(f[i][j + 1] , f[i][j] + dis(j , j + 1));
            f[j][j + 1] = min(f[j][j + 1] , f[i][j] + dis(i , j + 1));
        }
    printf("%.2f\n" , f[n - 1][n] + dis(n - 1 , n));
}

int main()
{
    freopen("~input.txt" , "r" , stdin);
    while (~scanf("%d",&n))
        work();
    return 0;
}
