/*************************************************************************
    > File Name: Antenna Placement.cpp
    > Author: tiankonguse
    > Mail: shen10000shen@gmail.com
    > Created Time: 2013/5/6 9:53:14
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<functional>
#include<algorithm>
using namespace std;
const int N=1001;
const char c = 'o';
struct P{
    int x,y;
    void init(int _x,int _y){x=_x,y=_y;}
}top[N];

int x[4]={0,0,1,-1};
int y[4]={1,-1,0,0};
char _str[55][20];
int h,w;

int n1,n2;
//n1,n2 为二分图的顶点集,其中x∈n1,y∈n2
int str[55][20];
bool _map[N][N],vis[N];
int link[N];
//link 记录n2 中的点y 在n1 中所匹配的x 点的编号

int find(int x) {
    int i;
    for(i=0; i<n2; i++) {
        if(_map[x][i]&&!vis[i]) { //x->i 有边,且节点i 未被搜索
            vis[i] = true;//标记节点已被搜索
//如果i 不属于前一个匹配M 或被i 匹配到的节点可以寻找到增广路
            if(link[i]==-1 || find(link[i])) {
                link[i]=x;//更新
                return true;//匹配成功
            }
        }
    }
    return false;
}


int mach() {
    int ans = 0;
    memset(link, -1, sizeof(link));
    for (int i = 0; i < n1; i++) {
        memset(vis,false,sizeof(vis));
        if (find(i))ans++;// 如果从第i个点找到了增光轨，总数加一
    }
//    printf("--%d\n",ans);
    return n1  - ans/2;
}

int main() {
    int cas,i,j,_x,_y;
    scanf("%d",&cas);
//cas = 10;
    while(cas--){
        memset(_str,c,sizeof(_str));
        memset(_map,false,sizeof(_map));

        scanf("%d%d",&h,&w);
        n1 = 0;
        for(i=1;i<=h;i++){
            scanf("%s",_str[i]+1);
            _str[i][w+1] = c;

            for(j=1;j<=w;j++){
                if(_str[i][j] != c){
                        top[str[i][j] = n1++].init(i,j);
                }
            }
        }

        for(i=0;i<n1;i++){
            for(j=0;j<4;j++){
                _x = top[i].x + x[j];
                _y = top[i].y + y[j];
                if(_str[_x][_y] != c){
                    _map[i][str[_x][_y]] = true;
                }
            }
        }
        n2 = n1;


        printf("%d\n",mach());

    }

    return 0;
}
