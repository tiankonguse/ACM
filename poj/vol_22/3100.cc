#include"iostream"
#include"cmath"
using namespace std;
int main(){
    double A,B,N,d1,d2;
    while(scanf("%lf%lf",&B,&N)){
       if(B==0 && N==0)break;
       A=1.0*(int)pow(B,1.0/N);
       d1=fabs(pow(A,N)-B);
       d2=fabs(pow(A+1,N)-B);
       if(d1<d2)printf("%.0lf\n",A);
       else printf("%.0lf\n",A+1);
    }
    return 0;
}
