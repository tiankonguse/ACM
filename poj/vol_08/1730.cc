#include"iostream"
#include"cmath"
using namespace std;
const double eps=1e-11;
bool equal(double a,double b){
    if(fabs(a-b)<eps)return true;
    return false;
}
int main(){
    double a;
    while(scanf("%lf",&a)&&a){
        if(a>0){
           for(double p=31;p>=1;p--){                  
               if(equal(pow(floor(pow(a,1.0/p)+eps),p),a)){
                  printf("%.0lf\n",p);
                  break;
               }
           }
       }
       else{
           for(double p=31;p>=1;p--){       
               if(equal(pow(floor(pow(-a,1.0/p)+eps),p),-a)){
                  if((int)p%2==1){
                     printf("%.0lf\n",p);
                     break;
                  }
                  else continue;
               }
           }
       }
    }
    return 0;
}
