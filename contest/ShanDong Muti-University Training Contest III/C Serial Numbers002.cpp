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
int main() {
    int t,i,j,n,m,num;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(i=0;i<m;i++)
          vis[i]=0;
        int k=0;
        for(i=1;i<=n;i++)
        {
            scanf("%d",&num);
            if(i==1)
            {
                num%=m;
                vis[num]=1;
                ans[k++]=num;
                for(j=0;j<m;j++)
            cout<<j<<"**"<<vis[j]<<endl;
            cout<<endl;
                continue;
            }
            for(j=k-1;j>=0;j--)
            {
                int d = (ans[j]+num)%m;
                if(vis[d]==0)ans[k++]=d;

                if(vis[d]<vis[ans[j]]+1)
                {
                    vis[d]=vis[ans[j]]+1;
                }
            }
            num %= m;
            if(vis[num]==0)ans[k++]=num;
            vis[num]++;
            for(j=0;j<m;j++)
            cout<<j<<"**"<<vis[j]<<endl;
            cout<<endl;
           // for(j=0;j<k;j++)
            //cout<<j<<"*&^^%%"<<ans[j]<<endl;
            //cout<<endl;
        }
        cout<<vis[0]<<endl;
    }
    return 0;
}
