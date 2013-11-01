/*************************************************************************
    > File Name: second_MST.cpp
    > Author: tiankonguse
    > Mail: shen10000shen@gmail.com
    > Created Time: 2013/5/19 9:49:04
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

const int inf = 2000000000;
const int N=10005; //point
const int M=100000;//edge

int toV[N], pre[N], head[N], lowc[N];
int len[M], next[M], path[M];
bool vis[N];
int cnt;

void addedge(int u, int v, int  w) {
    toV[cnt] = v;
    len[cnt] = w;
    next[cnt] = head[u];
    head[u] = cnt++;
}
void init() {
    memset(head, -1, sizeof(head));
    cnt=0;
}

void setUsed(int st,int pos){

}
void setPath(int st,int pos,int val){

}
int getPath(int st,int pos){
    return ;
}
int prim(int n, int st) {
    int minc, res = 0, i, j, pos,to;
    memset(vis,0,sizeof(vis));
    memset(path,0,sizeof(path));

    vis[st] = 1;
    for(i=0; i<n; i++) {
        lowc[i] = cost[st][i];
        pre[i] = st;
    }
    lowc[st] = inf;

    for(i = 0; i < n; i++) {
        minc = inf;
        for(j = 0; j < n; j++) {
            if(vis[j] == 0 && minc > lowc[j]) {
                minc = lowc[j];
                pos = j;
            }
        }
        if(inf == minc)return -1;
        setUsed(st,pos);
        res += minc;
        vis[pos] = 1;
        for(j = head[pos]; j != -1; j = next[j]) {
            to = toV[j];
            if(vis[to] == 1){
                setPath(to,pos,max(getPath(to,pre[pos]),lowc[pos]));
            }

            if(vis[to] == 0 && lowc[to] > len[j]) {
                lowc[to] = len[j];
                pre[to] = pos;
            }
        }
    }
    return res;
}


int main() {

    return 0;
}
