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

#define N 105
int n , m , K , A , B , C , D;
int g[N][N] , f[N];
int R[1001][N] , S[1001] , W[1001];
int FB[1001][N] , FD[1001][N];

void work() {
    int i , j , k , x , y , z;
    scanf("%d%d%d%d",&A,&B,&C,&D);
    memset(g , 63 , sizeof(g));
    for (i = 1 ; i <= n ; ++ i)
        g[i][i] = 0;
    int inf = g[0][0];
    K = 0;
    for (i = 1 ; i <= m ; ++ i) {
        scanf("%d%d%d",&z,&j,&x);
        if (j == 1)
            scanf("%d",&y) , g[x][y] = min(g[x][y] , z);
        else {
            ++ K , R[K][S[K] = 1] = x , W[K] = z;
            for (k = 0 ; k < j ; ++ k)
                scanf("%d",&y) , g[x][y] = min(g[x][y] , z) , R[K][++ S[K]] = y;
        }
    }
    for (k = 1 ; k <= n ; ++ k)
        for (i = 1 ; i <= n ; ++ i)
            for (j = 1 ; j <= n ; ++ j)
                g[i][j] = min(g[i][j] , g[i][k] + g[k][j]);
    int ans = min(inf , g[A][B] + g[C][D]);
    for (i = 1 ; i <= n ; ++ i) {
        if (g[A][i] >= inf) continue;
        if (g[C][i] >= inf) continue;
        if (g[i][B] >= inf) continue;
        if (g[i][D] >= inf) continue;
        ans = min(ans , g[A][i] + g[C][i] + g[i][B] + g[i][D]);
    }
    for (k = 1 ; k <= K ; ++ k) {
        y = S[k];
        memset(FB[k] , 63 , sizeof(FB[k]));
        memset(FD[k] , 63 , sizeof(FD[k]));
        for (j = 1 ; j <= y ; ++ j)
            if (R[k][j] == B)
                FB[k][j] = 0;
        FB[k][y] = min(g[R[k][y]][B] , FB[k][y]);
        for (j = y - 1 ; j >= 1 ; -- j)
            FB[k][j] = min(min(FB[k][j + 1] , FB[k][j]) , g[R[k][j]][B]);
        for (j = 1 ; j <= y ; ++ j)
            if (R[k][j] == D)
                FD[k][j] = 0;
        FD[k][y] = min(g[R[k][y]][D] , FD[k][y]);
        for (j = y - 1 ; j >= 1 ; -- j)
            FD[k][j] = min(min(FD[k][j + 1] , FD[k][j]) , g[R[k][j]][D]);
    }

    for (i = 1 ; i <= K ; ++ i) {
        for (j = 1 ; j <= S[i] ; ++ j)
            if (!f[R[i][j]])
                f[R[i][j]] = j;
        for (k = 1 ; k <= K ; ++ k) {
            for (j = 1 ; j <= S[k] ; ++ j)
                if (f[R[k][j]]) {
                    if (g[A][R[i][1]] >= inf) continue;
                    if (g[C][R[k][1]] >= inf) continue;
                    if (FB[k][j] >= inf) continue;
                    if (FD[i][f[R[k][j]]] >= inf) continue;
                    ans = min(ans , g[A][R[i][1]] + g[C][R[k][1]] + W[i] + W[k] + FD[i][f[R[k][j]]] + FB[k][j]);
                }
        }
        for (j = 1 ; j <= S[i] ; ++ j) {
            x = R[i][j];
            if (g[C][x] >= inf) continue;
            if (g[x][B] >= inf) continue;
            if (FD[i][j] >= inf) continue;
            if (g[A][R[i][1]] >= inf) continue;
            ans = min(ans , g[A][R[i][1]] + FD[i][j] + g[C][x] + g[x][B] + W[i]);
        }
        for (j = 1 ; j <= S[i] ; ++ j) {
            x = R[i][j];
            if (g[A][x] >= inf) continue;
            if (g[x][D] >= inf) continue;
            if (FB[i][j] >= inf) continue;
            if (g[C][R[i][1]] >= inf) continue;
            ans = min(ans , g[C][R[i][1]] + FB[i][j] + g[A][x] + g[x][D] + W[i]);
        }
        for (j = 1 ; j <= S[i] ; ++ j)
            f[R[i][j]] = 0;
    }

    if (ans == inf) {
        puts("Impossible!");
    } else {
        printf("%d\n" , ans);
    }
}

int main(){
    while (scanf("%d%d",&n,&m) , n || m)
        work();
    return 0;
}
