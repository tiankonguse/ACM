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
#include <set>
#include <map>
typedef long long LL;
typedef unsigned long long ULL;
using namespace std;
#define N 705

int n , m;
char s[N][N];
ULL R1[N][N] , C1[N][N] , R2[N][N] , C2[N][N];
ULL MAGIC = 31 , power[N];
int X1 , X2 , Y1 , Y2;
int r[N][N] , c[N][N];

bool check(int K) {
    int i , j; ULL X , Y;
    for (i = 1 ; i <= n ; ++ i) {
        for (j = 1 ; j + K - 1 <= m ; ++ j) {
            X = R1[i][j + K - 1] - power[K] * R1[i][j - 1];
            Y = R2[i][j] - power[K] * R2[i][j + K];
            r[i][j] = r[i - 1][j] + (X == Y);
        }
    }
    for (j = 1 ; j <= m ; ++ j) {
        for (i = 1 ; i + K - 1 <= n ; ++ i) {
            X = C1[j][i + K - 1] - power[K] * C1[j][i - 1];
            Y = C2[j][i] - power[K] * C2[j][i + K];
            c[i][j] = c[i][j - 1] + (X == Y);
        }
    }

    for (i = 1 ; i + K - 1 <= n ; ++ i) {
        for (j = 1 ; j + K - 1 <= m ; ++ j) {
            if (r[i + K - 1][j] - r[i - 1][j] == K && c[i][j + K - 1] - c[i][j - 1] == K) {
                X1 = i , X2 = i + K - 1;
                Y1 = j , Y2 = j + K - 1;
                return 1;
            }
        }
    }
    return 0;
}

void work()
{
    int i , j;
    scanf("%d%d",&n,&m);
    for (i = 1 ; i <= n ; ++ i)
        scanf("%s" , s[i] + 1);
    power[0] = 1;
    for (i = 1 ; i <= n || i <= m ; ++ i)
        power[i] = power[i - 1] * MAGIC;
    for (i = 1 ; i <= n ; ++ i) {
        for (j = 1 ; j <= m ; ++ j)
            R1[i][j] = R1[i][j - 1] * MAGIC + s[i][j] - 'a' + 1;
        for (j = m ; j > 0 ; -- j)
            R2[i][j] = R2[i][j + 1] * MAGIC + s[i][j] - 'a' + 1;
    }
    for (j = 1 ; j <= m ; ++ j) {
        for (i = 1 ; i <= n ; ++ i)
            C1[j][i] = C1[j][i - 1] * MAGIC + s[i][j] - 'a' + 1;
        for (i = n ; i > 0 ; -- i)
            C2[j][i] = C2[j][i + 1] * MAGIC + s[i][j] - 'a' + 1;
    }
    int ans = 0;
    int l = 0 , r = (min(n , m) - 1) / 2 , mid;
    while (l < r) {
        mid = (l + r + 1) >> 1;
        if (check(mid + mid + 1)) {
            l = mid;
        } else
            r = mid - 1;
    }
    ans = max(ans , l + l + 1);
    l = 0 , r = min(n , m) / 2;
    while (l < r) {
        mid = (l + r + 1) >> 1;
        if (check(mid + mid)) {
            l = mid;
        } else
            r = mid - 1;
    }
    ans = max(ans , l + l);
    check(ans);
    printf("%d %d %d %d\n" , X1 , Y1 , X2 , Y2);
}

int main()
{
    work();
    return 0;
}
