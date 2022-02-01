#include"iostream"
using namespace std;
double min(double a,double b){
    return a<b?a:b;
}
double c(double a,double b){
    double res=1;
    for(double i=1;i<=b;i++){
        res*=a/i;
        a--;
    }
    return res;
}
int main(){
    double a,b;
    while(scanf("%lf%lf",&a,&b)){
       if(a==0 && b==0)break;
       else printf("%.0lf\n",c(a+b,min(a,b))); 
    }
    return 0;
}
