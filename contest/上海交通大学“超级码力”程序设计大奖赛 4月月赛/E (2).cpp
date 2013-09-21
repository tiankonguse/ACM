/*************************************************************************
    > File Name: E003.cpp
    > Author: tiankonguse
    > Mail: shen10000shen@gmail.com
    > Created Time: 2013/5/14 22:51:56
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<set>
#include<queue>
#include<stack>
#include<functional>
#include<algorithm>
using namespace std;

const int N=1005;

bool top[N][27];

char bottom[1005];

//行为上部，列为下部，挑最少的点，使得所有的边和挑的点相连。最小顶点覆盖。

int n1,n2;
//n1,n2 为二分图的顶点集,其中x∈n1,y∈n2
bool _map[N][N],vis[N];
int _link[N];
//_link 记录n2 中的点y 在n1 中所匹配的x 点的编号

int find(int x) {
    int i;
    for(i=0; i<n2; i++) {
        if(_map[x][i]&&!vis[i]) { //x->i 有边,且节点i 未被搜索
            vis[i] = true;//标记节点已被搜索
//如果i 不属于前一个匹配M 或被i 匹配到的节点可以寻找到增广路
            if(_link[i]==-1 || find(_link[i])) {
                _link[i]=x;//更新
                return true;//匹配成功
            }
        }
    }
    return false;
}

int mach() {
    int ans = 0;
    memset(_link, -1, sizeof(_link));
    for (int i = 0; i < n1; i++) {
        memset(vis,false,sizeof(vis));
        if (find(i))ans++;// 如果从第i个点找到了增光轨，总数加一
    }
    return ans;
}

int main() {
    int n,cas,m,j,i,ans;
    char tmp[1005];
    scanf("%d",&cas);
    while(cas--){
        scanf("%d%d",&n,&m);
        n1 = n;
        memset(top,false,sizeof(top));
        for(i = 0; i < n; i++) {
            scanf("%s", tmp);
            for(j = 0; tmp[j]; j++)
                top[i][tmp[j]-'A'] = true;
        }

        ans = 0;
        while(m--){
            memset(_map,false,sizeof(_map));
            scanf("%s", tmp);
            for(i = 0; i < n; i++){
                for(j = 0; tmp[j]; j++){
                    if(top[i][tmp[j]-'A']){
                        _map[i][j] = true;
                    }
                }
            }
            n2 = j;
            if(mach() == n2){
                ans++;
            }
        }
        printf("%d\n",ans);

    }
    return 0;
}
