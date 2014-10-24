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
int a[N][N] , b[N];
bool f[N][N];
void work()
{
    int i , j , k;
    cin >> n;
    for (i = 1 ; i <= n ; ++ i)
        for (j = 1 ; j <= n ; ++ j)
            scanf("%d",&a[i][j]);
    cin >> m;
    for (i = 1 ; i <= m ; ++ i)
        scanf("%d",&b[i]);
    f[0][1] = 1;
    for (i = 1 ; i <= m ; ++ i) {
        for (j = 1 ; j <= n ; ++ j) {
            if (f[i - 1][j]) {
                for (k = 1 ; k <= n ; ++ k) {
                    if (a[j][k] == b[i]) {
                        f[i][k] = 1;
                    }
                }
            }
        }
    }
    vector<int> res;
    for (i = 1 ; i <= n ; ++ i)
        if (f[m][i])
            res.push_back(i);
    printf("%d\n" , res.size());
    for (i = 0 ; i < res.size() ; ++ i)
        printf("%d%c" , res[i] , " \n"[i + 1 == res.size()]);
}


int main()
{
    work();
    return 0;
}

