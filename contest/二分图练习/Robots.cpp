/*************************************************************************
    > File Name: Robots.cpp
    > Author: tiankonguse
    > Mail: shen10000shen@gmail.com
    > Created Time: 2013/5/6 19:01:33
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
//赤裸裸的求最小路径覆盖
struct Point{
    int x,y;
    void init(int _x,int _y){x=_x,y=_y;}
    bool operator<=(Point& right){
        return x<=right.x && y<=right.y;
    }
}point[1000];

const int N=601;

//行为上部，列为下部，挑最少的点，使得所有的边和挑的点相连。最小顶点覆盖。

int n1,n2;
//n1,n2 为二分图的顶点集,其中x∈n1,y∈n2
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
    return n1 - ans;
}


bool less(int a, int b){
    return point[a].x<=point[b].x && point[a].x<=point[b].x;
}

int main() {
    int _x, _y, n, i, j;

    while(scanf("%d%d",&_x,&_y),_x!=-1&&_y!=-1){
        n = 0;
        point[n++].init(_x,_y);
        while(scanf("%d%d",&_x,&_y),_x!=0&&_y!=0){
            point[n++].init(_x,_y);
        }
        memset(_map,false,sizeof(_map));
        n1 = n2 = n;
        for(i=0;i<n1;i++){
            for(j=i+1;j<n2;j++){
                if(point[i] <= point[j]){
                    _map[i][j] = true;
                }
            }
        }
        printf("%d\n",mach());

    }


    return 0;
}
