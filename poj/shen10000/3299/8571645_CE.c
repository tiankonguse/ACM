#include<stdio.h>
#include<math.h>

int main()
{
while(1)
{
char c;
c=getchar();    
if(c=='E')break;
float a,d;
scanf("%f %c %f",&a,&c,&d);
getchar(); 
   
float h = 6.11 * exp (5417.7530 * ( (1/273.16) - (1/(d + 273.16))));
h = 0.5555 * (h - 10.0) + a;
printf("T %.1lf D %.1lf H %.1lf\n",a,d,h);

}

return 0;
}
