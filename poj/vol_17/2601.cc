#include"iostream"
using namespace std;
int main(){
    int N;
    double a0,an1,c,s=0;
    scanf("%d",&N);
    scanf("%lf%lf",&a0,&an1);
    for(int i=N;i>=1;i--){
        scanf("%lf",&c);
        s+=i*c;
    }
    printf("%.2lf\n",(an1-2*s+N*a0)/(N+1));
   // system("pause");
    return 0;
}
