#include"iostream"
#include"cmath"
using namespace std;
const double pi=acos(-1.0);
int main(){
    int T;
    double D,d,s;
    scanf("%d",&T);
    while(T--){
        scanf("%lf%lf%lf",&D,&d,&s);
        printf("%d\n",(int)(pi/asin((d+s)/(D-d))));
    }
   // system("pause");
    return 0;
}
