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
#define maxn 305
#define maxm 50050
using namespace std;
int n;
int mp[maxn][maxn];
int dir[4][2] = {0, 1, 0, -1, -1, 0, 1, 0};
bool check(int x, int y){
    return x >= 0 && y >= 0;
}
struct node{
    int x, y, t;
    node(int _x, int _y, int _t){ x = _x, y = _y, t = _t;}
    node(){}
}tmp;
queue<node> q;
int mark[maxn][maxn];
int bfs(){
    if(mp[0][0] == 0) return -1;
    else if(mp[0][0] == inf) return 0;
    int tx, ty;
    while(!q.empty()) q.pop();
    memset(mark, 0x3f, sizeof(mark));
    mark[0][0] = 0;
    q.push(node(0, 0, 0));
    while(!q.empty()){
        tmp = q.front();
        q.pop();
        for(int i=0;i<4;i++){
            tx = tmp.x + dir[i][0];
            ty = tmp.y + dir[i][1];
            if(check(tx, ty) && tmp.t + 1 < mark[tx][ty] && tmp.t + 1 < mp[tx][ty]){
                if(mp[tx][ty] == inf) return tmp.t + 1;
                mark[tx][ty] = tmp.t + 1;
                q.push(node(tx, ty, tmp.t + 1));
            }
        }
    }
    return -1;
}
int main(){
    int x, y, t, tx, ty;
    while(~scanf("%d", &n)){
        memset(mp, 0x3f, sizeof(mp));
        for(int i=0;i<n;i++){
            scanf("%d%d%d", &x, &y, &t);
            mp[x][y] = min(mp[x][y], t);
            for(int j=0;j<4;j++){
                tx = x + dir[j][0];
                ty = y + dir[j][1];
                if(check(tx, ty)) mp[tx][ty] = min(mp[tx][ty], t);
            }
        }
        printf("%d\n", bfs());
    }
    return 0;
}
