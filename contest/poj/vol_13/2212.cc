#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>

#define inf 0x3f3f3f3f
#define Inf 0x3FFFFFFFFFFFFFFFLL
#define maxn 105
using namespace std;
bool mp[maxn][maxn][maxn];
int T, X, Y, Z, res;
int dir[6][3] = {0, 0, 1, 0, 0, -1, 0, 1, 0, 0, -1, 0, 1, 0, 0, -1, 0, 0};
bool check(int x, int y, int z){
    if(x >= 1 && x <= X && y >= 1 && y <= Y && z >= 1 && z <= Z) return true;
    else return false;
}
void dfs(int z, int x, int y){
    res++;
    mp[z][x][y] = false;
    int tx, ty, tz;
    for(int i=0;i<6;i++){
        tx = x + dir[i][0];
        ty = y + dir[i][1];
        tz = z + dir[i][2];
        if(check(tx, ty, tz) && mp[tz][tx][ty]) dfs(tz, tx, ty);
    }
}
int main(){
    int n, x, y;
    for(scanf("%d", &T);T--;){
        memset(mp, false, sizeof(mp));
        scanf("%d%d%d", &X, &Y, &Z);
        for(int i=1;i<=Z;i++){
            for(scanf("%d", &n);n--;){
                scanf("%d%d", &x, &y);
                mp[i][x][y] = true;
            }
        }
        res = 0;
        for(int i=1;i<=X;i++){
            for(int j=1;j<=Y;j++){
                if(mp[1][i][j]) dfs(1, i, j);
            }
        }
        printf("Je nutne vycerpat %d litru vody.\n", res * 1000);
    }
    return 0;
}
