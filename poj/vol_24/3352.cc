#include"iostream"
#include"cstdlib"
#include"vector"
#define min(a,b) (a<b?a:b)
#define MAXN 1005
using namespace std;
vector<int> map[MAXN];
int dfn[MAXN],low[MAXN],color[MAXN],degree[MAXN];
int cnt,N;
void dfs(int u,int p){
   int v,len=map[u].size();
   dfn[u]=low[u]=cnt++;
   for(int i=0;i<len;i++){
       v=map[u][i];
       if(!dfn[v]){
           dfs(v,u);
           low[u]=min(low[u],low[v]);
       }
       else if(p!=v){
           low[u]=min(low[u],dfn[v]);
       }
   }
}
void setcolor(int u){
    int v,len=map[u].size();
    for(int i=0;i<len;i++){
        v=map[u][i];
        if(!color[v]){
           if(low[v]>dfn[u])color[v]=cnt++;
           else color[v]=color[u];
           setcolor(v);
        }
    }
}
int main(){
    int r,a,b,l;
    scanf("%d%d",&N,&r);
    for(int i=0;i<r;i++){
        scanf("%d%d",&a,&b);
        map[a-1].push_back(b-1);
        map[b-1].push_back(a-1);
    }
    cnt=1;
    dfs(0,-1);
    cnt=2;
    color[0]=1;
    setcolor(0);
    for(int i=0;i<N;i++){
        l=map[i].size();
        for(int j=0;j<l;j++){
           if(color[i]!=color[map[i][j]])degree[color[i]]++;
        }
    }
    int res=0;
    for(int i=0;i<cnt;i++){
       if(degree[i]==1)res++;
    }
    printf("%d\n",(res+1)/2);
  //  system("pause");
    return 0;
}
