#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <bitset>

#define inf 0x3f3f3f3f
#define INF 0x3FFFFFFFFFFFFFFFLL
#define maxn 370
using namespace std;
int mp[maxn][maxn];
int next[maxn][maxn];
int mark[maxn][maxn];
int dir[8][2] = {-2, -1, -2, 1, -1, 2, 1, 2, 2, 1, 2, -1, 1, -2, -1, -2};
int n;
bool check(int x, int y){
    if(x < 0 || y < 0 || x >= n || y >= n) return false;
    else return true;
}
void dfs(int x, int y){
    if(mark[x][y] != -1){
      // printf("mark[%d][%d] = %d\n", x, y, mark[x][y]);
        return;
    }
    int res = 1, tx, ty;
    int px, py, qx, qy, xx, yy;
    for(int i=0;i<8;i++){
        tx = x + dir[i][0];
        ty = y + dir[i][1];
        if(check(tx, ty) && mp[tx][ty] > mp[x][y]){
            dfs(tx, ty);
          //  printf("mark[%d][%d] = %d\n", tx, ty, mark[tx][ty]);
            if(mark[tx][ty] + 1 > res){
                res = mark[tx][ty] + 1;
                next[x][y] = i;
            }
            else if(mark[tx][ty] + 1 == res){
                px = tx, py = ty;
                qx = x + dir[ next[x][y] ][0];
                qy = y + dir[ next[x][y] ][1];
             //   printf("(%d, %d) vs (%d, %d)\n", px, py, qx, qy);
                bool flag;
                for(int k=1;k<res;k++){
                    if(mp[px][py] < mp[qx][qy]){
                        flag = true;
                        break;
                    }
                    else if(mp[qx][qy] < mp[px][py]){
                        flag = false;
                        break;
                    }
                    else{
                        xx = px, yy = py;
                        px += dir[ mark[xx][yy] ][0];
                        py += dir[ mark[xx][yy] ][1];
                        xx = qx, yy = qy;
                        qx += dir[ mark[xx][yy] ][0];
                        qy += dir[ mark[xx][yy] ][1];
                    }
                }
                if(flag) next[x][y] = i;
            }
        }
    }
    mark[x][y] = res;
}
int main(){
    while(~scanf("%d", &n)){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                scanf("%d", &mp[i][j]);
            }
        }
        memset(next, 0xff, sizeof(next));
        memset(mark, 0xff, sizeof(mark));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(mark[i][j] == -1) dfs(i, j);
            }
        }
        int res = -1, rx, ry, px, py, tx, ty, xx, yy;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(mark[i][j] > res){
                    res = mark[i][j];
                    rx = i;
                    ry = j;
                }
                else if(mark[i][j] == res){
                    px = rx, py = ry;
                    tx = i, ty = j;
                    bool flag;
                    for(int k=0;k<res;k++){
                        if(mp[px][py] > mp[tx][ty]){
                            flag = true;
                            break;
                        }
                        else if(mp[px][py] < mp[tx][ty]){
                            flag = false;
                            break;
                        }
                        else{
                            xx = px, yy = py;
                            px = px + dir[ mark[xx][yy] ][0];
                            py = py + dir[ mark[xx][yy] ][1];
                            xx = tx, yy = ty;
                            tx = tx + dir[ mark[xx][yy] ][0];
                            ty = ty + dir[ mark[xx][yy] ][1];
                        }
                    }
                    if(flag){
                        rx = i;
                        ry = j;
                    }
                }
            }
        }
//        printf("%d (%d, %d)\n", res, rx, ry);
        printf("%d\n", res);
        for(int i=0;i<res;i++){
            printf("%d\n", mp[rx][ry]);
            px = rx + dir[ next[rx][ry] ][0];
            py = ry + dir[ next[rx][ry] ][1];
            rx = px;
            ry = py;
        }
    }
    return 0;
}
