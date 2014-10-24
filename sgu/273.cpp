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
#define N 205

int n , a[N];
bool f[N][N][4];
pair<int , int> A[4][16];
char str[N];

int tran(char c) {
    if (c == 'b') return 0;
    if (c == 'r') return 1;
    if (c == 'y') return 2;
    return 3;
}

void work()
{
    int i , j , k , l , t , e , q[4];
    for (i = 0 ; i < 4 ; ++ i)
        scanf("%d",&q[i]);
    for (i = 0 ; i < 4 ; ++ i) {
        for (j = 0 ; j < q[i] ; ++ j) {
            scanf("%s" , str);
            A[i][j] = make_pair(tran(*str) , tran(*(str + 1)));
        }
    }
    scanf("%s" , str) , n = strlen(str);
    for (i = 0 ; i < n ; ++ i) {
        a[i] = tran(str[i]);
    }
    for (i = 0 ; i < n ; ++ i)
        f[i][i][a[i]] = 1;
    for (k = 1 ; k < n ; ++ k) {
        for (i = 0 , j = k ; j < n ; ++ i , ++ j) {
            for (t = 0 ; t < 4 ; ++ t) {

                for (l = i ; l < j && !f[i][j][t] ; ++ l)
                    for (e = 0 ; e < q[t] && !f[i][j][t] ; ++ e)
                        f[i][j][t] |= f[i][l][A[t][e].first] && f[l + 1][j][A[t][e].second];

            }
        }
    }
    for (i = 0 , j = 0 ; i < 4 ; ++ i)
        if (f[0][n - 1][i])
            putchar("bryw"[i]) , j = 1;
    if (!j)
        puts("Nobody");
    else
        puts("");
}

int main()
{
    freopen("1.txt" , "r" , stdin);
    work();
    return 0;
}

