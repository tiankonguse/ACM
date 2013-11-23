#include<stdio.h>
#include<math.h>
#define PI 3.141592653589793

int main()
{
double x1,x2,x3,y1,y2,y3;
while(scanf("%lf%lf%lf%lf%lf%lf",&x1,&y1,&x2,&y2,&x3,&y3)!=EOF)
{
double a,b,c;
double s,q,l;
a=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
b=sqrt((x3-x2)*(x3-x2)+(y3-y2)*(y3-y2));
c=sqrt((x1-x3)*(x1-x3)+(y1-y3)*(y1-y3));
q=(a+b+c)/2;
s=sqrt(q*(q-c)*(q-b)*(q-a));
l=(a*b*c*PI)/(2*s);
printf("%.2lf\n",l);

}
 return 0;
}
