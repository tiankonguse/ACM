#include"iostream"
#include"cmath"
using namespace std;
const double pi=acos(-1.0);
int main(){
    double V,D;
    while(scanf("%lf%lf",&D,&V)&&V){
         printf("%.3lf\n",pow(D*D*D-6.0*V/pi,1.0/3.0));
    }
    return 0;
}

