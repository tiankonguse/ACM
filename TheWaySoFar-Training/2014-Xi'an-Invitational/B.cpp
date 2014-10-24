#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <cassert>
//#pragma comment(linker, "/STACK:16777216")
using namespace std;
typedef long long LL;
const int N = 35;
int n , g[N][N] , t[N];
int R[N] , L[N] , ans;

void dfs(int x , int sum , int T , int num) {
    for (int i = R[0] ; i ; i = R[i])
        if (T + g[x][i] > t[i])
            return;
    if (sum >= ans) return;
    L[R[x]] = L[x] , R[L[x]] = R[x];
    if (R[0] == 0) {
        ans = min(ans , sum);
        L[R[x]] = R[L[x]] = x;
        return;
    }
    for (int i = R[0] ; i ; i = R[i])
        dfs(i , sum + g[x][i] * num , T + g[x][i] , num - 1);
    L[R[x]] = R[L[x]] = x;
}

void work() {
    int i , j , k;
    for (i = 1 ; i <= n; ++ i)
        for (j = 1 ; j <= n ; ++ j)
            scanf("%d",&g[i][j]);
    for (k = 1 ; k <= n ; ++ k)
        for (i = 1 ; i <= n ; ++ i)
            for (j = 1 ; j <= n ; ++ j)
                g[i][j] = min(g[i][j] , g[i][k] + g[k][j]);
    for (i = 2 ; i <= n ; ++ i)
        scanf("%d",&t[i]);
    for (i = 0 ; i <= n ; ++ i)
        R[i] = i + 1 , L[i] = i - 1;
    R[n] = 0 , L[0] = n;
    ans = 1 << 30;
    dfs(1 , 0 , 0 , n - 1);
    if (ans == 1 << 30)
        puts("-1");
    else
        printf("%d\n",ans);
}

int main()
{
    while (~scanf("%d",&n))
        work();
    return 0;
}
