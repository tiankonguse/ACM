#include<stdio.h>
#include<stdlib.h>
#include<string.h>
const int M=10001;
int f[1001][M+1];
bool map[M+1];

int main()
{
int n;
scanf("%d",&n);
while(scanf("%d",&n)!=EOF)
{
	int b,m,p,max=0;
	memset(map,false,sizeof(map));
	memset(f,127,sizeof(f));
	
	for(int i=0;i<M;i++)
		f[0][i]=0;
		
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&m);		
		while(m--)
		{
			scanf("%d%d",&b,&p);
			map[b]=true;
			if(max<b)max=b;
			
			for(int k=b;k<M;k++)
			f[i][b]=(f[i-1][k]+p)<f[i][b]?(f[i-1][k]+p):f[i][b];
			
			for(int k=0;k<b;k++)
			if(f[i-1][k]+p<f[i][k])f[i][k]=f[i-1][k]+p;			
		}	
	}
		double ans=0.0;
		for(int i=1;i<=max;i++)
			if(map[i])
			{
				double an=(1.0*i)/f[n][i];
				if(an>ans)ans=an;	
			}	
		printf("%.3lf\n",ans);

}
	
return 0;	
}
