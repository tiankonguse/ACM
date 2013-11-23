#include<stdio.h>
#include<math.h>

int main()
{
while(1)
{
char c;
c=getchar();    
if(c==69)break;
double t;
double d;
scanf("%lf %c %lf",&t,&c,&d);
getchar(); 
   
double h; 
h = 6.11 * exp(5417.7530 * ( (1/273.16) - (1/(d + 273.16))));
h = 0.5555 * (h - 10.0) + t;
printf("T %.1lf D %.1lf H %.1lf\n",t,d,h);

}

return 0;
}
