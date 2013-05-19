/*************************************************************************
    > File Name: 魔法串.cpp
    > Author: tiankonguse
    > Mail: shen10000shen@gmail.com
    > Created Time: 2013/5/17 19:09:08
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

char a[1005],b[1005];
int s[30][30];

int main()
{

    int i,j,t,m;
    scanf("%d",&t);
    char s1[2],s2[2];
    int cas=0;
    while(t--)
    {
        scanf("%s%s",a,b);
        scanf("%d",&m);
        int len1 = strlen(a),len2 = strlen(b);
        memset(s,-1,sizeof(s));
        for(i=0;i<m;i++)
        {
            scanf("%s%s",s1,s2);
            s[s1[0]-'a'][s2[0]-'a']=1;
        }

        printf("Case #%d: ",++cas);
        if(isSubString(b,a)||flag)puts("happy");
        else puts("unhappy");
    }
    return 0;
}
