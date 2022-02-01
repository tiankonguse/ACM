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

#define N 25
int n;
char s[N][N];
int len[N];
int w[N][N];
bool use[N];
int f[14][1 << 14];

int cal(int x , int y) {
    int L = min(len[x] , len[y]) , i;
    for ( ; L >= 0 ; -- L) {
        for (i = 0 ; i < L ; ++ i) {
            if (s[y][i] != s[x][len[x] - L + i])
                break;
        }
        if (i >= L)
            return len[y] - L;
    }
    return len[y];
}

void work()
{
    int i , j , k;
    memset(use , 0 , sizeof(use));
    for (i = 0 ; i < n ; ++ i)
        scanf("%s" , s[i]);
    for (i = 0 ; i < n ; ++ i)
        for (j = 0 ;j < n ; ++ j) {
            if (i != j) {
                if (strstr(s[i] , s[j]))
                    use[j] = 1;
            }
        }
    j = n , n = 0;
    for (i = 0 ; i < j ; ++ i)
        if (!use[i])
            strcpy(s[n ++] , s[i]);
    for (i = 0 ; i < n ; ++ i)
        len[i] = strlen(s[i]);

    for (i = 0 ; i < n ; ++ i) {
        for (j = 0 ; j < n ; ++ j) {
            if (i != j) {
                w[i][j] = cal(i , j);
                //printf("%d %d %d\n" , i , j , w[i][j]);
            }
        }
    }
    memset(f , 63 , sizeof(f));
    for (i = 0 ; i < n ; ++ i)
        f[i][1 << i] = len[i];
    for (i = 1 ; i < 1 << n ; ++ i) {
        for (j = 0 ; j < n ; ++ j) {
            if (f[j][i] < 0x3f3f3f3f) {
                for (k = 0 ; k < n ; ++ k)
                    if (~i >> k & 1) {
                        f[k][i | (1 << k)] = min(f[k][i | (1 << k)] , f[j][i] + w[j][k]);
                    }
            }
        }
    }
    int ans = 1 << 30;
    for (i = 0 ; i < n ; ++ i)
        ans = min(ans , f[i][(1 << n) - 1]);
    printf("%d\n" , ans);
}

int main()
{
    //freopen("1.txt" , "r" , stdin);
    while (scanf("%d",&n) , n)
        work();
    return 0;
}
