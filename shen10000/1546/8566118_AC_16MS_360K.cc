#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
int x;
int m,n,i,len1;
char str1[9];
int str2[9];

while(scanf("%s%d%d",str1,&n,&m)!=EOF)
{

    x=0;
    
    len1=strlen(str1);

   for(i=0;i<len1;i++)
   {
    if(str1[i]>=65)str1[i]-=7;
           
    x=x*n+str1[i]-48;   
   }
    for(i=0;;i++)  
    {
        str2[i]=x%m;
        x=x/m;
    
        if(x==0||i>8)break;    
    } 

    len1=i; 
     
    if(len1>6)printf("  ERROR\n");
    else
    {
        for(i=6;i>=0;i--)
        {
             if(i>len1)printf(" ");
             
             else
             {
                 if(str2[i]>9) printf("%c",str2[i]+55);       
                 else  printf("%c",str2[i]+48);       
             }   
                
        }    
        printf("\n");    
            
    }
       
}
return 0;
}
