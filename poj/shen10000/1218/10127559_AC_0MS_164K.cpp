#include<stdio.h>
int map[]={1,0};
int main()
{
    int n,i,j;
    int str[105];
    scanf("%d",&n);
    while(~scanf("%d",&n))
    {
    for(int i=1;i<=n;i++)str[i]=1;
    for(int i=2;i<=n;i++)
        for(int j=i;j<=n;j+=i)
                str[j]=map[str[j]];
    int ans=0;
    for(int i=1;i<=n;i++)ans+=str[i];
    
    printf("%d\n",ans);
    }
return 0;
}