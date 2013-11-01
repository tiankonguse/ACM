#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int str0[6];
int str1[6];

int cmp(void const *a,void const *b)
{
return (*(int*)a - *(int*)b);	
}

int dp(int n,int num)
{
if(str1[n]<num)return 0;
if(str1[n]<num)return 1;
if(num<0||n<0)return 0;
if(num==str0[n])return 1;

if(dp(n-1,num)||dp(n-1,num-str0[n]))return 1;
return 0;	
}
int main()
{
	int n,i,m,k=1,sum;	
	while(1)
	{
		sum=0;i=0;n=6;
		while(n--)
		{
			scanf("%d",&m);	
		
			if(m!=0)
			{

				str0[i++]=m;
				sum+=m;						
			}
		}	
		

		
		if(sum==0)break;
		printf("Collection #%d:\n",k);
		k++;
		if(sum%2||i==1){printf("Can be divided.\n\n",k);continue;}	
		qsort(str0,i,sizeof(int),cmp);	
		str1[0]=str0[0];
		for(int j=1;j<i;j++)
		str1[j]=str1[j-1]+str0[j];
			
		sum>>=1;
		if(dp(i-1,sum)){printf("Can't be divided.\n\n",k);}
		else {printf("Can be divided.\n\n",k);}	
				
	}	
	
return 0;	
}

