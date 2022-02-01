#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
using namespace std;
int main()
{
	int n;
	
	while(scanf("%d",&n)!=EOF)
	{
		if(n&n-1)printf("NO\n");
		else printf("YES\n");		
	}

return 0;
}

