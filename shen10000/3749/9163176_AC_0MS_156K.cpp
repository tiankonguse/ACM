#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
using namespace std;
int main()
{
char str[350],*p,s2[]="ENDOFINPUT";
while(1)
{
	gets(str);	

	if(strcmp(str,s2)==0)break;
	
	gets(str);
	p=str;
	while(*p)
	{
		if(*p<='Z'&&*p>='A'){char c=(*p-'A'+21)%26+'A';putchar(c);}	
		else putchar(*p);
		p++;
	}
	putchar('\n');
	gets(str);	
}
getchar();getchar();
return 0;
}
