#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<sstream>
#include<string.h>
#include<vector>
#include<map>
#define MAXN 215
#define min(a,b) (a<b?a:b)
#define inf 0x3f3f3f3f
using namespace std;
int N,M;
vector<int>tree[MAXN];
map<string,int>mp;
int cost[MAXN];
bool nroof[MAXN];
int dp[MAXN][MAXN];
char str[2000];
int dfs(int u){
    int cnt=1,sz=tree[u].size();
    for(int i=0;i<sz;i++){
        cnt+=dfs(tree[u][i]);
    }
    dp[u][0]=0;
    for(int i=0;i<sz;i++){
        for(int j=N;j>=0;j--){
            for(int k=1;j-k>=0;k++){
                dp[u][j]=min(dp[u][j],dp[tree[u][i]][k]+dp[u][j-k]);
            }
        }
    }
    if(cost[u]<dp[u][cnt])dp[u][cnt]=cost[u];
    return cnt;
}
int main(){
    int c,a,id;
    string name;
    while(gets(str)){
        if(str[0]=='#')break;
        sscanf(str,"%d%d",&N,&M);
        id=1;
        for(int i=0;i<=N;i++)tree[i].clear();
        mp.clear();
        memset(nroof,false,sizeof(nroof));
        for(int i=0;i<N;i++){
            gets(str);
            stringstream ss(str);
            ss>>name>>c;
            if(mp.find(name)==mp.end())mp[name]=id++;
            a=mp[name];
            cost[a]=c;
            while(ss>>name){
                if(mp.find(name)==mp.end())mp[name]=id++;
                tree[a].push_back(mp[name]);
                nroof[mp[name]]=true;
            }
        }
        cost[0]=inf;
        for(int i=1;i<id;i++){
            if(!nroof[i])tree[0].push_back(i);
        }
        memset(dp,0x3f,sizeof(dp));
        dfs(0);
        int ans=inf;
        for(int i=M;i<=N;i++){
            if(dp[0][i]<ans)ans=dp[0][i];
        }
        printf("%d\n",ans);
    }
    return 0;
}
