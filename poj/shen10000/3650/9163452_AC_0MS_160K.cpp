#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
using namespace std;
int main()
{
char str[300],*p;
while(gets(str),str[0]!='#')
{
	p=str;
	while(*p)
	{
		switch(*p)
		{
			case ' ':printf("%%20");break;	
			case '!':printf("%%21");break;	
			case '$':printf("%%24");break;	
			case '%':printf("%%25");break;	
			case '(':printf("%%28");break;	
			case ')':printf("%%29");break;	
			case '*':printf("%%2a");break;	
			default:putchar(*p);
			
		}	
		p++;	
	}	
	putchar('\n');	
	
}
return 0;
}
