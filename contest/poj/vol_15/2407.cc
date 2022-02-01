#include"iostream"
#include"cstdlib"
using namespace std;
int Phi(int n){
   int i,j,ret=n;
   for(i=2,j=4;j<=n;i++,j+=i+i-1)
    if(!(n%i)){
    ret=ret/i*(i-1);
    while(!(n%i))n/=i;
   }
   if(n>1)ret=ret/n*(n-1);
   return ret;                   
}
int main(){
    int n;
    while(scanf("%d",&n)&&n){
       printf("%d\n",Phi(n));
    }
    return 0;
}

