#include<stdio.h>
#include<string.h>
int str[500002];
bool map[5000000];
int main()
{
	int c;
	memset(map,true,sizeof(map));
	str[0]=0;
	for(int i=1;i<=500000;i++)
	{
		c=str[i-1]-i;
		if(c>0 && map[c])
		{
			str[i]=c;
			map[c]=false;
		}
		else 
		{
			c=str[i-1]+i;
			str[i]=c;
			map[c]=false;
		}	
	}
while(scanf("%d",&c),c+1)
{
	printf("%d\n",str[c]);
}
return 0;
}
