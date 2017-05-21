#include"iostream"
using namespace std;
int getr(int a){
   int s=0;
   while(a){
       s=s*10+a%10;
       a/=10;
   }
   return s;
}
int main(){
    int N,a,b;
    scanf("%d",&N);
    while(N--){
       scanf("%d%d",&a,&b);
       printf("%d\n",getr(getr(a)+getr(b)));
    }
    return 0;
}
