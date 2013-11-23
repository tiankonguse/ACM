#include<stdio.h>

int main()
{

int a,b;
while(scanf("%d%d",&a,&b)!=EOF) 
{
int d=a;
while(a>=b)
{
d+=a/b;
a=a/b+a%b;    
}
 printf("%d\n",d);     
}

return 0;
}
