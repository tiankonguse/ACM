#include"iostream"
using namespace std;
int b[36];
int mod_exp(int a,int b0,int n)//return a^b0 % n
{
   if( a > n ) a %= n;
   int i, d = 1;
   for( i=0; i < 35; ++i ){
   b[i] = b0%2;
   b0 /= 2;
   if( b0 == 0 ) break;
   } //b[i]b[i-1]...b[0]为b0 的二进制表示
   for( ;i >= 0; --i ){
   d = (d*d)%n;
   if( b[i] == 1 ) d = (d*a)%n;
   }
   return d;
}
int main(){
    int T,M,N,a,b,r;
    scanf("%d",&T);
    while(T--){
       r=0;
       scanf("%d%d",&M,&N);
       for(int i=0;i<N;i++){
           scanf("%d%d",&a,&b);
           r=(r+mod_exp(a,b,M))%M;
       }
       printf("%d\n",r);
    }
   // system("pause");
    return 0;
}
