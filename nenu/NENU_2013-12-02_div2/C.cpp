#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<string>
#include<queue>
#include<map>
#include<cmath>
#include<stack>
#include<algorithm>
#include<functional>
#include<stdarg.h>
using namespace std;
#ifdef __int64
typedef __int64 LL;
#else
typedef long long ll;
#endif

int n,k;
ll d[25][10];
int digit[25];
ll ans=0;
void dfs(int pos,int pro)
{
    //if(pos==-1)return (have&&!res);
    //if(!limit&&d[pos][status][res][have]!=-1)return d[pos][status][res][have];
    if(pos==n)ans++;
    int start;
    if(pos==0)start=1;
    else start=0;
    int end = k-1;
    ll ans=0;
    for(int i=start; i<=end; i++)
    {
    	if(pro==0&&i==0)continue;
        dfs(pos-1,i);
    }
}
ll f()
{
    int len=n;
    ans=0;
    dfs(0,-1);
    return ans;
}
int main()
{
    int i,j,k,n;
    while(scanf("%d%d",&n,&k)!=EOF)
    {
        cout<<f()<<endl;
    }
}
