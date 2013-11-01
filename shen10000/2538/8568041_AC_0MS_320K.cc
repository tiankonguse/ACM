#include<stdio.h>
char key[50]="`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";

int main()
{
char c;
int i;
while((c=getchar())!=EOF)
{
 for(i=1;key[i]&&(key[i]!=c);i++);   
	if(key[i])
		putchar(key[i-1]);
	else
		putchar(c);  
}

return 0;
}
