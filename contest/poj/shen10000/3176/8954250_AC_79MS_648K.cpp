#include<stdio.h>
int str[352][352];
int n;
int max(int a,int b)
{
if(a>=b)return a;
return b;	
}
int main()
{
scanf("%d",&n);
for(int i=0;i<n;i++)
for(int j=0;j<=i;j++)
scanf("%d",&str[i][j]);


for(int i=n-2;i>=0;i--)
for(int j=0;j<=i;j++)
{
str[i][j]+=max(str[i+1][j],str[i+1][j+1]);	
}
printf("%d\n",str[0][0]);
    getchar();getchar();
return 0;
}
