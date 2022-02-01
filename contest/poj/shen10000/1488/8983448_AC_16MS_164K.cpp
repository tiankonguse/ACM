#include<stdio.h>
char c;
char const p='"';

int main()
{
char str1[2][9]={"``","''"};	
int map[2]={1,0};
int t=0;

while((c=getchar())!=EOF)
{
if(p==c){printf("%s",str1[t]);t=map[t];}	
else putchar(c);	
}	
return 0;	
}
