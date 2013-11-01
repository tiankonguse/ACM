#include<stdio.h>
#include<math.h>

int main()
{
while(1)
{
char a, b;
a = getchar();    
if(a == 69)break;
double x, y;

scanf("%lf %c %lf", &x, &b, &y);
getchar(); 
if((a == 'T' && b == 'D') || (a == 'D' && b == 'T'))
{ 
    if(a == 'D')
    {
    double p;
    p = x;
    x = y;
    y = p;
    }  
    double q,z; 
    q = 6.11 * exp(5417.7530 * ( (1 / 273.16) - (1 / (y + 273.16) ) ) );
    z = 0.5555 * (q - 10.0) + x;
    printf("T %.1lf D %.1lf H %.1lf\n", x, y, z);
}
else if((a == 'H' && b == 'D') || ( a== 'D' && b == 'H'))
{
    if(a == 'D')
    {
    double p;
    p = x;
    x = y;
    y = p;
    }  
    double q,z; 
    q = 6.11 * exp(5417.7530 * ( (1 / 273.16) - (1 / (y + 273.16) ) ) );
    z = x - 0.5555 * (q - 10.0);
    printf("T %.1lf D %.1lf H %.1lf\n", z, y, x);    
}
else if((a == 'T' && b == 'H') || (a == 'H' && b == 'T'))
{
    if(a == 'H')
    {
    double p;
    p = x;
    x = y;
    y = p;
    }  
    double q, z;
    q = 1 / 273.16 - log( ( (y - x) / 0.5555 + 10.0) / 6.11) / 5417.7530;
    z = 1 / q - 273.16;
     

    printf("T %.1lf D %.1lf H %.1lf\n", x, z, y);        
      
}
}

return 0;
}
