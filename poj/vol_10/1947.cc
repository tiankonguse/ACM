#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<vector>
#define MAXN 155
#define inf 0x7f7f7f7f
#define min(a,b) (a<b?a:b)
using namespace std;
int N,P;
vector<int>tree[MAXN];
int dp[MAXN][MAXN];
bool nroof[MAXN];
void init(){
    memset(nroof,false,sizeof(nroof));
    for(int i=0;i<N;i++)tree[i].clear();
}
void dfs(int u){
    int sz=tree[u].size();
    for(int i=0;i<sz;i++)dfs(tree[u][i]);

   // cout<<u<<endl;system("pause");

    for(int i=0;i<sz;i++){
        for(int j=P;j>1;j--){
            for(int k=1;k<j;k++){
                dp[u][j]=min(dp[u][j],dp[tree[u][i]][k]+dp[u][j-k]-2);
             //   printf("dp[%d][%d]=min(dp[%d][%d],dp[%d][%d]+dp[%d][%d])=%d\n",
            //           u,j,u,j,tree[u][i],k,u,j-k,dp[u][j]);
            }
        }
    }
}
int main(){
    int a,b,s;
    while(~scanf("%d%d",&N,&P)){
        for(int i=0;i<N-1;i++){
            scanf("%d%d",&a,&b);
            a--,b--;
            tree[a].push_back(b);
            nroof[b]=true;
        }
        memset(dp,0x3f,sizeof(dp));
        for(int i=0;i<N;i++){
            dp[i][1]=tree[i].size()+1;
            if(!nroof[i])s=i;
        }
        dp[s][1]--;
      //  for(int i=0;i<N;i++)printf("%d ",dp[i][1]);printf("\n");system("pause");
        dfs(s);
        int idx=0;
      //  for(int i=0;i<N;i++)printf("dp[%d][%d]=%d\n",i,P,dp[i][P]);
        for(int i=1;i<N;i++){
            if(dp[i][P]<dp[idx][P])idx=i;
        }
        printf("%d\n",dp[idx][P]);
    }
    return 0;
}
