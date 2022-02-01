#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<vector>
#define MAXN 1505
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
using namespace std;
int N;
vector<int>tree[MAXN];
bool nr[MAXN];
int dp[MAXN][MAXN];

void dfs(int u){
    int sz=tree[u].size();
    for(int i=0;i<sz;i++)dfs(tree[u][i]);
    int a0=0,a1=0;
    for(int i=0;i<sz;i++){
        a0+=dp[tree[u][i]][1];
        a1+=min(dp[tree[u][i]][0],dp[tree[u][i]][1]);
    }
    dp[u][0]=a0;
    dp[u][1]=a1+1;
}
int main(){
    int a,b,k;
    while(~scanf("%d",&N)){
        for(int i=0;i<N;i++)tree[i].clear();
        memset(nr,false,sizeof(nr));
        for(int i=0;i<N;i++){
            scanf("%d:(%d)",&a,&k);
            for(int j=0;j<k;j++){
                scanf(" %d",&b);
                tree[a].push_back(b);
                nr[b]=true;
            }
        }
        for(int i=0;i<N;i++){
            if(!nr[i]){
                dfs(i);
                printf("%d\n",min(dp[i][0],dp[i][1]));
                break;
            }
        }
    }
    return 0;
}
