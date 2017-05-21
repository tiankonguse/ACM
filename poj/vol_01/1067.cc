#include"iostream"
#include"cmath"
using namespace std;
double x=(1+sqrt(5.0))/2;
int main(){
    int a,b,t;
    while(scanf("%d%d",&a,&b)!=EOF){
          if(a>b){t=a,a=b,b=t;}
          if((int)((b-a)*x)==a)printf("0\n");
          else printf("1\n");
    }
    return 0;
}
