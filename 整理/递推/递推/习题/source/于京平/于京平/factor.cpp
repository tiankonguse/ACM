#include<stdio.h>
int main()
{
	freopen("factor.in","r+",stdin);
	freopen("factor.out","w+",stdout);
    int a,b,k,n,m,a1,b1;
    scanf("%d%d%d%d%d",&a,&b,&k,&n,&m);
    a1=a%10007;
    b1=b%10007;
    int f[100][100],i,j;
    f[1][0]=0;
    f[0][1]=1;
    f[1][1]=1;
    f[0][0]=1;
    for(i=1;i<=n;i++)
    {
        f[i][0]=0;
        for(j=1;j<=k;j++)
        {
            f[0][j]=1;
            f[i][j]=(f[i][j-1]*b1%10007+f[i-1][j-1]*a1%10007)&10007;
        }
    }
    printf("%d",f[n][k]);
    return 0;
}

