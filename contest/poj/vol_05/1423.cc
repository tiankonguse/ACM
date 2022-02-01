#include"iostream"
#include"cmath"
using namespace std;
int a[10000001];
double e=2.7182818284590452354;
double pi=3.141592653589793239;
int stl(int a){
     return (int)(0.5*log10(2*pi*a)+a*(log10((double)a)-log10(e)));
}
int main(){
    double sum=0;
    for(int i=1;i<=10000000;i++){
       sum+=log10((double)i);
       a[i]=(int)sum+1;
    }
    int t,m;
    scanf("%d",&t);
   /* for(int i=1;i<=10000000;i++){
      if(a[i]!=stl(i)+1)printf("#");
      if(i%100000==0)printf(".");
    }*/
    while(t--){
       scanf("%d",&m);
      // printf("%d\n",a[m]);
       printf("%d\n",stl(m)+1);
    }
    return 0;
}
