#include"iostream"
#include"cstdlib"
using namespace std;
int dat[10];
int change(int n){
   int res=0,cnt=0;
   while(n){
       if(n%10>4)n--;
       res+=(n%10)*dat[cnt++];
       n/=10;
   }
   return res;
}
int main(){
    dat[0]=1;
    for(int i=1;i<11;i++)dat[i]=dat[i-1]*9;
    int N;
    while(scanf("%d",&N)&&N){
       printf("%d: %d\n",N,change(N));
    }
    return 0;
}
