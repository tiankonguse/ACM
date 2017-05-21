#include"iostream"
#include"cmath"
#include"algorithm"
using namespace std;
double dis(double x1,double y1,double x2,double y2){
       return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
void fun(double x1,double y1,double x2,double y2,double &x,double &y){
   double a0,a1,d=dis(x1,y1,x2,y2);
   a0=acos(d/4.0);
   a1=asin((y2-y1)/d);
   x=x1+2*cos(a0+a1);
   y=y1+2*sin(a0+a1);
}
int main(){
    int T,n;
    double a[15],b[15],x,y;
    
    while(scanf("%d",&n)&&n){
          for(int j=0;j<n;j++){
                  scanf("%lf",&a[j]);
                  b[j]=1;
          }
          sort(a,a+n);
          for(int j=n-1;j>0;j--){
              for(int k=0;k<j;k++){
                 fun(a[k],b[k],a[k+1],b[k+1],x,y);
                 a[k]=x;
                 b[k]=y;
              }
          }
          printf("%.4lf %.4lf\n",a[0],b[0]);
    }
    return 0;
}
