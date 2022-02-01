#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
using namespace std;
int main()
{
char str1[20],str2[20],*p1,*p2;
int n,m;
while(scanf("%s%s",str1,str2)!=EOF)
{
	n=m=0;
	p1=str1;
	p2=str2;
	while(*p1)
	{
		n+=*p1-'0';	
		p1++;	
	}	
	while(*p2)
	{
		m+=*p2-'0';	
		p2++;	
	}	
	printf("%d\n",m*n);				
}
getchar();getchar();
return 0;
}
