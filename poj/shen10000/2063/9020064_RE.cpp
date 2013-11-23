#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct str
{
int t;
int v;	
}str1[12];

int sum=0,year=0;

int max(int a,int b)
{
return a>b?a:b;
}

int main()
{
int n,m;
scanf("%d",&n);
while(scanf("%d%d",&sum,&year)!=EOF) 
{
	scanf("%d",&n);
int _max=sum/1000;	
	for(int i=1;i<=n;i++)	
	{
		scanf("%d%d",&str1[i].t,&str1[i].v);	
		str1[i].t/=1000;
	}
		
	while(year--)
	{
		int str2[3000005]={0};
		for(int i=1;i<=n;i++)
		for(int j=str1[i].t;j<=_max;j++)	
			str2[j]=max(str2[j],str2[j-str1[i].t]+str1[i].v);
	sum+=str2[_max];
	_max=sum/1000;			
			
	}
	printf("%d\n",sum);		
}


getchar();getchar();
return 0;
}