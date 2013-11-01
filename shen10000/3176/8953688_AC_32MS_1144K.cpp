#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int str[352][352];
int str1[352][352];
int n;
int max(int a,int b)
{
	if(a>=b)return a;
	return 	b;
}
int fun(int a,int b)
{
if(str1[a][b]!=-1)return str1[a][b];

if(a==n)return str1[a][b]=str[a][b];

return str1[a][b]=str[a][b]+max(fun(a+1,b),fun(a+1,b+1));	
}

int main()
{

memset(str1,-1,sizeof(str1));
scanf("%d",&n);
for(int i=1;i<=n;i++)
for(int j=1;j<=i;j++)
scanf("%d",&str[i][j]);
printf("%d\n",fun(1,1));


    getchar();getchar();
return 0;
}
