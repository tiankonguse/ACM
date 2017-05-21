#include"iostream"
using namespace std;
int k[10001];
__int64 down[10001],up[10001];
void init(int m,int a,int b){
   __int64 sum,ksum;
   sum=down[1]=0;ksum=k[1];
   for(int i=2;i<=m;i++){
     down[i]=down[i-1]+b*ksum+sum;
     sum+=ksum;ksum+=k[i];
   }
   sum=up[m]=0;ksum=k[m];
   for(int i=m-1;i>=1;i--){
     up[i]=up[i+1]+a*ksum+sum;
     sum+=ksum;ksum+=k[i];
   }
}
int main(){
    int T,M,a,b,r=0;
    __int64 min,sum;
    scanf("%d",&T);
    while(T--){
       scanf("%d%d%d",&M,&a,&b);
       for(int i=1;i<=M;i++){
          scanf("%d",&k[i]);
       }
       min=1e18;
       init(M,a,b);
       for(int i=1;i<=M;i++){
          sum=up[i]+down[i];
          if(sum<min){
                      min=sum;
                      r=i;
          }
       }
       printf("%d\n",r);
    }
//  system("pause");
    return 0;
}
