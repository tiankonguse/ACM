#include"iostream"
#include"cmath"
using namespace std;
int main(){
    int T,p,n,res,m;
    scanf("%d",&T);
    while(T--){
       scanf("%d%d",&p,&n);
       while((n&1)==0)n>>=1;
       if(n==1)res=0;
       else{
          res=1;
          m=(int)sqrt(1.0*n);
          for(int i=3;i<m;i+=2){
              if(n%i==0)res+=2;
          }
          if(m*m==n)res++;
       }
       printf("%d %d\n",p,res);
    }
  //  system("pause");
    return 0;
}
