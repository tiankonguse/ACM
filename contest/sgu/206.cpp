#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
#include <stack>
#include <vector>
#include <queue>
#include <cmath>
#include <cassert>
using namespace std;
typedef long long LL;

#define N 405
int n , m , pre[N] , mcnt;
struct edge {
    int x , w , next;
}e[N << 1];
int f[N] , dep[N] , val[N];

int S , g[N][N] , lx[N] , ly[N] , match[N] , ans , slack[N];
bool fx[N] , fy[N];

bool find(int x) {
    fx[x] = 1;
    for (int y = 1 ; y <= S ; ++ y) {
        if (fy[y]) continue;
        if (lx[x] + ly[y] == g[x][y]) {
            fy[y] = 1;
            if (!match[y] || find(match[y])) {
                match[y] = x;
                return 1;
            }
        } else {
            slack[y] = min(slack[y] , lx[x] + ly[y] - g[x][y]);
        }
    }
    return 0;
}

void update() {
    int delta = 1 << 30 , i;
    for (i = 1 ; i <= S ; ++ i)
        if (!fy[i])
            delta = min(delta , slack[i]);
    for (i = 1 ; i <= S ; ++ i) {
        if (fx[i]) lx[i] -= delta;
        if (fy[i]) ly[i] += delta;
        slack[i] -= delta;
    }
}

void Kuhn_Munkras() {
    int i , j;
    for (i = 1 ; i <= S ; ++ i) {
        match[i] = lx[i] = ly[i] = 0;
        for (j = 1 ; j <= S ; ++ j)
            lx[i] = max(lx[i] , g[i][j]);
    }
    for (i = 1 ; i <= S ; ++ i) {
        while (1) {
            for (j = 1 ; j <= S ; ++ j)
                fx[j] = fy[j] = 0 , slack[j] = 1 << 30;
            if (find(i))
                break;
            else
                update();
        }
    }
}


void dfs(int x , int fa , int d) {
    f[x] = fa , dep[x] = d;
    for (int i = pre[x] ; ~i ; i = e[i].next) {
        int y = e[i].x;
        if ((i ^ 1) != fa) {
            dfs(y , i , d + 1);
        }
    }
}

void work() {
    int i , j , x , y , z;
    scanf("%d%d",&n,&m);
    memset(pre , -1 , sizeof(pre));
    for (i = 1 ; i < n ; ++ i) {
        scanf("%d%d%d",&x,&y,&z);
        val[i] = z;
        e[mcnt] = (edge) {y , z , pre[x]} , pre[x] = mcnt ++;
        e[mcnt] = (edge) {x , z , pre[y]} , pre[y] = mcnt ++;
    }
    dfs(1 , -1 , 0);
    for (i = 1 ; i <= m - n + 1 ; ++ i) {
        scanf("%d%d%d",&x,&y,&z);
        val[n + i - 1] = z;
        if (dep[x] < dep[y]) swap(x , y);
        while (dep[x] > dep[y]) {
            j = f[x] ^ 1;
            g[(j >> 1) + 1][i] = max(0 , val[(j >> 1) + 1] - z);
            x = e[j].x;
        }
        while (x != y) {
            j = f[x] ^ 1;
            g[(j >> 1) + 1][i] = max(0 , val[(j >> 1) + 1] - z);
            x = e[j].x;
            j = f[y] ^ 1;
            g[(j >> 1) + 1][i] = max(0 , val[(j >> 1) + 1] - z);
            y = e[j].x;
        }
    }
    S = max(n - 1 , m - n + 1);
    /*for (i = 1 ; i <= S ; ++ i) {
        for (j = 1 ; j <= S ; ++ j) {
            printf("%d%c" , g[i][j] , " \n"[j == S]);
        }
    }*/
    Kuhn_Munkras();
    for (i = 1 ; i < n ; ++ i)
        printf("%d\n" , val[i] - lx[i]);
    for (i = 1 ; i <= m - n + 1 ; ++ i)
        printf("%d\n" , val[n - 1 + i] + ly[i]);
}

int main(){
    work();
    return 0;
}
