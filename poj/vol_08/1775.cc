#include"iostream"
using namespace std;
int fac[11];
void init(){
    fac[0]=1;
    for(int i=1;i<=10;i++)fac[i]=fac[i-1]*i;
}
int main(){
    int n,p;
    bool flag;
    init();
    while(scanf("%d",&n)){
      if(n<0)break;
      flag=false;
      p=10;
      while(1){
         while(n<fac[p]){
             p--;
             if(p<0){flag=false;break;}
         }
         if(p<0)break;
         n-=fac[p--];
         if(n==0){flag=true;break;}
         if(p<0)break;
      }
      if(flag)printf("YES\n");
      else printf("NO\n");
    }
    return 0;
}
