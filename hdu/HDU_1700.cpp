#include<stdio.h>
#include<math.h>
double const PI=3.1415926;
double const esp= 0.0005;
double const sin120=sqrt(3.0)/2.0;
double const cos120=-0.5;
double const sin_120=-sqrt(3.0)/2.0;
double const cos_120=-0.5;

struct Point {
    double x,y;
} p1,p2;
double x,y;


bool iszero(double xx,double yy) {
    return (xx-yy<=esp) && (xx-yy>=-esp);
}

bool bigger(double xx,double yy) {
    return xx-yy>=esp;
}

int main() {
    int n;
    scanf("%d",&n);

    while(n--) {
        scanf("%lf%lf",&x,&y);
        p1.x = x*cos120 - y*sin120;
        p1.y = x*sin120 + y*cos120;

        p2.x = x*cos_120 - y*sin_120;
        p2.y = x*sin_120 + y*cos_120;



        if(bigger(p1.y,p2.y) || (iszero(p1.y,p2.y) && bigger(p1.x,p2.x))) {
            printf("%.3f %.3f %.3f %.3f\n",p2.x,p2.y,p1.x,p1.y);
        } else {
            printf("%.3f %.3f %.3f %.3f\n",p1.x,p1.y,p2.x,p2.y);
        }

    }
    return 0;
}
