/*************************************************************************
    > File Name: prim_MST.cpp
    > Author: tiankonguse
    > Mail: shen10000shen@gmail.com
    > Created Time: 2013/5/7 18:24:14
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
const int inf = 0x3fffffff;
int vis[N], lowc[N];

int prim(int cost[][N], int n,int st){
    int minc, res = 0, i, j, pos;
    memset(vis,0,sizeof(vis));
    vis[st] = 1;
    for(i=0;i<n;i++){
        lowc[i] = cost[st][i];
    }
    lowc[st] = inf;

    for(i = 0; i < n; i++){
        minc = inf;
        for(j = 0; j < n; j++){
            if(vis[j] == 0 && minc > lowc[j]){
                minc = lowc[j];
                pos = j;
            }
        }
        if(inf == minc)return -1;
        res += minc;
        vis[pos] = 1;
        for(j = 0; j < n; j++){
            if(vis[j] == 0 && lowc[j] > cost[pos][j]){
                lowc[j] = cost[pos][j];
            }
        }
    }
    return res;

}

int main() {

    return 0;
}
