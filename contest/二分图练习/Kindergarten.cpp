/*************************************************************************
    > File Name: Kindergarten.cpp
    > Author: tiankonguse
    > Mail: shen10000shen@gmail.com
    > Created Time: 2013/5/6 15:42:14
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
//男孩为上部，女孩为下部，挑出的点中任意两个点有边。最大团。
//最大团＝补图的最大点独立集
//最大点独立集＋最小点覆盖集＝n(G)
const int N=601;

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
    return n1 + n2 - ans;
}


int main() {
    int k,_x,_y,ca=1;
    while(scanf("%d%d%d",&n1,&n2,&k),n1){
        memset(_map,true,sizeof(_map));
        while(k--){
            scanf("%d%d",&_x,&_y);
            _map[_x-1][_y-1] = false;
        }
        printf("Case %d: %d\n",ca++,mach());

    }
    return 0;
}
