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
#define maxn 9
#define maxm 5000000
using namespace std;
char mp[maxn][maxn];
int n, sx, sy;
struct node{
    int x, y, t;
    char mark[9][9];
    node(int _x, int _y, int _t) { x = _x, y = _y, t = _t;}
    node(){}
    bool operator <(const node &b) const{
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(mark[i][j] != b.mark[i][j]){
                    return mark[i][j] < b.mark[i][j];
                }
            }
        }
        if(x == b.x) return y < b.y;
        else return x < b.x;
    }
}q[maxm], tmp;
set<node> st;

int dir[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};
inline bool check(int x, int y){
    return x >= 0 && x < n && y >= 0 && y < n;
}

int cnt;
int bfs(){
    if(mp[sx - 1][sy - 1] == 'E') return 0;
    int l = 0, h = 0;
    st.clear();
    tmp = node(sx - 1, sy - 1, 0);
    memcpy(tmp.mark, mp, sizeof(mp));
    st.insert(tmp);
    q[h++] = tmp;
    int x, y, tx, ty;
    while(l < h){
        tmp = q[l++];
        x = tmp.x, y = tmp.y;
        tmp.t++;
//        for(int i=0;i<n;i++){
//            for(int j=0;j<n;j++){
//                if(i==x&&j==y)putchar('o');
//                else printf("%c", tmp.mark[i][j]);
//            }
//            puts("");
//        }
//        cout<<x<<","<<y<<endl; system("pause");
        //move
        for(int i=0;i<4;i++){
            tx = x + dir[i][0];
            ty = y + dir[i][1];
            if(check(tx, ty) && tmp.mark[tx][ty] != '.'){
                if(mp[tx][ty] == 'E') return tmp.t;
                tmp.x = tx, tmp.y = ty;
                if(st.find(tmp) == st.end()){
                    st.insert(tmp);
                    q[h++] = tmp;
                }
            }
        }
        //topple
        if( !(tmp.mark[x][y] >= '2' && tmp.mark[x][y] <= '4') ) continue;
        int d = mp[x][y] - '0';
        bool flag;
        for(int i=0;i<4;i++){
            tx = x, ty = y;
            //check
            flag = true;
            for(int j=1;j<=d;j++){
                tx += dir[i][0];
                ty += dir[i][1];
                if(!check(tx, ty) || tmp.mark[tx][ty] != '.'){
                    flag = false;
                    break;
                }
            }
            if(!flag) continue;
            tx = x, ty = y;
            tmp.mark[x][y] = '.';
            for(int j=1;j<=d;j++){
                tx += dir[i][0];
                ty += dir[i][1];
                tmp.mark[tx][ty] = '1';
            }
            tmp.x = x + dir[i][0];
            tmp.y = y + dir[i][1];
            if(st.find(tmp) == st.end()){
                st.insert(tmp);
                q[h++] = tmp;
            }
            tx = x, ty = y;
            for(int j=1;j<=d;j++){
                tx += dir[i][0];
                ty += dir[i][1];
                tmp.mark[tx][ty] = '.';
            }
        }
    }
    return -1;
}
int main(){
    while(~scanf("%d%d%d", &n, &sx, &sy)){
        if(n == 0) break;
        for(int i=0;i<n;i++){
            scanf(" %s", mp[i]);
        }
        int res = bfs();
        if(res == -1) puts("Impossible.");
        else printf("%d\n", res);
    }
    return 0;
}
