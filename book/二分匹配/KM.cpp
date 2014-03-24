#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <numeric>
#include <functional>
using namespace std;
typedef long long ll;
#define inf (int)1e10
#define maxn 150
int edge[maxn][maxn];//邻接矩阵
int du[maxn],dv[maxn];//可行顶标
int head[maxn];//匹配节点的父节点
bool visu[maxn],visv[maxn];//判断是否在交错树上
int uN;//匹配点的个数
int slack[maxn];//松弛数组
bool dfs(int u) {
    visu[u]=true;
    for(int v=0; v<uN; v++)
        if(!visv[v]) {
            int t=du[u]+dv[v]-edge[u][v];
            if(t==0) {
                visv[v]=true;
                if(head[v]==-1||dfs(head[v])) {
                    head[v]=u;
                    return true;
                }
            } else slack[v]=min(slack[v],t);
        }
    return false;
}
int KM() {
    memset(head,-1,sizeof(head));
    memset(du,0,sizeof(du));
    memset(dv,0,sizeof(dv));
    for(int u=0; u<uN; u++)
        for(int v=0; v<uN; v++)
            du[u]=max(du[u],edge[u][v]);
    for(int u=0; u<uN; u++) {
        for(int i=0; i<uN; i++)slack[i]=inf;
        while(true) {
            memset(visu,0,sizeof(visu));
            memset(visv,0,sizeof(visv));
            if(dfs(u))break;
            int ex=inf;
            for(int v=0; v<uN; v++)if(!visv[v])
                    ex=min(ex,slack[v]);
            for(int i=0; i<uN; i++) {
                if(visu[i])du[i]-=ex;
                if(visv[i])dv[i]+=ex;
                else slack[i]-=ex;

            }
        }
    }
    int ans=0;
    for(int u=0; u<uN; u++)
        ans+=edge[head[u]][u];
    return ans;
}
int main() {
    //read;
    while(~scanf("%d",&uN)) {
        int sum=0;
        for(int i=0; i<uN; i++)
            for(int j=0; j<uN; j++) {
                scanf("%d",&edge[i][j]);
                sum+=edge[i][j];
            }
        printf("%d\n",sum-KM());
    }
    return 0;
}
