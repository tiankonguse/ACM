#include"iostream"
#include"cmath"
using namespace std;
const double pi=acos(-1.0);
int main(){
    int T;
    double R,N,v;
    scanf("%d",&T);
    for(int i=1;i<=T;i++){
       scanf("%lf%lf",&R,&N);
       printf("Scenario #%d:\n",i);
       v=cos(pi*(N-2)/N/2.0);
       printf("%.3lf\n",v*R/(v+1.0));
       if(i!=T)printf("\n");
    }
    return 0;
}
