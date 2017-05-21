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
    double x1,y1,x2,y2,x3,y3,x,y;
    while(~scanf("%lf%lf%lf%lf%lf%lf",&x1,&y1,&x2,&y2,&x3,&y3)){
       x=cal_center_x(x1,y1,x2,y2,x3,y3);
       y=cal_center_y(x1,y1,x2,y2,x3,y3);
       printf("%.2lf\n",sqrt((x-x1)*(x-x1)+(y-y1)*(y-y1))*pi*2.0);
    }
    return 0;
}
