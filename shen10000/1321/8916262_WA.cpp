#include<stdio.h>
int str[8][8],c;
int n=0,k=0,num=0;
int x=0;
bool p1=true;
void dfs(int step,int hhh)
{
	if(x<n-step-1)return;
	if(k-step>n-hhh)return;
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
			x--;
			dfs(step+1,i+1);
			x++;
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
	x=0;
	for(int i=0;i<n;i++)
	{
		getchar();
		p1=true;
		for(int j=0;j<n;j++)	
		{
			c=getchar();
			if(c=='#')str[i][j]=0;
			else {str[i][j]=1;if(p1){x++;p1=false;}}
		}		
	}	
num=0;
dfs(0,0);
printf("%d\n",num);
	
	
}
return 0;
}
