/*************************************************************************
    > File Name: A New Tetris Game.cpp
    > Author: tiankonguse
    > Mail: shen10000shen@gmail.com
    > Created Time: 2013/5/15 22:22:26
    > http://acm.hdu.edu.cn/showproblem.php?pid=1760
 ************************************************************************/

#include<cstdio>
#include<cstring>
using namespace std;
const int N = 55;
char g[N][N];
int n,m;
const char yes_c = '0';
const char no_c = '1';


//判断当前位置是否可放
bool _set(int i,int j) {
    if(g[i][j] == yes_c && g[i+1][j] == yes_c && g[i][j+1] == yes_c && g[i+1][j+1] == yes_c) {
        g[i][j] = g[i][j+1] = g[i+1][j] = g[i+1][j+1] = no_c;
        return true;
    }
    return false;
}
//清除当前状态的标记，恢复到初始状态
void _unset(int i,int j) {
    g[i][j] = g[i+1][j] = g[i][j+1] = g[i+1][j+1] = yes_c;
}

bool dfs() {
    int i,j;
    for(i=1; i<n; i++) {
        for(j=1; j<m; j++) {
            if(_set(i,j)) {
                if(!dfs()) {
                    _unset(i,j);
                    return true;//此位置放的话会导致一个必败态，故此状态必胜
                }
                _unset(i,j);
            }
        }
    }
    return false;//没有找到必败态或无路可走了，故此状态必败
}
int main() {
    while(scanf("%d%d",&n,&m)!=EOF) {
        for(int i=1; i<=n; i++) {
            scanf("%s",g[i]+1);
        }
        puts(dfs()?"Yes":"No");
    }
    return 0;
}
