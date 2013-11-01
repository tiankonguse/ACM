#include<stdio.h>


int main()
{

while(1)
{

char p;
p=getchar();     
if(p==46)break;
int q=0;
while(p!=10)  
{
if(p=='a') 
q++;    
p=getchar();    
}

   printf("%d\n",q);
} 
return 0;
}
