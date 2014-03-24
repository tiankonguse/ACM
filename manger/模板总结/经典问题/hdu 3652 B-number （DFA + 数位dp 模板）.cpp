#include<stdio.h>
#include<string.h>
const int N=40;
int dp[N][10],g[N][10],digit[10];
void initDFA()
{
     for(int i=0;i<13;i++) for(int j=0;j<10;j++)
     {
          g[i][j]=(i*10+j)%13;
          if(j==1) g[i][j]+=13;
     }
     for(int i=13;i<26;i++) for(int j=0;j<10;j++)
     {
          g[i][j]=(i*10+j)%13;
          if(j==1) g[i][j]+=13;
          if(j==3) g[i][j]+=26;
     }
     for(int i=26;i<39;i++) for(int j=0;j<10;j++)
          g[i][j]=(i*10+j)%13+26;
}
int dfs(int pos,int pre,int doing)
{
    if(pos==-1) return pre==26;
    if(!doing&&dp[pre][pos]!=-1) return dp[pre][pos];
    int end=doing?digit[pos]:9;
    int ans=0;
    for(int i=0;i<=end;i++)
    {
        ans+=dfs(pos-1,g[pre][i],doing&&i==end);
    }
    if(!doing) dp[pre][pos]=ans;
    return ans;
}
int cal(int x)
{
    int pos=0;
    while(x) digit[pos++]=x%10,x/=10;
    return dfs(pos-1,0,1);
}
int main()
{
   
    memset(dp,-1,sizeof(dp));
    initDFA();
    int n;
    while(scanf("%d",&n)==1)
          printf("%d\n",cal(n));
}
