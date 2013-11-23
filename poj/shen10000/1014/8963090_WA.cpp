#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int str0[6];
int dp(int n,int num)
{
if(num<0||n<0)return 0;
if(num==str0[n])return 1;


if(dp(n-1,num)||dp(n-1,num-str0[n]))return 1;
return 0;	
}
int main()
{
	int n,i,m,k=0,sum;	
	while(1)
	{
		sum=0;i=0;n=6;
		while(n--)
		{
			scanf("%d",&m);	
		
			if(m)
			{
				sum+=m;	
				str0[i++]=m;	
			}
		}	
		
		if(sum==0)break;
		k++;
		
		for(int j=0;j<i;j++)
		printf("%d ",str0[j]);

		if(sum%2||i==1){printf("Collection #%d:\nCan be divided.\n\n",k);continue;}	
		sum>>=1;	
		printf("%d\n",sum);		
		if(dp(i-1,sum)){printf("Collection #%d:\nCan't be divided.\n\n",k);}
		else {printf("Collection #%d:\nCan be divided.\n\n",k);}	
				
	}	
	
return 0;	
}
