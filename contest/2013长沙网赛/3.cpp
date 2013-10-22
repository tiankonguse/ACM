#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
int a[100005],b[100005],n,s[100005];
int main()
{
int i,j,k,q;
while(scanf("%d",&n)!=EOF)
{
for(i=1;i<=n;i++)
scanf("%d",&a[i]),s[i]=-1;
for(i=1;i<=n;i++)
scanf("%d",&b[i]);
if(n>=3)s[3]=b[2]-b[1];
for(i=6;i<=n;i+=3)
{
s[i] = b[i-1]-(b[i-2]-s[i-3]);
}
if(n-2>=1)s[n-2]=b[n-2]-b[n]
scanf("%d",&q);

}
}
