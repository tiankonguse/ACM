#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<ctime>
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
using namespace std;
const double eps = 1e-6;
struct circle{
    double x,y,r;
}cir[3];
inline double dist(double x1,double y1,double x2,double y2){
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
double dir[4][2]={0,1,0,-1,1,0,-1,0};
double ang[3];
double cal(double x,double y){
    double s=0,at=0;
    for(int i=0;i<3;i++){
        ang[i]=dist(x,y,cir[i].x,cir[i].y) / cir[i].r;
        at += ang[i];
    }
    at /= 3.0;
    for(int i=0;i<3;i++){
        s += (at-ang[i])*(at-ang[i]);
    }
    /*for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            s+= (ang[i]-ang[j])*(ang[i]-ang[j]);
        }
    }*/
    return s;
}
int main(){
    double x=0,y=0,rx,ry,tx,ty,r,t;
    while(1){
        for(int i=0;i<3;i++){
            scanf("%lf %lf %lf",&cir[i].x,&cir[i].y,&cir[i].r);
            x += cir[i].x;
            y += cir[i].y;
        }
        if(cir[0].r==0)break;
        x /= 3.0;
        y /= 3.0;
        r = 1e10;
        double delta = 1;

        int best;
        while(delta > eps){
            r=cal(x,y);
            best=-1;
            for(int i=0;i<4;i++){
                t=cal(x+dir[i][0]*delta,y+dir[i][1]*delta);
                if(t<r){
                    r=t;
                    best=i;
                }
            }
            if(best==-1)delta*=0.7;
            else{
                x+=dir[best][0]*delta;
                y+=dir[best][1]*delta;
            }

        }
        if(cal(x,y)< 1e-5) printf("%.2lf %.2lf\n",x+eps,y+eps);
        else printf("No solution\n");
    }
    return 0;
}
