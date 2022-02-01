#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
using namespace std;
int main()
{
int str[102][102],n,map[101]={0};
cin>>n;
for(int i=0;i<n;i++)
for(int j=0;j<n;j++)
	cin>>str[i][j];
for(int i=1;i<n;i++)
for(int j=0;j<i;j++)
{
(str[i][j]>str[j][i])?(map[i]++):(map[j]++);	
}
int max=map[0];
int p=0;	
for(int i=1;i<n;i++)
	if(max<map[i])
	{
		max=map[i];
		p=i;
	}	

printf("%d\n",p+1);

getchar();getchar();
return 0;
}
