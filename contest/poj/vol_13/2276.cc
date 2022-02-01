#include"iostream"
#include"cmath"
using namespace std;
const double pi=acos(-1.0);
int main(){
    double D,H,a,b,c;
    scanf("%lf%lf",&D,&H);
    while(scanf("%lf%lf%lf",&a,&b,&c)){
       if(a==0 && b==0 && c==0)break;
       a=tan(a*pi/180.0);
       b=tan(b*pi/180.0);
       c=tan(c*pi/180.0);
       printf("%.0lf\n",H+D/sqrt(0.5/a/a+0.5/c/c-1.0/b/b));
    }
    return 0;
}
