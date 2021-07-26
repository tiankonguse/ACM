/*************************************************************************
    > File Name:  Word maker.cpp
    > Author: tiankonguse
    > Mail: shen10000shen@gmail.com
    > Created Time: 2013/5/14 21:22:12
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
struct array
{
    int num,a[305];
}s[27];
char str[305];
int ans[27];
int main() {
    int t,i,j,n,m;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        memset(s,0,sizeof(s));
        for(i=1;i<=n;i++)
        {
            for(j=0;j<26;j++)
              ans[j]=0;
            scanf("%s",str);
            int len = strlen(str);
            for(j=0;j<len;j++)
            {
                ans[str[j]-'A']++;
            }
            for(j=0;j<26;j++)
            {
                if(ans[j])
                {
                    s[j].num++;s[j].a[s[j].num-1]=i;
                }
            }
        }

    }
    return 0;
}
