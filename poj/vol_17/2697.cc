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
using namespace std;
char mp[5][5], des[5][5];
struct node{
    char mp[5][5];
    int t, s;
    node(int _t, int _s) { t = _t, s = _s;}
    node(){}
    friend bool operator<(node a, node b){
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                if(a.mp[i][j] != b.mp[i][j]) return a.mp[i][j] < b.mp[i][j];
            }
        }
        return false;
    }
}tmp, cur;
queue<node> q;
set<node> st;
int dir[8][2] = {-1,-1, -1,0, -1,1, 0,1, 1,1, 1,0, 1,-1, 0,-1};
inline bool check(int x, int y){
    return x >= 0 && x < 4 && y >= 0 && y < 4;
}
int bfs(){
    while(!q.empty()) q.pop();
    memcpy(tmp.mp, mp, sizeof(mp));
    tmp.t = tmp.s = 0;
    st.clear();
    st.insert(tmp);
    q.push(tmp);
    int tx, ty, x, y;
    while(!q.empty()){
        tmp = q.front(); q.pop();
        bool flag = true;
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                if(tmp.mp[i][j] != des[i][j]){
                    flag = false;
                    break;
                }
            }
            if(!flag) break;
        }
        if(flag) return tmp.t;
        if(tmp.s == 0){
            for(int i=0;i<4;i++){
                for(int j=0;j<4;j++){
                    if(tmp.mp[i][j] == 'w'){
                        for(int d=0;d<8;d++){
                            tx = i + dir[d][0];
                            ty = j + dir[d][1];
                            while(check(tx, ty) && tmp.mp[tx][ty] == '*'){
                                memcpy(cur.mp, tmp.mp, sizeof(tmp.mp));
                                cur.mp[i][j] = '*';
                                cur.mp[tx][ty] = 'w';
                                cur.s = 1;
                                cur.t = tmp.t + 1;
                                if(st.find(cur) == st.end()){
                                    st.insert(cur);
                                    q.push(cur);
                                }
                                tx += dir[d][0];
                                ty += dir[d][1];
                            }
                        }
                    }
                }
            }
        }
        else{
            for(int i=0;i<4;i++){
                for(int j=0;j<4;j++){
                    if(tmp.mp[i][j] == 'b'){
                        for(int d=0;d<8;d++){
                            tx = i + dir[d][0];
                            ty = j + dir[d][1];
                            while(check(tx, ty) && tmp.mp[tx][ty] == '*'){
                                memcpy(cur.mp, tmp.mp, sizeof(tmp.mp));
                                cur.mp[i][j] = '*';
                                cur.mp[tx][ty] = 'b';
                                cur.s = 0;
                                cur.t = tmp.t + 1;
                                if(st.find(cur) == st.end()){
                                    st.insert(cur);
                                    q.push(cur);
                                }
                                tx += dir[d][0];
                                ty += dir[d][1];
                            }
                        }
                    }
                }
            }
        }
    }
    return -1;
}
int main(){
    int t;
    for(scanf("%d", &t);t--;){
        for(int i=0;i<4;i++) scanf(" %s", mp[i]);
        for(int i=0;i<4;i++) scanf(" %s", des[i]);
        printf("%d\n",bfs());
    }
    return 0;
}
