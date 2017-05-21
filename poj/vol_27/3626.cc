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
#define maxn 1010
#define base 502
using namespace std;
bool mp[maxn][maxn];
int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
int lx, ly, rx, ry;
bool check(int x, int y){
    if(x >= lx && x <= rx && y >= ly && y <= ry && !mp[x][y]) return true;
    else return false;
}
struct node{
    int x, y, t;
    node(int _x, int _y, int _t){ x = _x, y = _y, t = _t;}
    node(){}
}tmp;
queue<node>q;
int bfs(int dx, int dy){
    int tx, ty;
    if(dx == base && dy == base) return 0;
    mp[base][base] = true;
    while(!q.empty()) q.pop();
    q.push(node(base, base, 0));
    while(!q.empty()){
        tmp = q.front();
        q.pop();
        for(int i=0;i<4;i++){
            tx = tmp.x + dir[i][0];
            ty = tmp.y + dir[i][1];
            if(check(tx, ty)){
                if(tx == dx && ty == dy) return tmp.t + 1;
                mp[tx][ty] = true;
                q.push(node(tx, ty, tmp.t + 1));
            }
        }
    }
    return -1;
}
int main(){
    int x, y, n, a, b;
    while(~scanf("%d%d%d", &x, &y, &n)){
        x += base, y += base;
        memset(mp, false, sizeof(mp));
        lx = ly = inf, rx = ry = 0;
        for(int i=0;i<n;i++){
            scanf("%d%d", &a, &b);
            a += base, b += base;
            mp[a][b] = true;
            lx = min(lx, a);
            rx = max(rx, a);
            ly = min(ly, b);
            ry = max(ry, b);
        }
        lx--, rx++, ly--, ry++;
        printf("%d\n", bfs(x, y));
    }
    return 0;
}
