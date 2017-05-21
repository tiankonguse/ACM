#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <complex>
#define EPS (1e-4)
#define PI atan2(0,-1)
#define X real()
#define Y imag()

using namespace std;
typedef complex<double> Point;
double cross(Point a,Point b){return imag(conj(a)*b);}
int crosspoint(Point p1,Point p2,Point q1,Point q2,Point &r){
    double a = cross(p2-p1,q2-q1), b = cross(p2-p1,p2-q1);
    if(a==0)return b==0?0:-1;
    r = q1+b/a*(q2-q1);
    return 1;
}

int main(){
    int N;
    Point p1,p2,q1,q2,r;
    double x0,y0,x1,y1,x2,y2,x3,y3;
    scanf("%d",&N);
    printf("INTERSECTING LINES OUTPUT\n");
    for(int i=0;i<N;i++){
        scanf("%lf%lf%lf%lf%lf%lf%lf%lf",&x0,&y0,&x1,&y1,&x2,&y2,&x3,&y3);
        p1=Point(x0,y0);
        p2=Point(x1,y1);
        q1=Point(x2,y2);
        q2=Point(x3,y3);
        int ans=crosspoint(p1,p2,q1,q2,r);
        if(ans==1)printf("POINT %.2lf %.2lf\n",r.X,r.Y);
        else if(ans==-1)printf("NONE\n");
        else printf("LINE\n");
    }
    printf("END OF OUTPUT\n");
    return 0;
}
