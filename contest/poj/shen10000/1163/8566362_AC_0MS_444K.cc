#include<stdio.h>
#include<string.h>
int str0[105][105],str1[105][105];

int max(int a, int b)
{
 return a>b?a:b;       
}

int fun(int a,int b)
{
if(str1[a][b]!=-1)return str1[a][b];
if(a==0&&b==0)return str1[a][b]=str0[a][b];
if(b==0)return str1[a][b]=fun(a-1,b)+str0[a][b];
if(a==b)return str1[a][b]=fun(a-1,b-1)+str0[a][b];   
 return str1[a][b]=max(fun(a-1,b-1),fun(a-1,b))+str0[a][b];      
}

int main()
{

int n,i,j; 
memset(str1,-1,sizeof(str1));
scanf("%d",&n);
for(i=0;i<n;i++)
for(j=0;j<=i;j++)
{
scanf("%d",&str0[i][j]);    
}
int max=-1;
for(i=0;i<n;i++)
{
str1[n-1][i]=fun(n-1,i); 
max=max>str1[n-1][i]?max:str1[n-1][i];   
}
printf("%d\n",max);
//getchar();getchar();
return 0;
}
