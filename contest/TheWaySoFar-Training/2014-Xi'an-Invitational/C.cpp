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
//#include <cassert>
//#pragma comment(linker, "/STACK:16777216")
using namespace std;
typedef long long LL;
const int N = 1000;
int n , m , g[N][N];
int X[N * N] , Y[N * N] , cnt[N * N];
bool f[N];
LL d[N];
void work() {
    int i , j , x;
    scanf("%d%d%d%d",&X[0],&X[1],&Y[0],&Y[1]);
    for (i = 2 ; i < n * n ; ++ i) {
        X[i] = (12345 + (LL)X[i - 1] * 23456 + (LL)X[i - 2] * 34567 + (LL)X[i - 1] * X[i - 2] * 45678) % 5837501;
        Y[i] = (56789 + (LL)Y[i - 1] * 67890 + (LL)Y[i - 2] * 78901 + (LL)Y[i - 1] * Y[i - 2] * 89012) % 9860381;
    }
    x = 0;
    for (i = 0 ; i < n ; ++ i) {
        for (j = 0 ; j < n ; ++ j) {
            if (i == j)
                g[i][j] = 0;
            else
                g[i][j] = ((LL)X[x] * 90123 + Y[x]) % 8475871 + 1;
            x ++;
        }
    }
    for (i = 0 ; i < n ; ++ i)
        d[i] = 1LL << 60 , f[i] = 0;
    d[0] = 0;
    while (1) {
        x = -1;
        for (i = 0 ; i < n ; ++ i)
            if (!f[i] && (!~x || d[i] < d[x]))
                x = i;
        if (!~x) break; f[x] = 1;
        for (i = 0 ; i < n ; ++ i)
            d[i] = min(d[i] , d[x] + g[x][i]);
    }
    memset(cnt , 0 , sizeof(cnt));
    for (i = 1 ; i < n ; ++ i)
        ++ cnt[d[i] % m];
    for (i = 0 ; i < m ; ++ i)
        if (cnt[i]) {
            printf("%d\n" , i);
            break;
        }
}


int main()
{
    while (~scanf("%d%d",&n,&m))
        work();
    return 0;
}
