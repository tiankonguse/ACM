#include<stdio.h>
#include<string.h>
int str[129];
int main()
{

while(1)
{
memset(str,0,sizeof(str));
char p;
p=getchar();     
if(p==46)break;

while(p!=10)  
{
str[p]++;    
p=getchar();    
}
int max=-1;
for(int i=0;i<129;i++)
max=max>str[i]?max:str[i];
   printf("%d\n",max);
} 
return 0;
}
