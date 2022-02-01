#include"iostream"
#include"algorithm"
using namespace std;
int main(){
    double a[6];
    while(scanf("%lf%lf%lf%lf%lf%lf",a,a+1,a+2,a+3,a+4,a+5)){
        if(a[0]==0 && a[1]==0 && a[2]==0 && a[3]==0 && a[4]==0 && a[5]==0)break;
        sort(a,a+6);
        printf("%g\n",(a[1]+a[2]+a[3]+a[4])/4.0);
    }
    return 0;
}
