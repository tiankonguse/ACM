#include"iostream"
#include"cmath"
using namespace std;
const double pi=acos(-1.0);
double cal_center_x(double x1,double y1,double x2,double y2,double x3,double y3){   
    return((y1*(y2*y2+x2*x2-y3*y3-x3*x3) - y2*(y1*y1 - y3*y3 + x1*x1 - x3*x3) + y3*(y1*y1-y2*y2+x1*x1-x2*x2))/(2*(-x1*y2 + x1*y3 + x2*y1 - x2*y3 - x3*y1 + x3*y2)));   
}   
double cal_center_y(double x1,double y1,double x2,double y2,double x3,double y3){   
    return((x1*(x2*x2+y2*y2-x3*x3-y3*y3) - x2*(x1*x1 - x3*x3 + y1*y1 - y3*y3) + x3*(x1*x1-x2*x2+y1*y1-y2*y2))/(2*(-y1*x2 + y1*x3 + y2*x1 - y2*x3 - y3*x1 + y3*x2)));   
}   
int main(){
    double x1,y1,x2,y2,x3,y3,x,y,r,c,d,e;
    while(~scanf("%lf%lf%lf%lf%lf%lf",&x1,&y1,&x2,&y2,&x3,&y3)){
       x=cal_center_x(x1,y1,x2,y2,x3,y3);
       y=cal_center_y(x1,y1,x2,y2,x3,y3);
       r=sqrt((x-x1)*(x-x1)+(y-y1)*(y-y1));
       c=x*2.0;
       d=y*2.0;
       e=r*r-x*x-y*y;
       printf("(x ");
       if(x>0)printf("- %.3lf)^2 + (y ",x);
       else printf("+ %.3lf)^2 + (y ",-x);
       if(y>0)printf("- %.3lf)^2 = %.3lf^2\n",y,r);
       else printf("+ %.3lf)^2 = %.3lf^2\n",-y,r);
       printf("x^2 + y^2 ");
       if(c>0)printf("- %.3lfx ",c);
       else printf("+ %.3lfx ",-c);
       if(d>0)printf("- %.3lfy ",d);
       else printf("+ %.3lfy ",-d);
       if(e>0)printf("- %.3lf = 0\n\n",e);
       else printf("+ %.3lf = 0\n\n",-e);
    }
    return 0;
}
