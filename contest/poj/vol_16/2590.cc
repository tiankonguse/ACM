#include"iostream"
#include"cmath"
using namespace std;
int main(){
    int T,a,b,s,n;
    scanf("%d",&T);
    while(T--){
       scanf("%d%d",&a,&b);
       if(a==b){printf("0\n");continue;}
       s=b-a;
       n=(int)2*sqrt(s*1.0)-1;
       while((n+1)*(n+1)/4<s){
          n++;
       }
       printf("%d\n",n);
    }
    return 0;
}
