#include<stdio.h>
int main()
{
int x,y,m,n,l,i,a,b;
scanf("%d%d%d%d%d",&x,&y,&m,&n,&l);
a=x;
b=y;
for(i=1;;i++)
{
   
    x=(x+m)%l;

    y=(y+n)%l;
    
if(x==y)break;

if(x==a&&y==b)break;   
}

if(x==y)
    printf("%d\n",i);
else
    printf("Impossible\n");

return 0;
}
