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
#include <cassert>
using namespace std;
#define N 205
int n , X , a[N];
bool f[N][10005];
bool g[N][10005];

void work()
{
    int i , j , k;
    scanf("%d%d",&n,&X);
    for (i = 1 ; i <= n ; ++ i)
        scanf("%d",&a[i]);
    f[0][0] = 1;
    for (i = 1 ; i <= n ; ++ i) {
        for (j = 0 ; j <= X ; ++ j) {
            f[i][j] = f[i - 1][j];
            if (j >= a[i])
                f[i][j] |= f[i - 1][j - a[i]];
        }
    }
    g[n + 1][0] = 1;
    for (i = n ; i >= 1 ; -- i) {
        for (j = 0 ; j <= X ; ++ j) {
            g[i][j] = g[i + 1][j];
            if (j >= a[i])
                g[i][j] |= g[i + 1][j - a[i]];
        }
    }
    vector<int> res;
    for (i = 1 ; i <= n ; ++ i) {
        for (j = 0 ; j <= X ; ++ j)
            if (f[i - 1][j] && g[i + 1][X - j])
                break;
        if (j > X)
            res.push_back(a[i]);
    }
    printf("%d\n" , res.size());
    for (i = 0 ; i < res.size() ; ++ i)
        printf("%d%c" , res[i] , " \n"[i + 1 == res.size()]);
}

int main()
{
    work();
    return 0;
}

