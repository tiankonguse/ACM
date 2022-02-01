#include"iostream"
using namespace std;
int a[31]={1};
int main(){
    int sum=0;
    for(int i=1;i<=30;i++){
      if(i%2==1)a[i]=0;
      else{
         sum=3*a[i-2];
         for(int j=i-4;j>=0;j-=2){
            sum+=a[j]*2;
         }
         a[i]=sum;
      }
    }
    int n;
    while(scanf("%d",&n)){
       if(n==-1)break;
       printf("%d\n",a[n]);
    }
    return 0;
}
