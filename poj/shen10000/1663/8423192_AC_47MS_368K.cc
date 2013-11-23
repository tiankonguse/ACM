#include<stdio.h>

int main()
{

int num,x,y,i;
scanf("%d",&num);
for(i=0;i<num;i++)
{
    scanf("%d%d",&x,&y);
    if(x==y)
    {
        if((x+y)%4==0)printf("%d\n",x+y);    
        else printf("%d\n",x+y-1);
    }
    else if(x==y+2)
    {
        if((x+y)%4==0)printf("%d\n",x+y-1);    
        else printf("%d\n",x+y);       
    }
    else printf("No Number\n");
}

return 0;
}