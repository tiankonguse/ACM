#include <stdio.h>
#include <math.h>
#define PI 3.1415926

int main() {
    double x,y,x1,y1,x2,y2,cosx,a,b,c,r,delta;
    int t;
    scanf("%d",&t);
    while(t--) {
        scanf("%lf%lf",&x,&y);
        r=x*x+y*y;
        a=4;
        b=4*y;
        c=r-4*x*x;
        delta=b*b-4*a*c;
        y1=(-1*b-sqrt(delta))/(2*a);
        y2=(-1*b+sqrt(delta))/(2*a);
        if(x==0) {
            x1=-sqrt(r-y1*y1);
            x2=sqrt(r-y2*y2);
        } else {
            x1=(-1*r/2-y*y1)/x;
            x2=(-1*r/2-y*y2)/x;
        }
        printf("%.3lf %.3lf %.3lf %.3lf\n",x1,y1,x2,y2);
    }
    return 0;
}
