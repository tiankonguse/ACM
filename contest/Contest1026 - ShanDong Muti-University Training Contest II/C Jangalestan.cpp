/*************************************************************************
    > File Name: C Jangalestan.cpp
    > Author: tiankonguse
    > Mail: shen10000shen@gmail.com
    > Created Time: 2013/5/14 18:18:17
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
int a[1000006],prime[1000006];
int sum[1000006];
int main()
{
    int i,j,t,n;
    scanf("%d",&t);
    int k=0;
    for(i=2;i<=1000000;i++)
    {
        if(a[i]==0)
        {
            prime[k++]=i;
            if(k-1==0)sum[0]=i;
            else sum[k-1]=sum[k-2]+i;
            for(j=i+i;j<=1000000;j+=i)
            {
                a[j]=1;
            }
        }
    }
    while(t--)
    {
        scanf("%d",&n);
        int ans=0;
        for(i=0;i<k;i++)
        {
            if(sum[i]==n)ans++;
            for(j=i-1;j>=0;j--)
            {
                if(sum[i]-sum[j]>n)break;
                if(sum[i]-sum[j]==n)ans++;
                //cout<<sum[i]<<" "<<sum[j]<<endl;
            }
        }
        printf("%d\n",ans);
    }
}
