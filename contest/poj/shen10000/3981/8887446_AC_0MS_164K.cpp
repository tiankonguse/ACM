#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char str1[1500];
char *p;
int i;

int  main()
{
//freopen("3981in.txt","r",stdin);
//freopen("3981out.txt","w",stdout);
while(gets(str1))
{
    p=str1;                        
 for(i=0;p[i];i++)     
{
if(p[i+1]=='\0'){putchar(p[i]);break;}                      
if(p[i+2]=='\0'){putchar(p[i]);putchar(p[i+1]);break;}        
if(p[i]=='y'&&p[i+1]=='o'&&p[i+2]=='u'){i+=2;putchar('w');putchar('e');continue;}
putchar(p[i]);                      
}  
putchar('\n');                         
}

    // getchar();getchar();
return 0;
}
