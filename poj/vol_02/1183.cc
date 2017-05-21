#include"iostream"
using namespace std;
int main(){
    __int64 a,m,s;
    while(~scanf("%I64d",&a)){
         s=a*a+1;
         for(m=a;m>=1;m--){
             if(s%m==0)break;
         }
         printf("%I64d\n",a+a+m+s/m);
    }
    return 0;
}
