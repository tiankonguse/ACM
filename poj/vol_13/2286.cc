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

using namespace std;
int posx[24] = {           0,  0,
                           1,  1,
                       2,2,2,2,2,2,2,
                           3,  3,
                       4,4,4,4,4,4,4,
                           5,  5,
                           6,  6
};
int posy[24] = {           2,  4,
                           2,  4,
                       0,1,2,3,4,5,6,
                           2,  4,
                       0,1,2,3,4,5,6,
                           2,  4,
                           2,  4
};
int mp[8][8];
int pos[8][2] = {       2,2,2,3,2,4,
                        3,2,    3,4,
                        4,2,4,3,4,4
};
bool checkwin(){
    int r = mp[2][2], x, y;
    for(int i=1;i<8;i++){
        x = pos[i][0];
        y = pos[i][1];
        if(r != mp[x][y]) return false;
    }
    return true;
}

int h_cnt[4];
int h(){
    memset(h_cnt,0,sizeof(h_cnt));
    for(int i=0;i<8;i++){
        h_cnt[ mp[ pos[i][0] ][ pos[i][1] ] ] ++;
    }
    return 8 - max( h_cnt[1],max(h_cnt[2],h_cnt[3]) );
}

int pas[8][4] = {
//start,  direction
    0,2,   1, 0, //A
    0,4,   1, 0, //B
    2,6,   0,-1, //C
    4,6,   0,-1, //D
    6,4,  -1, 0, //E
    6,2,  -1, 0, //F
    4,0,   0, 1, //G
    2,0,   0, 1  //H
};
int opp[8] = {5,4,7,6,1,0,3,2};
void go(int id){
    int sx = pas[id][0];
    int sy = pas[id][1];
    int t = mp[sx][sy];
    int tx,ty;
    for(int i=0;i<6;i++){
        tx = sx + pas[id][2];
        ty = sy + pas[id][3];
        mp[sx][sy] = mp[tx][ty];
        sx = tx;
        sy = ty;
    }
    mp[sx][sy] = t;
}
char path[1234];
bool dfs(int limit, int d){
    if(d == limit) return checkwin();
    if(d + h() > limit) return false;
    for(int i=0;i<8;i++){
        go(i);
        path[d] = 'A'+i;
        if(dfs(limit,d+1))return true;
        go(opp[i]);
    }
    return false;
}

int main(){
    int x;
    memset(mp, 0, sizeof(mp));
    while(scanf("%d",&x) && x){
        mp[posx[0]][posy[0]] = x;
        for(int i=1;i<24;i++){
            scanf("%d",&x);
            mp[ posx[i] ][ posy[i] ] = x;
        }
        if(checkwin()){
            printf("No moves needed\n%d\n", mp[2][2]);
        }
        else{
            int deep = 1;
            while(!dfs(deep, 0)){
                deep++;
            }
            for(int i=0;i<deep;i++){
                putchar(path[i]);
            }
            printf("\n%d\n",mp[2][2]);
        }
    }
    return 0;
}
