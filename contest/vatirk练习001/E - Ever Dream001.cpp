/*************************************************************************
    > File Name: E - Ever Dream001.cpp
    > Author: tiankonguse
    > Mail: shen10000shen@gmail.com
    > Created Time: 2013/5/10 19:47:18
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
    char str[105];
    int num,len;
}s[5100];
char a[105],b[105];
int ans=0;
int main() {
        int t,n,i,j;
        scanf("%d",&t);
        while(t--)
        {
            scanf("%d",&n);
            getchar();
            ans=0;
            while(n--)
            {
                cin.getline(a,105);
                int len = strlen(a);
                int k=0;b="";
                for(i=0;i<len;i++)
                {
                    if(!((a[i]>='A'&&a[i]<='Z')||(a[i]>='a'&&a[i]<='z')))
                    {
                        for(j=0;j<ans;j++)
                        {

                        }
                    }
                }
            }
        }
    return 0;
}
