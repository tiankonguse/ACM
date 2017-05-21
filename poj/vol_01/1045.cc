#include"iostream"
#include"cmath"
using namespace std;
int main(){
    double vs,r,c,w;
    int n;
    scanf("%lf%lf%lf%d",&vs,&r,&c,&n);
    while(n--){
       scanf("%lf",&w);
       printf("%.3lf\n",c*r*w*vs/sqrt(c*r*w*c*r*w+1));
    }
    return 0;
}
