#include <cstdlib>
#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int n,k,i;
    double x,y,pi;
    scanf("%d",&n);
    pi=acos(-1);
    for (i=1;i<=n;i++)
    {
     scanf("%lf%lf",&x,&y);
     k=(int) ceil(pi*(x*x+y*y)/2/50);
     printf("Property %d: This property will begin eroding in year %d.\n",i,k);
    }
    printf("END OF OUTPUT.");
    return 0;
}