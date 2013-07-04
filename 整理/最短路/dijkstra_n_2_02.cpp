/*************************************************************************
    > File Name: dijkstra_n_2_02.cpp
    > Author: tiankonguse
    > Mail: shen10000shen@gmail.com
    > Created Time: 2013/5/7 9:19:13
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

const int N = 100;
const int INF = 0x3ffffff;
int cost[N][N];//两点之间的代价
int path[N];//当前节点的父亲
int lowcost[N];//当前节点到根的代价

//n个节点，st为源点
void dijkstra(int n,int st) {
    int i, j, _min, pre;
    bool vis[N];

    memset(vis,0,sizeof(vis));

    for(i=0; i<n; i++) {
        lowcost[i] = cost[st][i];
        path[i] = st;
    }

    vis[st] = 1;
    lowcost[st] = 0;
    path[st] = -1;//根

    for(i = 0; i < n; i++) {

        _min = INF;
        pre = st;

        for(j=0; j<n; j++) {
            if(vis[j] == 0 && lowcost[j] < _min) {
                _min = lowcost[j];
                pre = j;
            }
        }

        if(pre == st)break;

        vis[pre] = 1;

        for(j=0; j<n; j++) {
            if(lowcost[pre] + cost[pre][j] < lowcost[j]) {
                lowcost[j] = lowcost[pre] + cost[pre][j];
                path[j] = pre;
            }
        }
    }
    return ;
}
int main() {

    return 0;
}
