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
typedef long long LL;

#define N 11
int n , m , A[N] , B[N];
int f[111][N][N][N][N];

void work()
{
    int i , k , a , b , c , d , x;
    scanf("%d%d",&m,&n);
    for (i = 1 ; i <= n ; ++ i) {
        scanf("%d%d",&A[i] , &B[i]);
    }
    memset(f , 63 , sizeof(f));
    f[0][0][0][0][0] = 0;
    for (k = 0 ; k <= m ; ++ k) {
        for (a = n ; a >= 0 ; -- a) {
            for (b = n ; b >= 0 ; -- b) {
                for (c = n ; c >= 0 ; -- c) {
                    for (d = n ; d >= 0 ; -- d) {
                        if (f[k][a][b][c][d] >= 0x3f3f3f3f)
                            continue;
                        x = f[k][a][b][c][d];
                        f[k][0][a][b][c] = min(f[k][0][a][b][c] , x + 1);
                        for (i = 1 ; i <= n ; ++ i) {
                            if (B[i] == 1) {
                                if (a != i)
                                    f[k + A[i]][i][a][b][c] = min(f[k + A[i]][i][a][b][c] , x + 1);
                            } else if (B[i] == 2) {
                                if (a != i && b != i)
                                    f[k + A[i]][i][a][b][c] = min(f[k + A[i]][i][a][b][c] , x + 1);
                            } else if (B[i] == 3) {
                                if (a != i && b != i && c != i)
                                    f[k + A[i]][i][a][b][c] = min(f[k + A[i]][i][a][b][c] , x + 1);
                            } else {
                                if (a != i && b != i && c != i && d != i)
                                    f[k + A[i]][i][a][b][c] = min(f[k + A[i]][i][a][b][c] , x + 1);
                            }
                        }
                    }
                }
            }
        }
    }
    int ans = 1 << 30;
    for (k = m ; k <= m + 10 ; ++ k)
        for (a = 0 ; a <= n ; ++ a)
            for (b = 0 ; b <= n ; ++ b)
                for (c = 0 ; c <= n ; ++ c)
                    for (d = 0 ; d <= n ; ++ d)
                        ans = min(ans , f[k][a][b][c][d]);
    printf("%d\n" , ans);
}

int main()
{
    freopen("1.txt" , "r" , stdin);
    work();
    return 0;
}


