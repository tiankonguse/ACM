#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;

#define N 105
int n , m , K , ca;
int g[N][N];
int dis[N] , M[N] , S[N] , top;
bool vis[N];

bool dfs(int x) {
    S[++ top] = x;
    if (vis[x]) return 1;
    vis[x] = 1;
    for (int y = 1 ; y <= n ; ++ y) {
        if (x != y && M[x] != y && !vis[y]) {
            int z = M[y];
            if (dis[z] + g[z][y] < dis[x] + g[x][y]) {
                dis[z] = dis[x] + g[x][y] - g[z][y];
                if (dfs(z)) return 1;
            }
        }
    }
    -- top , vis[x] = 0;
    return 0;
}
//Maximum 
int match() {
    int i , j;
    for (i = 1 ; i <= n ; i += 2)
        M[i] = i + 1 , M[i + 1] = i;
    int cnt = 0;
    while (1) {
        top = 0;
        bool found = 0;
        memset(dis , 0 , sizeof(dis));
        memset(vis , 0 , sizeof(vis));
        for (i = 1 ; i <= n ; ++ i) {
            if (dfs(i)) {
                found = 1;
                int nx = M[S[top]];
                for (j = top - 1 ; S[j] != S[top] ; -- j) {
                    M[nx] = S[j];
                    swap(nx , M[S[j]]);
                }
                M[nx] = S[j] , M[S[j]] = nx;
                break;
            }
        }
        if (!found) {
            ++ cnt;
            if (cnt >= 3)
                break;
        }
    }
    int ret = 0;
    for (i = 1 ; i <= n ; ++ i)
        if (i > M[i])
            ret += g[i][M[i]];
    return ret;
}

void work() {
    int i , j , k , x , y , z;
    printf("Case %d: " , ++ ca);
    scanf("%d%d%d",&n,&m,&K);
    memset(g , 63 , sizeof(g));
    for (i = 1 ; i <= m ; ++ i) {
        scanf("%d%d%d",&x,&y,&z);
        g[x][y] = g[y][x] = z;
    }
    if (K & 1) {
        puts("Impossible");
        return;
    }
    for (k = 1 ; k <= n ; ++ k)
        for (i = 1 ; i <= n ; ++ i)
            for (j = 1 ; j <= n ; ++ j) if (i != j)
                g[i][j] = min(g[i][j] , g[i][k] + g[k][j]);
    for (i = 1 ; i <= n ; ++ i)
        for (j = 1 ; j <= n ; ++ j)
            g[i][j] = -g[i][j];
    n = K;
    printf("%d\n" , -match());
}

int main(){
    freopen("1.txt" , "r" , stdin);
    //while (cin >> n)
    int _; scanf("%d",&_); while(_ --)
        work();
    return 0;
}

