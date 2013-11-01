#include<stdio.h>
int str[8][8],c;
int n=0,k=0,num=0;

void dfs(int step,int hhh)
{
	if(step==k)
	{
		num++;
		return ;	
	}	
	
	for(int i=hhh;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(str[i][j])continue;	
			
			for(int h=0;h<n;h++)
			{
				str[i][h]++;	
				str[h][j]++;
			}	
			
			dfs(step+1,i+1);
			
			for(int h=0;h<n;h++)
			{
				str[i][h]--;	
				str[h][j]--;
			}	
		}			
	}			
}


int main()
{
while(scanf("%d%d",&n,&k),(n+1)&&(k+1))
{
	for(int i=0;i<n;i++)
	{
		getchar();
		for(int j=0;j<n;j++)	
		{
			c=getchar();
			if(c=='#')str[i][j]=0;
			else str[i][j]=1;
		}		
	}	
num=0;
dfs(0,0);
printf("%d\n",num);
	
	
}
return 0;
}
