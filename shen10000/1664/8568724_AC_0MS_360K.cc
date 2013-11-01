#include<stdio.h>

int fun2(int x,int y)
{ 
     
  int fun1(int,int);
  
  if(x==1||x==y)return 1;
    
return fun1(x-y,y);    
}



int fun1(int x,int y)
{
    if(x<y)y=x;
    
   int sum=0;
   int i;
   
   for(i=1;i<=y;i++)
       sum+=fun2(x,i); 
    
return  sum;   
}


int main()
{

int t,m,n,i,sum;

scanf("%d",&t);
 
for(i=1;i<=t;i++)
{
sum=0;        
scanf("%d%d",&n,&m); 
sum=fun1(n,m);       
printf("%d\n",sum);
}

return 0;
}
