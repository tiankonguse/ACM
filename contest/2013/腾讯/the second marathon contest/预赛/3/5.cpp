/********************************************************************
 ** @file    poj1466.cpp
 ** @author  liuke
 ** @date    Sat Apr 30 21:44:00 2011
 ** @brief  题目大意：在Ｎ个点的图G中选出m个点，使这m个点两两之间没有边．求m最大值．
[问题]二分图的最大匹配 , 最大独立数=顶点数-匹配数的一半
[定义]　给定一个二分图G，M为G边集的一个子集，如果M满足当中的任意两条边都不依附于同一个顶点，
则称M是一个匹配。
　　极大匹配(Maximal Matching)是指在当前已完成的匹配下,无法再通过增加未完成匹配的边的方式
来增加匹配的边数。最大匹配(maximum matching)是所有极大匹配当中边数最大的一个匹配。
选择这样的边数最大的子集称为图的最大匹配问题。
　　如果一个匹配中，图中的每个顶点都和图中某条边相关联，则称此匹配为完全匹配，也称作完备匹配
二分图最大匹配的经典匈牙利算法是由Edmonds在1965年提出的，
算法的核心就是根据一个初始匹配不停的找增广路，直到没有增广路为止。
匈牙利算法的本质实际上和基于增广路特性的最大流算法还是相似的，只需要注意两点：
（一）每个X节点都最多做一次增广路的起点；
（二）如果一个Y节点已经匹配了，那么增广路到这儿的时候唯一的路径是走到Y节点的匹配点
（可以回忆最大流算法中的后向边，这个时候后向边是可以增流的）。
 找增广路的时候既可以采用dfs也可以采用bfs，两者都可以保证O(nm)的复杂度，
因为每找一条增广路的复杂度是O(m)，而最多增广n次，dfs在实际实现中更加简短。
 **@version Copyright (c) 2011,河南理工大学-信管08-三班.
 ********************************************************************/
#include<cstdio>
#include<cstring>
#include<vector>
#include<iostream>
using namespace std;
#define MAX 502
vector<int>g[MAX];/*用向量表示边*/
int path[MAX];
bool vis[MAX];
int n;
bool dfs(int u) {
  for(int i=0;i<g[u].size();++i){
    int v=g[u][i];
    if(!vis[v]){
      vis[v]=true;
      if(path[v]==-1|| dfs(path[v])){
        //path[i] == -1 保证了第一条边和最后一条边为未匹配边
            //dfs(path[i])实现了交替路径;
        path[v]=u;return true;
      }
    }
  }
  return false;
}
int Hungary(){
  int ans=0;
  memset(path,-1,sizeof(path));
  for(int i=0;i<n;++i){
    memset(vis,false,sizeof(vis));
    if(dfs(i))ans++;
  }
  return (n-ans/2);
}
int main(int argc, char *argv[])
{
  while (scanf("%d",&n)!=EOF)
    {
      for(int i=0; i<n; i++)
        {
          g[i].clear();
          int x;int a;
          char c, cc;
          scanf("%d%c",&x,&c);
          scanf("  %c%d%c",&c,&x,&cc);
          for(int j=0; j<x; j++){
            scanf("%d",&a);
            g[i].push_back(a);
          }
        }
      printf("%d/n",Hungary());
    }
  return 0;
}
