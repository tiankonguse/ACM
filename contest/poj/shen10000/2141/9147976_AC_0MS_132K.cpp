#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
char str[300],str1[200],c;
while(scanf("%s",str)!=EOF)
{
	getchar();
	for(int i=0;i<26;i++)
	{
		str1['a'+i]=str[i];	
		str1['A'+i]=str[i]-'a'+'A';
	}
	gets(str);
	char *p=str;
	while(*p)
	{
		if(*p==' ')	putchar(*p);
		else putchar(str1[*p]);
		p++;
	}
	putchar('\n');
}

return 0;
}
