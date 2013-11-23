#include<stdio.h>
#include<stdlib.h>
#include<string.h>
const int M=10001;
const int N=2139062143;
int f1[M+1],f2[M+1];
bool map[M+1];

int main()
{
int n;
scanf("%d",&n);
while(scanf("%d",&n)!=EOF)
{
	int b,m,p,max=0;
	memset(map,false,sizeof(map));
	memset(f1,0,sizeof(f1));
	int g=0;
	memset(f2,127,sizeof(f2));
		
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&m);	
			
		while(m--)
		{
			
			scanf("%d%d",&b,&p);
			map[b]=true;
			if(max<b)max=b;	
					
			for(int k=b;k<M;k++)
			{	
				if(f1[k]+p < f2[b] )f2[b] = f1[k]+p;
				if(f1[k]==0||f1[k]==N){if(g<k)g=k+10;break;}
			}
			
			for(int k=0;k<b;k++)
			{
				if(f1[k]+p<f2[k])f2[k]=f1[k]+p;	
			}

				
		}
		    if(i==1)memset(f1,127,sizeof(f1));				
			for(int k=0;k<g;k++)
			{
				f1[k]=f2[k];
				f2[k]=N;
			}
			
	}
		double ans=0.0;
		for(int i=1;i<=max;i++)
			if(map[i])
			{
				double an=(1.0*i)/f1[i];
				if(an>ans)ans=an;	
			}	
		printf("%.3lf\n",ans);

}
	
return 0;	
}


