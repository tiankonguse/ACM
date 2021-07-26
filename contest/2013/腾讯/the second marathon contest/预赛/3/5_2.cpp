#include<cstdio>
#include<cstring>
#include<vector>
#include<iostream>
using namespace std;
#define MAX 1012
vector<int>g[MAX];/*用向量表示边*/
int path[MAX];
bool vis[MAX];
int num;
int str[MAX][MAX];
int mapx[9]={-2, -1, -1,  0, 0,  1, 1, 2};
int mapy[9]={ 0, -1,  1, -2, 2, -1, 1, 0};


bool dfs(int u) {
    for(int i=0; i<g[u].size(); ++i) {
        int v=g[u][i];
        if(!vis[v]) {
            vis[v]=true;
            if(path[v]==-1|| dfs(path[v])) {
                //path[i] == -1 保证了第一条边和最后一条边为未匹配边
                //dfs(path[i])实现了交替路径;
                path[v]=u;
                return true;
            }
        }
    }
    return false;
}
int Hungary() {
    int ans=0;
    memset(path,-1,sizeof(path));
    for(int i=0; i<num; ++i) {
        memset(vis,false,sizeof(vis));
        if(dfs(i))ans++;
    }
    return (num-ans/2);
}

int main() {
    int i,j,x,y, n,m,k;
    while (scanf("%d%d",&n,&m)!=EOF) {

        num = 0;
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                scanf("%d",&str[i][j]);
                if(str[i][j]){
                    str[i][j]= ++num;
                }
            }
        }

        for(i=0; i<num; i++){
            g[i].clear();
        }

        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                printf("%d ",str[i][j]);
                if(str[i][j]){
                    for(k=0;k<8;k++){
                        if(i+mapx[k]>=0 && i+mapx[k]<n && j+mapy[k]>=0 && j+mapy[k]<m && str[i+mapx[k]][j+mapy[k]]){
                            g[str[i][j]-1].push_back(str[i+mapx[k]][j+mapy[k]]-1);
                        }
                    }
                }
            }
            printf("\n");
        }

        printf("%d\n",Hungary());
    }
    return 0;
}
