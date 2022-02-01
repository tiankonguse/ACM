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
#define maxn 10100
using namespace std;
int xpos[maxn], ypos[maxn];
struct point{
    int x, y;
}p[maxn];
int dir[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};
int cal(int n, int x, int y){
    int res = 0;
    for(int i=0;i<n;i++){
        res += abs(x - p[i].x) + abs(y - p[i].y);
    }
    return res;
}
int main(){
    int n;
    int x1, x2, y1, y2;
    int res, cnt;
    while(~scanf("%d", &n)){
        for(int i=0;i<n;i++){
            scanf("%d%d", &p[i].x, &p[i].y);
            xpos[i] = p[i].x;
            ypos[i] = p[i].y;
        }
        sort(xpos, xpos + n);
        sort(ypos, ypos + n);
        if(n % 2 == 1){
            x1 = xpos[n / 2];
            y1 = ypos[n / 2];
            bool flag = false;
            for(int i=0;i<n;i++){
                if(p[i].x == x1 && p[i].y == y1){
                    flag = true;
                    break;
                }
            }
            if(!flag){
                printf("%d 1\n", cal(n, x1, y1));
            }
            else{
                res = inf, cnt = 0;
                int tx, ty, tr;
                for(int i=0;i<4;i++){
                    tx = x1 + dir[i][0];
                    ty = y1 + dir[i][1];
                    tr = cal(n, tx, ty);
                    if(tr == res) cnt++;
                    else if(tr < res){
                        res = tr;
                        cnt = 1;
                    }
                }
                printf("%d %d\n", res, cnt);
            }
        }
        else{
            x1 = xpos[n / 2 - 1];
            x2 = xpos[n / 2];
            y1 = ypos[n / 2 - 1];
            y2 = ypos[n / 2];
            res = cal(n, x1, y1), cnt = (y2 - y1 + 1) * (x2 - x1 + 1);
            for(int i=0;i<n;i++){
                if(p[i].x >= x1 && p[i].x <= x2 && p[i].y >= y1 && p[i].y <= y2) cnt--;
            }
            printf("%d %d\n", res, cnt);
        }


    }
    return 0;
}
