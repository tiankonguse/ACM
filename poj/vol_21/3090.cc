#include"iostream"
using namespace std;
int dat[1001];
int gcd(int a,int b){
    if(b==0)return a;
    else return gcd(b,a%b);
}
int main(){
    dat[0]=2;
    for(int i=1;i<=1000;i++){
       for(int j=1;j<=i;j++){
           if(gcd(i,j)==1){
              if(i==j)dat[i]++;
              else dat[i]+=2;
           }
       }
       dat[i]+=dat[i-1];
    }
    int T,N;
    scanf("%d",&T);
    for(int i=1;i<=T;i++){
       scanf("%d",&N);     
       printf("%d %d %d\n",i,N,dat[N]);
    }
  //  system("pause");
    return 0;
}
