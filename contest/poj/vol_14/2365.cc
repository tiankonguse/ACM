#include"iostream"
#include"cmath"
using namespace std;
const double pi=acos(-1.0);
double dist(double x1,double y1,double x2,double y2){
       return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
} 
int main(){
    int N;
    double r,x0,y0,x1,y1,x2,y2,s;
    scanf("%d%lf",&N,&r);
    s=2.0*pi*r;
    for(int i=0;i<N;i++){
       if(i==0){
                scanf("%lf%lf",&x0,&y0);
                x1=x0;
                y1=y0;
       }
       else{
          scanf("%lf%lf",&x2,&y2);
          s+=dist(x1,y1,x2,y2);
          x1=x2;
          y1=y2;
       }
    }
    s+=dist(x1,y1,x0,y0);
    printf("%.2lf\n",s);
    //system("pause");
    return 0;
}
