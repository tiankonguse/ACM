/*************************************************************************
    > File Name: BellmanFord.cpp
    > Author: tiankonguse
    > Mail: shen10000shen@gmail.com
    > Created Time: 2013/5/5 16:20:44
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
typedef int typec;
const int V = 100;
const int E = 10000;
const typec inf=0x3f3f3f3f; // max of cost
//n个定点，m个边
int n, m, pre[V], edge[E][3];
typec dist[V];
int relax (int u, int v, typec c) {
    if (dist[v] > dist[u] + c) {
        dist[v] = dist[u] + c;
        pre[v] = u;
        return 1;
    }
    return 0;
}
int bellman (int src) {
    int i, j;
    for (i=0; i<n; ++i) {
        dist[i] = inf;
        pre[i] = -1;
    }

    dist[src] = 0;
    bool flag;
    for (i=1; i<n; ++i) {
        flag = false; // 优化
        for (j=0; j<m; ++j) {
            if( 1 == relax(edge[j][0], edge[j][1], edge[j][2]) ) flag = true;
        }
        if( !flag ) break;
    }

    for (j=0; j<m; ++j) {
        if (1 == relax(edge[j][0], edge[j][1], edge[j][2]))
            return 0; // 有负圈
    }
    return 1;
}


int main() {

    return 0;
}
