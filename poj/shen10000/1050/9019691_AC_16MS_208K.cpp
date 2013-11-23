#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int n;
int str[101][101];
int b[101];
int fun2()
{
	int sum=-999999,c=0;
	for(int i=0;i<n;i++)
	{
		if(c>0)c+=b[i];	
		else c=b[i];
		if(c>sum)sum=c;	
	}	
return sum;	
}
int fun1()
{
	int sum=-9999;

	for(int i=0;i<n;i++)
	{
		memset(b,0,sizeof(b));	
		for(int j=i;j<n;j++)
		{
			for(int k=0;k<n;k++)b[k]+=str[j][k];
			int max=fun2();
			if(max>sum)sum=max;	
		}		
	}
		
return sum;	
}

int main()
{

while(scanf("%d",&n)!=EOF)
{
	
	for(int i=0;i<n;i++)
	for(int j=0;j<n;j++)
	scanf("%d",&str[i][j]);
	
	printf("%d\n",fun1());
}	
return 0;	
} 
