#include"iostream"
using namespace std;
int fun(int m,int n){
   if(m<0)return 0;
   if(m==0 || m==1 || n==1)return 1;
   else return fun(m-n,n)+fun(m,n-1);
}
int main(){
    int T,M,N;
    scanf("%d",&T);
    while(T--){
       scanf("%d%d",&M,&N);
       printf("%d\n",fun(M,N));
    }
    return 0;
}
