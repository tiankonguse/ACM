#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;

#define N 105
int n , a[N] , p[N];
int f[N][N][N][2];

int F(int i , int j , int k , int d)
{
    if (~f[i][j][k][d]) return f[i][j][k][d];
    int& res = f[i][j][k][d]; res = -1 << 30;
    if (i == j) {
        if (!d)
            return res = p[i] - abs(a[i]) * (k + 1);
        else
            return res = p[j] - abs(a[j]) * (k + 1);
    }
    else {
        if (!d) {
            res = max(res , F(i + 1 , j , k , 0) - (a[i + 1] - a[i]) * k);
            res = max(res , F(i + 1 , j , k , 1) - (a[j] - a[i]) * k);
            if (k < n) {
                res = max(res , F(i + 1 , j , k + 1 , 0) - (a[i + 1] - a[i]) * (k + 1) + p[i]);
                res = max(res , F(i + 1 , j , k + 1 , 1) - (a[j] - a[i]) * (k + 1) + p[i]);
            }
        }
        else {
            res = max(res , F(i , j - 1 , k , 0) - (a[j] - a[i]) * k);
            res = max(res , F(i , j - 1 , k , 1) - (a[j] - a[j - 1]) * k);
            if (k < n) {
                res = max(res , F(i , j - 1 , k + 1 , 0) - (a[j] - a[i]) * (k + 1) + p[j]);
                res = max(res , F(i , j - 1 , k + 1 , 1) - (a[j] - a[j - 1]) * (k + 1) + p[j]);
            }
        }
        return res;
    }
}

void work()
{
    int i , j , k , ans = 0;
    scanf("%d",&n);
    for (i = 1 ; i <= n ; ++ i)
        scanf("%d",&a[i]);
    for (i = 1 ; i <= n ; ++ i)
        scanf("%d",&p[i]);
    for (i = 0 ; i <= n ; ++ i)
        for (j = 0 ; j <= n ; ++ j)
            for (k = 0 ; k <= n ; ++ k)
                f[i][j][k][0] = f[i][j][k][1] = -1;
    for (i = 1 ; i <= n ; ++ i)
        for (j = i ; j <= n ; ++ j)
            ans = max(ans , max(F(i , j , 0 , 0) , F(i , j , 0 , 1)));
    printf("%d\n" , ans);
}

int main()
{
    int _; scanf("%d",&_); while (_ --)
        work();
    return 0;
}
