#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <complex>
#define eps (1e-4)
#define x real()
#define y imag()
#define min(a,b) (a<b?a:b)
#define max(a,b) (a>b?a:b)
using namespace std;
typedef complex<double> Point;
inline int sgn(double a){return (a>eps) - (a<-eps);}
bool sml(Point a,Point b){return sgn(a.x-b.x)==0 ? (sgn(a.y-b.y)<0) : (sgn(a.x-b.x)<0);}
bool rightb(Point a,Point b){return sgn(a.x-b.x)>=0 && sgn(a.y-b.y)<=0;}
double cross(Point a,Point b){return imag(conj(a)*b);}
double dmul(Point a,Point b){return real(conj(a)*b);}
bool crosspoint(Point p1,Point p2,Point q1,Point q2){
    double a=cross(p2-p1,q2-q1),b=cross(p2-p1,p2-q1),c=cross(q2-q1,p2-p1),d=cross(q2-q1,q2-p1);
    if(a==0){return b!=0? 0 : (sgn(dmul(q1-p1,q1-p2))<=0 || sgn(dmul(q2-p1,q2-p2))<=0);}
    else return (sgn(b/a)>=0 && sgn(b/a-1)<=0 && sgn(d/c)>=0 && sgn(d/c-1)<=0);
}
int judge(Point l[2],Point lt,Point rb,Point lb,Point rt){
    Point rlt = Point(min(lt.x,rb.x),max(lt.y,rb.y));
    Point rrb = Point(max(lt.x,rb.x),min(lt.y,rb.y));
    if((rightb(l[0],rlt) && rightb(rrb,l[0])) || (rightb(l[1],rlt) && rightb(rrb,l[1]))) return true;
    if(crosspoint(l[0],l[1],lt,lb))return true;
    if(crosspoint(l[0],l[1],lt,rt))return true;
    if(crosspoint(l[0],l[1],lb,rb))return true;
    if(crosspoint(l[0],l[1],rt,rb))return true;
    return false;
}
int main(){
    int N;
    Point l[2],lt,rb,lb,rt;
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        scanf("%lf %lf %lf %lf %lf %lf %lf %lf",
                &l[0].x,&l[0].y,&l[1].x,&l[1].y,&lt.x,&lt.y,&rb.x,&rb.y);
       // if(!sml(lt,rb))swap(lt,rb);
        lb=Point(lt.x,rb.y);
        rt=Point(rb.x,lt.y);
        printf(judge(l,lt,rb,lb,rt)? "T\n" : "F\n");
    }
    return 0;
}
