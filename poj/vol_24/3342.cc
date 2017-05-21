#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#define MAXN 205
#define max(a,b) (a>b?a:b)
using namespace std;
map<string,int>mp;
vector<int> tree[MAXN];
string s[MAXN][2];
int dp[MAXN][2];
bool flag[MAXN];
bool ff;
void dfs(int u){
    int size=tree[u].size();
    for(int i=0;i<size;i++)dfs(tree[u][i]);
    int s1=0,s2=0;
    bool ft=false;
    for(int i=0;i<size;i++){
        ft |= flag[tree[u][i]];
        s1+=dp[tree[u][i]][0]; //1
        s2+=max(dp[tree[u][i]][0],dp[tree[u][i]][1]); //0
    }
    dp[u][0]=s2;
    dp[u][1]=s1+1;
   // cout<<u<<":"<<dp[u][0]<<","<<dp[u][1]<<"::"<<ft<<endl;
    if(dp[u][0]>=dp[u][1] && ft)ff=true;
    if(dp[u][0]==dp[u][1])flag[u]=true;
}
int main(){
    int N,cnt;
    while(cin>>N&&N){
        mp.clear();
        for(int i=0;i<N;i++)tree[i].clear();
        cin>>s[0][0]; mp[s[0][0]]=0;
        for(int i=1;i<N;i++){
            cin>>s[i][0]>>s[i][1];
            mp[s[i][0]]=i;
        }
        for(int i=1;i<N;i++){
            tree[mp[s[i][1]]].push_back(mp[s[i][0]]);
        }
        ff=false;
        memset(flag,false,sizeof(flag));
        memset(dp,0,sizeof(dp));
        dfs(0);
        printf("%d ",max(dp[0][0],dp[0][1]));
        if(ff || dp[0][0]==dp[0][1])printf("No\n");
        else printf("Yes\n");
    }
    return 0;
}
