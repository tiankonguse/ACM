#include<stdio.h>
#include<string.h>
int num[55];
unsigned __int64 f[55][55];
int main()
{
  int n,m,ct=0;
  while(scanf("%d%d",&n,&m)!=EOF)
  {
      if(n==0&&m==0)   break;       
    int i,j,a,k;
    memset(num,0,sizeof(num));
    for(i=0;i<n;i++)
    {
       scanf("%d",&a);
       num[a]++;
    }
       memset(f,0,sizeof(f));
       f[0][0]=1;
       for(i=0;i<50;i++)
       for(j=0;j<=50;j++)
          for(k=0;k<=num[i+1];k++)
       f[i+1][j+k]=f[i+1][j+k]+f[i][j];
       printf("Case %d:\n",++ct);
    for(i=0;i<m;i++)
    {
       scanf("%d",&a);
    printf("%I64d\n",f[50][a]);
       }
    }
}