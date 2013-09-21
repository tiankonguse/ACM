/*************************************************************************
    > File Name: C Serial Numbers002.cpp
    > Author: tiankonguse
    > Mail: shen10000shen@gmail.com
    > Created Time: 2013/5/16 20:59:18
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<functional>
#include<algorithm>
using namespace std;
const int maxn = 100005;
int vis[maxn],ans[maxn];
struct array
{
    int num,times;
}s[maxn];
int main()
{
    int t,i,j,n,m,tmp,d;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(i=0;i<m;i++)
          vis[i]=0;
        int k=0;
        for(i=1;i<=n;i++)
        {
            scanf("%d",&tmp);
            int g=0;
            int kk = k;
            for(j=0;j<kk;j++)
            {
                d = (ans[j]+tmp)%m;
                if(vis[d]==0)ans[k++]=d;
                if(vis[d]<vis[ans[j]]+1)
                {
                    s[g].num=d;s[g++].times=vis[ans[j]]+1;
                }
            }
            d = tmp%m;
            if(vis[d]==0)ans[k++]=d;
            if(vis[d]<1)
            {
                s[g].num=d;s[g++].times=1;
            }
            for(j=0;j<g;j++)
            {
                if(vis[s[j].num]<s[j].times)
                  vis[s[j].num]=s[j].times;
            }
        }
        printf("%d\n",vis[0]);
    }
    return 0;
}
