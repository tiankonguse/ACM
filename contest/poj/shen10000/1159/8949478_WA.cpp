#include<stdio.h>
#include<string.h>
char str1[5002],str2[5002],str[5002];
short int str0[5002][5002]={0};
int max(int a,int b)
{
if(a>b)return a;
return b;	
}
int main()
{
	int n;
	scanf("%d",&n);
	scanf("%s",str);
	for(int i=0;str[i];i++)
	{
		str1[i+1]=str[i];
		str2[i+1]=str[n-i+1];	
	}
	
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	{
		if(str1[i]==str2[j])str0[i][j]=str0[i-1][j-1]+1;	
		else str0[i][j]=max(str0[i][j-1],str0[i+1][j]);			
	}
	
	printf("%d\n",n-str0[n][n]);
	

    getchar();getchar();
return 0;
}
/*

最小长度MINLEN    原字符S      S逆序字符S'     MLC为 S 与S' 的最长子串

MINLEN=N-MLC

*/
