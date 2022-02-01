#include"iostream"
#include"algorithm"
using namespace std;
bool cmp(int a,int b){
     return a>b;     
}
int main(){
    int N,M,F,i,sum,c=0,a[1001];
    bool flag;
    scanf("%d",&N);
    while(N--){
      c++;
      scanf("%d%d",&M,&F);
      for(i=0;i<F;i++){
        scanf("%d",&a[i]);
      }
      sort(a,a+F,cmp);
      sum=0;
      flag=false;
      for(i=0;i<F;i++){
         sum+=a[i];
         if(sum>=M){flag=true;break;}
      }
      printf("Scenario #%d:\n",c);
      if(flag)printf("%d\n\n",i+1);
      else printf("impossible\n\n");
    }
    return 0;
}
