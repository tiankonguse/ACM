#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
using namespace std;
double xmul(double x1,double y1,double x2,double y2){
    return x1*y2-x2*y1;
}
double area(double ax,double ay,double bx,double by,double cx,double cy){
    return fabs(xmul(ax-bx,ay-by,cx-bx,cy-by));
}
int main(){
    double ax,ay,bx,by,cx,cy,dx,dy,ex,ey,fx,fy;
    while(scanf("%lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf",
                 &ax,&ay,&bx,&by,&cx,&cy,&dx,&dy,&ex,&ey,&fx,&fy)){
        if(ax==0 && ay==0 && bx==0 && by==0 && cx==0 && cy==0 &&
           dx==0 && dy==0 && ex==0 && ey==0 && fx==0 && fy==0)
           break;

        double ar = area(dx,dy,ex,ey,fx,fy) / 2.0;
        double cr = area(ax,ay,bx,by,cx,cy);
        double hx = ax+(cx-ax)*ar/cr;
        double hy = ay+(cy-ay)*ar/cr;
        double gx = hx+bx-ax;
        double gy = hy+by-ay;
        printf("%.3lf %.3lf %.3lf %.3lf\n",gx,gy,hx,hy);
    }
    return 0;
}
