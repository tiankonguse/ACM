/*************************************************************************
    > File Name: kruskal_MST.cpp
    > Author: tiankonguse
    > Mail: shen10000shen@gmail.com
    > Created Time: 2013/5/7 17:37:52
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

const int N=1000;
const int E = N*N/2;

struct Edge{
    int from,to,val;
    bool operator<=(const Edge& e)const{
        return val <= e.val;
    }
    bool operator<(const Edge& e)const {
        return val < e.val;
    }

}edge[E];
int pre[N],rank[N];

void init(int n){
    for(int i=0;i<n;i++){
        pre[i] = i, rank[i] = 0;
    }
}

int find_pre(int node){
    if(pre[node] != node){
        pre[node] = find_pre(pre[node]);
    }
    return pre[node];
}

void merge_pre(int from, int to){
    from = find_pre(from);
    to = find_pre(to);

    if(from != to){
        if(rank[from] > rank[to]){
            pre[to] = from;
        }else{
            pre[from] = to;
            if(rank[from] == rank[to]){
                ++rank[to];
            }
        }
    }

}

int kruskal(int n,int m){
    sort(edge, edge + m);
    init(n);
    int find_edge = 0, i, pre_from, pre_to;
    int w = 0;

    for(i = 0; i < m; i++){
        pre_from = find_pre(edge[i].from);
        pre_to = find_pre(edge[i].to);
        if(pre_from == pre_to){
            continue;
        }
        merge_pre(pre_from, pre_to);

        w += edge[i].val;
        find_edge++;

        if(find_edge+1 == n)break;

    }
    return w;
}

int main() {

    return 0;
}
