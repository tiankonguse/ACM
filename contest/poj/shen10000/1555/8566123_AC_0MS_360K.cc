#include<stdio.h>

int main()
{

int str[10],i;
bool ch,bh;

while(scanf("%d",&str[0])!=EOF)
{
for(i=1;i<9;i++)
scanf("%d",&str[i]);
ch=false;
int k=0;
for(i=0;i<9;i++)
{
if(str[i]==0)continue;
if(ch==true)printf(" ");

if(ch==false&&str[i]!=1&&str[i]!=-1&&i!=8)printf("%d",str[i]);
else if(ch==false&&str[i]==-1&&i!=8)printf("-");
else if(ch==true){
   
   if(str[i]>0)
   {
        printf("+ ");
        if(str[i]>1)
        printf("%d",str[i]);
        else if(i==8&&str[i]==1)
        printf("%d",str[i]);
    }
    else
    {
     printf("- ");
        if(str[i]<-1)
        printf("%d",-str[i]);
        else if(i==8&&str[i]==-1)
        printf("%d",-str[i]);   
        
    }
}
if(i<7)printf("x^%d",8-i);
else if(i==7)printf("x");
if(i==8)k++;
else
ch=true;    
}
if(k==1&&ch==false)printf("%d",str[8]);
else if(ch==false)printf("0");    
printf("\n");    
    
}


return 0;
}
