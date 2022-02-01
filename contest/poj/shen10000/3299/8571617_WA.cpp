#include<stdio.h>
#include<math.h>

int main()
{
while(1)
{
char c;
c=getchar();    
if(c=='E')break;
double a,d;
scanf("%lf %c %lf",&a,&c,&d);
getchar(); 
   
double e = 6.11 * exp (5417.7530 * ( (1/273.16) - (1/(d + 273.16))));
double h = 0.5555 * (e - 10.0);
printf("T %.1lf D %.1lf H %.1lf\n",a,d,h+a);

}

return 0;
}
