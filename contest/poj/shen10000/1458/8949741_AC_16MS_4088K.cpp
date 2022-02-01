#include<stdio.h>
#include<string.h>
//#include<stdlib.h>
char str1[1000],str2[1000];
int str0[1001][1001]; 
int max(int a,int b)
{
if(a>=b)return a;
return b;	
}

int main()
{
while(scanf("%s%s",str1,str2)!=EOF)
{
	memset(str0,-1,sizeof(str0));    
	int m=strlen(str1);
	int n=strlen(str2); 
	for(int i=0;i<m;i++)
	for(int j=0;j<n;j++)
	{
		if(i==0&&j==0)
		{
			if(str1[i]==str2[j])str0[i][j]=1;	
			else str0[i][j]=0;	
		}
		else if(i==0)
		{
			if(str1[i]==str2[j])str0[i][j]=1;	
			else str0[i][j]=str0[i][j-1];	
		}
		else if(j==0)
		{
			if(str1[i]==str2[j])str0[i][j]=1;	
			else str0[i][j]=str0[i-1][j];	
		}	
		else
		{
			if(str1[i]==str2[j])str0[i][j]=str0[i-1][j-1]+1;	
			else str0[i][j]=max(str0[i][j-1],str0[i-1][j]);		
		}
		
	}
	
	  
	printf("%d\n",str0[m-1][n-1]);

}

return 0;
}
