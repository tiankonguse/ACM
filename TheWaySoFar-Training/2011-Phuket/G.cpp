#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>
#include <vector>
#include <stack>
#include <cmath>
using namespace std;
typedef long long LL;
#define N 25

const int n = 20;
int m , ca;
char s[N][N];
int X[N] , Y[N] , H[N] , W[N];
bool f[N];
int ans ;

int d[N];

void dfs(int XX , int YY , int k , int sum) {
    if (k > m) {
        ans = min(ans , sum);
        return;
    }
    int x = -1 , i , j;
    for (i = 1 ; i <= 5 ; ++ i)
        if (!~x || (d[i] < d[x]))
            x = i;
    for (i = 1 ; i <= m ; ++ i) {
        if (f[i]) continue;
        if (d[x] + H[i] > 5) continue;
        //x ~ x + W[i] - 1;
        if (x + W[i] - 1 > 5) continue;
        for (j = x ; j < x + W[i] ; ++ j)
            if (d[j] != d[x])
                break;
        if (j < x + W[i]) continue;

        f[i] = 1;
        for (j = x ; j < x + W[i] ; ++ j)
            d[j] += H[i];
        dfs(XX , YY , k + 1 , sum + abs(X[i] - (XX - 1 + x)) + abs(Y[i] - (YY - 1 + d[x] - H[i] + 1)));
        f[i] = 0;
        for (j = x ; j < x + W[i] ; ++ j)
            d[j] -= H[i];
    }
}

void work()
{
    int i , j;
    printf("Case %d: " , ++ ca);
    for (i = 1 ; i <= n ; ++ i)
        scanf("%s" , s[i] + 1);
    memset(f , 0 , sizeof(f));
    m = 0;
    for (i = 1 ; i <= n ; ++ i)
        for (j = 1 ; j <= n ; ++ j) {
            if (s[i][j] != 'x') continue;
            if (s[i - 1][j] == 'x') continue;
            if (s[i][j - 1] == 'x') continue;
            ++ m;
            W[m] = H[m] = 0;
            while (s[i + W[m]][j] == 'x')
                ++ W[m];
            while (s[i][j + H[m]] == 'x')
                ++ H[m];
            X[m] = i , Y[m] = j;
        }
    ans = 1 << 30;

    for (i = 1 ; i <= 16 ; ++ i) {
        for (j = 1 ; j <= 16 ; ++ j) {
            dfs(i , j , 1 , 0);
        }
    }
    if (ans == 1 << 30)
        puts("invalid data");
    else
        printf("%d\n" , ans);
}

int main()
{
    //freopen("1.txt" , "r" , stdin);
    int _; scanf("%d",&_); while (_ --)
        work();
    return 0;
}
