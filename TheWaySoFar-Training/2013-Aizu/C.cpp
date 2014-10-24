#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <algorithm>
#define N 105
using namespace std;

int n;
int Dx , Dy , dx[N] , dy[N];
int l[N] , r[N] , t[N] , b[N] , ans;
bool w[N][N][4];
bool f[N][N];
int dx4[] = {1 , -1 , 0 , 0} , dy4[] = {0 , 0 , 1 , -1};

void dfs(int x , int y) {
    if (f[x][y]) return; f[x][y] = 1;
    for (int i = 0 ; i < 4 ; ++ i) {
        if (w[x][y][i]) continue;
        int xx = x + dx4[i] , yy = y + dy4[i];
        if (xx < 0 || xx > Dx || yy < 0 || yy > Dy) continue;
        dfs(xx , yy);
    }
}

void work() {
    int i , j , x;
    Dx = Dy = 0;
    for (i = 0 ; i < n ; ++ i) {
        scanf("%d%d%d%d",&l[i],&t[i],&r[i],&b[i]);
        dx[Dx ++] = l[i] , dx[Dx ++] = r[i];
        dy[Dy ++] = t[i] , dy[Dy ++] = b[i];
    }
    sort(dx , dx + Dx) , Dx = unique(dx , dx + Dx) - dx;
    sort(dy , dy + Dy) , Dy = unique(dy , dy + Dy) - dy;
    for (i = 0 ; i < n ; ++ i) {
        l[i] = lower_bound(dx , dx + Dx , l[i]) - dx + 1;
        r[i] = lower_bound(dx , dx + Dx , r[i]) - dx + 1;
        t[i] = lower_bound(dy , dy + Dy , t[i]) - dy + 1;
        b[i] = lower_bound(dy , dy + Dy , b[i]) - dy + 1;
    }
    ++ Dx , ++ Dy;
    memset(w , 0 , sizeof(w));
    for (i = 0 ; i < n ; ++ i) {
        for (j = l[i] ; j < r[i] ; ++ j) {
            w[j][b[i]][3] = w[j][b[i] - 1][2] = 1;
            w[j][t[i]][3] = w[j][t[i] - 1][2] = 1;
        }
        for (j = b[i] ; j < t[i] ; ++ j) {
            w[l[i]][j][1] = w[l[i] - 1][j][0] = 1;
            w[r[i]][j][1] = w[r[i] - 1][j][0] = 1;
        }
    }
    memset(f , 0 , sizeof(f));
    ans = 0;
    for (i = 0 ; i < Dx ; ++ i)
        for (j = 0 ; j < Dy ; ++ j)
            if (!f[i][j]) {
                ++ ans;
                dfs(i , j);
            }
    printf("%d\n" , ans);
}

int main() {
    //freopen("1.txt" , "r" , stdin);
    while (scanf("%d",&n) , n)
        work();
    return 0;
}
