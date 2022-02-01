#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int mod[6]={60,30,20,15,12,10};
int str0[6],str1[6];

bool dp(int t,int sum)
{
	if(sum>str1[t])return false;
	if(t==0)
	{
		if(str0[t]>=sum)return true;
		return false;	
	}
	
	for(int i=0;i<=str0[t];i++)
	{
		int num=sum-(t+1)*i;
		if(num<0)return false;
		if(num==0)return true;
		if(dp(t-1,num))return true;	
	}	
	
	return false;	
}

int main()
{
	int n,i,m,k=1,sum;	
	while(1)
	{
		sum=0;n=6;
		for(i=0;i<n;i++)
		{
			scanf("%d",&str0[i]);	
			str0[i]%=mod[i];
			sum+=str0[i]*(i+1);
			str1[i]=sum;
		}	
	
		if(sum==0)break;
		printf("Collection #%d:\n",k);
		k++;
		if(sum%2||i==1){printf("Can't be divided.\n\n",k);continue;}	
	
		sum>>=1;
		if(dp(5,sum)){printf("Can be divided.\n\n",k);}
		else {printf("Can't be divided.\n\n",k);}	
				
	}	
	
return 0;	
}

