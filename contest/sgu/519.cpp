#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
using namespace std;
typedef long long LL;
#define N 205
int n , m;
int a[N][N] , ans;
void work()
{
    int i , j;
    scanf("%d%d",&n,&m);
    for (i = 1 ; i <= n ; ++ i)
        for (j = 1 ; j <= m ; ++ j)
            scanf("%1d" , &a[i][j]);
    for (i = 1 ; i <= n ; ++ i) {
        for (j = 1 ; j <= m ; ++ j) {
            ans += !!a[i][j] + !!a[i][j];
            if (a[i][j] > a[i - 1][j])
                ans += a[i][j] - a[i - 1][j];
            if (a[i][j] > a[i + 1][j])
                ans += a[i][j] - a[i + 1][j];
            if (a[i][j] > a[i][j - 1])
                ans += a[i][j] - a[i][j - 1];
            if (a[i][j] > a[i][j + 1])
                ans += a[i][j] - a[i][j + 1];
        }
    }
    cout << ans << endl;
}


int main()
{
    work();
    return 0;
}

