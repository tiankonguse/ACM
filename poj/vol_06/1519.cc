#include"iostream"
using namespace std;
int main(){
    char c[10000];
    int n,sum;
    while(scanf("%s",c)){
       if(c[0]=='0')break;
       n=0;
       for(int i=0;i<strlen(c);i++){
         n+=c[i]-48;
       }
       while(n/10){
         sum=0;
         while(n){
            sum+=n%10;
            n/=10;
         }
         n=sum;
       }
       printf("%d\n",n);
    }
    return 0;
}
