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
#include <cassert>
using namespace std;
typedef long long LL;

#define N 32
int n , m , P , ca;
double f[N][18000][2];
bool u[N][18000][2];
double w[5][N];
int p[N];
bool Link[N];

double dfs(int x , int msk , bool Q) {
    if (u[x][msk][Q]) return f[x][msk][Q];
    double& ans = f[x][msk][Q]; u[x][msk][Q] = 1;
    ans = -1e60; int a[6] = {} , i , j;
    for (i = 0 ; i < n ; ++ i)
        a[i] = msk / p[i] % P;
    if (x == m) {
        sort(a , a + n);
        if (a[n - 1] - a[0] <= 1)
            return ans = 0;
        return ans = -1e60;
    }
    for (i = 0 ; i < n ; ++ i) {
        if (a[i] + 1 >= P) continue;
        if (Link[x] && !Q)
            ans = max(ans , dfs(x + 1 , msk + p[i] , 0));
        else
            ans = max(ans , w[i][x] * (1 + dfs(x + 1 , msk + p[i] , 1)) + (1 - w[i][x]) * dfs(x + 1 , msk + p[i] , 0));
    }
    return ans;
}

void work() {
    int i , j , k , x , y;
    scanf("%d%d",&n,&m);
    //n = 5 , m = 30;
    P = (m + n - 1) / n + 1 , p[0] = 1;
    for (i = 1 ; i <= n ; ++ i)
        p[i] = p[i - 1] * P;
    scanf("%d",&k);
    memset(Link , 0 , sizeof(Link));
    while (k --)
        scanf("%d",&x) , Link[x - 1] = 1;
    for (i = 0 ; i < n ; ++ i)
        for (j = 0 ; j < m ; ++ j)
            scanf("%lf" , &w[i][j]);
    memset(u , 0 , sizeof(u));
    printf("Case %d: %f\n" , ++ca , dfs(0 , 0 , 0));
}

//Case 1: 22.478829
int main(){
    //freopen("1.txt","r",stdin);
    int _ ; scanf("%d",&_); while (_ --)
        work();
    return 0;
}
