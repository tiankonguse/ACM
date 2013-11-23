#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
using namespace std;
int main()
{
int str[100002];
int n,i;
while(scanf("%d",&n),n)
{
	for(i=1;i<=n;i++)
		scanf("%d",&str[i]);	
	bool p=true;
	for(i=1;i<=n&&p;i++)
		if(str[str[i]]!=i)
			p=false;	
	if(p)printf("ambiguous\n");
	else printf("not ambiguous\n");
}

return 0;
}
