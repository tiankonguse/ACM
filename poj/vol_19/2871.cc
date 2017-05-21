#include"iostream"
using namespace std;
int main(){
    double a,b;
    bool flag=false;
    while(scanf("%lf",&a)){
       if(a==999){printf("End of Output\n");break;}                    
       if(!flag){flag=true;b=a;continue;}
       else{
           printf("%.2lf\n",a-b);
           b=a;
       }
    }
    return 0;
}
